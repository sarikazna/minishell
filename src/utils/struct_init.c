/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:48:49 by srudman           #+#    #+#             */
/*   Updated: 2024/07/23 16:42:27 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// TO DO: Double check that all the variables in the structs are initialised

void	init_cmd(t_cmd **cmd)
{
	*cmd = malloc(sizeof(t_cmd));
	if (!(*cmd))
	{
		free(*cmd);
		// memory allocation failure and error management
		exit(EXIT_FAILURE); // to change
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
		// memory allocation failure and error management
		exit(EXIT_FAILURE); // to change
	}
	(*table)->infile = STDIN_FILENO;
	(*table)->outfile = STDOUT_FILENO;
	(*table)->errfile = STDERR_FILENO;
	(*table)->infile_valid = true;
	(*table)->outfile_valid = true;
	(*table)->pipes = 0;
	init_cmd(&((*table)->cmd));
}

void	init_shell(t_shell **shell)
{
	//int	i;

	*shell = malloc(sizeof(t_shell));
	if (!(*shell))
	{
		free(*shell);
		// memory allocation failure and error management
		exit(EXIT_FAILURE); // to change
	}
	//i = 0;
	/*while(i < 100)
	{
		(*shell)->env[i] = NULL;
		i++;
	}*/
	(*shell)->env_exists = false;
	(*shell)->prompt = NULL;
	(*shell)->directory = NULL;
	(*shell)->heredoc = NULL;
	init_table(&((*shell)->table));
}
