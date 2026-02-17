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

int	main(int ac, char **av)
{
	if (ac == 1)
		return 1;
	if(ac != 2)
		// argument is the file that needs to be handeld
	generate_map(av);
}
