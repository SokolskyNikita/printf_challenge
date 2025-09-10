/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ai <ai@student.42>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 00:00:00 by ai                #+#    #+#             */
/*   Updated: 2025/09/10 00:00:00 by ai               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

struct s_capture
{
	int			old_fd;
	int			pipefd[2];
	char		*buf;
	size_t		len;
};

static void	free_buf(char **p)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
}

void		capture_start(struct s_capture *cap)
{
	cap->buf = NULL;
	cap->len = 0;
	pipe(cap->pipefd);
	cap->old_fd = dup(1);
	dup2(cap->pipefd[1], 1);
	close(cap->pipefd[1]);
}

char		*capture_stop(struct s_capture *cap)
{
	char	tmp[256];
	ssize_t	rd;
	char	*newbuf;
	size_t	newlen;

	fflush(stdout);
	dup2(cap->old_fd, 1);
	close(cap->old_fd);
	cap->buf = NULL;
	cap->len = 0;
	while ((rd = read(cap->pipefd[0], tmp, sizeof(tmp))) > 0)
	{
		newlen = cap->len + (size_t)rd;
		newbuf = (char *)malloc(newlen + 1);
		if (!newbuf)
			break ;
		if (cap->buf)
			memcpy(newbuf, cap->buf, cap->len);
		memcpy(newbuf + cap->len, tmp, (size_t)rd);
		newbuf[newlen] = '\0';
		free_buf(&cap->buf);
		cap->buf = newbuf;
		cap->len = newlen;
	}
	close(cap->pipefd[0]);
	return (cap->buf);
}

int			assert_eq_str(const char *got, const char *exp, const char *label)
{
	const char	*gs;
	const char	*es;

	gs = (got ? got : "");
	es = (exp ? exp : "");
	if (strcmp(gs, es) != 0)
	{
		write(2, "[FAIL] ", 8);
		write(2, label, strlen(label));
		write(2, ": expected=", 11);
		write(2, es, strlen(es));
		write(2, ", got=", 6);
		write(2, gs, strlen(gs));
		write(2, "\n", 1);
		return (1);
	}
	write(2, "[OK] ", 5);
	write(2, label, strlen(label));
	write(2, "\n", 1);
	return (0);
}

