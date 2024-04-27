#include "minishell.h"

static int	ft_counter(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (counter);
}

static char	**ft_free(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		num;
	int		start;

	i = -1;
	num = 0;
	split = (char **)ft_calloc((ft_counter(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	while (num < ft_counter(s, c) && i++ >= -1)
	{
		if (s[i] != c && s[i])
		{
			start = i;
			num++;
			while (s[i] != c && s[i] != '\0')
				i++;
			split[num - 1] = ft_substr(s, (unsigned int)start, i - start);
			if (!split[num - 1])
				return (ft_free(split, num - 2));
		}
	}
	return (split);
}

/*---CREO QUE NO SE UTILIZA-----VERIFICAR ANTES DE ENTREGA---*/
/* Libera todo un array de strings (char **) */
//Chequear si ya hay una funcion que hace lo mismo en nuestro minishell????
void	ft_free_split(char **array_strings)
{
	size_t	i;

	i = 0;
	if (array_strings)
	{
		while (array_strings[i])
		{
			free(array_strings[i]);
			i++;
		}
		free(array_strings);
	}
}