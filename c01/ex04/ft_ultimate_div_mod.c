/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 08:00:55 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/02 10:03:22 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	f;
	int	s;

	f = *a;
	s = *b;
	*a = f / s;
	*b = f % s;
}
/*
int	main(void)
{
	int i;
	int j;
	int *a;
	int *b;

	i = 130;
	j = 7;
	a = &i;
	b = &j;
	ft_ultimate_div_mod(a, b);
	printf("%d\n", i);
	printf("%d", j);
	return (0);
}*/
