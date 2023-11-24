NAME =		libft.a

SRCS = 		 ft_strlen.c ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c ft_memset.c

HEADERS =	libft.h

OBJS =		$(SRCS:.c=.o)
BONUS_OBJS =	$(BONUS:.c=.o)

CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
				@ar rc $(NAME) $(OBJS)

%.o:		%.c
				@$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADERS)

bonus:		$(OBJS) $(BONUS_OBJS)
				@ar rc $(NAME) $(OBJS) $(BONUS_OBJS)

clean:
				@rm -f $(OBJS)

fclean:		clean
				@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
