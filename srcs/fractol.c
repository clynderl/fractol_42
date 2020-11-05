/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:04:04 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/05 13:18:48 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "ft_printf.h"

void	mlx_win_init(t_fractol *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, HEIGHT, WIDTH, "Fractol");
	env->img = mlx_new_image(env->mlx, HEIGHT, WIDTH);
	env->img_ptr = mlx_get_data_addr(env->img,
			&env->bpp, &env->sl, &env->endian);
}

void	fract_calc(t_fractol *env)
{
	if (env->it_max < 0)
		env->it_max = 0;
	if (env->fract == 0)
		mandelbrot_pthread(env);
	else if (env->fract == 1)
		julia_pthread(env);
	else if (env->fract == 2)
		burningship_pthread(env);
	if (env->show_text)
		put_text(env);
}

int		fract_init(char **argv, t_fractol *env)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		env->fract = 0;
		mandelbrot_init(env);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		env->fract = 1;
		julia_init(env);
	}
	else if (ft_strcmp(argv[1], "burningship") == 0)
	{
		env->fract = 2;
		burningship_init(env);
	}
	else
		return (0);
	return (1);
}

int		main(int argc, char *argv[])
{
	t_fractol	*env;

	if (!(env = (t_fractol*)malloc(sizeof(t_fractol))))
		return (-1);
	if (argc == 2 && fract_init(argv, env))
	{
		mlx_win_init(env);
		fract_calc(env);
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
