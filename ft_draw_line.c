/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:28:09 by smabunda          #+#    #+#             */
/*   Updated: 2018/08/09 15:09:07 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
//#include <stdio.h>
#include <stdlib.h>

int		abs(int n)
{
	return ((n>0) ? n : ( n * (-1)));
}

void		ft_draw_line(int x1, int y1, int x2, int y2, t_draw_line *ptr)
{
	t_drawline	*var;

	var = (t_drawline *)malloc(sizeof(t_drawline));

	(*var).dx = x2 - x1;
	(*var).dy = y2 - y1;

	(*var).steps = abs((*var).dx) > abs((*var).dy) ? abs((*var).dx) : abs((*var).dy);
	(*var).Xinc = (*var).dx / (float)(*var).steps;
	(*var).Yinc = (*var).dy / (float)(*var).steps;
	(*var).X = x1;
	(*var).Y = y1;
	(*var).i = 0;
	while ((*var).i < (*var).steps)
	{
		mlx_pixel_put((*ptr).mlx_ptr,(*ptr).win_ptr, (*var).X, (*var).Y, 0xff0000);
		(*var).X = (*var).X + (*var).Xinc;
		(*var).Y = (*var).Y + (*var).Yinc;
		(*var).i++;
		//delay(100);
	}
}

int			main(void)
{
	t_draw_line	*ptr;

	ptr = (t_draw_line*)malloc(sizeof(t_draw_line));

	(*ptr).mlx_ptr = mlx_init();
	(*ptr).win_ptr = mlx_new_window((*ptr).mlx_ptr, 800, 600, "WireFrame");

    int X0 = 25, Y0 = 50, X1 = 100, Y1 = 200;
    ft_draw_line(X0, Y0, X1, Y1, ptr);
	mlx_loop((*ptr).mlx_ptr);
    return (0);
}
