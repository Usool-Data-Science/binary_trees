CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic -std=gnu89

# List of utility function source files
UTIL_SRC = $(wildcard *.c)
UTIL_OBJ = $(UTIL_SRC:.c=.o)

# List of test files
TEST_SRC = $(wildcard test/*.c)
TEST_EXEC = $(TEST_SRC:test/%.c=%)

.PHONY: all clean

all: $(UTIL_OBJ) $(TEST_EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%: test/%.c $(UTIL_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(UTIL_OBJ) $(TEST_EXEC)

