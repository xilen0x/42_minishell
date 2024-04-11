#include "minishell.h"

/*Verifica si en el array de comandos o en la lista de 
redirecciones hay algun '$' que debiera ser expandido*/
void	should_expand_var(t_cmd **cmd)
{
	size_t	i;
	size_t	j = 0;//ELIMINAR ANTES DE ENTREGA
	t_cmd	*cmd_aux;
	t_redir	*redir_aux;

	cmd_aux = *cmd;
	while (cmd_aux != NULL)//recorre la lista t_cmd
	{
		i = 1;//porque el indice 0 es el commando y este no deberia tener '$'(a menos que sea literal' ' y no seria buena practica)
		printf("--scanned $ in command %zu--\n", j++);
		while (cmd_aux->command_and_arg[i] != NULL)//recorre la matriz del comando
		{
			if (ft_strchr(cmd_aux->command_and_arg[i], '$') != NULL)//si encuentra un '$'
				printf("	$ en indice %zu de la matriz\n", i);//ELIMINAR ANTES DE ENTREGA
//				if (!is_single_quoted(cmd_aux->command_and_arg[i])) return TRUE o FALSE. Si no en te, NO s'ha d'expandir.		
//					expansor(cmd_aux->command_and_arg[i]);//mallocarlo de nuevo expandido y liberar el viejo
			i++;
		}
		redir_aux = cmd_aux->redir;
		while (redir_aux != NULL)//recorre la lista redir
		{
			if (ft_strchr(redir_aux->filename, '$') != NULL)
				printf("	$ en t_redir\n");//ELIMINAR ANTES DE ENTREGA
//				if (!is_single_quoted(redir_aux->filename)) return TRUE o FALSE. Si no en te, NO s'ha d'expandir.		
//					expansor(cmd_aux->command_and_arg[i]);//mallocarlo de nuevo expandido y liberar el viejo
			redir_aux = redir_aux->next;
		}
		cmd_aux = cmd_aux->next;
	}
	printf("\n\n");//ELIMINAR ANTES DE ENTREGA
}
/*--Funcion que hace la expansion--*/
//Recibira como args (t_cmd **cmd, la copia del env, exit_status???)
//contendra al inicio algunos protectores para detectar errores de sintaxis 
/*
void	expansor(char **str)
{


}	-verifica si despues de '$' hay un '?'

--SI NO HAY CIERRE DE COMILLAS lo gestionaré como => syntax error near token 'print_del_token'
Al inicio: Las comillas le dicen al expansor si la variable se ha de expandir o no.
gestionar comillas al inicio de expander con una struct (comill single open,
 comill single closed, comill dob single, comill dob closed) booleana (TRUE = abierta, FALSE = cerrada o al reves)
con 4 if nos dira si esta abierta la simple o la doble y si esta cerrada la simple o la doble.
Ej: if ()




Despues del '$' para que sea una variable valida, 
-solo puede empezar por caracter alphabetico o '_', 
-solo puede contener caracteres alfabeticos (mayuscula o minuscula) o numericos o '_',
-debe coincidir exactamente hasta el '=' con una de las variables del 'env'.
y ademas despues del nombre de la variable ha de haber un espacio (si no lo hay, 
se ignora la variable y solo hace un salto de linea) 
Si coincide y ademas tiene algun otro caracter alphabetico o numerico ya no seria valida.

Si despues del '$' hay un '?' expande el exit_status del ultimo comando y si hay algun
 caracter concatenado al '?' tambien lo muestra concatenado al exit_status

'$' = bash: $: command not found



line: echo $USERhola
 res:  (solo hace un \n)
 ---------------
line: echo $?hola
res : 0hola (expande el exit_status y le concatena 'hola')

A CONTINUACION RESOLVER EL QUOTE REMOVAL
echo '$USERT' = $USER 
*/