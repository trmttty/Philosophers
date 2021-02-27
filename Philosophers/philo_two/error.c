/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:51:39 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/27 11:26:53 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		error_status(char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
	return (1);
}

void	*error_exit(t_state *state, char *message)
{
	state->thread_error = 1;
	sem_wait(state->sem_display);
	if (message)
		ft_putendl_fd(message, 2);
	sem_post(state->sem_stop);
	return ((void*)1);
}
