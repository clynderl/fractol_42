/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 12:04:04 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 17:57:44 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int argc, char *argv[])
{
	t_env	*env;

	if (argc == 2)
	{
		if (!(env = malloc(sizeof(t_env))))
			return (0);
		if (!(init_mlx(env)))
			return (0);
	}
	else
		usage();
	return (0);
}
