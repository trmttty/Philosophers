/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 11:59:22 by Jeanxavier        #+#    #+#             */
/*   Updated: 2021/02/24 10:36:59 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int			main(int argc, char **argv)
{
	t_philo		*philo;
	t_state		*state;
	t_data		*data;

	if (check_args(argc, argv))
		return (error_status(INVAL));
	if (!(state = ft_calloc(1, sizeof(t_state))))
		return (error_status(NOMEM));
	if (init_state(argc, argv, state))
		return (1);
	if (!(philo = ft_calloc(state->num_philo, sizeof(t_philo))))
		return (error_status(NOMEM));
	if (init_philosopher(philo, state))
		return (1);
	if (!(data = ft_calloc(state->num_philo, sizeof(t_data))))
		return (error_status(NOMEM));
	if (launch(philo, state, data))
		return (1);
	if (monitor(state))
		return (1);
	free(philo);
	free(state);
	free(data);
	return (0);
}
