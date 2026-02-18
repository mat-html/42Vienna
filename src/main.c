/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:01:47 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/17 16:09:52 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/f.h"

int	process_file(char *path)
{
	char *buf;
	t_map *m;

	buf = read_file(path);
	if (!buf)
	{
		print_map_error();
		return (1);
	}
	m = parse_map(buf);
	free(buf);
	if (!m)
	{
		print_map_error();
		return (1);
	}
	solve_and_print(m);
	free_map(m->grid);
	free(m);
	return (0);
}

int	main(int ac, char **av)
{
	int i;

	if (ac == 1)
	{
		if (process_file(NULL) != 0)
			return (1);
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		if (process_file(av[i]) != 0)
		{
			return (1);
		}
		if (i + 1 < ac)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
