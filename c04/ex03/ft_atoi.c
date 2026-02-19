/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:24:08 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/19 11:13:49 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ignore_space(char	*str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	find_sign(char	*str, int i)
{
	int	sign;

	sign = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	if (sign % 2 == 1)
	{
		sign = -1;
		return (sign);
	}
	sign = 1;
	return (sign);
}

int	ft_atoi(char	*str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	i = ignore_space(str);
	sign = find_sign(str, i);
	result = 0;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (sign < 0)
	{
		result = -result;
	}
	return (result);
}
/*
int main(){
	char str[205] = "      \t \n -+-+2314";

printf("%d", ft_atoi(str));
}*/
