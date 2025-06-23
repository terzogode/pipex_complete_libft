/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:12:40 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:28:09 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_strdupgnl(const char *s)
{
	char	*k;
	int		h;

	h = ft_strlen(s);
	k = malloc((h + 1) * sizeof(char));
	if (!k)
		return (NULL);
	h = 0;
	while (s[h] != '\0' && (h == 0 || s[h - 1] != '\n'))
	{
		k[h] = s[h];
		h++;
	}
	k[h] = '\0';
	return (k);
}
