# Makefile for fluid simulation using SDL2

# Compiler and flags
CC = gcc
CFLAGS = -O2 -Wall -lm `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs`

# Target binary
TARGET = fluid

# Source files
SRCS = fluid.c

# Build target
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Clean build artifacts
clean:
	rm -f $(TARGET)
