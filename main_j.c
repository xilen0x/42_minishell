/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minsh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:31:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/02/27 18:21:34 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
/*
typedef struct s_env
{
	char	**env_cpy;
	char	*key;
	char	*value;
}			t_env;
*/

/*-----------Makes an allocated char ** copy-------------*/
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
		exit (EXIT_FAILURE);//definirlo en el .h
	while (i < len)
	{
		*env[i] = ft_strdup(e[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

int main(int ac, char *av[], char *e[])
{
    char	*line;//string que contendra lo que se ingrese por stdin
//	t_env	env_cpy;
	char	**env;//contendra una copia del env del sistema

	if (ac != 1 || av[1])//proteje y usa 'ac' y 'av' para que el compilador no de error
	{
		printf("minishell do not accept arguments\n");
		return (0);
	}
	
	env = env_cpy(e);//hacemos nuestra propia copia del env del sistema

	while (1)//en teoria, loop infinito hasta que se presione Ctrl + C
	{
    	line = readline("minishell:-> ");// Muestra prompt y lee la línea de entrada

		add_history(line);//agrega line al historial
		free(line);
	}

    return (0);
}
