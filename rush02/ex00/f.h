/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzahirjo <mzahirjo@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 16:17:18 by mzahirjo          #+#    #+#             */
/*   Updated: 2026/02/15 23:00:59 by mzahirjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_H
# define F_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict
{
	char	*key;
	char	*value;
}	t_dict;

t_dict	*parse_dict(char *filename);
void	free_dict(t_dict *dict);

int		print_triplet(int n, t_dict *dict);
char	*ft_get_static_key(long n);
char	*get_mag_key(int len);
int		print_hundreds(int n, t_dict *dict);
int		process_chunk(char *nb, int chunk, t_dict *dict, char *mag);
int		ft_solve(char *nb, t_dict *dict);
int		ft_print_val(char *key, t_dict *dict);
char	*ft_strdup(char *src);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
