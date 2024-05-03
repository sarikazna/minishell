/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:38:29 by srudman           #+#    #+#             */
/*   Updated: 2024/05/03 15:17:47 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "minishell.h"

/* STRUCTS*/

/* Final command table provided by the parser to the executor*/
typedef struct s_table
{
	t_cmd	*cmd;
	int		infile; // Default value = 0, but can be redirected to some other infile
	int		outfile; // Default value = 1, but can be redirected to some other infile
	int		errfile; // Default value = 2, but can be redirected to some other infile
	bool	infile_valid; // not needed? true
	bool	outfile_valid; // not needed? true
	int		pipes; // default 0
	char	**env; // enivronemtn needed for excve(___, ____, **env);
	bool	env_exists; // yes/ no, default yes
	char	heredoc; // int or char?
	char	*prompt;
}	t_table;

/* A part of the final command table where all the command details are stored*/
typedef struct s_cmd
{
	t_cmd	*prev;
	t_cmd	*next; // in a pipe, there will be more than one command. Default value = NULL;
	bool	builtin; // no
	char	**path;	// path by the environment {/usr/bin, /sbin/bin,...}. Default value = NULL;
	char	**cmd_arg; // includes the command and flags, e.g. "cat -c" {cat, -c}. Default value = NULL;
	char	**args: // some commands contain certain arguments, e.g. "echo "hello world"". Default value = NULL;
	bool	skip_cmd; // in case it's already proven to be invalid. Default value = false;
}	t_cmd;

#endif