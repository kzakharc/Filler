#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzakharc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 16:41:27 by kzakharc          #+#    #+#              #
#    Updated: 2017/07/07 20:25:10 by kzakharc         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME    =   filler
CC      =   gcc
FLAG    =   -Wall -Wextra -Werror
LIBFT   =   ./Lib/big_libft.a
OBJ     =   ./strategy.o	    \
            ./filler.o          \
			./wrt_cln.o			\
			./main.o			\

.PHONY : libft

all : $(NAME)

$(NAME) : $(OBJ) libft
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIBFT)

libft:
	make -C ./Lib

%.o : %.c
	$(CC) $(FLAG) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make clean -C ./Lib

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./Lib

re: fclean all
