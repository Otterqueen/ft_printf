# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: aweiler <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/03/15 15:38:23 by aweiler      #+#   ##    ##    #+#        #
#    Updated: 2018/04/05 10:30:55 by aweiler     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #
.PHONY: all clean fclean re norme

CC = gcc

FLAGS = -Wall -Wextra -Werror

CPP_FLAGS = -I include

NAME = libftprintf.a

SRC_PATH = ./srcs
LIB_PATH = ./libft
INC_PATH = ./Includes
OBJ_PATH = ./obj
OBJLIB_PATH = ./obj

SRC_NAME =	essai.c \
			get_param.c \
			process.c \
			fonc_utl.c \
			process_bis.c \
			fix.c

LIB_NAME = 	 ft_isalpha.c   ft_memcpy.c    ft_putnbr.c    ft_strcat.c    ft_strjoin.c \
	  ft_strncpy.c  ft_tolower.c  ft_isascii.c  ft_memset.c   ft_putnbr_fd.c \
	  ft_strcmp.c    ft_strlen.c    ft_strnstr.c   ft_toupper.c   ft_atoi.c \
 	  ft_isdigit.c   ft_putchar.c   ft_putstr.c    ft_strcpy.c    ft_strncat.c \
	  ft_strsplit.c  ft_bzero.c    ft_isprint.c   ft_putendl.c  ft_putstr_fd.c \
	  ft_strdup.c    ft_strncmp.c   ft_strstr.c    ft_memccpy.c   ft_memmove.c \
	  ft_memchr.c    ft_memcmp.c    ft_strlcat.c   ft_strchr.c    ft_isalnum.c \
	  ft_strrchr.c   ft_memalloc.c  ft_memdel.c    ft_strnew.c    ft_strdel.c \
	  ft_strclr.c    ft_striter.c   ft_striteri.c  ft_strmap.c    ft_strmapi.c \
	  ft_strequ.c    ft_strnequ.c   ft_strsub.c    ft_strjoin.c   ft_strtrim.c \
	  ft_fillstr.c   ft_len_mot.c   ft_nb_mot.c    ft_len_int.c   ft_intlen.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	  ft_itoa.c      ft_lstdelone.c ft_lstdel.c    ft_lstadd.c    ft_lstiter.c \
	  ft_lstmap.c    ft_strjoin_bis.c ft_itoa_u.c ft_intlen_u.c ft_itoa_l.c \
	  ft_intlen_l.c  ft_itoa_base.c ft_str_toupper.c  ft_strcut.c ft_itoa_base_l.c \
	  ft_strjoinchar.c

INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJLIB_NAME = $(LIB_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
LIB = $(addprefix $(LIB_PATH)/, $(LIB_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJLIB = $(addprefix $(OBJLIB_PATH)/,$(OBJLIB_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(OBJLIB)
	@ar rc $(NAME) $(OBJ) $(OBJLIB) $(FLAG)
	@ranlib $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;35mCompilation\t\033[0;32m[OK]\033[0m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

$(OBJLIB_PATH)/%.o: $(LIB_PATH)/%.c
	@mkdir $(OBJLIB_PATH) 2> /dev/null || true
	@$(CC) -o $@ -c $<

clean: clean_lib
	@rm -rf $(OBJ) $(OBJLIB)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean fclean_lib
	@rm -rf ./obj $(NAME)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

clean_lib:
	@$(MAKE) -C $(LIB_PATH) clean

fclean_lib:
	@$(MAKE) -C $(LIB_PATH) fclean

re_lib:
	@$(MAKE) -C $(LIB_PATH) re

norme:
	@norminette $(SRC) $(LIB) $(INC)
	@echo "\033[1;34mft_printf\t\033[1;33mNorminette\t\033[0;32m[OK]\033[0m"