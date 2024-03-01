/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:31:05 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/03/01 14:20:08 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char *av[], char *e[])
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
    	line = readline("minishell$ ");// Muestra prompt y lee la línea de entrada

		add_history(line);//agrega line al historial
		free(line);
	}
    return (0);
}