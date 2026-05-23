CC = gcc
CFLAGS = -Wall -g

SRC_DIR = $(shell pwd)

OBJ_DIR = obj


SRCS = $(wildcard $(SRC_DIR)/*.c)

TARGETS = $(basename $(notdir $(SRCS)))


OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: run

$(shell mkdir -p $(OBJ_DIR))

$(TARGETS): %: $(OBJ_DIR)/%.o
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGETS)
	rm -rf $(OBJ_DIR)

rebuild: clean all

run: $(OBJ_DIR) $(TARGETS)
	./$(TARGETS)

.PHONY: all clean rebuild run
