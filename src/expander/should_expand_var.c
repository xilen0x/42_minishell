#include "minishell.h"

/*Verifica si en el comando, los argumentos o los archivos de 
redireccion hay alguna variable que deba ser expandida*/

void	should_expand_var(t_cmd **cmd)
{
	size_t	i;
	size_t	j;
	t_cmd	*cmd_aux;

	i = 1;//porque el indice 0 es el commando y este no deberia tener '$'(a menos que sea literal' ' y no seria buena practica)
	j = 0;
	cmd_aux = *cmd;
	while (cmd_aux != NULL)//recorre la lista t_cmd
	{
		while (cmd_aux->command_and_arg[i] != NULL)//recorre los elementos de la matriz del comando
		{
			if (ft_strchr(cmd_aux->command_and_arg[i], '$') != NULL)
				ves a expander con este puntero (cmd_aux->command_and_arg[i]);//habra que mallocar de nuevo este *char
			i++;
		}
		while (cmd_aux->redir)//recorre la lista redir
		{
			if (ft_strchr(cmd_aux->redir->filename, '$') != NULL)
				ves a expander con este puntero (cmd_aux->redir->filename);
			cmd_aux = cmd_aux->next;
		}
		cmd_aux = cmd_aux->next;
	}
}

/*--Funcion que hace la expansion--*/
//Recibira como args (t_cmd **cmd, la copia del env, exit_status???)
//contendra al inicio algunos protectores para detectar errores de sintaxis 
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

echo '$USERT' = $USER 