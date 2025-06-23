/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:36:28 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:23:05 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size -1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
/* int main(void)
{
	char src[] = "Se ni' mondo esistesse";
	char dest[20];
	size_t	k;
	size_t	n;
	
	n = 0;
	k = ft_strlcpy(dest, src, n);
	printf("src e' %s\n", src);
	printf("dest e' %s\n", dest);
	printf("La lunghezza e' %zu\n", k);
	return(0);
} */
