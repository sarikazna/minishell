/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:06:59 by fde-mour          #+#    #+#             */
/*   Updated: 2024/07/22 16:44:11 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

/*This function will check if the flag "-n" is valid and
checks it's expansion like "-nnnnn" which is valid too*/
bool	is_flag_valid(char	*flag)
{
	int	i;
	
	if (ft_strncmp(flag, "-n", 2) == 0)
	{
		i = 1; //flag[0] is "-"
		while (flag[i] != '\0')
		{
			if (flag[i] == 'n')
				i++;
			else
				return (FALSE);
		}
		return (TRUE);
	}
	return (FALSE);
}

/*Find how many n's are in the flag/
how many flags are in the command or
if it's only the flag and no other thing*/
int echo_n_flag(char **cmd_args, char **args)
{
	int i;
	
	i = 1; //Starts on 1 because we want to skip echo
	while (cmd_args[i] != NULL)
	{
		if (is_flag_valid(cmd_args[i]) == TRUE)
		{
			if (has_content(args) == FALSE)
				return (TRUE);
			i++;
		}
		else
			return (i + 1);
	}
	return (i + 1);
}

void	handle_flag(char **args, char **cmd_args)
{
	int i;
	
	i = echo_n_flag(args, cmd_args);
	if (i == TRUE) //If it's only flags, prints empty string
		write(1, "", 1);
	else
	{
		i = 0;
		while (args[i] != NULL)
		{
			echo_print(args[i], 0, 0, 0);
			if (args[i + 1] != NULL)
				write(1, " ", 1);
			i++;
		}
	}
}

void	my_echo(char **args)
{
	int	j;

	j = 0;
	while (args[j] != NULL)
	{
		echo_print(args[j], 0, 0, 0);
		if (args[j + 1] != NULL && is_special_filled(args[j]) != TRUE)
			write(1, " ", 1);
		else if (args[j + 1] != NULL && is_special_filled(args[j]) == TRUE && is_special_filled(args[j + 1]) == TRUE)
			write(1, " ", 1);
		j++;
	}
	write(1, "\n", 1);
}

void	run_echo(t_shell *shell, char **args, char **cmd_args)
{
	//char	**args;
	//char **cmd_flag;

	//args = shell->table->cmd->args;
	//cmd_flag = shell->table->cmd->cmd_arg;
	(void)shell;
	if (ft_strncmp(cmd_args[0], "echo", 4) == 0 && (args[0] == NULL || args[0][0] == '\0') && (cmd_args[1] == NULL))
		write(1, "\n", 1);
	else if (cmd_args[1] != NULL && is_flag_valid(cmd_args[1]) == TRUE)
		handle_flag(args, cmd_args);
	else
	{
		if (cmd_args[1] != NULL)
			echo_print(cmd_args[1], 0, 0, 0);
		my_echo(args);
	}
}
