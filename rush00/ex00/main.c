/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:04:30 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/01 16:59:15 by olpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	main(void)
{
	int	x;
	int	y;

	x = 5;
	y = 3;
	if (x <= 0 || y <= 0)
	{
		write(1, "X/Y needs to be positive!", 25);
		return (1);
	}
	else
	{
		rush(x, y);
	}
	return (0);
}
