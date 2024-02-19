# 42_minishell
    
 **readline**: Lee una línea de entrada desde la terminal. Valor de retorno: La línea de entrada leída.

   **rl_clear_history**: Borra el historial de líneas escritas en la terminal utilizando la biblioteca de edición de línea GNU Readline. Valor de retorno: No especificado (void).

   **rl_on_new_line**: Indica que el cursor está en una nueva línea en la terminal. Valor de retorno: No especificado (void).

   **rl_replace_line**: Reemplaza la línea actual en la terminal con una nueva línea proporcionada. Valor de retorno: No especificado (void).

   **rl_redisplay**: Redibuja la línea actual en la terminal. Valor de retorno: No especificado (void).

   **add_history**: Agrega una línea al historial de la terminal. Valor de retorno: No especificado (void).

   **printf**: Imprime texto formateado en la salida estándar (terminal). Valor de retorno: El número de caracteres impresos.

   **malloc**: Asigna memoria dinámicamente en el heap. Valor de retorno: La dirección del bloque de memoria asignado o NULL en caso de falla.

   **free**: Libera la memoria asignada dinámicamente. Valor de retorno: No especificado (void).

   **write**: Escribe datos en un descriptor de archivo (usualmente la salida estándar). Valor de retorno: El número de bytes escritos.

   **access**: Comprueba si un proceso puede acceder a un archivo. Valor de retorno: 0 si tiene acceso, -1 en caso contrario.

   **open**: Abre o crea un archivo. Valor de retorno: Un descriptor de archivo válido o -1 en caso de error.

   **read**: Lee datos desde un descriptor de archivo. Valor de retorno: El número de bytes leídos, 0 si ha llegado al final del archivo, -1 en caso de error.

   **close**: Cierra un descriptor de archivo. Valor de retorno: 0 si tiene éxito, -1 en caso de error.

   **fork**: Crea un nuevo proceso clonando el proceso actual. Valor de retorno: El PID del proceso hijo en el proceso padre, 0 en el proceso hijo, -1 en caso de error.

   **wait, waitpid, wait3, wait4**: Espera a que un proceso hijo termine. Valor de retorno: El PID del proceso hijo que terminó o -1 en caso de error.

   **signal, sigaction**: Establece un manejador para una señal específica. Valor de retorno: El manejador de señal anterior o SIG_ERR en caso de error.

   **sigemptyset, sigaddset**: Manipulan conjuntos de señales. Valor de retorno: 0 en caso de éxito, -1 en caso de error.

   **kill**: Envía una señal a un proceso. Valor de retorno: 0 en caso de éxito, -1 en caso de error.

   **exit**: Termina el proceso actual. Valor de retorno: No especificado, generalmente 0 para indicar éxito.

   **getcwd**: Obtiene el directorio de trabajo actual. Valor de retorno: Un puntero al nombre del directorio de trabajo o NULL en caso de error.

   **chdir**: Cambia el directorio de trabajo actual. Valor de retorno: 0 en caso de éxito, -1 en caso de error.

   **stat, lstat, fstat**: Obtiene información sobre un archivo. Valor de retorno: 0 en caso de éxito, -1 en caso de error.

   **unlink**: Elimina un archivo del sistema de archivos. Valor de retorno: 0 en caso de éxito, -1 en caso de error.

   **execve**: Ejecuta un programa. Valor de retorno: -1 en caso de error (si se ejecuta correctamente, el proceso actual se reemplaza y no se devuelve).

   **dup, dup2**: Duplica descriptores de archivo. Valor de retorno: El nuevo descriptor de archivo o -1 en caso de error.

   **pipe**: Crea un conducto de comunicación entre procesos. Valor de retorno: 0 en caso de éxito, -1 en caso de error.

   **opendir, readdir, closedir**: Manipulan directorios. Valor de retorno: Un puntero a una estructura de directorio o NULL en caso de error.

   **strerror, perror**: Traducen códigos de error en mensajes de error. Valor de retorno: El mensaje de error correspondiente o NULL.

   **isatty**: Comprueba si un descriptor de archivo se refiere a un terminal. Valor de retorno: 1 si es un terminal, 0 si no lo es, -1 en caso de error.

   **ttyname**: Obtiene el nombre del dispositivo de terminal asociado con un descriptor de archivo. Valor de retorno: El nombre del dispositivo de terminal o NULL en caso de error.

   **ttyslot**: Obtiene la entrada en la tabla de terminales para la terminal actual. Valor de retorno: El índice en la tabla o -1 en caso de error.

   **ioctl**: Controla dispositivos específicos. Valor de retorno: 0 en caso de éxito, -1 en caso de error.

   **getenv**: Obtiene el valor de una variable de entorno. Valor de retorno: Un puntero al valor de la variable o NULL si no está definida.

   **tcsetattr, tcgetattr**: Obtiene y establece los atributos del terminal. Valor de retorno: 0 en caso de éxito, -1 en caso de error.

   **tgetent, tgetflag, tgetnum, tgetstr, tgoto, tputs**: Funciones de la biblioteca de terminfo para manejar capacidades de la terminal. Valor de retorno: Diversos, consulte la documentación específica de cada función.
