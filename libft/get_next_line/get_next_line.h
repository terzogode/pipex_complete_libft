/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:47 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/02 12:38:18 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

//get_next_line
void			*ft_memmovegnl(void *dest, char *src, size_t n);
char			*ft_trasla(char *line, char *buf);
char			*ft_recalloc(char *buf, char *line, int fd);
char			*get_next_line(int fd);

//get_next_line_utils
size_t			ft_strlengnl(const char *s);
char			*ft_strjoingnl(char *s1, char *s2);
char			*ft_substrgnl(char const *s, unsigned int start, size_t len);
char			*ft_strchrgnl(const char *s, int c);
char			*ft_strdupgnl(const char *s);

#endif
