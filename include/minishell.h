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

}	t_built;

typedef struct s_env
{
	char	**env_cpy;
	char	*key;
	char	*value;
}			t_env;

int	builtings(t_built	*cmd, t_env	env);
char	**env_cpy(char *e[]);

#endif