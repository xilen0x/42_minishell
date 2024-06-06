/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:35:47 by castorga          #+#    #+#             */
/*   Updated: 2024/06/05 16:35:49 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* update environment variables*/
void	update_environment(t_env *env, char *current_wd)
{
	update_pwd(env);
	update_oldpwd(env, current_wd);
}

/* free current working directory */
int	free_current_wd(char *current_wd)
{
	if (current_wd != NULL && *current_wd != '\0')
	{
		free(current_wd);
		return (1);
	}
	return (0);
}
