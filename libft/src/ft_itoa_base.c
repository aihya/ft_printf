/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aihya <aihya@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:10:41 by aihya             #+#    #+#             */
/*   Updated: 2019/10/08 17:52:58 by aihya            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define UPPER_CASE	"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWER_CASE	"0123456789abcdefghijklmnopqrstuvwxyz"

long long	ll_abs(long long n)
{
	return (n >= 0 ? n : (-1) * n);
}

static char	*convert_to_base(long long value, int base, int cap)
{
	int			i;
	int			sign;
	char		buffer[66];
	long long	n;
	char		*base_conv_chars;

	base_conv_chars = ft_strdup(cap == 1 ? UPPER_CASE : LOWER_CASE);
	n = value;
	sign = 0;
	if (sign > 0)
		sign = 1;
	i = 0;
	while (n == LLONG_MIN || ll_abs(n) >= base)
	{
		buffer[i] = base_conv_chars[ll_abs(n % base)];
		n = n / base;
		i++;
	}
	buffer[i++] = base_conv_chars[ll_abs(n)];
	if (sign == 1)
		buffer[i++] = '-';
	buffer[i] = '\0';
	free(base_conv_chars);
	return (ft_strdup(buffer));
}

char		*ft_itoa_base(long long value, int base, int cap)
{
	char	*res;
	char	*buffer;
	int		len;
	int		j;

	buffer = convert_to_base(value, base, cap);
	len = (int)ft_strlen(buffer);
	res = (char *)malloc(sizeof(char) * (len + 1));
	len--;
	j = 0;
	while (len >= 0)
	{
		res[j] = buffer[len];
		len--;
		j++;
	}
	free(buffer);
	res[j] = '\0';
	return (res);
}
