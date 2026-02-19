/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:54:40 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/06 07:03:12 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcat(char *dest, char*src)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (src[i] != '\0')
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
    char src[30];

	printf("Your firstname is: ");
	scanf("%s", dest);
	printf("Your lastname is: ");
	scanf("%s", src);
    printf("You are  %s", ft_strcat(dest, src));
    return 0;
}
*/
