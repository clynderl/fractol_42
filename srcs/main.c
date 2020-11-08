/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:04:04 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/08 10:07:53 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

int		main(int argc, char *argv[])
{
	t_fractol	*env;

	if (!(env = (t_fractol*)malloc(sizeof(t_fractol))))
		return (-1);
	if (argc == 2 && fract_init(argv, env))
	{
		if (!(mlx_win_init(env)))
			return (0);
		fract_pthread(env);
		mlx_hook(env->win, 6, 1L < 6, mouse_julia, env);
		mlx_hook(env->win, 17, 0L, ft_close, env);
		mlx_key_hook(env->win, key_hook, env);
		mlx_mouse_hook(env->win, mouse_hook, env);
		mlx_loop(env->mlx);
	}
	else
		ft_printf("usage: fractol [ mandelbrot | julia | burningship ]\n");
	return (0);
}
