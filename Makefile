# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bleplat <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:05:04 by bleplat           #+#    #+#              #
#    Updated: 2020/02/28 15:30:25 by bleplat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###########################
###   B I N A R I E S   ###
###########################

NAME        = lem_in


###########################
###  L I B R A R I E S  ###
###########################

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a
LIBFTMO     = libftmo.so


###########################
###    S O U R C E S    ###
###########################

FNT =		li_main.c \
			li_perror.c \
			li_board.c \
			li_board_parse_input.c \
			li_parsing_should_line_be_ignored.c \
			li_parsing_nextline.c \
			li_parse_ants.c \
			li_parse_rooms.c \
			li_parse_links.c \
			li_room_find.c \
			li_make_link.c \
			li_board_add_output.c \
			li_print_input.c \
			li_print_result.c \


###########################
###    F O L D E R S    ###
###########################

INCLUDES = includes
SRC_DIR  = srcs
OBJ_DIR  = .obj
DEP_DIR  = $(OBJ_DIR)

SRC = $(patsubst %, $(SRC_DIR)/%, $(FNT))
DEP = $(patsubst %, $(DEP_DIR)/%.d, $(FNT))
OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(FNT))


###########################
###   C O M P I L E R   ###
###########################

CC = gcc

DEFINES = _DARWIN_USE_64_BIT_INODE
CDEFINES = $(patsubst %, -D%, $(DEFINES))

CFLAGS = -Wall -Wextra -Werror
CFLAGS += $(CDEFINES)
CFLAGS += -I $(INCLUDES)
CFLAGS += -I $(LIBFT_DIR)/includes

LDFLAGS += -L $(LIBFT_DIR) -lft


###########################
###      R U L E S      ###
###########################

.PHONY: all
all: $(NAME)

.PHONY: debug
debug: LDFLAGS += -L. -lftmo -rdynamic
debug: $(LIBFTMO) all

.PHONY: optimized
optimized: CFLAGS += -o3
optimized: all

$(NAME): $(LIBFT) $(OBJ)
	@printf "\e[92m" || true
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)
	@printf "\e[0m" || true

$(OBJ_DIR):
	@printf "\e[94m" || true
	mkdir -p $@
	@printf "\e[0m" || true

$(OBJ_DIR)/%.o: $(SRC_DIR)/% | $(OBJ_DIR)
	@printf "\e[96m" || true
	$(CC) $(CFLAGS) -o $@ -I $(INCLUDES) -c $<
	@printf "\e[0m" || true

$(LIBFT):
	@printf "\e[35m" || true
	make -C $(LIBFT_DIR) libft.a
	@printf "\e[0m" || true

$(LIBFTMO):
	@printf "\e[35m" || true
	make -C $(LIBFT_DIR) libftmo.so
	@printf "\e[35m" || true
	cp $(LIBFT_DIR)/libftmo.so $@
	@printf "\e[0m" || true

.PHONY: clean
clean:
	@printf "\e[93m" || true
	rm -f $(OBJ)
	rm -f $(OBJ_DIR)/*.o
	rmdir $(OBJ_DIR) || true
	make -C $(LIBFT_DIR) $@
	@printf "\e[0m" || true

.PHONY: fclean
fclean: clean
	@printf "\e[91m" || true
	rm -f $(NAME)
	rm -f $(LIBFTMO)
	make -C $(LIBFT_DIR) $@
	@printf "\e[0m" || true

.PHONY: re
re: fclean all
	@printf "\e[0m" || true


###########################
###  D O C   R U L E S  ###
###########################

.PHONY: help
help:
	@printf "\e[0mUSAGE:\n\e[0m" || true
	@printf "\e[0m\t./lem_in < MAP_FILE\n\e[0m" || true
	@printf "\e[0m\t./generator [OPTIONS] | ./lem_in\n\e[0m" || true