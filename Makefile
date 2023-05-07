SRCS			=	philosophers.c utils.c

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
# CFLAGS			= -Wall -Wextra -Werror
CFLAGS			=

NAME			= philo


all:			$(NAME) Makefile philosophers.h

$(NAME):		$(OBJS)
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re