/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttarumot <ttarumot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:31:24 by ttarumot          #+#    #+#             */
/*   Updated: 2021/02/20 20:05:45 by ttarumot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		kill_philosophers(t_data *data, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	while (i < data->n_philo)
		kill(philo[i++].pid, SIGKILL);
}

int			check_status(t_data *data, t_philo *philo, unsigned int *n_philo,
unsigned int i)
{
	int					status;

	(void)i;
	(void)philo;
	status = 0;
	waitpid(-1, &status, WNOHANG);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 42)
			return (42);
		else if (WEXITSTATUS(status) == 2)
		{
			*n_philo = *n_philo + 1;
			if (*n_philo == data->n_philo)
				return (2);
		}
	}
	return (0);
}

void		monitor_die(t_data *data, t_philo *philo)
{
	unsigned int		i;
	unsigned int		n_philo;
	int					status;

	i = 0;
	n_philo = 0;
	while (i < data->n_philo)
	{
		status = check_status(data, philo, &n_philo, i);
		if (status == 42 || status == 2)
			break ;
		i++;
		if (i == data->n_philo)
			i = 0;
	}
	kill_philosophers(data, philo);
	if (status == 2)
		display_all_meals_ate(data);
}

void		monitor(t_data *data, t_philo *philo)
{
	monitor_die(data, philo);
}
