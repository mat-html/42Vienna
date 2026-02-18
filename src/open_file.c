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

int	append_chunk(t_buf_ctx *ctx, char *data, ssize_t r)
{
	char *nb;

	if (*ctx->size + r >= *ctx->cap)
	{
		*ctx->cap = (*ctx->cap * 2 > *ctx->size + r) ?
			*ctx->cap * 2 : *ctx->size + r + 1;
		nb = malloc(*ctx->cap);
		if (!nb)
			return (0);
		for (size_t i = 0; i < *ctx->size; i++)
			nb[i] = (*ctx->buf)[i];
		free(*ctx->buf);
		*ctx->buf = nb;
	}
	for (ssize_t k = 0; k < r; k++)
		(*ctx->buf)[*ctx->size + k] = data[k];
	*ctx->size += r;
	(*ctx->buf)[*ctx->size] = '\0';
	return (1);
}

char	*read_stream(int fd)
{
	char *buf;
	char *tmp;
	ssize_t r;
	size_t size;
	size_t cap;

	cap = READ_CHUNK;
	buf = malloc(cap);
	if (!buf)
		return (NULL);
	size = 0;
	tmp = malloc(READ_CHUNK);
	if (!tmp)
	{
		free(buf);
		return (NULL);
	}
	while ((r = read(fd, tmp, READ_CHUNK)) > 0)
	{
		t_buf_ctx ctx;
		ctx.buf = &buf;
		ctx.cap = &cap;
		ctx.size = &size;
		if (!append_chunk(&ctx, tmp, r))
		{
			free(tmp);
			free(buf);
			return (NULL);
		}
	}
	free(tmp);
	if (r < 0)
	{
		free(buf);
		return (NULL);
	}
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