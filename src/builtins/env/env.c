/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:50:23 by fde-mour          #+#    #+#             */
/*   Updated: 2024/06/03 17:44:55 by filipemfbgo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	env(t_shell *shell)
{
	int		i;
	char	**args;

	args = shell->table->cmd->args;
	i = 0;
	if (args[1] != NULL)
	{
		ft_putstr_fd("Env command with too many arguments", shell->table->errfile);
		return (EXIT_FAILURE)
	}
	while (shell->env[i])
	{
		ft_putendl_fd(shell->env[i], shell->table->outfile);
		i++;
	}
	return (EXIT_SUCCESS);
}
