CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LDFLAGS	=
LDLIBS	=

SUFFIX	= .o
NAME	= libft.a

CORR_FILES = ./Makefile ./src

# DEBUG routine
ifeq ($(BUILD), Debug)
	CFLAGS	+= -fsanitize=address -g -O0 -D DEBUG
	SUFFIX	= .debug.o
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
	SRC += $(shell ls $(SRC_PREFIX)debug/*.c)
endif


OBJ = $(subst $(SRC_PREFIX), , $(SRC:.c=$(SUFFIX)))
OBJ := $(addprefix $(OBJ_PREFIX), $(OBJ))

.PHONY: all re debug bonus clean fclean dclean correction

all: $(NAME)

test:
	@echo hello;
	@echo test;

debug:
	@$(MAKE) BUILD=Debug all

$(NAME): $(OBJ)
	@echo "making $@"
	@ar rc $@ $^
	@ranlib $(NAME)

$(OBJ_PREFIX)%$(SUFFIX): $(SRC_PREFIX)%.c
	@echo "making $@"
	@mkdir -p $(OBJ_PREFIX)
	@mkdir -p $(OBJ_PREFIX)debug/
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	/bin/rm -rf $(OBJ_PREFIX)

fclean: clean
	/bin/rm -f $(NAME)

dclean: fclean
	/bin/rm -rf $(OBJ_PREFIX)

re: fclean all

correction_%:
	@echo "\033[32mCopying libft into \033[33m/tmp/$*\033[0m"
	@mkdir -p /tmp/$*/libft
	@rsync -r --copy-links $(CORR_FILES) /tmp/$*/libft
