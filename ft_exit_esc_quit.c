/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_esc_quit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 10:14:47 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/16 10:41:08 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_exit_esc_quit(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (0);
}
