/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:37:55 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/10 10:41:11 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----Imprime lista t_cmd---ELIMINAR ANTES DE ENTREGA----*/
void	print_cmd(t_cmd *lst)
{
	int	i;

	while (lst != NULL)
	{
		i = 0;
		printf("-----------------------\n");
		printf("t_cmd\n");
		if (lst->commands == NULL)
			printf("     commands = NULL\n");
		else
		{
			while (lst->commands[i])
			{
				printf("     <%s>\n", lst->commands[i]);
				i++;
			}
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
