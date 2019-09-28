/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:25:43 by aihya             #+#    #+#             */
/*   Updated: 2019/09/28 18:20:56 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		interpret_format(const char *format, va_list ap)
{
	int		i;
	t_fs	*fs;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && (fs = get_fs(format, i + 1)) != NULL)
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
	fs->length = 0;
	fs->specifier = 0;
	fs->size = 0;
	return (fs);
}

void	set_length(const char *format, int *i, t_fs *fs)
{
	if ((format[*i] == 'h' && format[*i + 1] && format[*i + 1] == 'h')
	||	(format[*i] == 'l' && format[*i + 1] && format[*i + 1] == 'l'))
	{
		fs->length = format[*i] == 'h' ? L_hh : L_ll;
		*i += 2;
	}
	else if (format[*i] == 'h' || format[*i] == 'l')
	{
		fs->length = format[*i] == 'h' ? L_h : L_l;
		*i = *i + 1;
	}
	else if (format[*i] == 'L')
	{
		fs->length = L_L;
		*i = *i + 1;
	}
	*i = *i - 1;
}

void	set_precision(const char *format, int *i, t_fs *fs)
{
	int		j;
	char	*num_string;

	*i = *i + 1;
	if (format[*i] && (format[*i] < 48 || format[*i] > 57))
		fs->precision = 0;
	else
	{
		j = 0;
		while (ft_strchr(NUMBERS, format[*i + j]))
			j++;
		num_string = ft_strsub(format, *i, j);
		fs->precision = ft_atoi(num_string);
		free(num_string);
		*i = *i + j;
	}
	*i = *i - 1;
}

void	set_flags(char c, t_fs *fs)
{
	if (c == ' ')
		fs->flags |= F_SPACE;
	else if (c == '+')
		fs->flags |= F_PLUS;
	else if (c == '-')
		fs->flags |= F_DASH;
	else if (c == '0')
		fs->flags |= F_ZERO;
	else if (c == '#')
		fs->flags |= F_HTAG;
}

void	set_width(const char *format, int *i, t_fs *fs)
{
	int		j;
	char	*num_string;

	j = 0;
	while (format[*i + j] && format[*i + j] >= 48 && format[*i + j] <= 57)
		j++;
	num_string = ft_strsub(format, *i, j);
	fs->width = ft_atoi(num_string);
	free(num_string);
	*i = (*i + j) - 1;
}

t_fs	*get_fs(const char *format, int start_index)
{
	int		i;
	t_fs	*fs;
	int		false_fs;

	false_fs = 0;
	i = start_index;
	fs = init_fs();
	while (format[i])
	{
		if (ft_strchr(LENGTHS, format[i]))
			set_length(format, &i, fs);
		else if (ft_strchr(SPECIFIERS, format[i]))
		{
			fs->specifier = format[i];
			break ;
		}
		else if (format[i] == '.')
			set_precision(format, &i, fs);
		else if (ft_strchr(FLAGS, format[i]))
			set_flags(format[i], fs);
		else if (ft_strchr(NUMBERS, format[i]))
			set_width(format, &i, fs);
		else if ((false_fs = 1))
			break ;
		i++;
	}
	if (false_fs)
	{
		free(fs);
		return (NULL);
	}
	return (fs);
}
