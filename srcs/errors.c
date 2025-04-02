/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:22:24 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/02 12:38:49 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	close(0);
	close(1);
	perror("Bru, you let it blank");
	exit(1);
}

void	errorcmd(void)
{
	perror("Bruh, really? Give me a command or a path, but let's say it");
	exit(1);
}

void	errorexec(char **command)
{
	int	index;

	index = 0;
	if (command[index] && command[index] != NULL)
	{
		while (command[index] != NULL)
		{
			if (command[index] != NULL)
				free(command[index]);
			index++;
		}
	}
	if (command != NULL)
		free(command);
	error();
}
