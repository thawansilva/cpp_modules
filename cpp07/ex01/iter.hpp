/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 21:10:26 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/29 21:17:15 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template<typename T, typename F>
void	iter(T *arr, size_t len, F func)
{
	if (!arr)
		return ;
	for (size_t i = 0; i < len; ++i) {
		func(arr[i]);
	}
}

template<typename T>
void print(T &num)
{
	std::cout << num << std::endl;
}
