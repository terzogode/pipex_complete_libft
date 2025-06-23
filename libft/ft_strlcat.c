/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:23:35 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:23:21 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		ndst;
	size_t		nsrc;
	size_t		i;

	ndst = 0;
	nsrc = 0;
	i = 0;
	while (dst[ndst] != '\0')
		ndst++;
	while (src[nsrc] != '\0')
		nsrc++;
	if (size <= ndst)
		return (size + nsrc);
	while (src[i] != '\0' && ((ndst + i) < (size - 1)))
	{
		dst[ndst + i] = src[i];
		i++;
	}
	dst[ndst + i] = '\0';
	return (ndst + nsrc);
}
/* int main (void)
{
	char		dst[]= "Voglio la liberta ";
	const char	src[]= "di andare alle poste";
	size_t		k;
	size_t		lollo;
	//size_t		lollu;

	k = 55;
	lollo = ft_strlcat(dst, src, k);
	printf("dest e' %s\n", dst);
	printf("la lunghezza e'%zu\n", lollo);
	lollu = strlcat(dst, src, k);
	printf("dest e' %s\n", dst);
	printf("la lunghezza e'%zu\n", lollu);
	return (0);
}*/
