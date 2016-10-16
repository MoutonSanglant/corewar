#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 18:45:02 by lalves            #+#    #+#              #
#    Updated: 2016/10/12 19:50:08 by akopera          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBFT_PATH			= ../libft
LIBFTPRINTF_PATH	= ../libftprintf

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I../includes
LDFLAGS	= -L$(LIBFT_PATH) -L$(LIBFTPRINTF_PATH)
LDLIBS	= -lft -lftprintf

SUFFIX	= .o
NAME	= asm

# DEBUG routine
ifeq ($(BUILD), Debug)
	CFLAGS	+= -fsanitize=address -g -O0 -D DEBUG
	SUFFIX	= .debug.o
	NAME	= asm.debug
endif

# OS flags
ARCH	= $(shell uname -m)
OS		= $(shell uname -s)

ifeq ($(OS), Darwin)
	LDLIBS +=
endif

ifeq ($(OS)_$(ARCH), Linux_x86_64)
	CFLAGS += -D LINUX
	LDLIBS +=
else ifeq ($(OS), Linux)
	CFLAGS += -D LINUX
	LDLIBS +=
endif

SRC_PREFIX = ./src/
OBJ_PREFIX = ./obj/

SRC	=	$(shell ls $(SRC_PREFIX)*.c)

ifeq ($(BUILD), Debug)
	SRC +=
endif

OBJ = $(subst $(SRC_PREFIX), , $(SRC:.c=$(SUFFIX)))
OBJ := $(addprefix $(OBJ_PREFIX), $(OBJ))

.PHONY: all clean fclean re libft libftprintf debug

all: $(NAME)

debug:
	@$(MAKE) BUILD=Debug all

$(NAME): $(OBJ) $(LIBFT_PATH)/libft.a $(LIBFTPRINTF_PATH)/libftprintf.a
	@echo "making $@"
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(LIBFT_PATH)/libft.a: libft

$(LIBFTPRINTF_PATH)/libftprintf.a: libftprintf

libft:
	@echo "making $@"
	@$(MAKE) -C $(LIBFT_PATH) BUILD=$(BUILD)

libftprintf:
	@echo "making $@"
	@$(MAKE) -C $(LIBFTPRINTF_PATH) BUILD=$(BUILD)

$(OBJ_PREFIX)%$(SUFFIX): $(SRC_PREFIX)%.c
	@echo "making $<"
	@mkdir -p $(OBJ_PREFIX)
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	/bin/rm -rf $(OBJ_PREFIX)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(LIBFTPRINTF_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(LIBFTPRINTF_PATH) fclean

cclean:
	/bin/rm -rf $(OBJ_PREFIX)
	/bin/rm -f $(NAME)

re: fclean all

rre: cclean all
