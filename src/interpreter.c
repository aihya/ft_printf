/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:25:43 by aihya             #+#    #+#             */
/*   Updated: 2019/09/27 19:25:40 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		interpret_format(const char *format, va_list ap)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			
		}
		i++;
	}
	return (1);
}

t_fs	*init_fs()
{
	t_fs	*fs;

	fs = (t_fs *)malloc(sizeof(t_fs));
	fs->flags = 0;
	fs->width = 0;
	fs->precision = DEFAULT;
	fs->lengths = 0;
	fs->specifier = 0;
	fs->size = 0;
	return (fs);
}
/*
t_fs	*new_fs(const char *format, int start_index)
{
	int		i;
	t_fs	*fs;

	i = start_index;
	fs = init_fs();
	while (format[i])
	{
		if (ft_strchr(LENGTHS, format[i]))
		{
			free(fs->lengths);
			if ((format[i] == 'h' && format[i + 1] && format[i + 1] == 'h')
			||	(format[i] == 'l' && format[i + 1] && format[i + 1] == 'l'))
			{
				fs->lengths = ft_strsub(format, i, 2);
				i += 2;
			}
			else if (format[i] == 'h' || format[i] == 'l')
			{
				fs->lengths = ft_strsub(format, i, 1);
				i++;
			}
			continue ;
		}
		else if (ft_strchr(SPECIFIERS, format[i]))
		{
			fs->specifier = format[i];
			break ;
		}
		else if (format[i] == ' ')
		{
			i++;
			continue ;
		}
		else if (format[i] == '.' && ++i)
		{
			while (format[i] && (format[i] == ' ' || format[i] == '0'))
			{
				if (format[i] == '0')
			}
		}
	}
}*/
