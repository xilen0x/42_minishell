
#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"


# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define WORD
// definir: REDIRECTION, PIPE, WORD, INVALID

typedef struct s_lst
{
	char			*value;
	int				keyword;//deberia ser un int?? 
	struct	s_list	*next;
}					t_lst;

char	**dup_array_2d(char *e[]);

//char	*ft_strdup(const char *s1);
//void	*ft_memcpy(void *dst, const void *src, size_t n);
//size_t	ft_strlen(const char *s);

#endif