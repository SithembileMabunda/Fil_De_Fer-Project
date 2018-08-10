/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:46:32 by smabunda          #+#    #+#             */
/*   Updated: 2018/08/09 16:39:57 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

/*typedef	struct	s_axis
{
	int	x;
	int	y;
	int	z;
}		t_axis;

typedef	struct	s_map
{
	int		width;
	int		height;
	t_vector	**vector;
}		t_map;

typedef	struct	s_vector
{
	double		vert;
	double		horz;
	double		diag;
}		t_vector;

typedef	struct	s_
{
	int		lat;
	int		lng;
}		t_;*/

typedef	struct	s_draw_line
{
	void    *win_ptr;
    void    *mlx_ptr;
}				t_draw_line;

typedef	struct	s_drawline
{
	int     dx;
    int     dy;
    int     steps;
    float   Xinc;
    float   Yinc;
    int     i;
    float   X;
    float   Y;
}				t_drawline;



int		**map_to_array(int arg);
void    ft_draw_line(int x1, int y1, int x2, int y2, t_draw_line *ptr);

#endif
