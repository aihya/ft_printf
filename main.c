/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:54:13 by aihya             #+#    #+#             */
/*   Updated: 2019/10/09 22:53:03 by aihya            ###   ########.fr       */
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
	printf("size: %d\n", fs->size);
}

int		main(void)
{
	char	*s;

	s = ft_strdup("");
	printf("[%-#10o]\n", 5000);
	ft_printf("{%-#10o}\n", 5000);

//	printf("%d\n", ft_atoi("-5000"));
//	print(get_fs("%%", 1));
//	ft_printf("%l%o%l\n");
	return (0);
}
