CC		= gcc
SRCS	= ft_printf.c ft_printf_utils.c \
		  ft_printf_utils2.c
OBJS	= $(SRCS:.c=.o)
BONUS	= ft_printf_bonus.c ft_printf_utils_bonus.c \
		  ft_printf_utils2_bonus.c
BONOBJS	= $(BONUS:.c=.o)
NAME	= libftprintf.a
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rcs
RM		= rm -f

INCS 	= ./
LIB_DIR	= ./libft
LIBFT	= libft.a

.c.o:
	$(CC) $(CFLAGS) -c $< -I $(INCS) -o $@

$(NAME): $(OBJS)
	make bonus -C $(LIB_DIR)/
	mv $(LIB_DIR)/$(LIBFT) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONOBJS)
	make fclean -C $(LIB_DIR)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

bonus: $(BONOBJS)
	make bonus -C $(LIB_DIR)/
	mv $(LIB_DIR)/$(LIBFT) $(NAME) 
	$(LIBC) $(NAME) $(BONOBJS)

.PHONY: all bonus clean fclean re .c.o
