/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:50:23 by fde-mour          #+#    #+#             */
/*   Updated: 2024/06/03 14:51:30 by filipemfbgo      ###   ########.fr       */
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
		printf("Env command with too many arguments");
		return (EXIT_FAILURE)
	}
	while (shell->env[i])
	{
		ft_putendl_fd(shell->env[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
