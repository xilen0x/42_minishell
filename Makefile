
NAME =	minishell

# Compiler
GCC := gcc

# Compiler flags
FLAGS := -Werror -Wextra -Wall -MMD -g -fsanitize=address

# Remove
RM 	:=	rm -rf

# Makefile
MKF :=	Makefile

# Root Folders
SRC_ROOT := src/
DEP_ROOT := .dep/
OBJ_ROOT := .objs/
INC_ROOT := include/
LIB_ROOT := lib/

INC_DIRS += ${INC_ROOT}

# Lib readline
READLINE_MK_ROOT := ${LIB_ROOT}readline/Makefile
READLINE_ROOT := ${LIB_ROOT}readline/
READLINE := ${READLINE_ROOT}libreadline.a ${READLINE_ROOT}libhistory.a

# Libft
LIBFT_ROOT := ${LIB_ROOT}libft/
LIBFT_INC := $(LIBFT_ROOT)include/
LIBFT := $(LIBFT_ROOT)libft.a

INC_DIRS += ${LIBFT_INC}
LIBS += -L${LIBFT_ROOT} -lft

INC_DIRS += ${READLINE_ROOT}
LIBS += -L${READLINE_ROOT} -ltermcap

# Source Files
################################################################################

FILES =	minishell.c \
									builtins/builtins.c \
									builtins/builtin_cd.c \
									builtins/builtin_pwd.c \
									builtins/builtin_echo.c \
									builtins/builtin_env.c \
									builtins/builtin_export.c \
									builtins/builtin_exit.c \
									arr2d/add_one_arr2d.c \
									arr2d/dup_arr2d.c \
									arr2d/free_arr2d.c \
									arr2d/size_arr2d.c \
									arr2d/rm_one_arr2d.c \
									arr2d/print_arr2d.c \
									lst_tokens/lst_new_node.c \
									lst_tokens/lst_add_back.c \
									lst_tokens/lst_last.c \
									lst_tokens/lst_size.c \
									lst_tokens/lst_clear.c \
									lst_tokens/t_lst_print.c \
									lst_commands/cmd_new_node.c \
									tokenizer.c \
									utils_libft.c \
									utils0.c

SRC 	:= $(addprefix $(SRC_ROOT), $(FILES))
OBJS 	:= $(addprefix $(OBJ_ROOT), $(FILES:.c=.o))
DEPS 	:= $(addprefix $(DEP_ROOT), $(FILES:.c=.d))
INCS 	:= $(addprefix -I, $(INC_DIRS))


# Colors
################################################################################

DEF_COLOR =		\033[0;39m
#DEL_LINE =		\033[2K
#ITALIC =		\033[3m
#GRAY =			\033[0;90m
#RED =			\033[0;91m
#BROWN =		\033[38;2;184;143;29m
#YELLOW =		\033[33m
DARK_YELLOW =	\033[38;5;143m
#DARK_GRAY =	\033[38;5;234m
DARK_GREEN =	\033[1m\033[38;2;75;179;82m


# Rules
################################################################################


all:	$(READLINE_MK_ROOT)
		@echo "$(DARK_GREEN)GNU READLINE 8.2 COMPILING... $(DEF_COLOR)"
		@$(MAKE) -sC $(READLINE_ROOT)
		@$(MAKE) $(LIBFT)
		@$(MAKE) $(NAME)
		@echo "                              $(DEF_COLOR)"
		@echo "$(DARK_GREEN)▶  MINISHELL BUILD COMPLETED!$(DEF_COLOR)"
		@echo "                              $(DEF_COLOR)"
		@echo "$(DARK_GREEN)-->	Now you can run ./minishell$(DEF_COLOR)"

clean:
		@$(RM) $(OBJ_ROOT)
		@$(RM) $(DEP_ROOT)
		@$(MAKE) clean -C $(LIBFT_ROOT)

fclean:	clean
		@$(RM) $(NAME)
		@$(RM) $(LIBFT)

re:
		@$(MAKE) fclean
		@$(MAKE) all

readline:
		@$(MAKE) $(READLINE_MK_ROOT)

cleanrl:
		@$(MAKE) clean -sC $(READLINE_ROOT)

$(READLINE_MK_ROOT):
		pwd ${BLOCK}
		cd ./${READLINE_ROOT} && ./configure
		cd ${BLOCK}

$(LIBFT):
		@$(MAKE) -sC $(LIBFT_ROOT)

$(NAME): $(OBJS)
		@$(GCC) $(FLAGS) $(OBJS) $(READLINE) $(LIBS) -o $(NAME)

$(OBJ_ROOT)%.o: $(SRC_ROOT)%.c $(READLINE) $(MKF)
		@mkdir -p $(dir $@) $(dir $(subst $(OBJ_ROOT), $(DEP_ROOT), $@))
		@echo "▶ Compiling minishell file: <$(notdir $<)>"
		@$(GCC) $(FLAGS) $(INCS) -c $< -o $@
		@mv $(patsubst %.o, %.d, $@) $(dir $(subst $(OBJ_ROOT), $(DEP_ROOT), $@))

-include $(DEPS)

.PHONY:	all bonus update clean fclean re