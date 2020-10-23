/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:59:14 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 12:46:14 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRATOL_H
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# define WIDTH 800
# define HEIGHT 600
# define MBTN_L 1
# define MBTN_R 2
# define MOUSE_UP 5
# define MOUSE_DOWN 4
# define MOUSE_LEFT 7
# define MOUSE_RIGHT 6

typedef struct	s_env
{
	int			(*fun)(struct s_env *e, int x, int y);
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img;
	int			bpp;
	int			en;
	int			ln;
}				t_env;


int		init_mlx(t_env *e);

#endif
