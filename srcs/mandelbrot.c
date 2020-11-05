/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 07:52:00 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/05 13:20:32 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_init(t_fractol *env)
{
	env->it_max = 50;
	env->zoom = 300;
	env->x1 = -2.05;
	env->y1 = -1.3;
	env->color = 265;
}

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

void	*mandelbrot(void *tab)
{
	t_fractol	*env;
	int		tmp;

	env = (t_fractol *)tab;
	env->x = 0;
	tmp = env->y;
	while (env->x < WIDTH)
	{
		env->y = tmp;
		while (env->y < env->y_max)
		{
			mandelbrot_calc(env);
			env->y++;
		}
		env->x++;
	}
	return (tab);
}

void	mandelbrot_pthread(t_fractol *env)
{
	t_fractol	tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];
	int			i;

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)env, sizeof(t_fractol));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, mandelbrot, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
