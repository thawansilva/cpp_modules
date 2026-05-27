/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:54:06 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/24 13:00:15 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data *data = 0;

	uintptr_t ptr = Serializer::serialize(data);
	Data *res = Serializer::deserialize(ptr);

	std::cout << &ptr << std::endl;
	std::cout << &res << std::endl;
	return (0);
}
