/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 17:03:32 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/05 16:24:34 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int		i;
	char	offset;
	char	*change_string;

	change_string = str;
	offset = 'a' - 'A';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = change_string[i] - offset;
		}
		i++;
	}
	return (str);
}
/*
int main(int argc, char **argv)
{
	if(argc < 2)
		argv[1] = "\0";
		//char a[] = {"something"};
	printf("%s", ft_strupcase(argv[1]));
	return(0); 
}*/
