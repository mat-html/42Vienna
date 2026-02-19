/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 15:24:07 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/05 16:18:54 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}
/*
int main(int argc, char **argv)
{
	//char num[225];
	if(argc < 2)
			argv[1] = "\0";
	ft_str_is_numeric(argv[1]);
	printf("%d", ft_str_is_numeric(argv[1]));
}*/
