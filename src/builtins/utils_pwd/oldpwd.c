/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldpwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:30:45 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 15:30:49 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*Funcion que cambia al directorio anterior y actualiza la variable OLDPWD*/
int	set_old_pwd(void)
{
	char	*previous_directory;

	previous_directory = getenv("OLDPWD");
	if (chdir(previous_directory) != 0)
		return (1);
	return (0);
}

/*actualiza la variable OLDPWD del entorno*/
int	update_oldpwd(t_env *env, char *current_wd)
{
	char	*previous_directory;

	previous_directory = current_wd;
	if (!previous_directory)
	{
		perror("getenv");
		free(previous_directory);
		return (1);
	}
	env = update_env(env, "OLDPWD", previous_directory);
	return (0);
}

// consulta el directorio anterior(si existe)
int	get_old_pwd(char *current_wd, t_env *env)
{
	if (!(variable_exists_op3(env, "OLDPWD")))
	{
		write(2, "cd: OLDPWD not set", 18);
		write(2, "\n", 1);
		return (1);
	}
	else if (variable_exists_op3(env, "OLDPWD"))
		update_oldpwd(env, current_wd);
	return (0);
}
