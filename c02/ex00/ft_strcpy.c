/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 06:52:03 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/11 11:58:09 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main(void)
{
	char *destination;
	char *source;
	char str[60] = {"Hello Woooooooorld"};
	char dest_str[100];

	destination = dest_str;
	source = str;
	ft_strcpy(destination, source);
	int i = 0;
	while(dest_str[i] != '\0'){
	printf("%c", dest_str[i]);
	i++;
	}
	return (0);
}*/
