/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:30:51 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/20 12:42:15 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int			check_args(int argc, char **argv)
{
    (void)argv;
	if (argc != 5 && argc != 6)
		return (1);
	return (0);
}
