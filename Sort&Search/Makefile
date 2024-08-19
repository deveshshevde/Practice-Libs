
CC = gcc
CFLAGS = -fsanitize=address -g  -Wall -Wextra -Werror


TARGET = target


SRCS = qsort.c


OBJS = $(SRCS:.c=.o)


DEPS = qsort.h


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	 
	./target

	rm -f target qsort.o


%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
