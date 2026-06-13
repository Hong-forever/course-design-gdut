from __future__ import annotations

import argparse
import re
from pathlib import Path

import matplotlib.pyplot as plt
import networkx as nx
import numpy as np
from networkx.algorithms.approximation import steinertree as st


DATA_FILE = Path(__file__).with_name("net_info.txt")
DEFAULT_NET_ID = 246


def read_net_info(filename: str | Path, net_id: int) -> np.ndarray:
    """Read one net from net_info.txt and return its pin coordinates.

    The file format is expected to contain blocks like:
    net246    The number of pins: 8
        0,12,34
        0,13,34
    """

    filename = Path(filename)
    net_pattern = re.compile(rf"^net{net_id}\b.*pins:\s*(\d+)", re.IGNORECASE)

    pin_count = None
    coordinates: list[list[float]] = []
    reading_pins = False

    with filename.open(encoding="utf-8") as handle:
        for raw_line in handle:
            line = raw_line.strip()
            if not line:
                continue

                match = net_pattern.match(line)
                if match:
                    pin_count = int(match.group(1))
                    reading_pins = True
                continue

            if line.startswith("net"):
                break

            parts = [part.strip() for part in line.split(",")]
            if len(parts) < 3:
                continue

            try:
                x_coord = float(parts[-2])
                y_coord = float(parts[-1])
            except ValueError:
                continue

            coordinates.append([x_coord, y_coord])
            if pin_count is not None and len(coordinates) >= pin_count:
                break

    if pin_count is None:
        raise ValueError(f"未找到 net{net_id}，请检查 {filename}")

    if not coordinates:
        raise ValueError(f"net{net_id} 没有读取到任何 pin 坐标")

    return np.asarray(coordinates, dtype=float)


def drop_duplicates(pin_cords: np.ndarray) -> np.ndarray:
    """Remove duplicated pin coordinates while preserving order."""

    if len(pin_cords) <= 1:
        return pin_cords

    seen: set[tuple[float, float]] = set()
    unique_rows: list[list[float]] = []
    for row in pin_cords:
        key = (float(row[0]), float(row[1]))
        if key in seen:
            continue
        seen.add(key)
        unique_rows.append([row[0], row[1]])

    return np.asarray(unique_rows, dtype=float)


def build_rectilinear_mesh_graph(pin_cords: np.ndarray) -> tuple[nx.Graph, list[tuple[float, float]]]:
    """Build a Manhattan grid graph from the terminal coordinates."""

    x_coords = sorted(float(value) for value in np.unique(pin_cords[:, 0]))
    y_coords = sorted(float(value) for value in np.unique(pin_cords[:, 1]))

    graph = nx.Graph()

    for x_coord in x_coords:
        for y_coord in y_coords:
            graph.add_node((x_coord, y_coord))

    for y_coord in y_coords:
        for left_x, right_x in zip(x_coords, x_coords[1:]):
            graph.add_edge((left_x, y_coord), (right_x, y_coord), length=abs(right_x - left_x))

    for x_coord in x_coords:
        for lower_y, upper_y in zip(y_coords, y_coords[1:]):
            graph.add_edge((x_coord, lower_y), (x_coord, upper_y), length=abs(upper_y - lower_y))

    terminals = [(float(row[0]), float(row[1])) for row in pin_cords]
    return graph, terminals


def draw_graph(graph: nx.Graph, pos: dict[tuple[float, float], tuple[float, float]]) -> None:
    """Draw the complete mesh graph."""

    plt.figure(figsize=(10, 10))
    nx.draw(
        graph,
        pos,
        node_color="#f5d76e",
        node_size=220,
        with_labels=False,
        edge_color="#c7c7c7",
        width=1.0,
    )


def draw_terminals(pin_cords: np.ndarray) -> None:
    """Highlight the original pins."""

    plt.scatter(pin_cords[:, 0], pin_cords[:, 1], c="red", s=60, label="pins", zorder=3)


def draw_steiner_tree(
    graph: nx.Graph,
    steiner_tree_graph: nx.Graph,
    pos: dict[tuple[float, float], tuple[float, float]],
) -> None:
    """Overlay the Steiner tree on top of the mesh graph."""

    nx.draw_networkx_edges(
        graph,
        pos,
        edgelist=list(steiner_tree_graph.edges()),
        edge_color="blue",
        width=2.8,
    )


def solve_net(net_id: int = DEFAULT_NET_ID, filename: str | Path = DATA_FILE) -> None:
    """Read one net, build the grid graph, and draw its Steiner tree."""

    pin_cords = read_net_info(filename, net_id)
    pin_cords = drop_duplicates(pin_cords)

    graph, terminals = build_rectilinear_mesh_graph(pin_cords)
    terminal_set = set(terminals)
    steiner_tree_graph = st.steiner_tree(graph, terminals, weight="length")

    pos = {node: node for node in graph.nodes()}
    draw_graph(graph, pos)
    draw_terminals(pin_cords)
    draw_steiner_tree(graph, steiner_tree_graph, pos)

    plt.gca().set_aspect("equal", adjustable="box")
    plt.title(f"net{net_id} 的 Steiner Tree")
    plt.legend(loc="best")
    plt.tight_layout()
    plt.show()

    total_length = sum(data.get("length", 1) for _, _, data in steiner_tree_graph.edges(data=True))
    print(f"net{net_id} pin 数量: {len(pin_cords)}")
    print(f"Steiner tree 边数: {steiner_tree_graph.number_of_edges()}")
    print(f"Steiner tree 总长度: {total_length}")
    print(f"终端集合: {sorted(terminal_set)}")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="VLSI 布线实验：读取线网并构造 Steiner 树")
    parser.add_argument("net_id", nargs="?", type=int, default=DEFAULT_NET_ID, help="要读取的线网编号")
    parser.add_argument(
        "--file",
        default=str(DATA_FILE),
        help="net_info.txt 的路径，默认使用脚本同目录下的文件",
    )
    return parser.parse_args()


def main() -> None:
    args = parse_args()
    solve_net(args.net_id, args.file)


if __name__ == "__main__":
    main()
