/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 08:59:18 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/08 10:07:52 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_calc(t_fractol *env)
{
	env->c_r = env->x / env->zoom + env->x1;
	env->c_i = env->y / env->zoom + env->y1;
	env->z_r = 0;
	env->z_i = 0;
	env->it = 0;
	while (env->z_r * env->z_r + env->z_i *
			env->z_i < 4 && env->it < env->it_max)
	{
		env->tmp = env->z_r;
		env->z_r = env->z_r * env->z_r -
			env->z_i * env->z_i + env->c_r;
		env->z_i = 2 * env->z_i * env->tmp + env->c_i;
		env->it++;
	}
	if (env->it == env->it_max)
		put_pxl_to_img(env, env->x, env->y, 0x000000);
	else
		put_pxl_to_img(env, env->x, env->y, (env->color * env->it));
}

void	burningship_calc(t_fractol *env)
{
	env->c_r = env->x / env->zoom + env->x1;
	env->c_i = env->y / env->zoom + env->y1;
	env->z_r = 0;
	env->z_i = 0;
	env->it = 0;
	while (env->z_r * env->z_r + env->z_i * env->z_i < 4
			&& env->it < env->it_max)
	{
		env->tmp = env->z_r * env->z_r - env->z_i * env->z_i + env->c_r;
		env->z_i = fabs(2 * env->z_r * env->z_i) + env->c_i;
		env->z_r = env->tmp;
		env->it++;
	}
	if (env->it == env->it_max)
		put_pxl_to_img(env, env->x, env->y, 0x000000);
	else
		put_pxl_to_img(env, env->x, env->y, (env->color * env->it));
}


void	julia_calc(t_fractol *env)
{
	env->z_r = env->x / env->zoom + env->x1;
	env->z_i = env->y / env->zoom + env->y1;
	env->it = 0;
	while (env->z_r * env->z_r + env->z_i
			* env->z_i < 4 && env->it < env->it_max)
	{
		env->tmp = env->z_r;
		env->z_r = env->z_r * env->z_r -
			env->z_i * env->z_i - 0.8 + (env->c_r / WIDTH);
		env->z_i = 2 * env->z_i * env->tmp + env->c_i / WIDTH;
		env->it++;
	}
	if (env->it == env->it_max)
		put_pxl_to_img(env, env->x, env->y, 0x000000);
	else
		put_pxl_to_img(env, env->x, env->y, (env->color * env->it));
}
