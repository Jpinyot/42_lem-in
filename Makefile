# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 22:43:59 by jpinyot           #+#    #+#              #
#    Updated: 2018/09/28 20:40:33 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Wextra -Werror

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
	   ft_extrafunc.c\
	   ft_printres_extra.c\
	   ft_atoi_li.c\
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
	@-./lem-in < unvalid_map/map_non_valid00
	@-./lem-in < unvalid_map/map_non_valid01
	@-./lem-in < unvalid_map/map_non_valid02
	@-./lem-in < unvalid_map/map_non_valid03
	@-./lem-in < unvalid_map/map_non_valid04
	@-./lem-in < unvalid_map/map_non_valid05
	@-./lem-in < unvalid_map/map_non_valid06
	@-./lem-in < unvalid_map/map_non_valid07
	@-./lem-in < unvalid_map/map_non_valid08
	@-./lem-in < unvalid_map/map_non_valid09
	@-./lem-in < unvalid_map/map_non_valid10
	@-./lem-in < unvalid_map/map_non_valid11
	@-./lem-in < unvalid_map/map_non_valid12
	@-./lem-in < unvalid_map/map_non_valid13
	@-./lem-in < unvalid_map/map_non_valid14
	@-./lem-in < unvalid_map/map_non_valid15
	@-./lem-in < unvalid_map/map_non_valid16
	@-./lem-in < unvalid_map/map_non_valid17
	@-./lem-in < unvalid_map/map_non_valid18
	@-./lem-in < unvalid_map/map_non_valid19
	@-./lem-in < unvalid_map/map_non_valid20
	@-./lem-in < unvalid_map/map_non_valid21
	@-./lem-in < unvalid_map/map_non_valid22
	@-./lem-in < unvalid_map/map_non_valid23
	@-./lem-in < unvalid_map/map_non_valid24
	@-./lem-in < unvalid_map/map_non_valid25
	@-./lem-in < unvalid_map/map_non_valid26
	@-./lem-in < unvalid_map/map_non_valid27
	@-./lem-in < unvalid_map/map_non_valid28
	@-./lem-in < unvalid_map/map_non_valid29
	@-./lem-in < unvalid_map/map_non_valid30
	@-./lem-in < unvalid_map/map_non_valid31
	@-./lem-in < unvalid_map/map_non_valid32
	@-./lem-in < unvalid_map/map_non_valid33
	@-./lem-in < unvalid_map/map_non_valid34
	@-./lem-in < unvalid_map/map_non_valid35
	@-./lem-in < unvalid_map/map_non_valid36
	@-./lem-in < unvalid_map/map_non_valid37
	@-./lem-in < unvalid_map/map_non_valid38

.PHONY: all clean fclean re
