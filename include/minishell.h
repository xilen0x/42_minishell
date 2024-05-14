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
# include <limits.h>

/*-----------------Defines-------------*/

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define TRUE 1
# define FALSE 0

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[1;34m"
# define END "\033[0m"
# define CYAN "\033[1;36m"
# define BLACK "\033[40m"
# define WHITE "\033[1;37m"
# define CLEAN_SCREEN "\033[2J"

/*--------------Signals-------------------*/
# define CTRL_C SIGINT
# define CTRL_SLASH SIGQUIT

/*--------------------Error messages-------------------*/
# define PRINT_MALLOC_ERR_0 "Error: malloc failed\n"
# define PRINT_SYNTAX_ERR_1 "syntax error near unexpected token `|'\n"
# define PRINT_SYNTAX_ERR_2 "syntax error near unexpected token `newline'\n"
# define PRINT_SYNTAX_ERR_3 "syntax error\n"

/*-----------global variable------------*/
int	get_signal;//recoge todos los exit_status

/*--------------------------- Pipe ---------------------------*/
# define READ 0
# define WRITE 1

//Environment list struct
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
	SMALLER,
	DOUBLE_SMALLER,
	GREATER,
	DOUBLE_GREATER
}	t_type;

/*------contiene la str y el tipo de cada token-----*/
typedef struct s_tok
{
	char			*str;//contendrá string solo si es WORD, sino será NULLL.
	t_type			type;
	struct s_tok	*next;
}					t_tok;

typedef enum e_redir_type
{
	NULL_REDIR = 0,
	REDIR_INPUT = 1,//<
	HEREDOC_INPUT = 2,//<<
	REDIR_OUTPUT = 3,//>
	REDIR_OUTPUT_APPEND = 4,//>> 
}	t_redir_type;

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
	char			**commands;
	t_redir			*redir;
	struct s_cmd	*next;
}					t_cmd;

/*---si las comillas simples o dobles estan abiertas (1) o cerradas (0)----*/
typedef struct s_qts
{
	int	s_quote;
	int	d_quote;
}	t_qts;

typedef struct s_exe
{
	char			**paths;
//	int				index;
	char			*cmd_fullpath;
	char			**new_array;
	pid_t			*pid;
	int				num_cmds;
	int				fd_input;
	int				fd_output;
	int				fd[2];
	int				dup_stdin;
	int				dup_stdout;
//	char			*path;
//	int				exit_stat;
}	t_exe;

/*---------------------------minishell -------------------------*/
int		bg_color(void);
void	init_msg(void);
void	set_signals(void);
void	minishell(char	*line, t_tok	*tok, t_env	*envlist, t_cmd	*cmd);
void	tokenizer(t_tok **tok, char *line);
void	parser(t_cmd **cmd, t_tok *tok);
void	init_exe(t_exe *exe, t_cmd *cmd);	
void	handle_error(char *str, t_tok **tok);
void	cleaner_envlist(t_env **lst);

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

/*---------------------------t_cmd -------------------------*/
t_cmd	*cmd_new_node(void);
t_cmd	*cmd_last(t_cmd *lst);
void	cmd_add_back(t_cmd **lst, t_cmd *new);
void	cmd_free(t_cmd **lst);
int		cmd_size(t_cmd *lst);//ELIMINAR ANTES DE ENTREGA

/*---------------------------t_redir -------------------------*/
t_redir	*redir_new_node(char *str, int redir_type);
t_redir	*redir_last(t_redir *lst);
void	redir_add_back(t_redir **lst, t_redir *new);
void	redir_free(t_redir **lst);
int		redir_size(t_redir *lst);//ELIMINAR ANTES DE ENTREGA

/*---------------------------utils_parser -------------------------*/
int		is_operator(t_tok *node);
size_t	commands_size(t_tok *tok);

/*---------------expander & quote removal--------------*/
void	should_expand(t_cmd *cmd, t_env *envlist);
char	*expand_quote_rm(char *str, t_env *envlist);
int		new_tok_len(char *str, t_env *envlist);
char	*new_tok_builder(char *str, t_env *envlist, char *result);
char 	*get_env_key(char *str);
char 	*get_env_val(char *env_key, t_env *envlist);

/*---------------utils-----------------*/
void	*p_malloc(size_t size);
//void	malloc_s_pointer_protect(void *name);
//void	malloc_d_pointer_protect(char **name);

/*--------------------------utils t_env-------------------*/
t_env	*lstlast(t_env *lst);
void	lstadd_back(t_env **lst, t_env *new);
t_env	*lstnew(char *key, char *value);
void	init_envlist(char **envp, t_env **envlist);
void	env_delone(t_env **env, char **node_to_del, void (*del)(void*));
void	cleaner_envlist(t_env **lst);


/*---------------------------executor.c -------------------------*/
char	**get_paths(t_env *env);
int		pre_executor(t_env **env, t_cmd *cmd, t_exe *exe);
int		search_command_path(t_cmd *cmd, t_exe *exe);
void	error_exe(int num);
int		list_to_array(t_env *env, t_exe *exe);
int		close_fd(t_exe	*exe);

/*---------------------------redirections.c -------------------------*/
int	pre_redirections(t_cmd *cmd, t_exe *exe);

/*---------------------------utils0.c -------------------------*/
int		ft_msgs(int n);
//int		get_exit_status(t_exe *exe);//funciones repetidas ?
//void	set_exit_status(int num, t_exe *exe);

/*---------------------------utils1.c -------------------------*/
int		ca_strchr(const char *s, int c);
char	*ft_strncpy(char *dest, char *src, unsigned int n);

/*-------------------exit_status----------------*/
unsigned int	get_exit_status_len(void);
char			*get_exit_status_val(void);

/*--------------------------- builtins -------------------------*/
int		builtins(t_cmd *cmd, t_env **env);
// int		builtin_exit(t_cmd *cmd);
int		builtin_exit(t_cmd *cmd, t_env *envlist);
int		builtin_pwd(t_env *env);
int		builtin_cd(t_cmd	*cmd, t_env **env);
int		builtin_env(t_cmd *cmd, t_env *env);
int		builtin_echo(t_cmd *cmd);
int		builtin_export(t_cmd *cmd, t_env **env);
int		builtin_unset(t_cmd *cmd, t_env **env);
int		is_builtins(t_cmd *cmd);

/*--------------------------- builtin export -------------------------*/
unsigned int	check_export(char *arg);
int		variable_exists(t_env *env, char *variable);
int		variable_exists_op2(t_env *env, char *variable);
int		variable_exists_op3(t_env *env, char *variable);
int		var_exists_oldpwd(t_env *env, char *variable);

t_env	*update_env(t_env *env, char *key, char *val);
int		get_pwd(t_env *env);
int		old_pwd(void);
int		go_path(char *path);

/*--------------------prints-----------------*/
void	print_arr2d(char **arr2d);//ELIMINAR ANTES DE ENTREGA
void	print_tok(t_tok *lst);//ELIMINAR ANTES DE ENTREGA
void	print_cmd(t_cmd *list);//ELIMINAR ANTES DE ENTREGA
void	print_redir(t_redir *lst);//ELIMINAR ANTES DE ENTREGA
void	ft_print_keys(t_env *env_struct);//ELIMINAR ANTES DE ENTREGA
void	ft_print_values(t_env *env_struct);//ELIMINAR ANTES DE ENTREGA
void	ft_printstack(t_env *env_struct);//ELIMINAR ANTES DE ENTREGA
void	print_cmd_para_executor(t_cmd *lst);//ELIMINAR ANTES DE ENTREGA

/*-----------redirections---------------*/
int	exist_redirections(t_redir *aux);

#endif