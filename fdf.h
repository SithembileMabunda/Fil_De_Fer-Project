/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 14:46:32 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/18 14:50:33 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H_
# define _FDF_H_

typedef	struct	s_axis
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

typedef		s_
{
	int		lat;
	int		lng;
}		t_;

#endif
