/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:53:49 by thaperei          #+#    #+#             */
/*   Updated: 2026/06/05 18:32:19 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>

template< typename T >
int easyfind(T const &container, int target)
{
	typename T::iterator i = std::find(container.begin(), container.end(), target);
	if (i != container.end())
		return (1);
	return	(0);
}

template< typename T >
int easyfind(T &container, int target)
{
	typename T::iterator i = std::find(container.begin(), container.end(), target);
	if (i != container.end())
		return (1);
	return	(0);
}
