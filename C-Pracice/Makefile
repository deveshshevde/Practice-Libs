
CC = gcc
CFLAGS = -fsanitize=address -g  -Wall -Wextra -Werror


TARGET = target


SRCS = calculator.c


OBJS = $(SRCS:.c=.o)


DEPS = 


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	./target
	rm -f target calculator.o


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
