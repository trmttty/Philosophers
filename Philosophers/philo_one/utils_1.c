/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:30:51 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/27 22:44:44 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int				check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (1);
	argv++;
	while (*argv)
	{
		if (!is_uint(*argv))
			return (1);
		if (ft_atou64(*argv) == 0)
			return (1);
		argv++;
	}
	return (0);
}

static int		is_wspace(const char c)
{
	return (c == '\t' || c == '\n' || c == '\v' \
			|| c == '\f' || c == '\r' || c == ' ');
}

int				is_uint(const char *str)
{
	while (is_wspace(*str))
		str++;
	if (*str == '-')
		return (0);
	while (*str)
	{
		if (*str < '0' && *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static uint64_t	set_number(const char *str)
{
	uint64_t	nb;

	nb = 0;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + (*str++ - '0');
	return (nb);
}

uint64_t		ft_atou64(const char *str)
{
	uint64_t	sign;

	sign = 1;
	while (is_wspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	return (sign * set_number(str));
}
