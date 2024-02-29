NAME = minishell

# Libraries
RL_DIR		= readline/
INCFLAG		+= -I $(RL_DIR)
READLINE	:= $(RL_DIR)libreadline.a $(RL_DIR)libhistory.a
RL_FILE		= readline.tar.gz
RL_URL		= http://git.savannah.gnu.org/cgit/readline.git/snapshot/readline-bfe9c573a9e376323929c80b2b71c59727fab0cc.tar.gz

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

LIBS		= -lreadline -ltermcap
DEFS		= -DREADLINE_LIBRARY

SRCS_DIR = src/
SRC_FILES =	 main.c

OBJS_DIR	= objs/
OBJ_FILES	= $(SRC_FILES:.c=.o)
OBJS		= $(addprefix $(OBJS_DIR), $(OBJ_FILES))
DEPS		:= $(OBJS:.o=.d)

INCLUDE  = -I include/ -I libft/
CC = clang
#CFLAGS = -g -Wall -Wextra -Werror -I$(INC_DIR) -fsanitize=address
CFLAGS = -g -Wall -Wextra -Werror $(INCLUDE)

RM = rm -rf
AR = ar rc

all:		$(READLINE)	$(NAME)

subsystems:
			@make -C $(LIBFT_DIR)
$(RL_DIR):
			@curl -k $(RL_URL) > $(RL_FILE)
			@tar -xf $(RL_FILE) && mv readline-* readline
			@rm -rf $(RL_FILE)

$(READLINE): $(RL_DIR)
			@if [ ! -f $(RL_DIR)config.status ] ; then \
				printf "\t$(YELLOW)Configuring READLINE...$(DEFAULT)" && \
				cd ./$(RL_DIR) && \
				./configure &> /dev/null && \
				echo ✅; \
			fi
			@printf "\t$(YELLOW)Making READLINE...$(DEFAULT)"
			@cd ./$(RL_DIR) && make &> /dev/null
			@echo ✅

$(NAME):	subsystems $(OBJS_DIR) $(OBJS) $(READLINE)
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
			@$(RM) $(NAME) $(READLINE)

re:			fclean all
-include $(DEPS)			

.PHONY: all clean fclean re subsystems
