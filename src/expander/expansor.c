#include "minishell.h"
//TODO ESTO ES PAJA NO DEFINITIVA
/*--Funcion que hace la expansion--*/
//Recibira como args (t_cmd **cmd, la copia del env, exit_status???)
//contendra al inicio algunos protectores para detectar errores de sintaxis 
//verificar si despues de '$' hay un '?'

char *quote_removal(t_cmd **cmd, t_list **env_cpy, int exit_status)//revisar el tipo de env_cpy
{
	int	s_quote;
	int	d_quote;

	s_quote = 0;
	d_quote = 0;
	
	while (*(line + len) && (*(line + len) != ' ' && *(line + len)!= '\t' \
		&& *(line + len) != '|' && *(line + len) != '<' \
		&& *(line + len) != '>' && *(line + len) != '\0'))//si es una WORD, busco su len
		{
			if (*(line + len) == '\'' || *(line + len) == '"')//si hay comillas
			{
				c = *(line + len);//inicializo 'c' con el caracter de comilla encontrado
				len++;
				while (*(line + len) && *(line + len) != c)//mientras exista y no sea otra comilla igual a 'c'
					len++;
			}
			if (*(line + len))
				len++;
		}

}



/*--------$--------*/
/*Despues del '$' para que sea una variable valida, 
solo puede empezar por caracter alphabetico o '_', 
solo puede contener caracteres alfabeticos (mayuscula o minuscula) o numericos o '_',
y debe coincidir exactamente hasta el '=' con una de las variables del 'env'.
y ademas despues del nombre de la variable ha de haber un espacio (si no lo hay, 
se ignora la variable y solo hace un salto de linea) 
Si coincide y ademas tiene algun otro caracter alphabetico o numerico ya no seria valida.*/


/*
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
*/