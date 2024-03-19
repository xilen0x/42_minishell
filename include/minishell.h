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

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

//---joan---
typedef enum e_keytok
{
	NULL_KEY = 0,//para inicializar con algo cuando aun no vaya a necesitarlo 
	WORD,
	PIPE,
	GREATER,
	SMALLER,
	DOUBLE_GREATER,
	DOUBLE_SMALLER,
	INVALID //(de momento no lo usare)
} 	t_keytok;

typedef struct s_lst
{
	char			*value;
	t_keytok		keyword;//ADMITIRA LOS ENUMS???
	struct	s_lst	*next;
}					t_lst;

//-----carlos------------------
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
}	t_built;

typedef struct s_env
{
	char	**env_cpy;
	char	**export_cpy;
	char	*key;
	char	*value;
	t_built	*env_to_build;
}	t_env;
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

int	init (t_built *cmd, int ac, char *av[]);
//int	builtins(t_built *cmd, t_env env, int ac, char *av[]);
int	builtins(t_built *cmd, t_lst token, t_env env, char *av[]);
int	builtin_cd(t_built *cmd, int ac);
int	builtin_pwd(void);
int	builtin_echo(t_built *cmd, int ac);
int	builtin_env(t_env env);
int	builtin_export(t_env env, int ac);
//int	builtin_exit(t_built *cmd, int ac, char *av[]);
int	builtin_exit(t_built *cmd, t_lst token, char *av[]);

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
size_t jc_strlcpy(char *dst, const char *src, size_t dstsize);

t_lst	*lstnew_node(char *value, int keyword);
t_lst	*ft_lstlast2(t_lst *lst);
void	jc_lstadd_back(t_lst **lst, t_lst *new);
int		jc_lstsize(t_lst *lst);
void	lst_print(t_lst *list);

char	**dup_arr2d(char **arr2d);
size_t  size_arr2d(char **arr2d);
void    free_arr2d(char **arr2d);
char    **add_one_arr2d(char **arr2d, char *new);
char    **rm_one_arr2d(char **arr2d, int index);
//char    **set_one_arr2d(char **arr2d, char *new_str, int index);//esta pendiente de hacer (si hace falta)
void	print_arr2d(char **arr2d);
void	init_msg(void);
void tokenizer(t_lst *tokens, char *line);

//char    *get_value_arr(char **arr, char *name);//pendiente de hacer(si hace falta)
// pendiente de hacer una funcion que comprueba si existe o no una variable env (puede retornar TRUE o FALSE, si existe podre reemplazarla, removerla o liberarla, si no existe podre añadirla)


#endif