/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wellcome_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: castorga <castorga@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:57:16 by castorga          #+#    #+#             */
/*   Updated: 2024/05/27 16:57:18 by castorga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----help message-----*/
int	help_mini(void)
{
	printf("\n%s█████████████████████████████████████████████████████████████ %s\n", CYAN, END);
	printf("\n%s█ 42 minishell, version 0.1-release (x86_64-apple-darwin19) █%s\n", CYAN, END);
	printf("\n%s█ Developed by jocuni-p & castorga                          █%s\n", CYAN, END);
	printf("\n%s█████████████████████████████████████████████████████████████ %s\n\n", CYAN, END);
	return (0);
}

/*----Welcome message-----*/
void	init_msg(void)
{
	printf("\n%s\
			██    ██ █ █    █ █  ████ █     █  ██████   █     █ %s\n", \
			CYAN, END);
	printf("%s\
			█  █   █ █ █ █  █ █ █     █     █  █        █     █%s \n", \
			CYAN, END);
	printf("%s\
			█  █   █ █ █  █ █ █ ███   ███████  ██████   █     █%s \n", \
			CYAN, END);
	printf("%s\
			█      █ █ █    █ █     █ █     █  █        █     █%s\n", \
			CYAN, END);
	printf("%s\
			█      █ █ █    █ █ ████  █     █  ██████   █████ █████ %s\n", \
			CYAN, END);
	printf("%s\n\t\tby jocuni-p & castorga%s\t\t\t\n", CYAN, \
		END);
	printf("\t\n\n");
}

/*Function that changes the color of the terminal*/
int	bg_color(void)
{
	printf(BLUE);
	printf(CLEAN_SCREEN);
	return (0);
}
