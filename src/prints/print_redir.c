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
