/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 17:09:08 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/14 19:29:26 by jomatic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_change.h"

// The function is still shit... hahahh
char *ft_change(char *num, const s_dict& dict)
{
	int	i;
	int numDict;

	i = 0;
	numDict = 0;
	while (numDict => 0 && num[i + 1] != '\0')
	{
		if(num[i] == dict[numDict].key[0])
		{
			print_value(dict[numDict].value);
		}
		else
		{
			numDict++;
		}
	}
	return 0;
}
