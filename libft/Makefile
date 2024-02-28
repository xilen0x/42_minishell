# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: castorga <castorga@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 11:59:47 by castorga          #+#    #+#              #
#    Updated: 2023/06/16 10:20:38 by castorga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ----------------- Variables ---------------------
NAME = libft.a

OBJ_DIR = ./obj/

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	  ft_isascii.c ft_isprint.c ft_strlen.c \
	  ft_memset.c ft_bzero.c ft_memcpy.c \
	  ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c \
	  ft_strrchr.c ft_strncmp.c ft_memchr.c \
	  ft_memcmp.c ft_strnstr.c ft_atoi.c \
	  ft_calloc.c ft_strdup.c ft_substr.c \
	  ft_strjoin.c ft_strtrim.c ft_split.c \
	  ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c 

SRCBONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		   ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		   ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJBONUS = $(addprefix $(OBJ_DIR), $(SRCBONUS:.c=.o))

DEPS = $(addsuffix .d, $(basename $(OBJ)))
MK = mkdir -p

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -I ./

CC = cc

HEADER = libft.h

# -------------------- Rules --------------------
#SRC = $(patsubst %,%.c,$(myFunctions))
#OBJS = $(patsubst %,%.o,$(myFunctions))

#Regla para construir archivos objeto a partir de los archivos fuente .c.
$(OBJ_DIR)%.o: %.c Makefile
	@echo "Compiling... $<"
	@$(MK) $(dir $@)
	@$(CC) $(CFLAGS) -MMD $(INCLUDE) -c $< -o $@

#Regla principal para construir el archivo de biblioteca principal libft.a.
all: $(NAME)

#Regla para construir el archivo de biblioteca principal libft.a utilizando 
# los archivos objeto y el archivo de encabezado.
$(NAME): $(OBJ) $(HEADER)
	@echo "Building... $@"
	ar rcs $(NAME) $(OBJ)

bonus: .bonus

.bonus: $(OBJBONUS)
		@echo "Building bonus..."
		ar rcs $(NAME) $(OBJBONUS)
		@touch .bonus


-include $(DEPS)

# -------------------- Clean --------------------
clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

#Al declarar estos objetivos como .PHONY, se garantiza que las reglas
# asociadas se ejecuten independientemente de si hay un archivo con el
# mismo nombre o no.
.PHONY: all clean fclean re bonus
