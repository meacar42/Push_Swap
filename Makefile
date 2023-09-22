
NAME = push_swap
CC = gcc  -Wall -Werror -Wextra
SRCS= main.c algorithm.c push.c r_rotate.c rotate.c swap.c utils.c utils2.c



RM = rm -rf

$(NAME):
	$(CC) $(SRCS) -o $(NAME)

all: $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) ./*.o

re: fclean all

re_bonus: fclean bonus

.PHONY : all fclean clean re re_bonus bonus
