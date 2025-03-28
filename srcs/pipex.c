/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:22:19 by mbrighi           #+#    #+#             */
/*   Updated: 2025/03/28 17:49:45 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*pathfinder(char *cmd, char **envp)
{
	int		i;
	char	*final_path;
	char	**first_path;
	char	*cmonanotherpath;

	i = 0;
	if (!cmd || !envp)
		return (NULL);
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	first_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (first_path[i])
	{
		cmonanotherpath = ft_strjoin(first_path[i], "/");
		final_path = ft_strjoin(cmonanotherpath, cmd);
		free (cmonanotherpath);
		if (access(final_path, F_OK | X_OK) == 0)
			return (freepath(first_path), final_path);
		free (final_path);
		i++;
	}
	if (access(cmd, F_OK | X_OK | R_OK ) == 0)
		return (freepath(first_path), ft_strdup(cmd));
	return (freepath(first_path), NULL);
}

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
	path = pathfinder(command[0], envp);
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
