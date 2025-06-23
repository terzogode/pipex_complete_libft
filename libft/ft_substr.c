/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:29:18 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:22:18 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*daje;
	unsigned char	*is;
	size_t			l;

	l = 0;
	is = (unsigned char *)s;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	daje = malloc(sizeof(char) * len + 1);
	if (!daje)
		return (NULL);
	while (is[start] != '\0' && len > l)
	{
		daje[l] = is[start];
		start++;
		l++;
	}
	daje[l] = '\0';
	return ((char *)daje);
}
/* int	main(void)
{
	char const		s[] = "Se ni' mondo esistesse un po' di bene";
	unsigned int	start;
	size_t			len;
	char			*k;
	size_t			n;
	
	start = 30;
	len = 30;
	n = -1;
	k = ft_substr(s, start, len);
	while (k && k[++n] != '\0')
		printf("%c", k[n]);
	free(k);
} */