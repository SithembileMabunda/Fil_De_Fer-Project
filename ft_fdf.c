/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:16:07 by smabunda          #+#    #+#             */
/*   Updated: 2018/08/21 13:07:34 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf(char *arg)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	(*fdf).fd = open(arg, O_RDONLY);
	if ((*fdf).fd <= 0)
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		exit(0);
	}
	(*fdf).zoom = 25;
	(*fdf).mlx_ptr = mlx_init();
	(*fdf).win_ptr = mlx_new_window((*fdf).mlx_ptr, WINW, WINH, "Fil De Fer");
	(*fdf).fn = arg;
	(*fdf).array = map_to_array(fdf);
	ft_draw_horz(fdf);
	ft_draw_vert(fdf);
	mlx_key_hook((*fdf).win_ptr, ft_esc, fdf);
	mlx_loop((*fdf).mlx_ptr);
}
