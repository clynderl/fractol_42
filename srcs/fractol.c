/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:04:04 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/05 07:56:23 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_win_init(t_fractol *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, HEIGHT, WIDTH, "Fractol");
	env->img = mlx_new_image(env->mlx, HEIGHT, WIDTH);
	env->img_ptr = mlx_get_data_addr(env->img,
			&env->bpp, &env->sl, &env->endian);
}

void	fract_calc(t_fractol *data)
{
	if (data->it_max < 0)
		data->it_max = 0;
	if (data->fract == 0)
		mandelbrot_pthread(data);
	else if (data->fract == 1)
		julia_pthread(data);
	else if (data->fract == 2)
		burningship_pthread(data);
	if (data->show_text)
		put_text(data);
}

int		fract_init(char **argv, t_fractol *env)
{
	if (ft_strcmp(argv[1], "mandelbrot"))
	{
		env->fract = 0;
		mandelbrot_init(env);
	}
	else if (ft_strcmp(argv[1], "julia"))
	{
		env->fract = 1;
		julia_init(env);
	}
	else if (ft_strcmp(argv[1], "burningship"))
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
		mlx_loop(env->mlx);
	}
	else
		ft_printf("usage: fractol [ mandelbrot | julia | burningship ]\n");
	return (0);
}
