/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:48:49 by srudman           #+#    #+#             */
/*   Updated: 2024/05/03 17:53:32 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_data(t_table *data)
{
	data = malloc(sizeof(t_table));
	if (!data)
	{
		free(data);
		// put error that memory failed
	}
	infile = STDIN_FILENO;
	outfile = STDOUT_FILENO;
	errfile = STDERR_FILENO;
	infile_valid = true;
	otufile_valid = true;
	pipes = 0;
	env = NULL;
	env_exists = true;
	heredoc = NULL;
	prompt = NULL;
	init_cmd(data);
}

void init_cmd(t_table *data)
{
	data.cmd = malloc(sizeof(t_cmd));
	if (!data.cmd)
	{
		free(data.cmd);
	}
	data.cmd.prev = NULL;
	data.cmd.next = NULL;
	data.cmd.builtin = false;
	data.cmd.path = NULL;
	data.cmd.cmd_arg = NULL;
	data.cmd.args = NULL;
	data.cmd.skip_cmd = false;
}