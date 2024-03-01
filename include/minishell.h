/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocuni-p <jocuni-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:22:25 by jocuni-p          #+#    #+#             */
/*   Updated: 2024/03/01 15:33:45 by jocuni-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"

typedef struct s_token
{
	char	*value;
	int		keyword;//no se si el enum deberia ser un int o un char 
	int		position;
}			t_token;

DEFINIR LOS ENUMS QUE SERAN LOS DIFERENTES TIPOS DE KEYWORDS (no se si char o int)

char	**env_cpy(char *e[]);

//char	*ft_strdup(const char *s1);
//void	*ft_memcpy(void *dst, const void *src, size_t n);
//size_t	ft_strlen(const char *s);

#endif