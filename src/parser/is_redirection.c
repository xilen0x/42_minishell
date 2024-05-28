#include "minishell.h"

/*Returns TRUE if 'node' contains '<', '>', '<<', '>>' and FALSE otherwise.*/

int	is_redirection(t_tok *node)
{
	if (node->type == GREATER || node->type == SMALLER \
    || node->type == D_GREATER || node->type == D_SMALLER)
		return (TRUE);
	return (FALSE);
}