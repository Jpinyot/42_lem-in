# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 22:43:59 by jpinyot           #+#    #+#              #
#    Updated: 2018/06/04 21:55:06 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = 

SRC_DIR = srcs/

STR_DIR = srcs/struct/

PRT_DIR = srcs/print/

FUNC_DIR = srcs/func/

SRC = main.c\
      lem_in.c\
      getord.c\
      getstruct.c\
      getlinks.c\
      getpaths.c\
      translate.c\
      antdist.c\
      printres.c\

FUNC = ft_idgenerator.c\
       ft_mindistance.c\
       ft_read_nd_clear.c\
       ft_getaxis.c\
       ft_insertlink.c\
       ft_linkupdown.c\
	   ft_exit.c

STR = ft_newstruct.c\
      ft_deletemap.c\
      ft_deleteid.c\
      ft_deletepath.c\
      ft_deletehex.c\
      ft_deletedstr.c\

PRT = ft_putmap.c\
      ft_putres.c\
      ft_visula.c\
      ft_putbanner.c\
      ft_staticpath.c\
      ft_statichex.c\
      ft_dynamicpath.c\
      ft_putdstr.c\

OBJ_SRC = $(patsubst %.c, $(SRC_DIR)%.o, $(SRC))
OBJ_STR = $(patsubst %.c, $(STR_DIR)%.o, $(STR))
OBJ_FUNC = $(patsubst %.c, $(FUNC_DIR)%.o, $(FUNC))
OBJ_PRT = $(patsubst %.c, $(PRT_DIR)%.o, $(PRT))

OBJ = $(SRC:.c=.o) $(STR:.c=.o) $(PRT:.c=.o) $(FUNC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ_SRC) $(OBJ_STR) $(OBJ_PRT) $(OBJ_FUNC)
	@$(MAKE) -C libft
	@gcc $(FLAGS) -L./libft/ -lft -L./libft/ft_printf -lftprintf -I./includes $(OBJ) -o $(NAME)
%.o : %.c
	@gcc $(FLAGS) -I./includes -c $<

clean:
	@$(MAKE) -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean
	make
check:
	./lem_in < valid_map/valid_map00 | cat -e
	./lem_in < valid_map/valid_map01 | cat -e
	./lem_in < valid_map/valid_map02 | cat -e
	./lem_in < valid_map/valid_map03 | cat -e
	./lem_in < valid_map/valid_map04 | cat -e
	./lem_in < valid_map/valid_map05 | cat -e
	./lem_in < valid_map/valid_map06 | cat -e
	./lem_in < valid_map/valid_map07 | cat -e
	./lem_in < valid_map/valid_map08 | cat -e
	./lem_in < valid_map/valid_map09 | cat -e
	./lem_in < valid_map/valid_map10 | cat -e
	./lem_in < valid_map/valid_map11 | cat -e
	./lem_in < valid_map/valid_map12 | cat -e
	./lem_in < valid_map/valid_map13 | cat -e
	./lem_in < valid_map/valid_map14 | cat -e
	./lem_in < valid_map/valid_map15 | cat -e
	./lem_in < valid_map/validOrNot_Do_not_worry00 | cat -e
	./lem_in < valid_map/valid_map_dead_way00 | cat -e
	./lem_in < valid_map/valid_map_long_way00 | cat -e
	./lem_in < valid_map/valid_map_long_way01 | cat -e


.PHONY: all clean fclean re
