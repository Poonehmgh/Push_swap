NAME =pushswaplibft.a
SRC = push_swap.c moves.c moves2.c input_handle.c input_process.c calculations.c utils.c executions.c list.c
OBJS = $(SRC:.c=.o)
AR = ar cr
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g


all: $(NAME)
LIB:
	make -C ./libft
	cp ./libft/libft.a $(NAME)

$(NAME): LIB $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) pushswaplibft.a -o push_swap 

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/pushswaplibft.a
	rm -f pushswaplibft.a
	rm -f push_swap
	rm -f push_swap.a

re: fclean all

.PHONY: all clean fclean re