CC		= gcc
SRCS	= $(filter-out %_bonus.c, $(wildcard ft_*.c))
OBJS	= $(SRCS:.c=.o)
BONUS	= $(wildcard ft_*_bonus.c)
BONOBJS	= $(BONUS:.c=.o)
NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rc
LIBR	= ranlib
RM		= rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -I ./ -o $@

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(BONOBJS)
	$(RM) $(NAME)
	$(LIBC) $(NAME) $(OBJS) $(BONOBJS)
	$(LIBR) $(NAME)
