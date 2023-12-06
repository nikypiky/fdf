CC := cc
CFLAGS := -Wall -Wextra -Werror
LDFLAGS := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

TARGET := fdf.a
SOURCES := main.c join_points.c
OBJECTS := $(SOURCES:.c=.o)

.PHONY: all clean fclean re run

all: $(TARGET) run

$(TARGET): $(OBJECTS)
	@ar -rc $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	@$(CC) $(CFLAGS) -c main.c -o main.o
	@$(CC) -o main main.o -L. $(TARGET) $(LDFLAGS)
	@./main
	@echo

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(TARGET) main

re: fclean all
