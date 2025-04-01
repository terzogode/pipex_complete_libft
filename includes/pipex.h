/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:30:46 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/01 19:06:18 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h> 
# include <sys/stat.h>
# include "../libft/libft.h"

//pipex
void	child(char **argv, pid_t *pid1, char **envp);
void	daddy(char **argv, pid_t *pid1, char **envp);
void	exeggcute(const char *argv, char **envp);

//utils
void	*freepath(char **first_path);
int		open_file(char *file, int in_or_out, int *mfd);
char	*ft_strjoingnl(char *s1, char *s2);
void	*pathfinder(char *cmd, char **envp);
char	*alt_access(char *cmd, char *path);

//errors
void	error(void);
void	errorcmd(void);
void	errorexec(char **command);

#endif
