/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:03:56 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/17 15:32:17 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/f.h"

int	number_from_header(char *s, int len)
{
	int i;
	int n;

	i = 0;
	n = 0;
	if (len <= 0)
		return (-1);
	while (i < len)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n);
}

int	parse_line_and_copy(char *p, t_map *m, int cols, char **out)
{
	int k;

	*out = malloc(cols + 1);
	if (!*out)
		return (0);
	k = 0;
	while (k < cols)
	{
		if (p[k] != m->empty && p[k] != m->obstacle)
		{
			free(*out);
			return (0);
		}
		(*out)[k] = p[k];
		k++;
	}
	(*out)[cols] = '\0';
	return (1);
}

int	get_header_len(char *buf)
{
	int header_len;

	header_len = 0;
	while (buf[header_len] && buf[header_len] != '\n')
		header_len++;
	if (buf[header_len] != '\n' || header_len < 4)
		return (-1);
	return (header_len);
}

char	*extract_header(char *buf, t_map *m)
{
	int header_len;
	int cols;
	char *p;

	header_len = get_header_len(buf);
	if (header_len < 0)
		return (NULL);
	m->empty = buf[header_len - 3];
	m->obstacle = buf[header_len - 2];
	m->full = buf[header_len - 1];
	if (m->empty == m->obstacle || m->empty == m->full ||
		m->obstacle == m->full)
		return (NULL);
	m->rows = number_from_header(buf, header_len - 3);
	if (m->rows <= 0)
		return (NULL);
	p = buf + header_len + 1;
	cols = 0;
	while (p[cols] && p[cols] != '\n')
		cols++;
	if (cols == 0)
		return (NULL);
	m->cols = cols;
	return (p);
}

int	fill_grid_lines(t_map *m, char *p)
{
	int i;

	i = 0;
	while (i < m->rows)
	{
		if (!p)
			break;
		if (!parse_line_and_copy(p, m, m->cols, &m->grid[i]))
			return (0);
		if (p[m->cols] == '\n')
			p = p + m->cols + 1;
		else
			p = p + m->cols;
		i++;
	}
	m->grid[m->rows] = NULL;
	return (i == m->rows);
}

int	alloc_grid(t_map *m)
{
	m->grid = malloc(sizeof(char *) * (m->rows + 1));
	if (!m->grid)
		return (0);
	return (1);
}

void	print_map_error(void)
{
	write(1, "map error\n", 10);
}

void	print_map(t_map *m)
{
	int i;

	i = 0;
	while (i < m->rows)
	{
		write(1, m->grid[i], m->cols);
		write(1, "\n", 1);
		i++;
	}
}

t_map	*parse_map(char *buf)
{
	t_map *m;
	char *p;

	if (!buf)
		return (NULL);
	m = malloc(sizeof(t_map));
	if (!m)
		return (NULL);
	p = extract_header(buf, m);
	if (!p || !alloc_grid(m))
	{
		free(m);
		return (NULL);
	}
	if (!fill_grid_lines(m, p))
	{
		free_map(m->grid);
		free(m);
		return (NULL);
	}
	return (m);
}
