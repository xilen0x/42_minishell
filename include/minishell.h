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
	char	*key;
	char	*value;
}			t_env;

typedef struct s_shell
{
	char	**tokens;
	char	**pipes;
	int		pipex;
	int		exit;
	//t_pipe	*p;
	char	**args;
	char	*cmd;
}	t_shell;

int		builtings(t_built	*cmd, t_env	env, int ac);
char	**env_cpy(char *e[]);
int		change_directory(t_built	*cmd, int ac);
int		get_pwd(void);

#endif