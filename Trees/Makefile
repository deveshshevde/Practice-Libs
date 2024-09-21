
CC = gcc
CFLAGS = -fsanitize=address -g  -Wall -Wextra -Werror


TARGET = tree


SRCS = main.c tree.c 


OBJS = $(SRCS:.c=.o)


DEPS = tree.h


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	./tree
	rm -f target *.o


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
