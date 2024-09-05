CC = gcc
CFLAGS = -fsanitize=address -g -Wall -Wextra -Werror

TARGET = target
SRCS = MacChange.c
OBJS = $(SRCS:.c=.o)
DEPS = MacChange.h

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

# Rule to run the compiled program
run: $(TARGET)
	./$(TARGET)

get_mac: 
	networksetup -getmacaddress en0
change_addr:
	sudo ifconfig en0 ether $(ADDR)
.PHONY: all clean run
