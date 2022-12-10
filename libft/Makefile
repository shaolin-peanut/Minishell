# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 16:18:24 by gmontaur          #+#    #+#              #
#    Updated: 2021/11/25 16:18:25 by gmontaur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra -O3 -c
INCLUDES = -I$(HEADERS_DIRECTORY)

##################################################################
#Header PART OF MAKEFILE
##################################################################
HEADERS_LIST = \
	libft.h \
	ft_printf.h

HEADERS_DIRECTORY = ./incl/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

##################################################################
#SOURCES PART OF MAKEFILE
##################################################################
SOURCES_DIRECTORY = ./src/
LIBFT_DIRECTORY = libft/
LIBFT_SOURCES_LIST = \
	ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_lstclear.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstlast.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_lstsize.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_dup_matrix.c \
    ft_extend_matrix.c \
    ft_free_matrix.c \
	ft_lsttomatrix.c \
    ft_matrix_del_elem.c \
    ft_matrix_replace_in.c \
    ft_matrixlen.c \
    ft_matrixtolst.c \
    ft_putmatrix_fd.c

PRINTF_DIRECTORY = printf/
PRINTF_SOURCES_LIST = \
	file.c \
	file2.c \
	ft_printf.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
SOURCES_LIST = \
	$(addprefix $(LIBFT_DIRECTORY), $(LIBFT_SOURCES_LIST)) \
	$(addprefix $(PRINTF_DIRECTORY), $(PRINTF_SOURCES_LIST))

##################################################################
#OBJECTS PART OF MAKEFILE
##################################################################
OBJECTS_DIRECTORY = objs/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)
	@echo "\n\t$(NAME):\t$(GREEN)object files were created$(RESET)"
	@echo "\t$(NAME):\t$(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)/$(LIBFT_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)/$(PRINTF_DIRECTORY)
	@echo "\t$(NAME):\t$(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"
clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "\t$(NAME):\t$(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "\t$(NAME):\t$(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re
