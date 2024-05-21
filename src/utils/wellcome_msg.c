#include "minishell.h"

/*----Wellcome message-----*/
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
	//printf(CYAN);
}

/*Function that changes the color of the terminal*/

int	bg_color(void)
{
	printf(BLUE);
	printf(CLEAN_SCREEN);
	return (0);
}