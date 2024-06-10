/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:42:11 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/06/10 10:42:13 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----Imprime una lista t_tok----*/
void	print_tok(t_tok *lst)
{
	printf("\n=== %i tokens ===\n", tok_size(lst));
	while (lst)
	{
		printf("%s (%u)\n", lst->str, lst->type);
		lst = lst->next;
	}
	printf("\n");
}
