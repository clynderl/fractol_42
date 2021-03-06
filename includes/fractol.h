/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:59:14 by clynderl          #+#    #+#             */
/*   Updated: 2020/11/08 09:57:34 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <pthread.h>
# include "libft.h"
# define HEIGHT 600
# define WIDTH 600
# define THREAD_WIDTH 5
# define THREAD_NUMBER 120

typedef struct	s_fractol
{
	void		(*function)(struct s_fractol *e);
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			fract;
	int			color;
	int			julia_mouse;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	double		zoom;
	double		x1;
	double		y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
}				t_fractol;

int		mlx_win_init(t_fractol *env);
void	mandelbrot_calc(t_fractol *env);
void	julia_calc(t_fractol *env);
void	burningship_calc(t_fractol *env);
void	fract_pthread(t_fractol *env);
int		ft_close(void);
void	put_pxl_to_img(t_fractol *data, int x, int y, int color);
void	burningship_init(t_fractol *data);
void	fract_calc(t_fractol *data);
int		fract_init(char **argv, t_fractol *env);
int		key_hook(int keycode, t_fractol *data);
int		mouse_julia(int x, int y, t_fractol *data);
int		mouse_hook(int mousecode, int x, int y, t_fractol *data);

#endif
