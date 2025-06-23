/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:45 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:28:15 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trasla(char *line, char *buf)
{
	char	*temp;
	char	*newline_pos;
	size_t	remaining_len;

	newline_pos = ft_strchr(buf, '\n');
	if (newline_pos != NULL)
	{
		temp = ft_substr(buf, 0, (newline_pos - buf + 1));
		line = ft_strjoingnl(line, temp);
		free(temp);
		remaining_len = ft_strlen(newline_pos + 1);
		ft_memmove(buf, newline_pos + 1, remaining_len + 1);
	}
	return (line);
}

char	*ft_recalloc(char *buf, char *line, int fd)
{
	int	bytes_read;

	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && ft_strchr(buf, '\n') == NULL)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
		buf[bytes_read] = 0;
		if (bytes_read == 0)
			return (line);
		if (ft_strchr(buf, '\n') == NULL)
		{
			line = ft_strjoingnl(line, buf);
			buf[0] = '\0';
		}
		else
			return (ft_trasla(line, buf));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (ft_strlen(buf) > 0)
	{
		if (ft_strchr(buf, '\n') != NULL)
			return (ft_trasla(line, buf));
		line = ft_strjoingnl(line, buf);
		buf[0] = '\0';
	}
	return (ft_recalloc(buf, line, fd));
}
/* 
int	main(int argc, char **argv)
{
    int		fd;

    fd = open(argv[1], O_RDONLY);
    if (argc != 2)
    {
		write(1, "\n", 1);
	    return (1);
	}
	else
    {
        char *line = get_next_line(fd);
        while (line)
        {
            printf("[%s]", line);
            free(line);
            line = get_next_line(fd);
        }
		// get_next_line(fd);
    //    get_next_line(fd);
    }
    close(fd);    
    return (0);
} */

/* int	main()
{
    int		fd;

    fd = 0;
	char *line = get_next_line(fd);
	while (line)
	{
		printf("[%s]", line);
		free(line);
		line = get_next_line(fd);
	}
    close(fd);    
    return (0);
} */
