/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 07:29:07 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/02 10:02:49 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
	int j;
	int k;
	int *ptr;
	int *ptr1;

	j = 76;
	k = 79;
	ptr = &j;
	ptr1 = &k;
	write(1, &j ,1);
    write(1, &k, 1);
	ft_swap(ptr, ptr1);
	write(1, &j ,1);
	write(1, &k, 1);
	return (0);
}*/
