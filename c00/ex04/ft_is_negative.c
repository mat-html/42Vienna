/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:36:02 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/02 06:11:51 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	char	p;

	if (n < 0)
	{
		p = 'N';
		write(1, &p, 1);
	}
	else
	{
		p = 'P';
		write(1, &p, 1);
	}
}
//int	main(void)
//{
//	int	i;
//
//	i = 5;
//	ft_is_negative(i);
//	return (0);
//}
