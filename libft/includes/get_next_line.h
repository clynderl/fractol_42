/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:19:23 by clynderl          #+#    #+#             */
/*   Updated: 2020/10/23 17:16:17 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 2048
# define MAX_FD 8192
# include "libft.h"
# include <unistd.h>

typedef struct		s_file
{
	int				fd;
	char			*str;
	struct s_file	*next;
}					t_file;

int		get_next_line(const int fd, char **line);

#endif
