/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 09:34:02 by smabunda          #+#    #+#             */
/*   Updated: 2018/08/23 14:14:56 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	link_x(t_fdf **fdf, int x, int y)
{
	(*fdf)->p1[0] = (x - 1) * (*fdf)->zoom + WINW / 3;
	(*fdf)->p1[1] = y * (*fdf)->zoom + WINH / 3;
	(*fdf)->p2[0] = x * (*fdf)->zoom + WINW / 3;
	(*fdf)->p2[1] = y * (*fdf)->zoom + WINH / 3;
	(*fdf)->p1[0] -= 2 * (*fdf)->array[y][x - 1];
	(*fdf)->p1[1] -= 2 * (*fdf)->array[y][x - 1];
	(*fdf)->p2[0] -= 2 * (*fdf)->array[y][x];
	(*fdf)->p2[1] -= 2 * (*fdf)->array[y][x];
}

void	link_y(t_fdf **fdf, int x, int y)
{
	(*fdf)->p1[0] = x * (*fdf)->zoom + WINW / 3;
	(*fdf)->p1[1] = (y - 1) * (*fdf)->zoom + WINH / 3;
	(*fdf)->p2[0] = x * (*fdf)->zoom + WINW / 3;
	(*fdf)->p2[1] = y * (*fdf)->zoom + WINH / 3;
	(*fdf)->p1[0] -= 2 * (*fdf)->array[y - 1][x];
	(*fdf)->p1[1] -= 2 * (*fdf)->array[y - 1][x];
	(*fdf)->p2[0] -= 2 * (*fdf)->array[y][x];
	(*fdf)->p2[1] -= 2 * (*fdf)->array[y][x];
}

void	ft_draw_line(t_fdf *fdf, int color)
{
	int i;

	(*fdf).x1 = (*fdf).p1[0];
	(*fdf).x2 = (*fdf).p2[0];
	(*fdf).y1 = (*fdf).p1[1];
	(*fdf).y2 = (*fdf).p2[1];
	(*fdf).dx = (*fdf).x2 - (*fdf).x1;
	(*fdf).dy = (*fdf).y2 - (*fdf).y1;
	fdf->steps = LINE;
	(*fdf).xx = (*fdf).dx / (float)(*fdf).steps;
	(*fdf).yy = (*fdf).dy / (float)(*fdf).steps;
	(*fdf).x = (*fdf).x1;
	(*fdf).y = (*fdf).y1;
	i = 0;
	while (i < (*fdf).steps)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, fdf->x, fdf->y, color);
		(*fdf).x = (*fdf).x + (*fdf).xx;
		(*fdf).y = (*fdf).y + (*fdf).yy;
		i++;
	}
}

void	ft_draw_horz(t_fdf *fdf)
{
	(*fdf).i = 0;
	while ((*fdf).i < (*fdf).height)
	{
		(*fdf).j = 1;
		while ((*fdf).j < (*fdf).width)
		{
			link_x(&fdf, (*fdf).j, (*fdf).i);
			if ((*fdf).array[(*fdf).i][(*fdf).j] != 0 && (*fdf).array[(*fdf).i][(*fdf).j - 1])
				ft_draw_line(fdf, BLUE);
			else
				ft_draw_line(fdf, RED);
			(*fdf).j++;
		}
		(*fdf).i++;
	}
}

void	ft_draw_vert(t_fdf *fdf)
{
	(*fdf).j = 0;
	while ((*fdf).j < (*fdf).width)
	{
		(*fdf).i = 1;
		while ((*fdf).i < (*fdf).height)
		{
			link_y(&fdf, (*fdf).j, (*fdf).i);
			if ((*fdf).array[(*fdf).i][(*fdf).j] != 0 && (*fdf).array[(*fdf).i - 1][(*fdf).j] != 0)
				ft_draw_line(fdf, BLUE);
			else
				ft_draw_line(fdf, RED);
			(*fdf).i++;
		}
		(*fdf).j++;
	}
}
