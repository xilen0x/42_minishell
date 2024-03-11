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
# include "arr2d.h"

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

//# define WORD  definir: REDIRECTION, PIPE, WORD, INVALID

/*---joan---*/

enum e_keytok
{
	WORD,
	PIPE,
	OPERATOR,
	INVALID
};

typedef struct s_lst
{
	char			*value;
	int				keyword;//ADMITIRA LOS ENUMS?? HAY QUE PONER QUE ES DE TIPO e_keytok ??
	struct	s_list	*next;
}					t_lst;

/*-----carlos------------------
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
  ---------------------*/


typedef struct s_shell
{
	t_lst	**tokens;
	char	**pipes;
	int		pipex;
	int		exit;
	//t_pipe	*p;
	char	**args;
	char	*cmd;
}	t_shell;

//int		builtings(t_built	*cmd, t_env	env, int ac);
int		builtings(t_built	*cmd, char **env, int ac);
char	**env_cpy(char *e[]);
int		change_directory(t_built	*cmd, int ac);
int		get_pwd(void);
//char	**dup_array_2d(char *envp[]);

#endif