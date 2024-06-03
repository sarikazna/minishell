/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:06:59 by fde-mour          #+#    #+#             */
/*   Updated: 2024/05/28 14:56:34 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	run_echo(t_shell *shell)
{
	char	**args;

	args = shell->table->cmd->args;
	if (ft_strcmp(args[0], "echo") == TRUE && args[1] == NULL)
		write(1, "\n", 1);
	else if (is_flag_valid(args[1]) == TRUE)
		handle_flag(args);
	else
		echo(shell, args);
}

/*This function will check if the flag "-n" is valid and
checks it's expansion like "-nnnnn" which is valid too*/
bool	is_flag_valid(char	*arg)
{
	int	i;
	
	if (ft_strcmp(arg, "-n") == TRUE)
		return (TRUE);
	else if (ft_strcmp(arg, "-n", 2) == TRUE)
	{
		i = 1; //arg[0] is "-"
		while (arg[i] != '\0')
		{
			if (arg[i] == 'n')
				i++;
			else
				return (FALSE);
		}
	}
	return (TRUE);
}

void	handle_flag(char **args)
{
	int i;
	
	i = echo_flag(args);
	if (i == TRUE); //If it's only flags, prints empty string
		write(1, "", 1);
	else
	{
		while (args[j] != NULL)
		{
			if (args[i + 1] != NULL)
				write(1, " ", 1);
			i++;
		}
	}
}

/*Find how many n's are in the flag or
how many flags are in the command or
if it's only the flag and no other variable*/
int echo_n_flag(char **args)
{
	int i;

	i = 1;
	while (args[i + 1] != NULL)
	{
		if (is_flag_valid(args[i]) == TRUE)
			i++;
		else
			return (i);
	}
	if (ft_strncmp(args[i], "-n", 2) == 0)
	{
		if (is_flag_valid(args[i]) == TRUE) //If it's only the flag and nothing else
			return (TRUE);
		else
			return (i);
	}
	return (i);
}

void	echo(t_shell *shell, char **args)
{
	int	j;

	j = 1;
	while (args[j] != NULL)
	{
		echo_print(args[j], 0, 0, 0);
		if (args[j + 1] != NULL && is_special_filled(args[j]) != TRUE)
			write(1, " ", 1);
		else if (args[j + 1] != NULL && is_special_filled(args[j]) == TRUE
			&& is_special_filled(args[j + 1]) == TRUE)
			write(1, " ", 1);
		j++;
	}
	write(1, "\n", 1);
}