/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 11:28:09 by smabunda          #+#    #+#             */
/*   Updated: 2018/08/06 16:03:20 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		abs(int n)
{
	return ((n>0) ? n : ( n * (-1)));
}

void	ft_draw_line(int x1, int y1, int x2, int y2)
{
	int		dx;
	int		dy;
	int		steps;
	float	Xinc;
	float	Yinc;
	int		i;
	float	X;
	float	Y;

	dx = x2 - x1;
	dy = y2 - y1;

	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	Xinc = dx / (float)steps;
	Yinc = dy / (float)steps;
	X = X1;
	Y = Y1;
	i = 0;
	while (i < steps)
	{
		mlx_pixel_put(, , X, Y, 0x0ffff);
		X = X + Xinc;
		Y = Y + Yinc;
		i++;
	}
}
