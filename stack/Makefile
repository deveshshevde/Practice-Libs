
CC = gcc
CFLAGS = -fsanitize=address -g  -Wall -Wextra -Werror


TARGET = target


SRCS = main.c LL.c stack.c


OBJS = $(SRCS:.c=.o)


DEPS = LL.h stack.h


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	./target
	rm -f target stack.o LL.o main.o
	


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
