/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:31:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/03/06 19:22:14 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//#include "libft/libft.h"

/*-----------Makes an allocated copy of env-------------*/
char	**env_dup(char *e[])
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
		return (EXIT_FAILURE);//quizas deberia retornar 0 ???
	}
	env = env_dup(e);//nos duplicamos el env del sistema

	while (1)//loop infinito hasta que se presione Ctrl+D o se cierre el programa
	{
//		poner las señales en escucha y hacer funcion para gestionarlas(handler ??)	
		line = readline("___minishell$ ");
		if (line != NULL)
			add_history(line);//agregamos 'line' al historial, lo gestiona biblioteca readline
//		gestionar Ctrl+C (para que interrumpa el proceso actual, invocando a SIGINT y presente el prompt de nuevo)
//		tokenizer(line);
		free(line);//libero la linia que retorno readline seguramente mallocada
//		parser(la struct/list con los tokens);
	}
	write(1, "the_end\n", 8);
	return (0);
}
