
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -fno-stack-protector

SOURCES := $(wildcard *.c)
TARGETS := $(SOURCES:.c=)

.PHONY: all clean

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(TARGETS) $(addsuffix .exe,$(TARGETS))
