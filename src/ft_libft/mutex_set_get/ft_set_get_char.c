/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_get_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:40:00 by allan             #+#    #+#             */
/*   Updated: 2024/10/17 17:16:47 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	set_char(pthread_mutex_t *mutex, char *dest, char value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

char	get_char(pthread_mutex_t *mutex, char *value)
{
	char	get;

	pthread_mutex_lock(mutex);
	get = *value;
	pthread_mutex_unlock(mutex);
	return (get);
}

void	set_u_char(pthread_mutex_t *mutex,
		unsigned char *dest, unsigned char value)
{
	pthread_mutex_lock(mutex);
	*dest = value;
	pthread_mutex_unlock(mutex);
}

unsigned char	get_u_char(pthread_mutex_t *mutex, unsigned char *value)
{
	unsigned char	get;

	pthread_mutex_lock(mutex);
	get = *value;
	pthread_mutex_unlock(mutex);
	return (get);
}
