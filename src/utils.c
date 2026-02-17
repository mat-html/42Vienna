/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxia <sxia@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 16:32:25 by sxia              #+#    #+#             */
/*   Updated: 2026/02/17 16:46:05 by sxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_map(char **map)
{
	int	i = 0;

    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
