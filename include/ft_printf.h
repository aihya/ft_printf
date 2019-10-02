/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:29:07 by aihya             #+#    #+#             */
/*   Updated: 2019/10/02 20:34:27 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

# define DEFAULT	-1
# define SPECIFIERS	"cspdiouxXf%"
# define LENGTHS	"hlL"
# define FLAGS		"#0-+ "
# define NUMBERS	"0123456789"
# define ALL		"01234567893#-+ hlL."

# define F_HTAG		1
# define F_ZERO		2
# define F_DASH		4
# define F_PLUS		8
# define F_SPACE	16

# define L_h		1
# define L_hh		2
# define L_l		3
# define L_ll		4
# define L_L		5

typedef struct	s_fs
{
	unsigned int	flags:5;
	int				width;
	int				precision;
	int				length;
	char			specifier;
	int				size;
}				t_fs;

void	print(t_fs *fs);
int		ft_printf(const char *format, ...);
int		interpret_format(const char *format, va_list ap);
t_fs	*get_fs(const char *format, int start_index);

#endif
