/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 08:39:40 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/19 11:20:28 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_write_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

void	ft_swap(char *str)
{
	int		k;
	int		i;
	char	temp;

	i = 0;
	k = 0;
	while (str[i] != '\0')
		i++;
	while (i > k)
	{
		temp = str[k];
		str[k] = str[i - 1];
		str[i - 1] = temp;
		i--;
		k++;
	}
	ft_write_str(str);
}

int	int_min_max(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (0);
	}
	else
	{
		write(1, "2147483647", 10);
		return (0);
	}
	return (0);
}

void	ft_check_nb(int nb)
{
	int		i;
	char	str[15];

	i = 0;
	if (nb < 0 && nb != -2147483648)
	{
		nb *= (-1);
		write(1, "-", 1);
	}
	while (nb >= 10)
	{
		str[i] = '0' + nb % 10;
		i++;
		nb /= 10;
	}
	if (nb < 10 && nb >= 0)
	{
		str[i] = '0' + nb;
		i++;
	}
	str[i] = '\0';
	ft_swap(str);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648 || nb == 2147483647)
	{
		int_min_max(nb);
	}
	else
	{
		ft_check_nb(nb);
	}
}
/*
int main()
{
	int n = 0;

	ft_putnbr(n);
	return(0);
}*/
