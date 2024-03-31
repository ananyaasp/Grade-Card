CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c grade_calculator.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean

all: grade_card

grade_card: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f grade_card $(OBJS)
