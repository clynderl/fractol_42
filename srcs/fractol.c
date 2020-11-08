/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 07:52:00 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/08 10:07:54 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	*draw_fractal(void *tab)
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
			env->function(env);
			env->y++;
		}
		env->x++;
	}
	return (tab);
}

void	fract_pthread(t_fractol *env)
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
		pthread_create(&t[i], NULL, draw_fractal, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
