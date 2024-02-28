CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src
OBJ_DIR		= objects
INC_DIR		= includes
LIB_DIR		= libft
LIBFT		= libft.a

NAME		= pipex
CAP_NAME	= $(shell echo $(NAME) | awk '{print toupper(substr($$0, 1, 1)) substr($$0, 2)}')
SRC_NAME	= pipex.c path.c args.c error.c
OBJ_NAME	= $(notdir $(SRC_NAME:.c=.o))
SRCS		= $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJS		= $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
BONUS_OBJS	= $(BONUS:.c=.o)
RM			= rm -f
RM_DIR		= rm -rf

# COLORS #
C_GREEN		= \033[0;32m
C_RED		= \033[0;31m
C_BLUE		= \033[0;34m
C_DEF		= \033[0m

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(INC_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -I $(INC_DIR) -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(OBJS)
	@echo "$(C_BLUE)Builing $(NAME)...$(C_DEF)"
	@make all -s -C ./$(LIB_DIR)/
	@$(CC) $(CFLAGS) $(OBJS) -L./$(LIB_DIR) ./$(LIB_DIR)/$(LIBFT) -o $(NAME)
	@echo "$(C_GREEN)$(CAP_NAME) built and ready to go!$(C_DEF)"

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@make fclean -s -C $(LIB_DIR)
	@echo "$(C_RED)Cleaned objects folder!$(C_DEF)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(C_RED)Cleaned $(NAME) program!$(C_DEF)"

re: fclean all

bonus: $(BONOBJS)
	make all -C $(LIB_DIR)/
	cp $(LIB_DIR)/$(LIBFT) $(LIBFT)
	gcc $(CFLAGS) -L. -l:$(LIBFT) $(BONUS_OBJS) -o $(NAME)

test: bonus
	@$(CC) -o test.o -I $(INCS) -c test.c
	@$(CC) -o test test.o -L. -l:$(LIBFT)
	@./test
	@echo "\n"
	@$(RM) test test.o

.PHONY: all bonus clean fclean re .c.o
