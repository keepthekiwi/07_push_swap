# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skillian <skillian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/12 19:29:48 by skillian          #+#    #+#              #
#    Updated: 2022/03/02 21:27:04 by skillian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/ft_printf.a
SRC =	A_stack.c \
		B_arg_input.c \
		C_operations.c \
		D_utils.c \
		E_sort_three.c \
		F_sort_five.c \
		G_indexing.c \
		H_big_sort.c

OBJ = 	$(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(LIBFT) $(OBJ)
	@echo "Compiling push_swap..."
	@gcc $(FLAGS) $(LIBFT) $(FT_PRINTF) $(OBJ) -o $(NAME)

.c.o:	
	@gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
	@make --directory=./libft

$(FT_PRINTF):
	@make --directory=./ft_printf

clean:
	@echo "Cleaning..."
	@make fclean --directory=./libft
	@make fclean --directory=./ft_printf
	@rm -fr $(OBJ)

fclean: clean
	@rm -fr $(NAME)

re: fclean all

visual: 
	python3 pyviz.py `ruby -e "puts (-1..3).to_a.shuffle.join(' ')"`
