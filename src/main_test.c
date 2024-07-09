/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 14:06:12 by fde-mour          #+#    #+#             */
/*   Updated: 2024/07/09 18:57:51 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/minishell.h"

void	print_double_pointer(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell *shell;
	char *args[] = { "echo", "Boas", NULL }; 
	
	arg_checker(argc, argv);
	ft_putstr_fd("\nFilipe and Sara welcome you to minishell\n", STDOUT_FILENO);
	init_shell(&shell);
	env_handling(shell, envp);
	run_echo(shell, args);
	return (0);
}