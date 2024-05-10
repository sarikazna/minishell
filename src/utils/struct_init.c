/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:48:49 by srudman           #+#    #+#             */
/*   Updated: 2024/05/10 16:15:10 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/minishell.h"


void init_cmd(t_cmd **cmd)
{
	*cmd = malloc(sizeof(t_cmd));
	if (!(*cmd))
	{
		free(*cmd);
		// put error that memory failed
	}
	(*cmd)->prev = NULL;
	(*cmd)->next = NULL;
	(*cmd)->builtin = false;
	(*cmd)->path = NULL;
	(*cmd)->cmd_arg = NULL;
	(*cmd)->args = NULL;
	(*cmd)->skip_cmd = false;
}

void	init_table(t_table **table)
{
	*table = malloc(sizeof(t_table));
	if (!(*table))
	{
		free(*table);
		// put error that memory failed
	}
	(*table)->infile = STDIN_FILENO;
	(*table)->outfile = STDOUT_FILENO;
	(*table)->errfile = STDERR_FILENO;
	(*table)->infile_valid = true;
	(*table)->outfile_valid = true;
	(*table)->pipes = 0;
	init_cmd(&((*table)->cmd));
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
	init_table(&(shell->table));
}