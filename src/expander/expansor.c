#include "minishell.h"

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