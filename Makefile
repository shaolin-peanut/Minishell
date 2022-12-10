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

NAME = minishell

HEADERS_DIRECTORY		= include/
HEADERS_LIST = \
	execution.h \
    minishell.h \
    parser.h \
    token.h \

HEADERS					= $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

# === File && Header === #
SOURCES_DIRECTORY		= src/

BUILT_IN_DIR			= built_in/
ENV_DIR					= env/
EXEC_DIR				= execution/
PARSER_DIR				= parser/
REDIR_DIR				= redirection/
UTILS_DIR				= utils/

BUILT_IN_LIST			= \
	built_in.c \
    built_in_exe.c \
    exit.c \
    error.c \
    export.c

ENV_LIST				= \
	dollar.c \
    env.c \
    prompt.c \
    read_line.c \
    signal.c

EXEC_LIST				= \
	bin_exe.c \
    execution.c \
    get.c \
    get2.c \
    is_redirection.c \
    is_token.c \
    status.c \
    variable.c

PARSER_LIST			= \
	basic_char_checks.c \
    cmd_path_check.c \
    compound_char_checks.c \
    create_tokens.c \
    heredoc.c \
    operators_checks.c \
    parser.c \
    processing.c \
    prompt.c \
    quotes.c \
    testing.c \
    token_init.c \
    variables.c \
    word_processing.c

REDIR_LIST				= \
	close.c \
    manage_redirection.c \
    processing_redirection.c

UTILS_LIST			= \
	build_argv.c \
    error.c \
    init_structs.c \
    list_utils.c \
    memory.c \
    memory2.c \
    parser_utils.c \
    sort.c

SOURCES_LIST					= \
	main.c \
	$(addprefix $(BUILT_IN_DIR), $(BUILT_IN_LIST)) \
	$(addprefix $(ENV_DIR), $(ENV_LIST)) \
	$(addprefix $(EXEC_DIR), $(EXEC_LIST)) \
	$(addprefix $(PARSER_DIR), $(PARSER_LIST)) \
	$(addprefix $(REDIR_DIR), $(REDIR_LIST)) \
	$(addprefix $(UTILS_DIR), $(UTILS_LIST))

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# ==== Objects ==== #
OBJECTS_DIRECTORY = objs/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# ==== Template ==== #
TEMPLATE = include/header.txt

# ==== Execute ==== #
EXE = @./$(NAME)
LIBFT = libft/libft.a
# ==== Debug && Leak ==== #
SANITIZE 		= -fsanitize=address -fno-omit-frame-pointer
#LEAKS 			= -fsanitize=leak
DEBUGGER		= lldb

# ==== Remove ==== #
RM_FILE = /bin/rm -rf

# ==== Objet && compiling ==== #
#OBJS			= $(SRCS:.c=.o)
CC				?= gcc
FLAGS			= -g3
FLAGS 			+= -Wall -Werror -Wextra
FLAGS 			+= $(SANITIZE) $(LEAKS)
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

INCLUDES = -I$(HEADERS_DIRECTORY)

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@echo "\n\t$(NAME):\t$(GREEN)object files were created$(RESET)"
	@echo "> Compiling libft"
	@$(MAKE) -C libft
	@echo "> Creating minishell"
	@$(CC) $(OBJECTS) $(FLAGS) $(READLINE) $(LIBFT) -o $(NAME)
	@cat "$(TEMPLATE)"

$(OBJECTS_DIRECTORY):
	@echo "> Compiling $(NAME) files"
	@echo "\t$(NAME):\t$(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"
	@mkdir -p $(OBJECTS_DIRECTORY)
	@mkdir -p $(OBJECTS_DIRECTORY)/$(BUILT_IN_DIR)
	@mkdir -p $(OBJECTS_DIRECTORY)/$(ENV_DIR)
	@mkdir -p $(OBJECTS_DIRECTORY)/$(EXEC_DIR)
	@mkdir -p $(OBJECTS_DIRECTORY)/$(PARSER_DIR)
	@mkdir -p $(OBJECTS_DIRECTORY)/$(REDIR_DIR)
	@mkdir -p $(OBJECTS_DIRECTORY)/$(UTILS_DIR)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@echo "> Removing libft object files"
	@$(MAKE) clean -C libft
	@echo "> Removing minishell object files"
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "\t$(NAME):\t$(RED)object files were deleted$(RESET)"

fclean: clean
	@echo "\t$(NAME):\t$(RED)$(NAME) was deleted$(RESET)"
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)

re : fclean all

.PHONY			: all clean fclean re
