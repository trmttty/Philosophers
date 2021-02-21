/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:51:39 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/22 00:35:23 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int     error_status(char *message)
{
    if (message)
        ft_putendl_fd(message, 2);
    return (1);
}
