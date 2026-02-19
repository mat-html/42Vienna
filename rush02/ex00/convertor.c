/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 22:47:39 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/15 22:47:48 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

int	ft_print_val(char *key, t_dict *dict)
{
	int	i;

	i = 0;
	while (dict[i].key)
	{
		if (ft_strcmp(dict[i].key, key) == 0)
		{
			ft_putstr(dict[i].value);
			return (1);
		}
		i++;
	}
	return (0);
}

int	print_triplet(int n, t_dict *dict)
{
	if (!print_hundreds(n, dict))
		return (0);
	if (n >= 20)
	{
		if (!ft_print_val(ft_get_static_key((n / 10) * 10), dict))
			return (0);
		if (n % 10)
		{
			write(1, " ", 1);
			if (!ft_print_val(ft_get_static_key(n % 10), dict))
				return (0);
		}
	}
	else if (n > 0)
	{
		if (!ft_print_val(ft_get_static_key(n), dict))
			return (0);
	}
	return (1);
}

int	ft_solve(char *nb, t_dict *dict)
{
	int		len;
	int		chunk;
	char	*mag;

	len = ft_strlen(nb);
	if (len == 0)
		return (1);
	chunk = len % 3;
	if (chunk == 0)
		chunk = 3;
	mag = get_mag_key(len);
	return (process_chunk(nb, chunk, dict, mag));
}
