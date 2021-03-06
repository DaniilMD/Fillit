NAME = fillit

SRC = fillit.c preparings.c getcode.c trytofill.c kostili.c

OBJ = fillit.o preparings.o getcode.o trytofill.o kostili.o

HEADER = fillit.h

$(NAME): $(OBJ)
	@make -C libft/
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) -L libft -lft 

%.o:%.c $(HEADER)
	@gcc -Wall -Wextra -Werror -I . -c $< -o $@

clean:
	@/bin/rm -f *~
	@/bin/rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re
