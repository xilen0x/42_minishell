#include "minishell.h"

/*---If len is bigger than 0, initializes t_tok->str and t_tok->type--*/
void	init_word_str(size_t len, t_tok *new_tok, char *line, size_t i)
{
	if (len > 0)
	{
		new_tok->str = (char *)p_malloc(sizeof(char) * (len + 1));//malloco *str dentro del nodo
		ft_strlcpy(new_tok->str, line + i, len + 1);//Copio en str el trozo de line que me interesa
		new_tok->type = WORD;//seteo type
	}
}