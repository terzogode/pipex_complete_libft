/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:59:01 by mbrighi           #+#    #+#             */
/*   Updated: 2025/03/25 16:48:52 by mbrighi          ###   ########.fr       */
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

void	errorexec(char **command, char *path)
{
	int	index;

	index = -1;
	free(path);
	while (command[++index])
		free(command[index]);
	free(command);
	error();
}

void	*freepath(char **first_path)
{
	int	i;

	i = -1;
	while (first_path[++i])
		free (first_path[i]);
	free (first_path);
	return (NULL);
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
	{
		perror("Can't touch this");
		exit(1);
	}
	return (ret);
}
