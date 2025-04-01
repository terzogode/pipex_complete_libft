/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 20:59:01 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/01 19:06:37 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*freepath(char **first_path)
{
	int	i;

	if (!first_path)
		return (NULL);
	i = -1;
	while (first_path[++i])
		free (first_path[i]);
	free (first_path);
	return (NULL);
}

int	open_file(char *file, int in_or_out, int *mfd)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0777);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (ret == -1)
	{
		perror("Can't touch this");
		close(mfd[0]);
		close(mfd[1]);
		exit(1);
	}
	return (ret);
}

char	*ft_strjoingnl(char *s1, char *s2)
{
	int				is1;
	int				is2;
	unsigned char	*l;

	is1 = 0;
	is2 = 0;
	if (!s1)
		return (ft_strdup(s2));
	l = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!l)
		return (NULL);
	while (s1[is1])
	{
		l[is1] = s1[is1];
		is1++;
	}
	free (s1);
	while (s2[is2])
	{
		l[is1 + is2] = s2[is2];
		is2++;
	}
	l[is1 + is2] = '\0';
	return ((char *)l);
}

void	*pathfinder(char *cmd, char **envp)
{
	int		i;
	char	*final_path;
	char	**first_path;

	i = 0;
	if (!cmd || !envp)
		return (NULL);
	if (access(cmd, F_OK | X_OK | R_OK) == 0)
		return (ft_strdup(cmd));
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	first_path = ft_split(envp[i] + 5, ':');
	i = -1;
	while (first_path && first_path[++i])
	{
		final_path = alt_access(cmd, *first_path);
		if (final_path)
			return (freepath(first_path), final_path);
	}
	return (freepath(first_path), NULL);
}

char	*alt_access(char *cmd, char *path)
{
	char	*final_path;

	final_path = ft_strjoin(path, "/");
	final_path = ft_strjoingnl(final_path, cmd);
	if (access(final_path, F_OK | X_OK) == 0)
		return (final_path);
	return (NULL);
}
