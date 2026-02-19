/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 22:43:50 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/15 22:53:04 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

char	*ft_get_static_key(long n)
{
	static char	buf[25];
	int			i;

	i = 23;
	buf[24] = '\0';
	if (n == 0)
		return ("0");
	while (n > 0)
	{
		buf[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (&buf[i + 1]);
}

char	*get_mag_key(int len)
{
	static char	buf[64];
	int			i;
	int			target;

	if (len <= 3)
		return (NULL);
	if (len % 3 == 0)
		target = len - 3;
	else
		target = len - (len % 3);
	buf[0] = '1';
	i = 1;
	while (i <= target)
	{
		buf[i] = '0';
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int	print_hundreds(int n, t_dict *dict)
{
	if (n < 100)
		return (1);
	if (!ft_print_val(ft_get_static_key(n / 100), dict))
		return (0);
	write(1, " ", 1);
	if (!ft_print_val("100", dict))
		return (0);
	n %= 100;
	if (n > 0)
		write(1, " ", 1);
	return (1);
}

int	process_chunk(char *nb, int chunk, t_dict *dict, char *mag)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (i < chunk)
		n = n * 10 + (nb[i++] - '0');
	if (n > 0)
	{
		if (!print_triplet(n, dict))
			return (0);
		if (mag)
		{
			write(1, " ", 1);
			if (!ft_print_val(mag, dict))
				return (0);
		}
		i = chunk;
		while (nb[i] == '0')
			i++;
		if (nb[i])
			write(1, " ", 1);
	}
	return (ft_solve(nb + chunk, dict));
}
