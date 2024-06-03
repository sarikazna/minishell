/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:20:22 by fde-mour          #+#    #+#             */
/*   Updated: 2024/06/03 15:06:27 by filipemfbgo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	builtins(t_shell *shell)
{
	char	**cmd_arg;

	cmd_arg = shell->table->cmd->cmd_arg;
	if (ft_strcmp(cmd_arg[0], "echo") == TRUE) //Add if skip == false + if built-in or not
		return (echo(shell, shell->table->cmd->args));
	else if (ft_strcmp(cmd_arg[0], "export") == TRUE)
		return (export(shell));
	else if (ft_strcmp(cmd_arg[0], "env") == TRUE)
		return (env(shell));
	else if (ft_strcmp(cmd_arg[0], "unset") == TRUE)
		return (unset(shell));
	else if (ft_strcmp(cmd_arg[0], "exit") == TRUE)
		return (ft_exit(shell));
	else if (ft_strcmp(cmd_arg[0], "pwd") == TRUE)
		return (pwd(shell));
	else if (ft_strcmp(cmd_arg[0], "cd") == TRUE)
		return (cd(shell));
}