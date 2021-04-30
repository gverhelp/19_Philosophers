SRCS =		srcs/main.c \
			srcs/parsing.c \
			srcs/routine.c \
			srcs/time.c \
			srcs/ft_init.c \
			srcs/utils.c \
			srcs/libft.c \

OBJS = 		$(SRCS:%.c=%.o)

NAME = 		philo_one

CFLAGS =	-g -Wextra -Wall -Werror -pthread

all:		$(NAME)

$(NAME):	$(OBJS)
			gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean :
			rm -rf $(OBJS)

fclean : 	clean
			rm -rf $(NAME)

re :		fclean all