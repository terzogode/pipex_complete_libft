/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrighi <mbrighi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:31:09 by mbrighi           #+#    #+#             */
/*   Updated: 2025/04/07 20:23:55 by mbrighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*k;
	int		h;

	h = ft_strlen(s);
	k = malloc((h + 1) * sizeof(char));
	if (!k)
		return (NULL);
	h = 0;
	while (s[h] != '\0')
	{
		k[h] = s[h];
		h++;
	}
	k[h] = '\0';
	return (k);
}
/* int main(void)
{
	const char	s[] = "Perche eravamo fatti  e perche sono un po' deficiente";
	char *p = ft_strdup(s);
	// int num = 0;
	// while (p[num++] != '\0')
	// 	printf("l'array allocato e' %d\n", p[num]);
	printf("Il contenuto di k e' %s\n", p);
	free(p);
	return (0);
} */