/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:38:29 by srudman           #+#    #+#             */
/*   Updated: 2024/05/06 14:46:25 by filipemfbgo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
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
	char	*heredoc; // int or char?
}	t_table;

typedef struct s_shell
{
	char	**env; // enivronemtn needed for excve(___, ____, **env);
	bool	env_exists; // yes/ no, default yes
	char	*username; //Username 
	char	*prompt;
	char	*directory;
	t_table *table;
	
	
}

#endif