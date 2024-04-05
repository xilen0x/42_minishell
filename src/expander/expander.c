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
/*-Pre-expansor: verifica si hay algun '$' en 'str' y devuelve TRUE or FALSE*/
//Si la WORD contiene, en alguna posicion '$' llamaremos a la funcion 'expander'.
int	check_for_dollar(nodo o char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{



	}



}

void expander(t_cmd **cmd, int exit)
{
	




}
/*--Funcion que hace el expander--*/
//Recibira como args (t_cmd **cmd, la copia del env, exit_status???)

	-verifica si despues de '$' hay un '?'


Despues del '$' para que sea una variable valida, 
solo puede empezar por caracter alphabetico o '_', 
solo puede contener caracteres alfabeticos (mayuscula o minuscula) o numericos o '_',
y debe coincidir exactamente hasta el '=' con una de las variables del 'env'.
y ademas despues del nombre de la variable ha de haber un espacio (si no lo hay, 
se ignora la variable y solo hace un salto de linea) 
Si coincide y ademas tiene algun otro caracter alphabetico o numerico ya no seria valida.

Si despues del '$' hay un '?' expande el exit_status del ultimo comando y si hay algun
 caracter concatenado al '?' tambien lo muestra concatenado al exit_status

'$' = bash: $: command not found

echo '$'+otros_caracteres = si los caracteres despues del $ coinciden EXACTAMENTE con una de las
 variables de env hasta antes del '=', lo sustituiremos en el WORD.
line: echo $USERhola
 res:  (solo hace un \n)
line: echo $?hola
res : 0hola (expande el exit_status y le concatena 'hola')

echo '$USERT' = esto solo nos da un salto de linea y vuelve a mostrar el prompt, porque no encuentra 