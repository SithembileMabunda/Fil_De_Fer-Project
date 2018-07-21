/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:02:05 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/21 13:02:30 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

int		main(void)
{
	void *window;
	void *mlx;
	int x;
	int y;

	x = 300;
	y = 600;
	mlx = mlx_init();
	window = mlx_new_window(mlx, 1000, 1000, "practice");
	while ((x >= 250 && x <= 750) || (y >= 250 && y <= 750))
	{
		mlx_pixel_put(mlx, window, x, y, 0x00FFFFFF);
		x++;
		y++;
	}
	mlx_key_hook(window, ft_exit_esc_quit, 0);
	mlx_loop(mlx);
}
