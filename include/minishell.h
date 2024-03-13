#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "utils_libft.h"//joan .decidir si esta o la anterior
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "builtins.h"
# include "arr2d.h"//joan
# include "lst.h"//joan

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

/*---joan---*/
typedef enum e_keytok
{
	WORD = 0,
	PIPE,
	GREATER,
	SMALLER,
	DOUBLE_GREATER,
	DOUBLE_SMALLER,
	INVALID //(de moment al tokenizer no usar)
} 	t_keytok;

typedef struct s_lst
{
	char			*value;
	t_keytok		keyword;//ADMITIRA LOS ENUMS???
	struct	s_list	*next;
}					t_lst;

//-----carlos------------------
typedef struct s_env
{
	char	**env_cpy;
	char	*key;
	char	*value;
}			t_env;

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

int	init (t_built *cmd, char *av[]);
int	builtins(t_built *cmd, t_env env, int ac);
int	builtin_cd(t_built *cmd, int ac);
int	builtin_pwd(void);
int	builtin_echo(t_built *cmd, int ac);
int	builtin_env(t_env env);
int	builtin_export(t_env env, int ac);

#endif