#include "minishell.h"

/*Returns TRUE if 'node' contains a <, >, << or >>, FALSE otherwise.*/

int	is_operator(t_lst *node)
{
	if (node->key == GREATER || node->key == SMALLER \
    || node->key == D_GREATER || node->key == D_SMALLER)
		return (TRUE);
	return (FALSE);
}
