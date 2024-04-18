#ifndef QUOTE_REM_H
# define QUOTE_REM_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

//Environment Struct
typedef struct s_env
{
	char			*key;
	char			*val;
	struct s_env	*next;
}	t_env;


/*---------------------------utils lista env.c -------------------------*/
void	init_list(char **envp, t_env **envlist);
void	ft_printstack(t_env *env_struct);
void	ft_print_keys(t_env *env_struct);
void	ft_print_values(t_env *env_struct);
void	ft_printstack(t_env *env_struct);
void	ft_free_split(char **array_strings);
t_env	*lstlast(t_env *lst);
void	lstadd_back(t_env **lst, t_env *new);
t_env	*lstnew(char *key, char *value);



int		tok_len(char *str, t_env *envlist);
char	*quote_removal(char *str, t_env *envlist);
char 	*get_var_name(char *str);



/*----------UTILS DE LIBFT-----------*/
int		ft_isalnum(int c);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);


#endif