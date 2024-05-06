/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipemfbgomes <filipemfbgomes@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:21:04 by fde-mour          #+#    #+#             */
/*   Updated: 2024/05/06 18:02:42 by filipemfbgo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/*Function to create the prompt*/
void	prompt(t_shell *shell)
{
	char	*half;
	char	*final;
	char	*user;
	char	*half2;
	char	*half3;

	if (shell->prompt != NULL)
		free(shell->prompt);
	user = ft_strjoin(get_env_var(shell, "USER=") + 5, "@"); //1st username + @
	half = ft_strjoin_modified(user, get_env_var(shell, "HOSTNAME=") + 8); //username@ + logname
	half2 = ft_strjoin(half, ":~"); //username@logname + :~
	half3 = ft_strjoin_modified(half2, get_env_var(shell, "PWD=") + 4); //username@logname:~ + path
	final = ft_strjoin(half3, "$"); //username@logname:~path + $
	free(half);
	free(half3);
	shell->prompt = "on";
}

/*Aditional function to help find the current directory*/
char	*get_curr_dir(t_shell *shell)
{
	int		i;
	char	*directory;
	char	*pwd;

	i = 0;
	pwd = get_env_var(shell, "PWD=");
	
}

char	*get_env_var(t_shell *shell, char *var)
{
	int		i;
	char	*env_var;

	i = 0;
	while (shell->env[i] != NULL)
	{
		if (ft_strncmp(var, shell->env[i], ft_strlen(var)) == 0)
		{
			env_var = ft_strdup(shell->env[i]);
			return (env_var);
		}
		i++;
	}
	return (NULL);
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