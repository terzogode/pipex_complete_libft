/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:22:19 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/01 19:07:01 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, int *mfd, char **envp)
{
	int	fd;

	fd = open_file(argv[1], 0, mfd);
	dup2(fd, 0);
	close(fd);
	dup2(mfd[1], 1);
	close(mfd[0]);
	close(mfd[1]);
	exeggcute(argv[2], envp);
}

void	daddy(char **argv, int *mfd, char **envp)
{
	int	fd;

	fd = open_file(argv[4], 1, mfd);
	dup2(fd, 1);
	close(fd);
	dup2(mfd[0], 0);
	close(mfd[1]);
	close(mfd[0]);
	exeggcute(argv[3], envp);
	exit(1);
}

void	exeggcute(const char *argv, char **envp)
{
	char	*path;
	char	**command;

	command = ft_split(argv, ' ');
	if (!command)
		errorcmd();
	path = pathfinder(*command, envp);
	if (!path)
	{
		freepath(command);
		error();
	}
	execve(path, command, envp);
	free(path);
	errorexec(command);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	int		mfd[2];
	int		last_status;
	int		current_status;

	if (argc != 5)
		return (0);
	if (pipe(mfd) == -1)
		exit (1);
	pid1 = fork();
	if (pid1 == -1)
		exit (1);
	if (!pid1)
		child(argv, mfd, envp);
	pid1 = fork();
	if (pid1 == -1)
		exit(1);
	if (pid1 == 0)
		daddy(argv, mfd, envp);
	close(mfd[0]);
	close(mfd[1]);
	while (waitpid(-1, &current_status, 0) != -1)
		last_status = current_status;
	return (last_status);
}
