/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:29:07 by aihya             #+#    #+#             */
/*   Updated: 2019/09/26 13:00:34 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

# define SPECIFIERS	"cspdiouxXf%"
# define LENGHTS	"hlL"
# define FLAGS		"#0-+"

typedef struct	s_fs
{
	char	*flags;
	int		width;
	int		precision;
	int		length;
	char	specifier;
}				t_fs;

int		ft_printf(const char *format, ...);
int		interpret_format(const char *format, va_list ap);

#endif
