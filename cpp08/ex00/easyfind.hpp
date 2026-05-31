/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 13:53:49 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/31 17:58:12 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>

//template< typename T >
//int easyfind(T &container, int target)
//{
//	typename T::iterator i;
//	for (i = container.begin(); i != container.end(); ++i)
//	{
//		if (*i == target)
//			return 1;
//	}
//	return	(0);
//}

template< typename T >
int easyfind(T &container, int target)
{
	typename T::iterator i = std::find(container.begin(), container.end(), target);
	if (i != container.end())
		return 1;
	return	(0);
}
