/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:41:54 by aihya             #+#    #+#             */
/*   Updated: 2019/10/16 22:55:25 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

int		print_x_on_right(t_fs *fs, char *s, int size, int val)
{
	int		ret;

	ret = 0;
	if (fs->precision != DEFAULT)
	{
		if (fs->precision >= fs->width)
		{
			ret += set_x_right_prefix(val, fs, fs->precision, 0);
			ret += repeate_char(48, fs->precision - size);
			ft_putstr(s);
		}
		else if (fs->precision >= size)
		{
			ret += set_x_right_prefix(val, fs, fs->precision, 0);
			ret += repeate_char(48, fs->precision - size);
			ft_putstr(s);
		}
		else
		{
			ret += set_x_right_prefix(val, fs, size, 0);
			ft_putstr(s);
		}
	}
	else
	{
		ret += set_x_right_prefix(val, fs, size, DEFAULT);
		ft_putstr(s);
	}
	return (ret + size);
}

int		set_x_left_prefix(int val, t_fs *fs, int comp_target, int dp)
{
	int		ret;

	ret = 0;
	if (val != 0 && (fs->flags & F_HTAG))
	{
		ft_putstr("0x");
		if (dp != DEFAULT)
		{
			ret += repeate_char(48, fs->width - comp_target - 2) + 2;
		}
	}
	return (ret);
}
int		print_x_on_left(t_fs *fs, char *s, int size, int val)
{
	int		ret;

	ret = 0;
	if (fs->precision != DEFAULT)
	{
		if (fs->precision >= fs->width)
		{
			ret += set_x_left_prefix(val, fs, fs->precision, 0);
			ret += repeate_char(48, fs->precision - size);
			ft_putstr(s);
		}
		else if (fs->precision >= size)
		{
			ret += set_x_left_prefix(val, fs, fs->precision + size, 0);
			ft_putstr(s);
			ret += repeate_char(32, fs->precision);
		}
		else
		{
			ft_putstr(s);
			ret += set_x_left_prefix(val, fs, size, 0);
		}
	}
	else
	{
		ret += set_x_left_prefix(val, fs, size, DEFAULT);
		ft_putstr(s);
		if (val != 0 && (fs->flags & F_HTAG))
			ret += repeate_char(32, fs->width - size - 2) + 2;
		else
			ret += repeate_char(32, fs->width - size);
	}
	/*ret = repeate_char(48, fs->precision - size);
	  if (fs->precision >= fs->width)
	  ft_putstr(s);
	  else if (fs->precision > size)
	  {
	  ft_putstr(s);
	  ret += repeate_char(32, fs->width - fs->precision);
	  }
	  else
	  {
	  ft_putstr(s);
	  ret += repeate_char(32, fs->width - size);
	  }*/
	return (ret + size);
}

static char	*get_s(unsigned long long int val, t_fs *fs)
{
	char	*s;
	char	*tmp;

	if (val == 0)
	{
		if (fs->precision == 0)
			s = ft_strdup("");
		else
			s = ft_strdup("0");
		return (s);
	}
	s = ft_itoa_base_u(val, 16, 0);
	return (s);
}

int		print_x(t_fs *fs, va_list ap)
{
	unsigned long long int	val;
	char					*s;
	int						size;
	int						ret;

	if (fs->length == L_hh)
		val = (unsigned char)va_arg(ap, int);
	else if (fs->length == L_h)
		val = (unsigned short int)va_arg(ap, int);
	else if (fs->length == L_l)
		val = (unsigned long int)va_arg(ap, long int);
	else if (fs->length == L_ll)
		val = (unsigned long long int)va_arg(ap, long long int);
	else
		val = (unsigned int)va_arg(ap, int);
	s = get_s(val, fs);
	size = (int)ft_strlen(s);
	ret = 0;
	if (fs->flags & F_DASH)
		ret = print_x_on_left(fs, s, size, val);
	else
		ret = print_x_on_right(fs, s, size, val);
	free(s);
	return (ret);
}

