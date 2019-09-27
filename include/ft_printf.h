/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:29:07 by aihya             #+#    #+#             */
/*   Updated: 2019/09/27 19:21:31 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

# define DEFAULT	-1
# define SPECIFIERS	"cspdiouxXf%"
# define LENGTHS	"hlL"
# define FLAGS		"#0-+ "
# define NUMBERS	"0123456789"

# define F_HT		1
# define F_ZERO		2
# define F_DASH		4
# define F_PLUS		8
# define F_SPACE	16

# define L_h		1
# define L_hh		2
# define L_l		4
# define L_ll		8
# define L_L		16

typedef struct	s_fs
{
	int		flags:5;
	int		width;
	int		precision;
	int		lengths:5;
	char	specifier;
	int		size;
}				t_fs;

int		ft_printf(const char *format, ...);
int		interpret_format(const char *format, va_list ap);

#endif
