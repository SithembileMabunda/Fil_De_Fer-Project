/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:38:07 by smabunda          #+#    #+#             */
/*   Updated: 2018/08/21 12:20:12 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_size(t_fdf *fdf)
{
	int		row;
	int		col;
	char	**split;
	char	*line;

	if ((fdf->fd = open((*fdf).fn, O_RDONLY)) < 0)
		exit(0);
	row = 0;
	while (get_next_line((*fdf).fd, &line) == 1)
	{
		row++;
		col = 0;
		split = ft_strsplit(line, ' ');
		while (split[col])
			col++;
		if (row == 1)
			fdf->width = col;
		if (fdf->width != col)
		{
			perror("Line Width Are Is Not Equal");
			exit(0);
		}
	}
	fdf->height = row;
}

int		**map_to_array(t_fdf *fdf)
{
	int		**array;
	int		i;
	int		j;
	char	**s;

	i = 0;
	ft_size(fdf);
	(*fdf).fd = open((*fdf).fn, O_RDONLY);
	array = (int **)malloc(sizeof(int *) * (*fdf).height);
	while (get_next_line((*fdf).fd, &(*fdf).line) > 0)
	{
		if ((*fdf).width == 0)
		{
			perror("File Is Empty");
			exit(0);
		}
		j = 0;
		s = ft_strsplit((*fdf).line, ' ');
		array[i] = (int *)malloc(sizeof(int) * (*fdf).width);
		while (s[j])
		{
			array[i][j] = ft_atoi(s[j]);
			j++;
		}
		free((*fdf).line);
		i++;
	}
	close((*fdf).fd);
	return (array);
}
