#include "minishell.h"

/*Función que obtiene y guarda los envp path*/
void	ft_get_paths(char **envp, t_env *data)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	data->paths = ft_split(&envp[i][5], ':');
}

Recibira como args (t_cmd **cmd, la copia del env, exit_status???)
Si la WORD contiene, en alguna posicion '$' llamaremos a la funcion 'expander'.


Despues del '$' para que sea una variable valida, 
solo puede empezar por caracter alphabetico o '_', 
solo puede contener caracteres alfabeticos (mayuscula o minuscula) o numericos o '_',
y debe coincidir exactamente hasta el '=' con una de las variables del 'env'. 
Si coincide y ademas tiene algun otro caracter alphabetico o numerico ya no seria valida.

'$' = bash: $: command not found

echo '$'+otros_caracteres = si los caracteres despues del $ coinciden EXACTAMENTE con una de las
 variables de env hasta antes del '=', lo sustituiremos en el WORD.
 
echo '$USERT' = esto solo nos da un salto de linea y vuelve a mostrar el prompt, porque no encuentra 