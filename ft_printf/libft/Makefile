CC		= gcc
SRCS	= ft_abs.c ft_alnum.c ft_atoi.c ft_bzero.c ft_calloc.c \
		  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c \
		  ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c ft_max.c \
		  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		  ft_memrcpy.c ft_memset.c ft_min.c ft_putchar_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strcmp.c \
		  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		  ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_nbrlen.c ft_unbrlen.c
OBJS	= $(SRCS:.c=.o)
BONUS	= ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		  ft_lstclear_bonus.c ft_lstdelone_bonus.c \
		  ft_lstiter_bonus.c ft_lstlast_bonus.c \
		  ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c
BONOBJS	= $(BONUS:.c=.o)
NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rcs
RM		= rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -I ./ -o $@

$(NAME): $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS) $(BONOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(OBJS) $(BONOBJS)
	$(RM) $(NAME)
	$(LIBC) $(NAME) $(OBJS) $(BONOBJS)

.PHONY: all .c.o clean fclean bonus re
