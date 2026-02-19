/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copilot <copilot@example.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:00:00 by copilot           #+#    #+#             */
/*   Updated: 2026/02/18 00:00:00 by copilot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/f.h"
#define READ_CHUNK 16384

int	resize_buf(t_buf_ctx *ctx, ssize_t r)
{
	char	*nb;
	size_t	i;

	if (*ctx->cap * 2 > *ctx->size + r)
		*ctx->cap *= 2;
	else
		*ctx->cap = *ctx->size + r + 1;
	nb = malloc(*ctx->cap);
	if (!nb)
		return (0);
	i = 0;
	while (i < *ctx->size)
	{
		nb[i] = (*ctx->buf)[i];
		i++;
	}
	free(*ctx->buf);
	*ctx->buf = nb;
	return (1);
}

int	append_chunk(t_buf_ctx *ctx, char *data, ssize_t r)
{
	ssize_t	k;

	if (*ctx->size + r >= *ctx->cap)
	{
		if (!resize_buf(ctx, r))
			return (0);
	}
	k = 0;
	while (k < r)
	{
		(*ctx->buf)[*ctx->size + k] = data[k];
		k++;
	}
	*ctx->size += r;
	(*ctx->buf)[*ctx->size] = '\0';
	return (1);
}

int	init_stream(char **buf, char **tmp, size_t *cap)
{
	*cap = READ_CHUNK;
	*buf = malloc(*cap);
	if (!*buf)
		return (0);
	*tmp = malloc(READ_CHUNK);
	if (!*tmp)
	{
		free(*buf);
		return (0);
	}
	return (1);
}

int	read_loop(int fd, char **buf, char *tmp, size_t *size, size_t *cap)
{
	ssize_t		r;
	t_buf_ctx	ctx;

	while ((r = read(fd, tmp, READ_CHUNK)) > 0)
	{
		ctx.buf = buf;
		ctx.cap = cap;
		ctx.size = size;
		if (!append_chunk(&ctx, tmp, r))
			return (0);
	}
	if (r < 0)
		return (0);
	return (1);
}

char	*read_stream(int fd)
{
	char	*buf;
	char	*tmp;
	size_t	size;
	size_t	cap;

	size = 0;
	if (!init_stream(&buf, &tmp, &cap))
		return (NULL);
	if (!read_loop(fd, &buf, tmp, &size, &cap))
	{
		free(tmp);
		free(buf);
		return (NULL);
	}
	free(tmp);
	return (buf);
}


char	*read_file(char *path)
{
	int fd;
	char *res;

	if (!path)
		fd = 0;
	else
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return (NULL);
	}
	res = read_stream(fd);
	if (fd != 0)
		close(fd);
	return (res);
}