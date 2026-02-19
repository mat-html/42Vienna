/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 06:37:23 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/06 07:03:41 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	n;

	i = 0;
	n = 0;
	while (src[i] != '\0' && i < nb)
	{
		if (dest[n] == '\0')
		{
			dest[n] = src[i];
			dest[n + 1] = '\0';
			i++;
		}
		n++;
	}
	return (dest);
}
/*
int main() {
    char dest[100];
    char src[20];
    unsigned int num = 0;

	printf("Put a string: ");
	scanf("%s", dest);
	printf("Put second string: ");
	scanf("%s", src);
	printf("Put a number: ");
	scanf("%d", &num);
    printf("%s", ft_strncat(dest, src, num));
    return 0;
}*/
