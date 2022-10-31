NAME					= minishell

CC						= gcc
CFLAGS					= -Wall -Werror -Wextra
AR						= ar rcs
RM						= rm -rf

LIBFT_DIR				= ./libft/
LIBFT_FLAGS				= -L ./$(LIBFT_DIR) -lft
LIBFT_FILE				= $(LIBFT_DIR)libft.a

INCS_DIR				= ./include/
SRCS_DIR				= ./src/

INCS					= -I include

SRCS					= $(SRCS_DIR)main.c \
						  $(SRCS_DIR)/parser/parser.c \
						$(SRCS_DIR)/parser/prompt.c \
						$(SRCS_DIR)/parser/basic_char_checks.c \
						$(SRCS_DIR)/parser/operators_checks.c \
						$(SRCS_DIR)/parser/compound_char_checks.c \
						$(SRCS_DIR)/parser/cmd_path_check.c \
						$(SRCS_DIR)/parser/word_processing.c \
						$(SRCS_DIR)/parser/processing.c \
						$(SRCS_DIR)/parser/variables.c \
						$(SRCS_DIR)/parser/quotes.c \
						$(SRCS_DIR)/parser/heredoc.c \
						$(SRCS_DIR)/parser/create_tokens.c \
						$(SRCS_DIR)/parser/token_init.c \
						$(SRCS_DIR)/parser/testing.c \
						$(SRCS_DIR)/executor/executor.c \
						$(SRCS_DIR)/utils/matrix.c \
						$(SRCS_DIR)/utils/init_structs.c \
						$(SRCS_DIR)/utils/error.c \
						$(SRCS_DIR)/utils/memory.c \
						$(SRCS_DIR)/utils/list_utils.c \
						$(SRCS_DIR)/utils/build_argv.c

					
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -lreadline -fsanitize=address -o $(NAME) $(OBJS) $(LIBFT_FLAGS) -I $(INCS_DIR)

all : $(NAME)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS) minishell.dSYM

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) minishell.dSYM

re : fclean all

norm :
	norminette $(SRCS) $(INCS_DIR)*.h

PHONY	: all clean fclean re
