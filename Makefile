
NAME = minishell

SRCS_DIR				= src/
INCS_DIR				= include/

# === File && Header === #
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
						$(SRCS_DIR)/utils/sort.c \
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
						$(SRCS_DIR)/execution/variable.c \
						$(SRCS_DIR)/execution/get.c \
						$(SRCS_DIR)/processing/bin_processing.c \
						$(SRCS_DIR)/processing/processing_built.c \
						$(SRCS_DIR)/processing/processing_cmd.c \
						$(SRCS_DIR)/processing/processing_redirection.c \
						$(SRCS_DIR)/processing/variable_value.c \
						$(SRCS_DIR)/is/is_redirection.c \
						$(SRCS_DIR)/is/is_token.c \
						$(SRCS_DIR)/env/signal.c \
						$(SRCS_DIR)/env/read_line.c \
						$(SRCS_DIR)/env/prompt.c

# ==== Template ==== #
TEMPLATE = include/header.txt

# ==== Execute ==== #
EXE = @./$(NAME)
LIBFT = libft/libft.a
# ==== Debug && Leak ==== #
#SANITIZE 		= -fsanitize=address
#LEAKS 			= -fsanitize=leak
DEBUGGER		= lldb

# ==== Remove ==== #
RM_FILE = /bin/rm -rf

# ==== Objet && compiling ==== #
OBJS			= $(SRCS:.c=.o)
CC				?= gcc
FLAGS			= -g3
FLAGS 			+= -Wall -Werror -Wextra
FLAGS 			+= $(SANITIZE)
READLINE		= -lreadline
MAKE			= make -s

# Cross fLags
UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	NPROC := $(shell nproc)
	
else
	NPROC := $(shell sysctl -n hw.ncpu)
	FLAGS += -I$(HOME)/.brew/opt/readline/include
    READLINE += -L$(HOME)/.brew/opt/readline/lib
	
endif

# === Convert all .c to .o with flags and header === # 
%.o : %.c
			@$(CC) $(FLAGS) -I $(INCS_DIR) -c $< -o $@
	
$(NAME) : 	    $(OBJS)
				@echo "==== Create all .o ===="
				@echo "==== Compiling all .c ===="
				@echo "==== Compiling libft ===="
				@$(MAKE) -C libft
				@echo "==== Compiling Minishell ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"		

all : 	 $(NAME)

clean :
				@echo "==== Remove all Libft .o ===="
				@$(MAKE) clean -C libft
				@echo "==== Remove all Minishell .o ===="
				@$(RM_FILE) $(OBJS)

fclean : clean
				@$(MAKE) fclean -C libft
				@$(RM_FILE) $(NAME)

debug : 		$(OBJS)
				@echo "==== Mode Debug Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(SANITIZE) $(LIBFT) -o $(NAME)
				$(DEBUGGER) $(NAME)
				@cat "$(TEMPLATE)"
				
sanitize :		$(OBJS)
				@echo "==== Mode Sanitize Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(SANITIZE) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"

leak :			$(OBJS)
				@echo "==== Mode Leak Activate ===="
				@$(CC) $(OBJS) $(FLAGS) $(READLINE) $(LEAKS) $(LIBFT) -o $(NAME)
				@cat "$(TEMPLATE)"


re : fclean all
.PHONY			: all clean fclean re leak sanitize