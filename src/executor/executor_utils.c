/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:49:03 by fde-mour          #+#    #+#             */
/*   Updated: 2024/07/02 15:55:32 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	simple_execute(t_shell *shell)
{
	int	status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_putstr_fd("minishell: fork failed, no child has been created", shell->table->errfile);
	else if (pid == 0) //The command happens in the child process
	
}

void	execute_in_child(t_shell *shell)
{
	
}