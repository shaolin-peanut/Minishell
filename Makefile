NAME		=	minishell

HEADER		=	./include/

CC			=	gcc

CFLAGS		=	-Werror -Wall -Wextra -g -I $(HEADER)

SRCS		=	src/main.c

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all
