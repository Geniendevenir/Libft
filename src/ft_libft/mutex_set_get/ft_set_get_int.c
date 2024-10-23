/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_get_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:40:00 by allan             #+#    #+#             */
/*   Updated: 2024/10/17 17:16:39 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_int(pthread_mutex_t *mutex, int *dest, int value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

int	get_int(pthread_mutex_t *mutex, int *value)
{
	int	get;

	pthread_mutex_lock(mutex);
	get = *value;
	pthread_mutex_unlock(mutex);
	return (get);
}

void	set_u_int(pthread_mutex_t *mutex,
		unsigned int *dest, unsigned int value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

unsigned int	get_u_int(pthread_mutex_t *mutex, unsigned int *value)
{
	unsigned int	get;

	pthread_mutex_lock(mutex);
	get = *value;
	pthread_mutex_unlock(mutex);
	return (get);
}
