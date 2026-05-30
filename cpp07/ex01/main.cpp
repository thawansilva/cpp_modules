/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 20:32:52 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/29 21:10:42 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

int main( void )
{
	int arr_int[5] = {1, 2, 3, 4, 5};
	iter(arr_int, 5, print<int>);
	std::cout << std::endl;
	
	float arr_float[5] = {1.10, 2.20, 3.30, 4.40, 5.50};
	iter(arr_float, 5, print<float>);
	std::cout << std::endl;

	char arr_char[5] = { 'a', 'e', 'i', 'o', 'u'};
	iter(arr_char, 5, print<char>);
	return 0;
}
