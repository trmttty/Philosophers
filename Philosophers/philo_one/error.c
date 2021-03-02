/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 23:51:39 by ttarumot          #+#    #+#             */
/*   Updated: 2021/03/02 09:41:32 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		error_status(char *message)
{
	if (message)
		ft_putendl_fd(message, 2);
	return (1);
}

void	*error_exit(t_state *state, char *message)
{
	state->thread_error = 1;
	pthread_mutex_lock(state->m_display);
	if (message)
		ft_putendl_fd(message, 2);
	pthread_mutex_unlock(state->m_display);
	return ((void*)1);
}
