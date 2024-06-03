/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:15:26 by fde-mour          #+#    #+#             */
/*   Updated: 2024/06/01 16:41:01 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	unset(t_shell *shell)
{
	char	**args;
	char	**tmp;
	int		i;

	i = 1;
	args = shell->table->cmd->args;
	if (unset_error(shell, args) == 1)
		return (EXIT_FAILURE);
	else
	{
		while (args[i] != NULL)
		{
			tmp = del_var(shell->env, args[i]);
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
		ft_putendl_fd("minishell: unset: not enough arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	while (args[i] != NULL) //Verify start for each argument
	{
		if (ft_strlen(args[i]) == 0 || args[i][0] == '?' || args[i][0] == '$')
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(args[i], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		else if ((arg[i][0] >= 48 && arg[i][0] <= 57) || invalid_chars(arg[i]) == 1)
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(args[i], STDERR_FILENO);
			ft_putendl_fd("': invalid parameter name", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCESS);
		
}
