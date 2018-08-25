/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:38:07 by smabunda          #+#    #+#             */
/*   Updated: 2018/08/25 10:13:32 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdp(void **array)
{
	int n;

	n = 0;
	while (array[n])
	{
		free(array[n]);
		n++;
	}
	free(array);
}

void	mtp(t_fdf *fdf, char **split, char *line)
{
	(*fdf).row++;
	(*fdf).col = 0;
	split = ft_strsplit(line, ' ');
	while (split[(*fdf).col])
		(*fdf).col++;
	if ((*fdf).row == 1)
		fdf->width = (*fdf).col;
	fdp((void **)split);
	if (fdf->width != (*fdf).col)
	{
		ft_putstr("Line Width Are Not Equal\n");
		exit(0);
	}
}

void	ft_size(t_fdf *fdf)
{
	char	**split;
	char	*line;

	if ((fdf->fd = open((*fdf).fn, O_RDONLY)) < 0)
	{
		ft_putstr("hello");
		exit(0);
	}
	(*fdf).row = 0;
	while (get_next_line((*fdf).fd, &line) == 1)
	{
		mtp(fdf, split, line);
		free(line);
	}
	fdf->height = (*fdf).row;
	if ((*fdf).width == 0 || (*fdf).height == 0)
	{
		ft_putstr("File Is Empty\n");
		exit(0);
	}
}

int		**map_to_array(t_fdf *fdf)
{
	int		**array;
	char	**s;

	(*fdf).i = 0;
	ft_size(fdf);
	(*fdf).fd = open((*fdf).fn, O_RDONLY);
	array = (int **)malloc(sizeof(int *) * ((*fdf).height) + 1);
	while (get_next_line((*fdf).fd, &(*fdf).line) > 0)
	{
		(*fdf).j = 0;
		s = ft_strsplit((*fdf).line, ' ');
		array[(*fdf).i] = (int *)malloc(sizeof(int) * ((*fdf).width) + 1);
		while (s[(*fdf).j])
		{
			array[(*fdf).i][(*fdf).j] = ft_atoi(s[(*fdf).j]);
			(*fdf).j++;
		}
		free((*fdf).line);
		array[(*fdf).i][(*fdf).j] = '\0';
		fdp((void **)s);
		(*fdf).i++;
	}
	array[(*fdf).i] = NULL;
	close((*fdf).fd);
	return (array);
}
