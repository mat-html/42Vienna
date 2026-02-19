/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 13:58:08 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/15 22:09:39 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

int	count_valid_entries(char *filename)
{
	int		fd;
	int		count;
	char	c;
	int		new_line;

	count = 0;
	new_line = 1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, &c, 1) > 0)
	{
		if (new_line)
		{
			while (c == ' ' && read(fd, &c, 1) > 0)
				;
			if (c >= '0' && c <= '9')
				count++;
			new_line = 0;
		}
		if (c == '\n')
			new_line = 1;
	}
	close(fd);
	return (count);
}

static char	*read_key(int fd, char *c)
{
	char	temp[1024];
	int		i;

	while (read(fd, c, 1) > 0 && (*c == '\n' || *c == ' '))
		;
	i = 0;
	while (*c >= '0' && *c <= '9')
	{
		if (i < 1023)
			temp[i++] = *c;
		if (read(fd, c, 1) <= 0)
			break ;
	}
	temp[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(temp));
}

static char	*read_value(int fd, char c)
{
	char	temp[1024];
	int		i;

	while (c == ' ')
		if (read(fd, &c, 1) <= 0)
			return (NULL);
	i = 0;
	while (c != '\n' && i < 1023)
	{
		temp[i++] = c;
		if (read(fd, &c, 1) <= 0)
			break ;
	}
	while (i > 0 && temp[i - 1] == ' ')
		i--;
	temp[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(temp));
}

int	set_entry(int fd, t_dict *entry)
{
	char	c;

	entry->key = read_key(fd, &c);
	if (!entry->key)
		return (0);
	while (c == ' ')
		if (read(fd, &c, 1) <= 0)
			return (0);
	if (c != ':')
	{
		while (read(fd, &c, 1) > 0 && c != ':')
			if (c == '\n')
				return (0);
		if (c != ':')
			return (0);
	}
	if (read(fd, &c, 1) <= 0)
		return (0);
	entry->value = read_value(fd, c);
	if (!entry->value)
		return (0);
	return (1);
}

t_dict	*parse_dict(char *filename)
{
	t_dict	*dict;
	int		count;
	int		i;
	int		fd;
	int		status;

	count = count_valid_entries(filename);
	if (count <= 0)
		return (NULL);
	dict = malloc(sizeof(t_dict) * (count + 1));
	if (!dict)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	while (i < count)
	{
		status = set_entry(fd, &dict[i]);
		if (status == 0)
		{
			close(fd);
			return (NULL);
		}
		i++;
	}
	dict[i].key = NULL;
	close(fd);
	return (dict);
}
