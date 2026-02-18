#include "../include/f.h"

int	min3(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	return (c);
}

void	process_row(t_map *m, int i, t_dp_state *state)
{
	int j;

	j = 0;
	while (j < m->cols)
	{
		if (m->grid[i][j] == m->empty)
		{
			if (i == 0 || j == 0)
				state->curr[j] = 1;
			else
				state->curr[j] = min3(state->prev[j], state->curr[j - 1],
					state->prev[j - 1]) + 1;
			if (state->curr[j] > state->max->size)
			{
				state->max->size = state->curr[j];
				state->max->i = i;
				state->max->j = j;
			}
		}
		else
			state->curr[j] = 0;
		j++;
	}
}

void	mark_square(t_map *m, t_sqr *max)
{
	int r;
	int c;

	if (max->size <= 0)
		return ;
	for (r = max->i - max->size + 1; r <= max->i; r++)
	{
		for (c = max->j - max->size + 1; c <= max->j; c++)
			m->grid[r][c] = m->full;
	}
}



void	solve_and_print(t_map *m)
{
	t_sqr max;

	max.size = 0;
	max.i = 0;
	max.j = 0;
	if (!find_max_square(m, &max))
	{
		print_map_error();
		return ;
	}
	mark_square(m, &max);
	print_map(m);
}

int	find_max_square(t_map *m, t_sqr *max)
{
	int *prev;
	int *curr;
	int i;

	if (!alloc_arrays(&prev, &curr, m->cols))
		return (0);
	for (i = 0; i < m->cols; i++)
		prev[i] = 0;
	i = 0;
	while (i < m->rows)
	{
		t_dp_state state;
		state.prev = prev;
		state.curr = curr;
		state.max = max;
		process_row(m, i, &state);
		{
			int *tmp = prev;
			prev = curr;
			curr = tmp;
		}
		i++;
	}
	free(prev);
	free(curr);
	return (1);
}

int	alloc_arrays(int **prev, int **curr, int cols)
{
	*prev = malloc(sizeof(int) * cols);
	*curr = malloc(sizeof(int) * cols);
	if (!*prev || !*curr)
	{
		if (*prev) free(*prev);
		if (*curr) free(*curr);
		return (0);
	}
	return (1);
}
