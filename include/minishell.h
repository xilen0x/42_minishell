#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "builtins.h"
# include "arr_2d.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define WORD
// definir: REDIRECTION, PIPE, WORD, INVALID

typedef struct s_lst
{
	char			*value;
	int				keyword;//deberia ser un int?? 
	struct s_list	*next;
}					t_lst;

typedef struct s_builtings
{
	char	*echo;
	char	*cd;
	char	*pwd;
	char	*export;
	char	*unset;
	char	*env;
	char	*exit;
	char	*cmd1;
	char	*path;//borrar luego

}	t_built;

typedef struct s_env
{
	char	**env_cpy;
	char	**export_cpy;
	char	*key;
	char	*value;
	t_built	*env_to_build;
}			t_env;

/*typedef struct s_shell
{
	char	**tokens;
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
int		init(t_built *cmd, char *av[]);
int		builtins(t_built *cmd, t_env env, int ac);
int		builtin_cd(t_built *cmd, int ac);
int		builtin_pwd(void);
int		builtin_echo(t_built *cmd, int ac);
int		builtin_env(t_env env);
int		builtin_export(t_env env, int ac);

#endif