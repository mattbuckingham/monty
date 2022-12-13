CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89
RM=rm -rf
SRC=*.c
BETTY=betty
TARGET=monty

clean:
	$(RM) *~ \#*\# \.\#* \	$(TARGET)
re:
	clean all
all:
	betty $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)
dev:
	$(CC) $(SRC) -o $(TARGET)
