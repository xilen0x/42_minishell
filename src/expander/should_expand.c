/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   should_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 16:28:34 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/06 11:10:24 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*static void	should_expand_core(t_cmd *cmd_aux, t_env *envlist)
{
	size_t	i;
	t_redir	*redir_aux;

	redir_aux = cmd_aux->redir;
	i = 0;
	while (cmd_aux->commands && cmd_aux->commands[i])//busca $, ', " en los comandos
	{
		if (ft_strchr(cmd_aux->commands[i], '$') != NULL ||
			ft_strchr(cmd_aux->commands[i], '\'') != NULL ||
			ft_strchr(cmd_aux->commands[i], '"') != NULL)
			cmd_aux->commands[i] = expand_quote_rm(cmd_aux->commands[i], \
			envlist);
		i++;
	}
	while (redir_aux)//busca ', ", $ en las redirecciones
	{
		if (ft_strchr(redir_aux->fname, '$') != NULL ||
			ft_strchr(redir_aux->fname, '\'') != NULL ||
			ft_strchr(redir_aux->fname, '"') != NULL)
			redir_aux->fname = expand_quote_rm(redir_aux->fname, envlist);
		redir_aux = redir_aux->next;
	}
}
*/
/* Look for any expandable or quote removable token into 'cmd' list */
/*
void	should_expand(t_cmd *cmd, t_env *envlist)
{
	t_cmd	*cmd_aux;

	cmd_aux = cmd;
	while (cmd_aux)
	{
		i = 0;
		while (cmd_aux->commands && cmd_aux->commands[i])//busca $, ', " en los comandos
		{
			if (ft_strchr(cmd_aux->commands[i], '$') != NULL ||
				ft_strchr(cmd_aux->commands[i], '\'') != NULL ||
				ft_strchr(cmd_aux->commands[i], '"') != NULL)
				cmd_aux->commands[i] = expander(cmd_aux->commands[i], envlist);
			i++;
		}
		while (redir_aux)//busca ', ", $ en las redirecciones
		{
		 	if (ft_strchr(redir_aux->fname, '$') != NULL ||
				ft_strchr(redir_aux->fname, '\'') != NULL ||
				ft_strchr(redir_aux->fname, '"') != NULL)
//		 	{
//	 			redir_tmp = expander(redir_aux->filename, envlist);
//		 		redir_aux->filename = redir_tmp;
//		 	}
				redir_aux->fname = expander(redir_aux->fname, envlist);
		 	redir_aux = redir_aux->next;
		}
		cmd_aux = cmd_aux->next;
	}
}
*/
void	should_expand(t_cmd *cmd, t_env *envlist)
{
	size_t	i;
	t_redir	*redir_aux;

	redir_aux = cmd->redir;
	while (cmd)
	{
		i = 0;
		while (cmd->commands && cmd->commands[i])//busca $, ', " en los comandos
		{
			if (ft_strchr(cmd->commands[i], '$') != NULL \
				|| ft_strchr(cmd->commands[i], '\'') != NULL \
				|| ft_strchr(cmd->commands[i], '"') != NULL)
				cmd->commands[i] = expander(cmd->commands[i], envlist);
			i++;
		}
		while (redir_aux)//busca ', ", $ en las redirecciones
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
