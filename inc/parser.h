/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:38:29 by srudman           #+#    #+#             */
/*   Updated: 2024/07/08 16:10:54 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdbool.h>
# include "minishell.h"

/* STRUCTS*/

typedef struct s_cmd t_cmd;

/* A part of the final command table where all the command details are stored*/
typedef struct s_cmd
{
	t_cmd	*prev;
	t_cmd	*next; // in a pipe, there will be more than one command. Default value = NULL;
	bool	builtin; // default is false
	// pointer to builtin struct?
	char	**path;	// path by the environment {/usr/bin, /sbin/bin,...}. Default value = NULL;
	char	**cmd_arg; // includes the command and flags, e.g. "cat -c" {cat, -c}. Default value = NULL;
	char	**args; // some commands contain certain arguments, e.g. "echo "hello world"". Default value = NULL;
	bool	skip_cmd; // in case it's already proven to be invalid. Default value = false;
}	t_cmd;

/* Final command table provided by the parser to the executor*/
typedef struct s_table
{
	t_cmd	*cmd;
	int		infile; // Default value = STDIN_FILENO, but can be redirected to some other infile
	int		outfile; // Default value = STDOUT_FILENO, but can be redirected to some other outfile
	int		errfile; // Default value = STDERR_FILENO, but can be redirected to some other errfile
	bool	infile_valid; // not needed? true
	bool	outfile_valid; // not needed? true
	int		pipes; // default 0
}	t_table;

typedef struct s_shell
{
	char	*env[100]; // enivronemtn needed for excve(___, ____, **env);
	bool	env_exists; // yes/ no, default yes
	char	*prompt;
	char	*directory;
    char	*heredoc; // int or char?
	int		exit_code;
	t_table *table;
}   t_shell;

#endif