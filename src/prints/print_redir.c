/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:42:03 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/10 10:42:05 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----Imprime una lista t_redir----*/
void	print_redir(t_redir *lst)
{
	printf("     t_redir\n");
	if (!lst)
	{
		printf("            NULL\n");
		return ;
	}
	while (lst)
	{
		printf("            (%i)%s\n", lst->redir_type, lst->fname);
		lst = lst->next;
	}
}
