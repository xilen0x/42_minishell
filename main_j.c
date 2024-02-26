/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minsh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:31:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/02/26 18:08:39 by jocuni-p         ###   ########.fr       */
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

int main(int ac, char **av, char **e)
{
    char	*line;//string que contendra lo que se ingrese por stdin
//	t_env	env_cpy;
	char	**env;//contendra una copia del env del sistema

	if (ac != 1)//protector de entrada
	{
		printf("minishell do not accept arguments\n")
		exit (0);
	}
	(void)ac;//para que compilador no diga que no se usa
	(void)av;



	env = hacer una funcion que haga copia de 'e'



	while (1)//loop infinito hasta que se presione Ctrl + C
	{
    	line = readline("minishell:-> ");// Muestra prompt y lee la línea de entrada

		add_history(line);//agrega line al historial
//		printf("La línea ingresada es: %s\n", line);
		free(line);
	}
    return 0;
}
