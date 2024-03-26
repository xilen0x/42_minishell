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

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef struct s_builtings t_built;
// # define BLUE_BG =	"\033[0;97;44m"

//---joan---
typedef enum e_keytok
{
	NULL_KEY = 0,//para inicializar con algo cuando aun no vaya a necesitarlo 
	WORD,
	PIPE,
	GREATER,
	SMALLER,
	D_GREATER,
	D_SMALLER,
//	INVALID //(de momento, no lo usare)
} 	t_keytok;

typedef struct s_lst
{
	char			*val;//solo puede ser NULL(si es un operador) o el string que contenga la WORD
	t_keytok		key;//alguno de los enums
	struct	s_lst	*next;
}					t_lst;

typedef struct s_cmd//estructura de cada pipeline
{
	char			**cmd_arg;//COMANDO + TODOS LOS ARGS/OPCIONES(si no hay, NULL)
//	LISTA			*fd_io;//redireccion de entrada del pipeline (si no hay, NULL)
	struct s_cmd	*next;
}					t_cmd;

//-----carlos------------------
typedef struct s_env
{
	char	**env_cpy;
	char	**export_cpy;
	char	*key;
	char	*val;
	t_built	*to_built;
}	t_env;

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

/*
typedef struct s_shell
{
	t_lst	**tokens;
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
/* ------------------------ builtins ------------------------ */
int		init (t_built *cmd, int ac, char *av[]);
int		builtins(t_built *cmd, int ac, char *av[], t_env env);
//int	is_builtin(t_built *cmd, int ac, char *av[]);
int		builtin_cd(t_built *cmd, int ac);
int		builtin_pwd(void);
int		builtin_echo(t_built *cmd, int ac);
int		builtin_env(t_env env);
int		builtin_export(t_built *cmd, t_env env, int ac);
int		builtin_exit(t_built *cmd, int ac, char *av[]);
int		builtin_unset(t_built *cmd, t_env env, int ac);

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
size_t 	str_l_cpy(char *dst, const char *src, size_t dstsize);

t_lst	*lst_new_node(char *val, int key);
t_lst	*lst_last(t_lst *lst);
void	lst_add_back(t_lst **lst, t_lst *new);
int		lst_size(t_lst *lst);
void	lst_clear(t_lst **lst);
void	lst_print(t_lst *list);
char	**dup_arr2d(char **arr2d);
size_t  size_arr2d(char **arr2d);
void    free_arr2d(char **arr2d);
char    **add_one_arr2d(char **arr2d, char *new);
char    **rm_one_arr2d(char **arr2d, int index);
void	print_arr2d(char **arr2d);
void	init_msg(void);

void	set_signals(void);
int 	bg_color();
int		ca_strcmp(char *s1, char *s2);
//char    **set_one_arr2d(char **arr2d, char *new_str, int index);//esta pendiente de hacer (si hace falta)

t_cmd	*cmd_new_node(unsigned int index);

void 	tokenizer(t_lst *tokens, char *line);
void    parser(t_cmd *cmd, t_lst *tokens);
//char    *get_value_arr(char **arr, char *name);//pendiente de hacer(si hace falta)
// pendiente de hacer una funcion que comprueba si existe o no una variable env (puede retornar TRUE o FALSE, si existe podre reemplazarla, removerla o liberarla, si no existe podre añadirla)
#endif