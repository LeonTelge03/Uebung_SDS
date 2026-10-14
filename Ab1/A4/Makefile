
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -fno-stack-protector
LDLIBS += -lreadline

SOURCES := $(wildcard *.c)
TARGETS := $(SOURCES:.c=)

.PHONY: all clean

all: $(TARGETS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

clean:
	$(RM) $(TARGETS) $(addsuffix .exe,$(TARGETS))
