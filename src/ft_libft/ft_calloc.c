/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:31:43 by allan             #+#    #+#             */
/*   Updated: 2024/10/22 22:21:10 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (size > __SIZE_MAX__ / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == (NULL))
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}
