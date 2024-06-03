/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-mour <fde-mour@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:21:04 by fde-mour          #+#    #+#             */
/*   Updated: 2024/05/20 16:28:45 by fde-mour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/minishell.h"

/*Function to create the prompt*/
// FILIPE TO FIX: In Sara's case, the prompt didn't fully appear srudman@=:~/home/srudman/minishell$
void	prompt(t_shell *shell)
{
	char	*half;
	char	*half2;
	char	*half3;
	char	*final;
	char	*user;

	if (shell->prompt != NULL)
		free(shell->prompt);
    if (shell->env_exists == true)
    {
        if ((get_env_var(shell, "USER=") != NULL) && (get_env_var(shell, "LOGNAME=") != NULL))
        {
	        user = ft_strjoin(get_env_var(shell, "USER=") + 5, "@"); //1st username + @
	        half = ft_strjoin_modified(user, get_env_var(shell, "HOSTNAME=") + 8); //username@ + logname
            half2 = ft_strjoin(half, ":~"); //username@logname + :~
            if (get_env_var(shell, "PWD=") != NULL)
             {
	            half3 = ft_strjoin_modified(half2, get_env_var(shell, "PWD=") + 4); //username@logname:~ + path
	            final = ft_strjoin(half3, "$ "); //username@logname:~path + $
                free(half3);
             }
                free(half);
        }
        else
        {
            final = "->  minishell: ";
        }
    }
    else
    {
        final = "->  minishell: ";
    }
	    shell->prompt = final;
}

/*int main() {
    // Example test array of environment variables
    char *test[] = {
        "PWD=/home/filipemfbgomes",
        "WAYLAND_DISPLAY=wayland-0",
        "LC_IDENTIFICATION=pt_PT.UTF-8",
        "QT_IM_MODULE=ibus",
        "LC_MEASUREMENT=pt_PT.UTF-8",
        "DESKTOP_SESSION=ubuntu",
        "XDG_MENU_PREFIX=gnome-",
        "OLDPWD=/home/filipemfbgomes",
        "USER=filipemfbgomes",
        "DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus",
        NULL // Last element must be NULL to indicate the end of the array
    };

    // Call the get_env_var2 function to retrieve an environment variable
    char *result = get_env_var2(test, "USER");

    // Print the result
    if (result != NULL) {
        printf("Environment variable: %s\n", result);
        free(result); // Free the memory allocated by ft_strdup
    } else {
        printf("Environment variable not found\n");
    }

    return 0;
}
*/