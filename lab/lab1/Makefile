CC = gcc
CFLAGS = -Wall -g

# 源文件目录
SRC_DIR = $(shell pwd)
# 目标文件目录（可选，用于存放 .o 文件）
OBJ_DIR = obj

# 查找 src 目录下的所有 .c 文件
SRCS = $(wildcard $(SRC_DIR)/*.c)
# 生成对应的可执行文件名（去掉目录和 .c 后缀）
TARGETS = $(basename $(notdir $(SRCS)))

# 生成 .o 文件路径（放在 obj 目录下）
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(OBJ_DIR) $(TARGETS)

# 创建 obj 目录
$(shell mkdir -p $(OBJ_DIR))

# 为每个源文件单独生成可执行文件
# 使用静态模式：% 匹配每个 TARGET
$(TARGETS): %: $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) -o $@ $^

# 编译 .c 到 .o（放在 obj 目录）
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGETS)
	rm -rf $(OBJ_DIR)

# 清理并重新编译所有
rebuild: clean all

# 运行第一个 target（如果有多个，默认运行第一个）
run: $(firstword $(TARGETS))
	./$(firstword $(TARGETS))

# 如果 src 下有多个 .c 文件，可以分别运行
.PHONY: all clean rebuild run
