/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:51:39 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/24 22:09:28 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int     error_status(char *message)
{
    if (message)
        ft_putendl_fd(message, 2);
    return (1);
}

void    exit_status(char *message)
{
    if (message)
        ft_putendl_fd(message, 2);
    exit(1);
}

void    error_exit(t_state *state, char *message)
{
    state->thread_error = 1;
	sem_wait(state->sem_display);
    if (message)
        ft_putendl_fd(message, 2);
    exit(1);
}
