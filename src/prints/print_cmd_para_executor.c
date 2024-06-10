/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_para_executor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:38:31 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/10 10:39:50 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_cmd_para_executor(t_cmd *lst)
{
	int	i;

	while (lst != NULL)
	{
		i = 0;
		printf("-----------------------\n");
		printf("Executor recibe: ");
		while (lst->commands[i] != NULL)
		{
			printf("<%s>", lst->commands[i]);
			i++;
		}
		printf("\n");
		if (lst->redir != NULL)
			print_redir(lst->redir);
		else
			printf("     t_redir = NULL\n");
		lst = lst->next;
	}
	printf("-----------------------\n");
}
