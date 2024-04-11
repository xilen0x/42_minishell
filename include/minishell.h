#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef READLINE_LIBRARY
#  define READLINE_LIBRARY
# endif

# include "../lib/libft/libft.h"
# include <readline.h>
# include <history.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

/*------------------------Defines-----------------------*/

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define TRUE 1
# define FALSE 0

/*--------------------Error messages-------------------*/

# define PRINT_SYNTAX_ERR_1 "syntax error near unexpected token `|'\n"
# define PRINT_SYNTAX_ERR_2 "syntax error near unexpected token `newline'\n"
# define PRINT_SYNTAX_ERR_3 "syntax error\n"

//typedef struct s_builtings t_built;

//---joan---
typedef enum e_type
{
	NULL_TYPE = 0,//para saber que se ha inicializado ya 
	WORD,
	PIPE,
	GREATER,
	SMALLER,
	DOUBLE_GREATER,
	DOUBLE_SMALLER
}	t_type;

typedef struct s_tok
{
	char			*str;//contendrá string solo si es WORD, sino será NULLL.
	t_type			type;
	struct s_tok	*next;
}					t_tok;//contiene los datos de cada token

typedef enum e_redir_type
{
	NULL_REDIR = 0,//Creo que no es necesario
	REDIR_OUTPUT = 3,//>
	REDIR_INPUT = 4,//<
	REDIR_OUTPUT_APPEND = 5,//>> 
	HEREDOC_INPUT = 6//<<
}	t_redir_type;

typedef struct s_redir
{
	char			*filename;
	t_redir_type	redir_type;
	struct s_redir	*next;
}					t_redir;//contiene los datos de cada redirección


typedef struct s_cmd
{
	char			**command_and_arg;
	t_redir			*redir;
	struct s_cmd	*next;
}					t_cmd;//contiene los datos de cada pipe

//-----carlos------------------

typedef struct s_env
{
	char	**env_cpy;
	char	**export_cpy;
	char	**paths;
	char	*cmd_fullpath;
	char	*key;
	char	*val;
	char	*type;
	char	*str;
	t_cmd	*to_cmd;
}	t_env;

typedef struct s_shell
{
	int				exit_status;
	t_cmd			*link_cmd;
	t_env			*link_env;
	t_redir			*link_redir;
	t_redir_type	*link_redir_t;
	t_tok			*link_tok;
	// char	**pipes;
	// int		pipex;
	//t_pipe	*p;
	// char	**args;
}	t_shell;


/*---------------------------minishell -------------------------*/
int		bg_color(void);
void	init_msg(void);
void	tokenizer(t_tok **tok, char *line);
void	parser(t_cmd **cmd, t_tok *tok);
void	handle_error(char *str, t_tok **tok);
/*---------------------------array 2d -------------------------*/
size_t	size_arr2d(char **arr2d);
char	**dup_arr2d(char **arr2d);
char	**add_one_arr2d(char **arr2d, char *new);
char	**rm_one_arr2d(char **arr2d, int index);
void	free_arr2d(char **arr2d);
void	print_arr2d(char **arr2d);//ELIMINAR ANTES DE ENTREGA

/*---------------------------t_tok -------------------------*/
t_tok	*tok_new_node(char *str, int type);
t_tok	*tok_last(t_tok *lst);
void	tok_add_back(t_tok **lst, t_tok *new);
void	tok_free(t_tok **lst);
int		tok_size(t_tok *lst);//ELIMINAR ANTES DE ENTREGA
void	tok_print(t_tok *lst);//ELIMINAR ANTES DE ENTREGA

/*---------------------------t_cmd -------------------------*/
t_cmd	*cmd_new_node(void);
t_cmd	*cmd_last(t_cmd *lst);
void	cmd_add_back(t_cmd **lst, t_cmd *new);
void	cmd_free(t_cmd **lst);
int		cmd_size(t_cmd *lst);//ELIMINAR ANTES DE ENTREGA
void	cmd_print(t_cmd *list);//ELIMINAR ANTES DE ENTREGA

/*---------------------------t_redir -------------------------*/
t_redir	*redir_new_node(char *str, int redir_type);
t_redir	*redir_last(t_redir *lst);
void	redir_add_back(t_redir **lst, t_redir *new);
void	redir_free(t_redir **lst);
int		redir_size(t_redir *lst);//ELIMINAR ANTES DE ENTREGA
void	redir_print(t_redir *lst);//ELIMINAR ANTES DE ENTREGA

/*---------------------------utils_parser -------------------------*/
int		is_operator(t_tok *node);
size_t	command_and_arg_size(t_tok *tok);

/*---------------------------utils_libft -------------------------*/
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
size_t	str_l_cpy(char *dst, const char *src, size_t dstsize);
int		ca_strcmp(char *s1, char *s2);

/*---------------------------signals.c -------------------------*/
void	set_signals(void);

/*---------------------------executor.c -------------------------*/
//int		init_momentaneo(char *av[], t_env *data);
void	ft_get_paths(char **envp, t_env *data);
//int		search_cmds(t_env *data);
int		executor(t_env *data, t_cmd cmd);
int		search_command_path(char *cmd, t_env *env);

/*---------------------------utils0.c -------------------------*/
int		ft_msgs(int n);
int		exit_status(void);
/*---------------------------utils1.c -------------------------*/
int		ca_strchr(const char *s, int c);

/*--------------------------- builtins -------------------------*/
int		builtins(t_cmd *cmd, int ac, char *av[], t_env *env);
int		builtin_exit(t_cmd *cmd, int ac, char *av[]);
int		builtin_pwd(void);
int		builtin_cd(t_cmd *cmd, t_env env);
int		builtin_env(t_cmd *cmd, t_env env);
int		builtin_echo(t_cmd *cmd);
int		builtin_export(t_cmd *cmd, t_env *env);
//int	builtin_unset(t_cmd *cmd, t_env env, int ac);

/*--------------------------- builtin export -------------------------*/
unsigned int	check_export(char *arg);

#endif