/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:48:49 by srudman           #+#    #+#             */
/*   Updated: 2024/05/06 14:49:45 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// init t_shell is needed instead of t_table

void	init_data(t_table *data)
{
	data = malloc(sizeof(t_table));
	if (!data)
	{
		free(data);
		// put error that memory failed
	}
	data->infile = STDIN_FILENO;
	data->outfile = STDOUT_FILENO;
	data->errfile = STDERR_FILENO;
	data->infile_valid = true;
	data->outfile_valid = true;
	data->pipes = 0;
	data->env = NULL;
	data->env_exists = true;
	data->heredoc = NULL;
	data->prompt = NULL;
	init_cmd(data);
}

void init_cmd(t_table *data)
{
	data->cmd = malloc(sizeof(t_cmd));
	if (!data->cmd)
	{
		free(data->cmd);
	}
	data->cmd->prev = NULL;
	data->cmd->next = NULL;
	data->cmd->builtin = false;
	data->cmd->path = NULL;
	data->cmd->cmd_arg = NULL;
	data->cmd->args = NULL;
	data->cmd->skip_cmd = false;
}