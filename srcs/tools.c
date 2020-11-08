/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 07:54:36 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/08 10:07:55 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_close(void)
{
	exit(1);
	return (0);
}

void	put_pxl_to_img(t_fractol *env, int x, int y, int color)
{
	if (env->x < WIDTH && env->y < WIDTH)
	{
		color = mlx_get_color_value(env->mlx, color);
		ft_memcpy(env->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}
