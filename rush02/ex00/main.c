/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboualla <eboualla@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:16:33 by eboualla          #+#    #+#             */
/*   Updated: 2026/02/15 18:22:52 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f.h"

void	free_dict(t_dict *dict)
{
	int	i;

	if (!dict)
		return ;
	i = 0;
	while (dict[i].key)
	{
		free(dict[i].key);
		free(dict[i].value);
		i++;
	}
	free(dict);
}

int	valid_int(char *str)
{
	int	i;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

char	*get_input_nb(int argc, char **argv)
{
	char	*nb;

	if (argc < 2 || argc > 3)
		return (NULL);
	if (argc == 2)
		nb = argv[1];
	else
		nb = argv[2];
	if (!valid_int(nb))
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	while (*nb == '0' && *(nb + 1))
		nb++;
	return (nb);
}

static t_dict	*init_dict(int argc, char **argv)
{
	if (argc == 3)
		return (parse_dict(argv[1]));
	return (parse_dict("numbers.dict"));
}

int	main(int argc, char **argv)
{
	char	*nb;
	t_dict	*dict;
	int		status;

	nb = get_input_nb(argc, argv);
	if (!nb)
		return (1);
	dict = init_dict(argc, argv);
	if (!dict)
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	if (nb[0] == '0' && nb[1] == '\0')
		status = ft_print_val("0", dict);
	else
		status = ft_solve(nb, dict);
	if (!status)
		write(1, "Dict Error\n", 11);
	else
		write(1, "\n", 1);
	free_dict(dict);
	return (0);
}
