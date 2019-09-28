/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:54:13 by aihya             #+#    #+#             */
/*   Updated: 2019/09/28 19:26:02 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(t_fs *fs)
{
	printf("flags: %d\n", fs->flags);
	printf("width: %d\n", fs->width);
	printf("precision: %d\n", fs->precision);
	printf("length: %d\n", fs->length);
	printf("specifier: %c\n", fs->specifier);
}

int		main(void)
{
//	printf("%  50000d", 5);
//	printf("%d\n", ft_atoi("5000"));
	print(get_fs("%.000002 .00002a", 1));
//	ft_printf("%l%o%l\n");
	return (0);
}
