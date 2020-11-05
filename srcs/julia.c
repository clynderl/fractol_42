/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 07:53:16 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/05 13:20:21 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_julia(int x, int y, t_fractol *env)
{
	if (env->fract == 1 && env->julia_mouse == 1)
	{
		env->c_r = x * 2;
		env->c_i = y * 2 - 800;
		fract_calc(env);
	}
	return (0);
}

void	julia_init(t_fractol *env)
{
	env->it_max = 50;
	env->zoom = 200;
	env->x1 = -2.0;
	env->y1 = -1.9;
	env->color = 265;
	env->c_r = 0.285;
	env->c_i = 0.01;
	env->julia_mouse = 1;
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

void	*julia(void *tab)
{
	int		tmp;
	t_fractol	*env;

	env = (t_fractol *)tab;
	env->x = 0;
	tmp = env->y;
	while (env->x < WIDTH)
	{
		env->y = tmp;
		while (env->y < env->y_max)
		{
			julia_calc(env);
			env->y++;
		}
		env->x++;
	}
	return (tab);
}

void	julia_pthread(t_fractol *env)
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
		pthread_create(&t[i], NULL, julia, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
