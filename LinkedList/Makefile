
CC = gcc
CFLAGS = -fsanitize=address -g  -Wall -Wextra -Werror


TARGET = target


SRCS = main.c LL.c


OBJS = $(SRCS:.c=.o)


DEPS = LL.h


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	./target


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
