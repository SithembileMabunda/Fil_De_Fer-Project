/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_esc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 10:05:02 by smabunda          #+#    #+#             */
/*   Updated: 2018/08/26 11:55:15 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_esc(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}
