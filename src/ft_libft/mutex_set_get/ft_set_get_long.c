/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_get_long.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:40:00 by allan             #+#    #+#             */
/*   Updated: 2024/10/17 17:16:23 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	get;

	pthread_mutex_lock(mutex);
	get = *value;
	pthread_mutex_unlock(mutex);
	return (get);
}

void	set_u_long(pthread_mutex_t *mutex,
		unsigned long *dest, unsigned long value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

unsigned long	get_u_long(pthread_mutex_t *mutex, unsigned long *value)
{
	unsigned long	get;

	pthread_mutex_lock(mutex);
	get = *value;
	pthread_mutex_unlock(mutex);
	return (get);
}
