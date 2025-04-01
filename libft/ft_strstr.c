/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:31:23 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/01 12:36:22 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *to_find)
{
	size_t	b;
	size_t	l;

	b = 0;
	l = 0;
	if (to_find[l] == '\0')
		return ((char *)&big[b]);
	while (big[b] != '\0')
	{
		l = 0;
		while (big[b + l] == to_find[l] && to_find[l] != '\0')
			l++;
		if (to_find[l] == '\0')
			return ((char *)&big[b]);
		b++;
	}
	return (NULL);
}
