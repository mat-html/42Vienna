/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 07:39:55 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/02 07:59:20 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*mod = a % b;
	*div = a / b;
}
/*
int	main(void)
{
	int	i;
	int	j;
	int r;
	int	m;
	int	*div;
	int	*mod;

	i = 123;
	j = 4;
	div = &r;
	mod = &m;

	ft_div_mod(i, j, div, mod);
	printf("%d\n", r);
	printf("%d", m);
	return(0);
}*/
