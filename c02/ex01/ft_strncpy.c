/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 08:09:55 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/12 17:30:38 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
	}
	return (dest);
}
/*
int main(void){
	char *dest;
	char *src;
	unsigned int n;
	char string[20] = {"Hello World!!!"};
	char dest_str[225];

	dest = dest_str;
	src = string;
	n = 3;
	ft_strncpy(dest, src, n);
	printf("%s", dest_str);
	return 0;
}*/
