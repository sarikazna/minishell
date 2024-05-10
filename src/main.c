/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:12:15 by srudman           #+#    #+#             */
/*   Updated: 2024/05/10 18:24:43 by filipemfbgo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/minishell.h"

/* The program ./minishell does not accept any arguments to that is reviewed 
in arg_checker() function. 
init() initialises the struct t_table data to it's default values.
We also need to keep minishell "alive" so we implement
minishell loop using while (1). */

int	main(int argc, char **argv, char **envp)
{
	t_shell *shell;
	
	// loop inspiration> https://github.com/Alice-inNovember/42_Minishell/blob/main/srcs/main.c#L35
	arg_checker(argc, argv); // checker to run ./minishell
	ft_putstr_fd("\nFilipe and Sara welcome you to minishell\n", STDOUT_FILENO);
	init_shell(&shell);
	env_handling(shell, envp);
    while (1) // minishell loop
    {
		signals(); // signal handling - Filipe to do
		prompt(shell); // prompt - Filipe
		readline(shell->prompt);
		// enviroment - Sara to do
		// customer terminal promt - Filipe to do
		// readline - Sara to do
		// at the prompt to history - Filipe to do
		// lexer - Sara to do
		// parser - Sara to do
		// executor - Filipe to do
		// error handling
		// clear data
		(void)envp;
	}
	return (0);
}

