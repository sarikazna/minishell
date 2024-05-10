/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:48:49 by srudman           #+#    #+#             */
/*   Updated: 2024/05/10 14:18:53 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/minishell.h"

void init_cmd(t_table *table)
{
	table->cmd = malloc(sizeof(t_cmd));
	if (!table->cmd)
	{
		free(table->cmd);
		// put error that memory failed
	}
	table->cmd->prev = NULL;
	table->cmd->next = NULL;
	table->cmd->builtin = false;
	table->cmd->path = NULL;
	table->cmd->cmd_arg = NULL;
	table->cmd->args = NULL;
	table->cmd->skip_cmd = false;
}

void	init_table(t_table *table)
{
	table = malloc(sizeof(t_table));
	if (!table)
	{
		free(table);
		// put error that memory failed
	}
	table->infile = STDIN_FILENO;
	table->outfile = STDOUT_FILENO;
	table->errfile = STDERR_FILENO;
	table->infile_valid = true;
	table->outfile_valid = true;
	table->pipes = 0;
	init_cmd(table);
}

void	init_shell(t_shell *shell)
{
	int	i;
	
	shell = malloc(sizeof(t_shell));
	if (!shell)
	{
		free(shell);
		// put error that memory failed
	}
	i = 0;
	while (i < 100)
	{
		shell->env[i] = NULL;
		i++;
	}
	shell->env_exists = true;
	shell->prompt = NULL;
	shell->directory = NULL;
	shell->heredoc = NULL;
	init_table(shell->table);
}