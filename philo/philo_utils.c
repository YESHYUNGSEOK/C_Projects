/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:16:42 by hyungnoh          #+#    #+#             */
/*   Updated: 2023/02/16 12:40:14 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_fork_cursor(int	*cur, int *next, int i, int num_of_philos)
{
	if (i == num_of_philos - 1)
	{
		*cur = i;
		*next = 0;
	}
	else
	{
		*cur = i;
		*next = i + 1;
	}
}

int	philo_is_full(t_philos *philos)
{
	if (philos->table->must_eat <= 0)
		return (TRUE);
	else if (philos->status == FULL)
		return (FALSE);
	else
		return (TRUE);
}

int	philo_is_alive(t_philos *philos)
{
	pthread_mutex_lock(&philos->table->die);
	if (philos->table->philo_status == DEAD)
	{
		pthread_mutex_unlock(&philos->table->die);
		return (0);
	}
	if (philos->status == DEAD)
	{
		philos->table->philo_status = DEAD;
		printf("%d\t%d\tdied\n", \
		get_time() - philos->table->start_time, philos->cur + 1);
		pthread_mutex_unlock(&philos->table->die);
		return (0);
	}
	pthread_mutex_unlock(&philos->table->die);
	return (1);
}

int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	check_status(t_philos *philos)
{
	if (philos->must_eat == philos->table->must_eat
		&& philos->table->must_eat > 0)
	{
		philos->status = FULL;
		return (1);
	}
	if (get_time() - philos->last_meal > philos->table->time_to_die)
	{
		philos->status = DEAD;
		return (1);
	}
	if (philos->table->philo_status == DEAD)
		return (1);
	return (0);
}
