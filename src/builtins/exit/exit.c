/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:18:11 by fde-mour          #+#    #+#             */
/*   Updated: 2024/06/03 17:55:49 by filipemfbgo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_exit(t_shell	*shell)
{
	char	**cmd_arg;
	int		exit_code;
	
	args = shell->table->cmd->cmd_arg;
	if (ft_strcmp(cmd_arg[0], "exit") == TRUE && cmd_arg[1] == NULL)
			normal_exit(shell);
	if (ft_strcmp(cmd_arg[0], "exit") == TRUE && cmd_arg[1] != NULL && cmd_arg[2] != NULL)
	{
			ft_putstr_fd("minishell: exit: too many arguments\n", shell->table->errfile);
			return (EXIT_FAILURE);
	}
	else if (cmd_arg[2] == NULL && cmd_arg[1] != NULL)
			exit_code(shell, args);
}

void	normal_exit(t_shell *shell)
{
	ft_putendl_fd("exit", shell->table->errfile);
	//function to free
	exit(0);
}

void exit_code(t_shell *shell, char **args)
{
	int		i;
	int 	len;
	int 	code;
	
	i = ;
	len = ft_strlen(args[1]);
	if (is_code_correct(shell, args[1]) == 1)
		code = shell->exit_code;
	else
	{
		code = 255;
		ft_putendl_fd("exit", shell->table->errfile);
		ft_putstr_fd("exit: ", shell->table->errfile);
		ft_putstr_fd(args[1], shell->table->errfile);
		ft_putstr_fd(": numeric argument required\n", shell->table->errfile);
		//function to free
		exit(code);
	}
	//function to free
	exit(code);	
}


int	is_code_correct(t_shell *shell, char *arg)
{
	int i;
	int	result;
	int	sign;

	sign = 0;
	result = 0;
	i = 0;
	if (args[0] == '+')
		i++;
	if (args[0] == '-')
	{
		i++;;
		sign = -1;
	}
	while (args[i] != '\0')
	{
		if (args[i] < '0' || args[i] > '9')
			return (0);
		result = (result * 10) + (args[i] - '0');
		if (result > 255)
			result %= 256;
		i++;
	}
	if (sign == -1)
		result = 256 - result;
	shell->exit_code = result;
	return (1);
}
