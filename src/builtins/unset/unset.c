/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:15:26 by fde-mour          #+#    #+#             */
/*   Updated: 2024/07/09 15:48:47 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	unset(t_shell *shell)
{
	char	**cmd_arg;
	char	**tmp;
	int		i;

	i = 1;
	args = shell->table->cmd->cmd_arg;
	if (unset_error(shell, cmd_arg) == 1)
		return (EXIT_FAILURE);
	else
	{
		while (cmd_arg[i] != NULL)
		{
			tmp = del_var(shell->env, cmd_arg[i]);
			//free env;
			shell->env = tmp;
		}
	}
	return (EXIT_SUCESS);
}

int	unset_error(t_shell *shell, char **args)
{
	int	i;

	i = 0;
	if (args[1] == NULL)
	{
		ft_putendl_fd("unset: not enough arguments", shell->table->errfile);
		return (EXIT_FAILURE);
	}
	while (args[i] != NULL) //Verify start for each argument
	{
		if (ft_strlen(args[i]) == 0 || args[i][0] == '?' || args[i][0] == '$')
		{
			ft_putstr_fd("unset: `", shell->table->errfile);
			ft_putstr_fd(args[i], shell->table->errfile);
			ft_putendl_fd("': not a valid identifier", shell->table->errfile);
			return (EXIT_FAILURE);
		}
		else if ((arg[i][0] >= 48 && arg[i][0] <= 57) || invalid_chars(arg[i]) == 1)
		{
			ft_putstr_fd("unset: `", shell->table->errfile);
			ft_putstr_fd(args[i], shell->table->errfile);
			ft_putendl_fd("': invalid parameter name", shell->table->errfile);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCESS);
		
}
