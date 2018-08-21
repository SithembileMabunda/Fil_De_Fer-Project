/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 09:18:34 by smabunda          #+#    #+#             */
/*   Updated: 2018/08/21 17:22:56 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include "../LIBFT/libft.h"
# include "mlx.h"
# include <errno.h>
# include <math.h>

# define RED 0xff0000
# define BLUE 0x0000ff
# define WINW 1366
# define WINH 768
# define LINE (abs(fdf->dx) > abs(fdf->dy) ? abs(fdf->dx) : abs(fdf->dy))

typedef	struct	s_fdf
{
	int			fd;
	char		*line;
	void		*win_ptr;
	void		*mlx_ptr;
	int			width;
	int			height;
	int			dx;
	int			dy;
	int			steps;
	float		x;
	float		y;
	float		xx;
	float		yy;
	int			p1[2];
	int			p2[2];
	int			i;
	int			j;
	int			**array;
	int			x1;
	char		*fn;
	int			y1;
	int			x2;
	int			y2;
	int			zoom;
	int			col;
	int			row;
}				t_fdf;

int				abs(int n);
void			link_x(t_fdf **fdf, int x, int y);
void			link_y(t_fdf **fdf, int x, int y);
void			ft_draw_line(t_fdf *fdf, int color);
void			ft_draw_vert(t_fdf *fdf);
void			ft_draw_horz(t_fdf *fdf);

int				**map_to_array(t_fdf *fdf);
void			ft_size(t_fdf *fdf);

int				ft_esc(int keycode, void *param);

void			ft_fdf(char *arg);

#endif
