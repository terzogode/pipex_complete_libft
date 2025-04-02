/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:45 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/02 12:38:18 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmovegnl(void *dest, char *src, size_t n)
{
	unsigned char	*pd;
	unsigned char	*ps;
	size_t			k;

	pd = (unsigned char *)dest;
	ps = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (pd > ps && pd < ps + n)
	{
		k = n;
		while (k > 0)
		{
			pd[k - 1] = ps[k - 1];
			k--;
		}
		return ((void *)dest);
	}
	k = 0;
	while (k < n)
	{
		pd[k] = ps[k];
		k++;
	}
	return ((void *)dest);
}

char	*ft_trasla(char *line, char *buf)
{
	char	*temp;
	char	*newline_pos;
	size_t	remaining_len;

	newline_pos = ft_strchrgnl(buf, '\n');
	if (newline_pos != NULL)
	{
		temp = ft_substrgnl(buf, 0, (newline_pos - buf + 1));
		line = ft_strjoingnl(line, temp);
		free(temp);
		remaining_len = ft_strlengnl(newline_pos + 1);
		ft_memmovegnl(buf, newline_pos + 1, remaining_len + 1);
	}
	return (line);
}

char	*ft_recalloc(char *buf, char *line, int fd)
{
	int	bytes_read;

	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE && ft_strchrgnl(buf, '\n') == NULL)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(line), NULL);
		buf[bytes_read] = 0;
		if (bytes_read == 0)
			return (line);
		if (ft_strchrgnl(buf, '\n') == NULL)
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
	if (ft_strlengnl(buf) > 0)
	{
		if (ft_strchrgnl(buf, '\n') != NULL)
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