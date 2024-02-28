NAME = minishell

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

SRCS_DIR = src/
SRC_FILES =	 main.c

OBJS_DIR =	objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))
DEPS        := $(OBJS:.o=.d)

INCLUDE  = -I include/ -I libft/
CC = clang
#CFLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR) -fsanitize=address
CFLAGS = -g -Wall -Wextra -Werror $(INCLUDE)

RM = rm -rf
AR = ar rc


all: 		$(NAME)

subsystems:
			@make -C $(LIBFT_DIR)

$(NAME):	subsystems $(OBJS_DIR) $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -L libft/ -lft -o $@

$(OBJS_DIR):
			@mkdir $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean: 		
			make -C $(LIBFT_DIR) clean
			@$(RM) $(OBJS) $(DEPS)


fclean: 	clean
			make -C $(LIBFT_DIR) fclean
			@$(RM) $(NAME)

re:			fclean all
-include $(DEPS)			

.PHONY: all clean fclean re subsystems
