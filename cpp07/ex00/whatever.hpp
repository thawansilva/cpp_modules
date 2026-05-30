/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:06:41 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/29 20:33:35 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void	swap(T &x, T&y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
T	&min(T &x, T&y)
{
	return (x < y ? x : y);
}

template<typename T>
T	&max(T &x, T&y)
{
	return (x > y ? x : y);
}
