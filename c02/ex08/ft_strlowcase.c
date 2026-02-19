/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 18:52:05 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/05 16:26:12 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int		i;
	char	offset;

	i = 0;
	offset = 'a' - 'A';
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += offset;
		i++;
	}
	return (str);
}
/*
int main(int argc, char **argv)
{
	if(argc < 2)
			argv[1] = "\0";
	printf("%s", ft_strlowcase(argv[1]));
	return 0;
}*/
