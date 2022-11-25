UNAME = $(shell uname -s)
CC = gcc -MD
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HEADER = libft.h
SRC_DIR = src
OBJ_DIR = obj
NAME = libft.a

SRC =	ft_atoi.c ft_calloc.c ft_putendl_fd.c	\
	ft_itoa.c ft_putchar_fd.c ft_putstr_fd.c	\
	ft_isdigit.c ft_memset.c ft_split.c			\
	ft_strchr.c ft_strdup.c ft_strjoin.c		\
	ft_strlcpy.c ft_strlen.c ft_strncmp.c		\
	ft_strnstr.c ft_strtrim.c ft_substr.c		\
	ft_isspace.c ft_nbrlen.c ft_countchar.c ft_atoi2.c \
	ft_free_matrix.c ft_dup_matrix.c ft_strchr_i.c ft_putmatrix_fd.c \
	ft_matrixlen.c ft_strchars_i.c ft_extend_matrix.c ft_matrixtolst.c \
	ft_lsttomatrix.c ft_matrix_replace_in.c  ft_matrix_del_elem.c \
	ft_lstadd_back.c ft_lstclear.c ft_lstlast.c ft_lstsize.c ft_lstnew.c \

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): create_dirs $(OBJ) bonus

bonus: create_dirs $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) -r libft.a
	@${RM} ${NAME}

create_dirs:
	@mkdir -p $(OBJ_DIR)

norminette:
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) inc/libft.h

re: fclean
	@make all

-include $(OBJ_DIR)/*.d

.PHONY: all bonus clean fclean norminette create_dirs re 
