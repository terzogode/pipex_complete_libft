/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 18:30:46 by mbrighi           #+#    #+#             */
/*   Updated: 2025/03/28 17:15:55 by mbrighi          ###   ########.fr       */
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
void	*pathfinder(char *cmd, char **envp);
void	child(char **argv, pid_t *pid1, char **envp);
void	daddy(char **argv, pid_t *pid1, char **envp);
void	exeggcute(const char *argv, char **envp);

//utils
void	error(void);
void	errorcmd(void);
void	errorexec(char **command);
void	*freepath(char **first_path);
int		open_file(char *file, int in_or_out, int *mfd);

#endif
