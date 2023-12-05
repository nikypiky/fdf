Library     = fdf
files       = file1 file2 file3  # Add your source files here
Compiler    = cc
CmpFlags    = -Wall -Wextra -Werror
MinilibX    = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
NAME        = $(Library).a
CFILES      = $(files:%=%.c)
OFILES      = $(files:%=%.o)

all: $(NAME) run

$(NAME): $(OFILES)
	@ar -rc $(NAME) $(OFILES)

%.o: %.c
	@$(Compiler) $(CmpFlags) -c $< -I./ -g3 -D $(BUFFER) -g

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: $(NAME)
	@$(Compiler) $(CmpFlags) -c main.c -o main.o -I./ -g3 -D $(BUFFER) -g
	@$(Compiler) $(CmpFlags) -o main main.o -L. $(NAME) $(MinilibX) -g
	@./main
	@echo

.PHONY: all, clean, fclean, re, run
