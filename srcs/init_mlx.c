/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:32:37 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 17:57:48 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_mlx(t_env *e)
{
	if ((e->mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((e->win_ptr = mlx_new_window(e->mlx_ptr, WIDTH, HEIGHT, "Fractol")) == NULL)
		return (0);
	if ((e->img_ptr = mlx_new_image(e->mlx_ptr, WIDTH, HEIGHT)) == NULL)
		return (0);
	if ((e->img = mlx_get_data_addr(e->img_ptr, &e->bpp, &e->ln, &e->en)) == NULL)
		return (0);
	e->bpp /= 8;
	return (1);
}
