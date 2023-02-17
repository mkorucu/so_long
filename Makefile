# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkorucu <mkorucu@student.42istanbul.com.t  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 17:22:58 by mkorucu           #+#    #+#              #
#    Updated: 2022/09/29 17:23:00 by mkorucu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c map_check.c keys_errors.c

OBJS = $(SRCS:.c=.o)

CC = gcc

MFLAGS =  ./sources/libft/libft.a ./mlx/libmlx.a ./sources/ft_printf/libftprintf.a ./sources/get_next_line/get_next_line.a

AFLAGS =  -Wall -Wextra -Werror -I ./mlx -I ./libft -I ./ft_printf -I ./get_next_line

RM = rm -rf

NAME = so_long

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./sources/get_next_line
	make -C ./sources/libft
	make -C ./sources/ft_printf
	make -C ./mlx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	$(RM) ./sources/libft/*.a
	$(RM) ./*.a
	$(RM) ./sources/ft_printf/*.a
	$(RM) ./sources/get_next_line/*.a
	$(RM) $(NAME)

clean :
	$(RM) ./sources/libft/*.o
	$(RM) ./*.o
	$(RM) ./sources/ft_printf/*.o
	$(RM) ./sources/get_next_line/*.o

re : fclean all

.PHONY : all fclean clean re
