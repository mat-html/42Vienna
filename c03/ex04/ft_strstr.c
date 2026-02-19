/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 07:04:14 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/12 13:49:19 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		while (str[j] == to_find[i] && str[j] != '\0')
		{
			j++;
			i++;
		}
		if (to_find[i] == '\0')
		{
			return (str + (j - i));
		}
		j++;
		i = 0;
	}
	return ("NULL");
}
/*
int main(int argc, char **argv)
{
	if (argc < 3)
		argv[3] = "\0";
	
	printf("Found:%s", ft_strstr(argv[1], argv[2]));
	return (0);
}*/
