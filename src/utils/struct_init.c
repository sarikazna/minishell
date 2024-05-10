/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:48:49 by srudman           #+#    #+#             */
/*   Updated: 2024/05/10 17:13:16 by srudman          ###   ########.fr       */
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

void init_table(t_table **table) {
    *table = malloc(sizeof(t_table));
    if (!(*table)) {
        // Handle memory allocation failure
        printf("Memory allocation failed for t_table\n");
        exit(EXIT_FAILURE);
    }

    // Initialize table members
    (*table)->infile = STDIN_FILENO;
    (*table)->outfile = STDOUT_FILENO;
    (*table)->errfile = STDERR_FILENO;
    (*table)->infile_valid = true;
    (*table)->outfile_valid = true;
    (*table)->pipes = 0;

    // Initialize cmd member of table
    init_cmd(&((*table)->cmd));
}

void init_shell(t_shell **shell) {
    int i;

    // Allocate memory for t_shell
    *shell = malloc(sizeof(t_shell));
    if (!(*shell)) {
        // Handle memory allocation failure
        printf("Memory allocation failed for t_shell\n");
        exit(EXIT_FAILURE);
    }

    // Initialize environment array
    for (i = 0; i < 100; i++) {
        (*shell)->env[i] = NULL;
    }
    (*shell)->env_exists = true;
    (*shell)->prompt = NULL;
    (*shell)->directory = NULL;
    (*shell)->heredoc = NULL;

    // Initialize t_table
    init_table(&((*shell)->table));
}
