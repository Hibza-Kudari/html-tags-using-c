
CC = gcc
CFLAGS = -std=c11 -O2 -Wall -Wextra
TARGET = check_html
SRC = src/check_html_tags.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f $(TARGET)
