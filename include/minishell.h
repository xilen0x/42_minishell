#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

/*------------------------Defines-----------------------*/

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define TRUE 1
# define FALSE 0

/*--------------------Error messages-------------------*/

# define PRINT_SYNTAX_ERR_1 "syntax error near unexpected token `|'\n"
# define PRINT_SYNTAX_ERR_2 "syntax error near unexpected token `newline'\n"
# define PRINT_SYNTAX_ERR_3 "syntax error\n"

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
} 	t_type;

typedef struct s_tok
{
	char			*str;//sera NULL si es un operador o un string si es una WORD
	t_type			type;
	struct s_tok	*next;
}					t_tok;

typedef enum e_red_io
{
	NULL_REDIR = 0,
	REDIR_OUTPUT = 3,//>
	REDIR_INPUT = 4,//<
	REDIR_OUTPUT_APPEND = 5,//>>
	HEREDOC_INPUT = 6//<<
} 	t_red_io;

typedef struct s_redir
{
	char			*filename;
	t_red_io		red_io;
	struct s_redir	*next;
}					t_redir;

typedef struct s_cmd
{
	char			**command_and_arg;//comando + argumentos/opciones
	t_redir			*redir;//lista con operador de redireccion y su filename
	struct s_cmd	*next;
}					t_cmd;//contiene los datos de un pipe
/*
//-----carlos------------------
typedef struct s_builtings
{
	//char	*echo_n;
	char	*cd;
	char	*pwd;
	char	*export;
	char	*unset;
	//char	*env;
	char	*exit;
	char	*cmd1;
	char	*path;//borrar luego(posiblemente)
	//char	*the_string;
}	t_built;

typedef struct s_env
{
	char	**env_cpy;
	char	**export_cpy;
	char	*type;
	char	*str;
	t_built	*env_to_build;
}	t_env;

typedef struct s_shell
{
	t_tok	**tok;
	char	**pipes;
	int		pipex;
	int		exit;
	//t_pipe	*p;
	char	**args;
	char	*cmd;
}	t_shell;

//int		builtings(t_built	*cmd, char **env, int ac);
//char	**env_cpy(char *e[]);
//char	**dup_array_2d(char *envp[]);

int	init (t_built *cmd, int ac, char *av[]);
int	builtins(t_built *cmd, t_env env, int ac, char *av[]);
int	builtin_cd(t_built *cmd, int ac);
int	builtin_pwd(void);
int	builtin_echo(t_built *cmd, int ac);
int	builtin_env(t_env env);
int	builtin_export(t_env env, int ac);
int	builtin_exit(t_built *cmd, int ac, char *av[]);
*/

/*----------------minishell----------------*/
void 	tokenizer(t_tok **tok, char *line);
void    parser(t_cmd **cmd, t_tok *tok);

void	handle_error(char *str, t_tok **tok);

/*---------------------array 2d----------------*/
size_t  size_arr2d(char **arr2d);
char	**dup_arr2d(char **arr2d);
char    **add_one_arr2d(char **arr2d, char *new);
char    **rm_one_arr2d(char **arr2d, int index);
void    free_arr2d(char **arr2d);
void	print_arr2d(char **arr2d);//ELIMINAR ANTES DE ENTREGA

/*-----------------t_tok------------------*/
t_tok	*tok_new_node(char *str, int type);
t_tok	*tok_last(t_tok *lst);
void	tok_add_back(t_tok **lst, t_tok *new);
void	tok_free(t_tok **lst);
int		tok_size(t_tok *lst);//ELIMINAR ANTES DE ENTREGA
void	tok_print(t_tok *lst);//ELIMINAR ANTES DE ENTREGA

/*-------------------t_cmd----------------*/
t_cmd	*cmd_new_node(void);
t_cmd	*cmd_last(t_cmd *lst);
void	cmd_add_back(t_cmd **lst,t_cmd *new);
void	cmd_free(t_cmd **lst);
int		cmd_size(t_cmd *lst);//ELIMINAR ANTES DE ENTREGA
void	cmd_print(t_cmd *list);//ELIMINAR ANTES DE ENTREGA

/*-----------------t_redir-----------------*/
t_redir	*redir_new_node(char *str, int red_io);
t_redir	*redir_last(t_redir *lst);
void	redir_add_back(t_redir **lst,t_redir *new);
void	redir_free(t_redir **lst);
int		redir_size(t_redir *lst);//ELIMINAR ANTES DE ENTREGA
void	redir_print(t_redir *lst);//ELIMINAR ANTES DE ENTREGA

/*--------------utils_parser---------------*/
int		is_operator(t_tok *node);
size_t 	command_and_arg_size(t_tok *tok);

/*---------------utils_libft-----------------*/
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
size_t 	str_l_cpy(char *dst, const char *src, size_t dstsize);


#endif