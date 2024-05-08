
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
									utils/p_malloc.c \
									builtins/builtins.c \
									builtins/builtin_env.c \
									builtins/builtin_cd.c \
									builtins/builtin_echo.c \
									builtins/builtin_export.c \
									builtins/builtin_unset.c \
									builtins/builtin_exit.c \
									builtins/builtin_pwd.c \
									executor/executor.c \
									arr2d/add_one_arr2d.c \
									arr2d/dup_arr2d.c \
									arr2d/free_arr2d.c \
									arr2d/size_arr2d.c \
									arr2d/rm_one_arr2d.c \
									tokens/tok_new_node.c \
									tokens/tok_add_back.c \
									tokens/tok_last.c \
									tokens/tok_size.c \
									tokens/tok_free.c \
									commands/cmd_new_node.c \
									commands/cmd_add_back.c \
									commands/cmd_free.c \
									commands/cmd_last.c \
									commands/cmd_size.c \
									utils/utils_env.c \
									utils/utils0.c \
									utils/utils1.c \
									utils/utils2.c \
									utils/utils3.c \
									tokenizer/tokenizer.c \
									utils_parser/is_operator.c \
									utils_parser/command_and_arg_size.c \
									utils_parser/handle_error.c \
									redirs/redir_add_back.c \
									redirs/redir_free.c \
									redirs/redir_last.c \
									redirs/redir_new_node.c \
									redirs/redir_size.c \
									parser/parser.c \
									expander/should_expand.c\
									expander/expand_and_quote_remove.c \
									expander/get_env_val.c \
									expander/new_tok_len.c \
									expander/new_tok_builder.c \
									expander/get_env_key.c \
									signals.c \
									exit_status/get_exit_status_val.c \
									exit_status/get_exit_status_len.c \
									prints/print_tok.c \
									prints/print_cmd.c \
									prints/print_redir.c \
									prints/print_envlist.c \
									prints/print_arr2d.c \
									prints/print_cmd_para_executor.c

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
#DARK_GRAY 	=	\033[38;5;234m
DARK_GREEN 	=	\033[1m\033[38;2;75;179;82m
GREEN 		=	\033[0;32m

# Rules
################################################################################

all:	$(READLINE_MK_ROOT)
		@echo "$(DARK_GREEN)GNU READLINE 8.2 COMPILING... $(DEF_COLOR)"
		@$(MAKE) -sC $(READLINE_ROOT)
		@echo "$(DARK_GREEN)LIBFT COMPILING... $(DEF_COLOR)"
		@$(MAKE) $(LIBFT)
		@echo "$(DARK_GREEN)MINISHELL COMPILING... $(DEF_COLOR)"
		@$(MAKE) $(NAME)
		@echo "                              $(DEF_COLOR)"
		@echo "$(GREEN)▶  MINISHELL BUILD COMPLETED!$(DEF_COLOR)"
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