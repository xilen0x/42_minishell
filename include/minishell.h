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

# define PRINT_MALLOC_ERR_0 "Error: malloc failed\n"
# define PRINT_SYNTAX_ERR_1 "syntax error near unexpected token `|'\n"
# define PRINT_SYNTAX_ERR_2 "syntax error near unexpected token `newline'\n"
# define PRINT_SYNTAX_ERR_3 "syntax error\n"

typedef struct s_builtings t_built;

/*===========joan===========*/
//Environment Struct
typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env	*next;
}					t_env;

typedef enum e_type
{
	NULL_TYPE = 0,//para saber que se ha inicializado ya 
	WORD,
	PIPE,
	GREATER,
	SMALLER,
	DOUBLE_GREATER,
	DOUBLE_SMALLER
} 	t_type;

/*------contiene la str y el tipo de cada token-----*/
typedef struct s_tok
{
	char			*str;//contendrá string solo si es WORD, sino será NULLL.
	t_type			type;
	struct s_tok	*next;
}					t_tok;

typedef enum e_redir_type
{
	NULL_REDIR = 0,//Creo que no es necesario
	REDIR_OUTPUT = 3,//>
	REDIR_INPUT = 4,//<
	REDIR_OUTPUT_APPEND = 5,//>> 
	HEREDOC_INPUT = 6//<<
} 	t_redir_type;

/*----contiene los datos de cada redirección------*/
typedef struct s_redir
{
	char			*filename;
	t_redir_type	redir_type;
	struct s_redir	*next;
}					t_redir;

/*------contiene los datos de cada pipe de la linea de comando-----*/
typedef struct s_cmd
{
	char			**command_and_arg;
	t_redir			*redir;
	struct s_cmd	*next;
	//char			*pipe_test;//lo borarre luego(carlos)
}					t_cmd;

/*---si las comillas simples o dobles estan abiertas (1) o cerradas (0)----*/
typedef struct s_qts
{
	int	s_quote;
	int	d_quote;
}	t_qts;

//-----carlos------------------
/*COMENTO PARA QUE NO DE CONFLICTO CON MI t_env envlist
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
	t_built	*env_to_build;
	t_built	*to_built;
	t_cmd	*to_cmd;
}	t_env;
*/
typedef struct s_builtings
{
	//char	*echo_n;
	// char	*cd;
	// char	*pwd;
	// char	*export;
	// char	*unset;
	//char	*env;
	// char	*exit;
	char	*cmd1;
	char	*path;//borrar luego(posiblemente)
	//char	*the_string;
	t_env	*to_env;
}	t_built;

/*typedef struct s_shell
{
	t_tok	**tok;
	char	**pipes;
	int		pipex;
	int		exit;
	//t_pipe	*p;
	char	**args;
	char	*cmd;
}	t_shell;*/

//int		builtings(t_built	*cmd, char **env, int ac);
//char	**env_cpy(char *e[]);
//char	**dup_array_2d(char *envp[]);
/*
int		init (t_built *cmd, int ac, char *av[]);
int		builtins(t_built *cmd, int ac, char *av[], t_env env);
int		builtin_cd(t_built *cmd, int ac);
int		builtin_pwd(void);
int		builtin_echo(t_built *cmd, int ac);
int		builtin_env(t_env env);
int		builtin_export(t_built *cmd, t_env env, int ac);
int		builtin_exit(t_built *cmd, int ac, char *av[]);
int		builtin_unset(t_built *cmd, t_env env, int ac);
*/
/*----------------minishell----------------*/
void 	tokenizer(t_tok **tok, char *line, unsigned int *exit_status);
void    parser(t_cmd **cmd, t_tok *tok, unsigned int *exit_status);
void	handle_error(char *str, t_tok **tok);
int 	bg_color();
void	init_msg(void);

/*---------------------array 2d----------------*/
size_t  size_arr2d(char **arr2d);
char	**dup_arr2d(char **arr2d);
char    **add_one_arr2d(char **arr2d, char *new);
char    **rm_one_arr2d(char **arr2d, int index);
void    free_arr2d(char **arr2d);//OJO CARLOS: ESTA FUNCION REEMPLAZA A ft_free_split, solo he cambiado el nombre

/*-----------------utils t_tok------------------*/
t_tok	*tok_new_node(char *str, int type);
t_tok	*tok_last(t_tok *lst);
void	tok_add_back(t_tok **lst, t_tok *new);
void	tok_free(t_tok **lst);
int		tok_size(t_tok *lst);//ELIMINAR ANTES DE ENTREGA

/*-------------------utils t_cmd----------------*/
t_cmd	*cmd_new_node(void);
t_cmd	*cmd_last(t_cmd *lst);
void	cmd_add_back(t_cmd **lst,t_cmd *new);
void	cmd_free(t_cmd **lst);
int		cmd_size(t_cmd *lst);//ELIMINAR ANTES DE ENTREGA

/*-----------------utils t_redir-----------------*/
t_redir	*redir_new_node(char *str, int redir_type);
t_redir	*redir_last(t_redir *lst);
void	redir_add_back(t_redir **lst,t_redir *new);
void	redir_free(t_redir **lst);
int		redir_size(t_redir *lst);//ELIMINAR ANTES DE ENTREGA

/*--------------utils_parser---------------*/
int		is_operator(t_tok *node);
size_t 	command_and_arg_size(t_tok *tok);
//size_t tok_operator_cnt(t_tok *tokens); DE MOMENTO NO LO USAMOS
//size_t tok_word_cnt(t_lst *tokens); DE MOMENTO NO LO USAMOS
void	handle_error(char *str, t_tok **tok);

/*---------------expander & quote removal--------------*/
void	should_expand(t_cmd **cmd, t_env *envlist, unsigned int exit_status);
char	*expand_and_quote_remove(char *str, t_env *envlist, unsigned int exit_status);
int		new_tok_len(char *str, t_env *envlist, unsigned int exit_status);
char	*new_tok_builder(char *str, t_env *envlist, char *result);
char 	*get_env_key(char *str);
char 	*get_env_val(char *env_key, t_env *envlist);

/*---------------utils-----------------*/
void	*p_malloc(size_t size);
//void	malloc_s_pointer_protect(void *name);
//void	malloc_d_pointer_protect(char **name);

/*-------------------------signals.c--------------------------*/
void	set_signals(void);

/*--------------------------utils t_env-------------------*/
t_env	*lstlast(t_env *lst);
void	lstadd_back(t_env **lst, t_env *new);
t_env	*lstnew(char *key, char *value);
void	init_envlist(char **envp, t_env **envlist);
void	cleaner(t_env **lst);

/*-------------------------executor.c--------------------------*/
//int		init_momentaneo(char *av[], t_env *data);
void	ft_get_paths(char **envp, t_env *data);
int		search_cmds(t_env *data);
int		executor(t_env *data);

/*-------------------------utils0.c--------------------------*/
int		ft_errors(int n);

/*-------------------------int	builtins.c-------------------*/
int		is_builtin(t_built *cmd, int ac, char *av[], t_env env);

/*-------------------exit_status----------------*/
unsigned int	get_exit_status_len(unsigned int exit_status);
char	*get_exit_status_val(unsigned int exit_status);

/*--------------------prints-----------------*/
void	print_arr2d(char **arr2d);//ELIMINAR ANTES DE ENTREGA
void	print_tok(t_tok *lst);//ELIMINAR ANTES DE ENTREGA
void	print_cmd(t_cmd *list);//ELIMINAR ANTES DE ENTREGA
void	print_redir(t_redir *lst);//ELIMINAR ANTES DE ENTREGA
void	ft_print_keys(t_env *env_struct);//ELIMINAR ANTES DE ENTREGA
void	ft_print_values(t_env *env_struct);//ELIMINAR ANTES DE ENTREGA
void	ft_printstack(t_env *env_struct);//ELIMINAR ANTES DE ENTREGA

#endif