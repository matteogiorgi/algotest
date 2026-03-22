CC = cc
CFLAGS = -Wall -Wextra -pedantic -std=c11 -g -O0

TARGET = bin/sorting
SRC = src/sorting.c
HDR = src/sorting.h

.PHONY: all run valgrind clean

all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
	rm -f $(TARGET)
