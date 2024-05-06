/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:21:35 by srudman           #+#    #+#             */
/*   Updated: 2024/05/06 19:07:16 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <errno.h>
# include <string.h> // needed for strerror
# include <sys/types.h> // needed?
# include <dirent.h> // neeed for pwd
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/ioctl.h> // needed for ioctl
# include <termios.h>
# include <stdbool.h>
# include <curses.h>
# include <term.h>
# include "../libft/libft.h"
# include "parser.h"
# include "utils.h"
# include "error.h"
# include "lexer.h"
# include "builtins.h"
# include "executor.h"

typedef struct s_shell
{
	char	*env[100]; // enivronemtn needed for excve(___, ____, **env);
	bool	env_exists; // yes/ no, default yes
	char	*prompt;
	char	*directory;
    char	*heredoc; // int or char?
	t_table *table;
}   t_shell

#endif