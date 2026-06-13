import networkx as nx
import matplotlib.pyplot as plt
import numpy as np
import re
import argparse
import sys

def drop_duplicates(pin_coords):
    return np.unique(pin_coords, axis=0)

def generate_steiner_tree_for_net(net_id):
    """
    为指定的net_id生成并显示斯坦纳树。

    :param net_id: 要处理的线网ID (整数)
    """
    print(f"--- 开始处理 Net {net_id} ---")
    
    # 1. 读取数据文件“net_info.txt”的信息
    try:
        with open("net_info.txt", 'r') as f:
            lines = f.readlines()
    except FileNotFoundError:
        print("错误: net_info.txt 文件未找到。请确保该文件与脚本在同一目录下。")
        return

    pin_coords_list = []
    reading_pins = False
    nos_pins = 0
    
    for line in lines:
        line = line.strip()
        # 匹配线网起始行
        match = re.match(f'net{net_id}\\t.+pins: (\\d+)', line)
        if match:
            nos_pins = int(match.group(1))
            if nos_pins == 0:
                print(f"警告: Net {net_id} 有 0 个引脚，跳过。")
                return
            reading_pins = True
            continue
        
        # 读取引脚坐标
        if reading_pins and len(pin_coords_list) < nos_pins:
            parts = re.split(',', line)
            if len(parts) == 3:
                _, x, y = parts
                pin_coords_list.append([int(x), int(y)])
        
        # 如果已读完所有引脚，则停止
        if reading_pins and len(pin_coords_list) == nos_pins:
            break

    if not pin_coords_list:
        print(f"错误: 未在文件中找到 Net {net_id} 或其引脚信息。")
        return
        
    pin_coords = np.array(pin_coords_list)

    # 2. 去除重复的pin
    pin_coords = drop_duplicates(pin_coords)
    if pin_coords.shape[0] < 2:
        print(f"Net {net_id} 去重后引脚数少于2，无法生成树。")
        if pin_coords.shape[0] == 1:
            plt.figure(figsize=(8, 6))
            plt.scatter(pin_coords[:, 0], pin_coords[:, 1], c='red', s=100)
            plt.title(f"Net {net_id} - 只有一个引脚")
            plt.grid(True)
            plt.show()
        return

    print(f"去重后的引脚坐标 ({pin_coords.shape[0]}个):")
    print(pin_coords)

    # 3. 建立Hanan网格图
    unique_x = sorted(list(set(pin_coords[:, 0])))
    unique_y = sorted(list(set(pin_coords[:, 1])))

    coord_to_node = { (x, y): i for i, (x, y) in enumerate(np.array(np.meshgrid(unique_x, unique_y)).T.reshape(-1, 2)) }
    node_to_coord = { i: coord for coord, i in coord_to_node.items() }

    G_hanan = nx.Graph()
    for node_idx, coord in node_to_coord.items():
        G_hanan.add_node(node_idx, pos=coord)

    for i in range(len(unique_y)):
        for j in range(len(unique_x)):
            current_node_idx = coord_to_node[(unique_x[j], unique_y[i])]
            if j + 1 < len(unique_x):
                right_node_idx = coord_to_node[(unique_x[j+1], unique_y[i])]
                weight = unique_x[j+1] - unique_x[j]
                G_hanan.add_edge(current_node_idx, right_node_idx, length=weight)
            if i + 1 < len(unique_y):
                up_node_idx = coord_to_node[(unique_x[j], unique_y[i+1])]
                weight = unique_y[i+1] - unique_y[i]
                G_hanan.add_edge(current_node_idx, up_node_idx, length=weight)

    terminal_nodes = [coord_to_node[tuple(p)] for p in pin_coords]

    # 4. 计算斯坦纳树
    from networkx.algorithms.approximation import steiner_tree
    st_tree = steiner_tree(G_hanan, terminal_nodes, weight='length')

    # 5. 把斯坦纳树用图形方式显示出来
    plt.figure(figsize=(12, 8))
    pos = nx.get_node_attributes(G_hanan, 'pos')

    nx.draw(G_hanan, pos, node_size=10, node_color='lightblue', width=0.5)
    nx.draw(st_tree, pos, node_size=50, node_color='green', width=2.0, edge_color='green')
    
    pin_pos = {node: pos[node] for node in terminal_nodes}
    nx.draw_networkx_nodes(G_hanan, pin_pos, nodelist=terminal_nodes, node_size=100, node_color='red')

    plt.title(f"Net {net_id} - Steiner Tree on Hanan Grid")
    plt.show()

    total_length = sum(data['length'] for u, v, data in st_tree.edges(data=True))
    print(f"斯坦纳树的总长度: {total_length}")
    print(f"--- 完成处理 Net {net_id} ---\n")

if __name__ == '__main__':
    # --- 设置命令行参数解析 ---
    parser = argparse.ArgumentParser(description="为VLSI布线问题中的指定线网生成并显示斯坦纳树。")
    parser.add_argument("net_id", type=int, help="要处理的线网ID (一个整数)")
    
    # 如果没有提供参数，打印帮助信息
    if len(sys.argv) == 1:
        parser.print_help(sys.stderr)
        sys.exit(1)
        
    args = parser.parse_args()
    
    # --- 调用主函数 ---
    generate_steiner_tree_for_net(args.net_id)
