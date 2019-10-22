/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:27:40 by aihya             #+#    #+#             */
/*   Updated: 2019/10/22 18:40:11 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		put_x(int htag_condition, int size, int add_zeros, char *s)
{
	int		ret;

	ret = 0;
	if (htag_condition)
	{
		ret += 2;
		ft_putstr("0x");
	}
	if (add_zeros)
		ret += repeate_char(48, size);
	ft_putstr(s);
	return (ret);
}

int		put_trailing_spaces(t_fs *fs, int condition, int comp_target)
{
	int		ret;

	ret = 0;
	if (condition)
		ret += repeate_char(32, fs->width - comp_target - 2);
	else
		ret += repeate_char(32, fs->width - comp_target);
	return (ret);
}

int		set_x_right_prefix(int val, t_fs *fs, int comp_target, int dp)
{
	int		ret;

	ret = 0;
	if (val != 0 && (fs->flags & F_HTAG))
	{
		if (dp == DEFAULT && (fs->flags & F_ZERO))
		{
			ft_putstr("0x");
			ret += repeate_char(48, fs->width - comp_target - 2) + 2;
		}
		else
		{
			ret += repeate_char(32, fs->width - comp_target - 2) + 2;
			ft_putstr("0x");
		}
	}
	else
	{
		if (dp == DEFAULT && (fs->flags & F_ZERO))
			ret += repeate_char(48, fs->width - comp_target);
		else
			ret += repeate_char(32, fs->width - comp_target);
	}
	return (ret);
}
