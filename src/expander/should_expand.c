/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:28:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/07 16:27:31 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	should_expand(t_cmd *cmd, t_env *envlist)
{
	size_t	i;
	t_redir	*redir_aux;

	redir_aux = cmd->redir;
	while (cmd)
	{
		i = 0;
		while (cmd->commands && cmd->commands[i])
		{
			if (ft_strchr(cmd->commands[i], '$') != NULL \
				|| ft_strchr(cmd->commands[i], '\'') != NULL \
				|| ft_strchr(cmd->commands[i], '"') != NULL)
				cmd->commands[i] = expander(cmd->commands[i], envlist);
			i++;
		}
		while (redir_aux)
		{
			if (ft_strchr(redir_aux->fname, '$') != NULL \
				|| ft_strchr(redir_aux->fname, '\'') != NULL \
				|| ft_strchr(redir_aux->fname, '"') != NULL)
				redir_aux->fname = expander(redir_aux->fname, envlist);
			redir_aux = redir_aux->next;
		}
		cmd = cmd->next;
	}
}
