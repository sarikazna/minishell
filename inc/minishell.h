/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:21:35 by srudman           #+#    #+#             */
/*   Updated: 2024/04/27 21:42:51 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h> // can we use this, Filipe?
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <errno.h>
# include <string.h> // needed?
# include <sys/types.h> // needed?
# include <dirent.h> // neeed?
# include <sys/wait.h>
# include "../libft/libft.h"
# include "parser.h"
# include "utils.h"
# include "error.h"
# include "lexer.h"
# include "builtins.h"
# include "executor.h"


#endif