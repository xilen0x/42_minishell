/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:31:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/03/05 10:23:27 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//#include "libft/libft.h"

/*-----------Makes an allocated copy of env-------------*/
char	**env_cpy(char *e[])
{
	char	**env;
	int		len;
	int		i;   

	i = 0;
	len = 0;
	while (e && e[len])
		len++;
	env = (char **)malloc((len + 1) * sizeof(char *));
	if (env == NULL)
		exit (EXIT_FAILURE);//definirlo en el .h  ???
	while (i < len)
	{
		env[i] = ft_strdup(e[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

int	main(int ac, char *av[], char *e[])
{
	char	*line;//string que contendra lo que se ingrese por stdin
	char	**env;//contendra una copia del env del sistema

	if (ac != 1 || av[1])//si hay algun argumento
	{
		printf("minishell do not accept arguments\n");
		return (0);
	}
	env = env_cpy(e);//copiamos el env del sistema

	while ((int)1)//en teoria, loop infinito hasta que se presione Ctrl + C
	{
		line = readline("minishell$ ");
		if (line != NULL)
		add_history(line);//agrega line al historial
		//			tokenizer(line);
		free(line);

	}
	return (0);
}
