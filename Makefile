# Nombre del programa
TARGET = minishell

# Compilador
CC = clang

# Directorios de los archivos de encabezado, archivos objeto y bibliotecas
INCLUDE_DIR = ./include
LIBFT_DIR = ./libft
READLINE_DIR = ./readline
OBJ_DIR = ./objs

ARR2D_OBJ_DIR = $(OBJ_DIR)/arr2d

LST_OBJ_DIR = $(OBJ_DIR)/lst

# Directorio de los archivos fuente
SRC_DIR = ./src

# Opciones de compilación
CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address

# bibliotecas
LIBFT = $(LIBFT_DIR)/libft.a
READLINE = $(READLINE_DIR)/libreadline.a $(READLINE_DIR)/libhistory.a

# Bibliotecas adicionales necesarias
LIBS = -lreadline -ltermcap

# Archivos fuente
SOURCES = $(addprefix $(SRC_DIR)/, minishell.c \
									builtins/builtins.c \
									builtins/builtin_cd.c \
									builtins/builtin_pwd.c \
									builtins/builtin_echo.c \
									builtins/builtin_env.c \
									builtins/builtin_export.c \
									arr2d/add_one_arr2d.c \
									arr2d/dup_arr2d.c \
									arr2d/free_arr2d.c \
									arr2d/size_arr2d.c \
									arr2d/rm_one_arr2d.c \
									lst/ft_lstadd_back.c \
									lst/ft_lstlast.c \
									lst/ft_lstlast.c \
									utils_libft.c \
									tokenizer.c \
									utils0.c)

# Archivos objeto generados por el compilador
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS = $(OBJECTS:.o=.d)

# Directorios de los archivos de dependencias
DEPDIRS = $(OBJ_DIR)/builtins $(ARR2D_OBJ_DIR) $(LST_OBJ_DIR)

# Incluir archivos de encabezado
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(READLINE_DIR)

# Regla por defecto, compilación del programa
all: $(TARGET)

# Regla para compilar el programa
$(TARGET): $(LIBFT) $(READLINE) $(OBJECTS)
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ $(LIBFT) $(READLINE) $(LIBS)

# Regla para compilar cada archivo fuente
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(ARR2D_OBJ_DIR) $(LST_OBJ_DIR) $(DEPDIRS)
	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@

# Regla para crear los directorios de dependencias si no existen
$(DEPDIRS):
	@mkdir -p $(DEPDIRS)

# Regla para construir la biblioteca libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Regla para construir la biblioteca readline
$(READLINE):
	@make -C $(READLINE_DIR)

# Regla para limpiar archivos temporales y el programa compilado
clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(READLINE_DIR) clean

# Regla para limpiar archivos temporales y el programa compilado
fclean: clean
	@rm -f $(TARGET)
	@make -C $(LIBFT_DIR) fclean

# Regla para reconstruir el proyecto desde cero
re: fclean all

# Crea el directorio de objetos si no existe
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Incluye las dependencias
-include $(DEPS)

# Reglas PHONY
.PHONY: all clean fclean re

## Nombre del programa
#TARGET = minishell
#
## Compilador
#CC = clang
#
## Directorios de los archivos de encabezado, archivos objeto y bibliotecas
#INCLUDE_DIR = ./include
#LIBFT_DIR = ./libft
#READLINE_DIR = ./readline
#OBJ_DIR = ./objs
#
## Directorio de los archivos fuente
#SRC_DIR = ./src
#
## Opciones de compilación
#CFLAGS = -g -Wall -Wextra -Werror #-fsanitize=address
#
## bibliotecas
#LIBFT = $(LIBFT_DIR)/libft.a
#READLINE = $(READLINE_DIR)/libreadline.a $(READLINE_DIR)/libhistory.a
#
## Bibliotecas adicionales necesarias
#LIBS = -lreadline -ltermcap
#
## Archivos fuente
#SOURCES = $(addprefix $(SRC_DIR)/, minishell.c \
#									arr2d/add_one_arr2d.c \
#									arr2d/dup_arr2d.c \
#									arr2d/free_arr2d.c \
#									arr2d/size_arr2d.c \
#									arr2d/rm_one_arr2d.c \
#									utils_libft.c \
#									tokenizer.c)
#
## Archivos objeto generados por el compilador
#OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
#DEPS = $(OBJECTS:.o=.d)
#
## Directorios de los archivos de dependencias
#DEPDIRS = $(OBJ_DIR)/arr2d
#
## Incluir archivos de encabezado
#INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR) -I$(READLINE_DIR)
#
## Regla por defecto, compilación del programa
#all: $(TARGET)
#
## Regla para compilar el programa
#$(TARGET): $(LIBFT) $(READLINE) $(OBJECTS)
#	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ $(LIBFT) $(READLINE) $(LIBS)
#
## Regla para compilar cada archivo fuente
#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEPDIRS)
#	@$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@
#
## Regla para crear los directorios de dependencias si no existen
#$(DEPDIRS):
#	@mkdir -p $(DEPDIRS)
#
## Regla para construir la biblioteca libft
#$(LIBFT):
#	@make -C $(LIBFT_DIR)
#
## Regla para construir la biblioteca readline
#$(READLINE):
#	@make -C $(READLINE_DIR)
#
## Regla para limpiar archivos temporales y el programa compilado
#clean:
#	@rm -rf $(OBJ_DIR)
#	@make -C $(LIBFT_DIR) clean
#	@make -C $(READLINE_DIR) clean
#
## Regla para limpiar archivos temporales y el programa compilado
#fclean: clean
#	@rm -f $(TARGET)
#	@make -C $(LIBFT_DIR) fclean
#
## Regla para reconstruir el proyecto desde cero
#re: fclean all
#
## Crea el directorio de objetos si no existe
#$(OBJ_DIR):
#	@mkdir -p $(OBJ_DIR)
#
## Incluye las dependencias
#-include $(DEPS)
#
## Reglas PHONY
#.PHONY: all clean fclean re
