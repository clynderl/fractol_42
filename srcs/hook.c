/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 07:55:02 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/08 10:02:26 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys_mac.h"

int		key_hook2(int keycode, t_fractol *env)
{
	if (keycode == KEY_2)
		env->color = 2050;
	else if (keycode == KEY_3)
		env->color = 265;
	else if (keycode == KEY_P)
		env->julia_mouse = !env->julia_mouse;
	return (0);
}

int		key_hook(int keycode, t_fractol *env)
{
	if (keycode == KEY_ESCAPE)
		exit(1);
	else if (keycode == KEY_PAD_ADD)
		env->it_max += 50;
	else if (keycode == KEY_PAD_SUB)
		env->it_max -= 50;
	else if (keycode == KEY_LEFT)
		env->x1 -= 30 / env->zoom;
	else if (keycode == KEY_RIGHT)
		env->x1 += 30 / env->zoom;
	else if (keycode == KEY_DOWN)
		env->y1 += 30 / env->zoom;
	else if (keycode == KEY_UP)
		env->y1 -= 30 / env->zoom;
	// else if (keycode == 49)
	// 	fract_init(env);
	else if (keycode == KEY_1)
		env->color = 1677216;
	key_hook2(keycode, env);
	fract_pthread(env);
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
	fract_pthread(env);
	return (0);
}
