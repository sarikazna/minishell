/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srudman <srudman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 17:12:15 by srudman           #+#    #+#             */
/*   Updated: 2024/05/03 18:33:32 by srudman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/* The program ./minishell does not accept any arguments to that is reviewed 
in arg_checker() function. 
init() initialises the struct t_table data to it's default values.
We also need to keep minishell "alive" so we implement
minishell loop using while (1). */

int	main(int argc, char **argv, char **envp)
{
	t_table data;
	
	arg_checker(argc, argv); // checker to run ./minishell
	ft_putstr_fd("\nFilipe and Sara welcome you to minishell\n", STDOUT_FILENO);
    while (1) // minisehll loop
    {
		init_data(&data);
		// signal handling - Filipe to do
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