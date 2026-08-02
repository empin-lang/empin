CC = gcc

CFLAGS = -Wall -g -MMD -MP
TARGET = empin
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj

SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

DEPS = $(OBJS:.o=.d)

INC_DIRS = $(shell find $(INC_DIR) -type d)
CFLAGS += $(addprefix -I, $(INC_DIRS))

$(TARGET): $(OBJS)
	$(CC) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEPS)

.PHONY: clean
clean:
	rm -f $(TARGET)
	rm -rf $(OBJ_DIR)
