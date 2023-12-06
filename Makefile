Library     = fdf
files       = 	fdf \
				join_points.c \
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
	@$(Compiler) $(CmpFlags) -c $< -I./ -I/usr/include -Imlx_linux -O3 -g3 -o $@

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

run: $(NAME)
	@$(Compiler) $(CmpFlags) -c main.c -o main.o -I./ -g3 -g
	@$(Compiler) $(CmpFlags) -o main main.o -L. $(NAME) $(MinilibX) -g
	@./main
	@echo

.PHONY: all, clean, fclean, re, run
