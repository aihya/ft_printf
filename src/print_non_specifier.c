/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_non_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:39:00 by aihya             #+#    #+#             */
/*   Updated: 2019/10/11 15:34:22 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		print_non_specifier(t_fs *fs, int c)
{
	int		size;

	size = 0;
	if (fs->width > 1)
	{
		if (fs->flags & F_DASH)
		{
			ft_putchar(c);
			repeate_char(' ', fs->width - 1);
		}
		else if (fs->flags & F_ZERO)
		{
			repeate_char('0', fs->width - 1);
			ft_putchar(c);
		}
		else if ((fs->flags & F_ZERO) == 0)
		{
			repeate_char(' ', fs->width - 1);
			ft_putchar(c);
		}
		size = 1 + fs->width - 1;
	}
	else
	{
		ft_putchar(c);
		size = 1;
	}
	return (size);
}
