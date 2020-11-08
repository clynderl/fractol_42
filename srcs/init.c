/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 09:17:42 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/08 09:58:22 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_fractol *env)
{
	env->it_max = 50;
	env->zoom = 300;
	env->color = 265;
	if (env->fract == 0)
	{
		env->x1 = -2.05;
		env->y1 = -1.3;
	}
	else if (env->fract == 1)
	{
		env->x1 = -2.2;
		env->y1 = -2.5;
	}
	else if (env->fract == 2)
	{
		env->x1 = -2.0;
		env->y1 = -1.9;
		env->c_r = 0.285;
		env->c_i = 0.01;
		env->julia_mouse = 1;
	}
}

int		fract_init(char **argv, t_fractol *env)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		env->fract = 0;
		init(env);
		env->function = mandelbrot_calc;
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		env->fract = 1;
		init(env);
		env->function = julia_calc;
	}
	else if (ft_strcmp(argv[1], "burningship") == 0)
	{
		env->fract = 2;
		init(env);
		env->function = burningship_calc;
	}
	else
		return (0);
	return (1);
}

int		mlx_win_init(t_fractol *env)
{
	if ((env->mlx = mlx_init()) == NULL)
		return (0);
	if ((env->win = mlx_new_window(env->mlx, HEIGHT, WIDTH, "Fractol")) == NULL)
		return (0);
	if ((env->img = mlx_new_image(env->mlx, HEIGHT, WIDTH)) == NULL)
		return (0);
	if ((env->img_ptr = mlx_get_data_addr(env->img,
			&env->bpp, &env->sl, &env->endian)) == NULL)
				return (0);
	env->bpp /= 8;
	return (1);
}
