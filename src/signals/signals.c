/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:10:29 by fde-mour          #+#    #+#             */
/*   Updated: 2024/07/08 15:23:20 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*Go back here when doing heredocs, cuz we might need a variable 
to store when control+c is pressed*/

/*Function is called when control+c is pressed*/
void	handle_sigint(int sig_num)
{
	if (sig_num == SIGINT) //Signal Interrupts
	{
		write(1, "\n", 2);
		rl_on_new_line(); //Moves the input prompt to a new line
		rl_replace_line("", 0); //Clears the first line of the input prompt. 0 is the number of characters to replace so it means the entire line will be replaced
		rl_redisplay(); //Refreshes the display of the input line, reflecting any changes made to it since the last time it was displayed.
	}
}

/*What this function does is basically calls the function "handle_sigint" when captures the control_c signal
When control+c is pressed, it should display the prompt in a new line */
void	signal_ctrl_c(void)
{
	struct sigaction	ctrl_c;

	ctrl_c.sa_handler = handle_sigint;
	ctrl_c.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_c.sa_mask);
	sigaction(SIGINT, &ctrl_c, NULL);
}

/*What this function does is basically calls the function "SIG_IGN" when captures the control_c signal 
When control+/ is pressed, it should do nothing*/
void	signal_ctrl_slash(void)
{
	struct sigaction	ctrl_slash;

	ctrl_slash.sa_handler = SIG_IGN; //Signal ignore
	ctrl_slash.sa_flags = SA_RESTART;
	sigemptyset(&ctrl_slash.sa_mask);
	sigaction(SIGQUIT, &ctrl_slash, NULL);
}

void	signals(void)
{
	signal_ctrl_slash();
	signal_ctrl_c();
}