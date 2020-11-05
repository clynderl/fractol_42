/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 07:55:02 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/05 13:20:01 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook2(int keycode, t_fractol *env)
{
	if (keycode == 19)
		env->color = 2050;
	else if (keycode == 20)
		env->color = 265;
	else if (keycode == 35)
		env->julia_mouse = !env->julia_mouse;
	else if (keycode == 34)
		env->show_text = !env->show_text;
	return (0);
}

int		key_hook(int keycode, t_fractol *env)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69)
		env->it_max += 50;
	else if (keycode == 78)
		env->it_max -= 50;
	else if (keycode == 123)
		env->x1 -= 30 / env->zoom;
	else if (keycode == 124)
		env->x1 += 30 / env->zoom;
	else if (keycode == 125)
		env->y1 += 30 / env->zoom;
	else if (keycode == 126)
		env->y1 -= 30 / env->zoom;
	// else if (keycode == 49)
	// 	fract_init(env);
	else if (keycode == 18)
		env->color = 1677216;
	key_hook2(keycode, env);
	fract_calc(env);
	return (0);
}

void	ft_zoom(int x, int y, t_fractol *env)
{
	env->x1 = (x / env->zoom + env->x1) - (x / (env->zoom * 1.3));
	env->y1 = (y / env->zoom + env->y1) - (y / (env->zoom * 1.3));
	env->zoom *= 1.3;
	env->it_max++;
}

void	ft_dezoom(int x, int y, t_fractol *env)
{
	env->x1 = (x / env->zoom + env->x1)  - (x / (env->zoom / 1.3));
	env->y1 = (y / env->zoom + env->y1) - (y / (env->zoom / 1.3));
	env->zoom /= 1.3;
	env->it_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_fractol *env)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, env);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, env);
	fract_calc(env);
	return (0);
}
