/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:53:49 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/04 19:40:16 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template< typename T >
int easyfind(T const &container, int target)
{
	for (typename T::iterator i = container.begin(); i != container.end(); ++i)
		if (*i == target) return 1;
	return	(0);
}

template< typename T >
int easyfind(T &container, int target)
{
	for (typename T::iterator i = container.begin(); i != container.end(); ++i)
		if (*i == target) return 1;
	return	(0);
}
