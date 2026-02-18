/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomatic <jomatic@student.42vienna.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:05:28 by jomatic           #+#    #+#             */
/*   Updated: 2026/02/17 16:58:03 by sxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F_H
#define F_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s_sqr {
	int size;
	int i;
	int j;
} t_sqr;

typedef struct s_map {
	char **grid;
	int rows;
	int cols;
	char empty;
	char obstacle;
	char full;
} t_map;

typedef struct s_dp_state {
	int *prev;
	int *curr;
	t_sqr *max;
} t_dp_state;

typedef struct s_buf_ctx {
	char **buf;
	size_t *cap;
	size_t *size;
} t_buf_ctx;

int	ft_strlen(char *str);
void	ft_putstr(char *str);
void	generate_map(char **map);
void	free_map(char **map);

char	*read_file(char *path);
t_map	*parse_map(char *buf);
int	validate_map(t_map *m, char *buf);
void	solve_and_print(t_map *m);
void	print_map(t_map *m);
void	print_map_error(void);

int	min3(int a, int b, int c);
void	process_row(t_map *m, int i, t_dp_state *state);
void	mark_square(t_map *m, t_sqr *max);
int	find_max_square(t_map *m, t_sqr *max);
int	alloc_arrays(int **prev, int **curr, int cols);

int	number_from_header(char *s, int len);
int	parse_line_and_copy(char *p, t_map *m, int cols, char **out);
int	get_header_len(char *buf);
char	*extract_header(char *buf, t_map *m);
int	fill_grid_lines(t_map *m, char *p);
int	alloc_grid(t_map *m);

int	append_chunk(t_buf_ctx *ctx, char *data, ssize_t r);
char	*read_stream(int fd);

int	process_file(char *path);

#endif
