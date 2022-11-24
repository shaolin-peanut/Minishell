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
						$(SRCS_DIR)/utils/init_structs.c \
						$(SRCS_DIR)/utils/error.c \
						$(SRCS_DIR)/utils/memory.c \
						$(SRCS_DIR)/utils/list_utils.c \
						$(SRCS_DIR)/utils/build_argv.c \
						$(SRCS_DIR)/utils/parser_utils.c \
						\
						$(SRCS_DIR)/built_in/built_in.c \
						$(SRCS_DIR)/built_in/built_in_exe.c \
						$(SRCS_DIR)/built_in/export.c \
						$(SRCS_DIR)/redirection/close.c \
						$(SRCS_DIR)/redirection/heredoc.c \
						$(SRCS_DIR)/redirection/manage_redirection.c \
						$(SRCS_DIR)/redirection/redirect.c \
						$(SRCS_DIR)/execution/access.c \
						$(SRCS_DIR)/execution/bin_exe.c \
						$(SRCS_DIR)/execution/execution.c \
						$(SRCS_DIR)/execution/status.c \
						$(SRCS_DIR)/execution/get.c \
						$(SRCS_DIR)/processing/bin_processing.c \
						$(SRCS_DIR)/processing/processing_built.c \
						$(SRCS_DIR)/processing/processing_cmd.c \
						$(SRCS_DIR)/processing/processing_redirection.c \
						$(SRCS_DIR)/processing/variable_value.c \
						$(SRCS_DIR)/is/is_redirection.c \
						$(SRCS_DIR)/is/is_token.c


					
OBJS					= $(SRCS:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I $(INCS_DIR) -o $@ -c $?

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -lreadline -g -o $(NAME) $(OBJS) $(LIBFT_FLAGS) -I $(INCS_DIR)

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
