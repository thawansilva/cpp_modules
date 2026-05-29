/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 12:54:06 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/29 17:54:53 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data;

	uintptr_t serialize_ptr = Serializer::serialize(&data);
	Data *deserialize_ptr = Serializer::deserialize(serialize_ptr);

	std::cout << serialize_ptr << std::endl;
	std::cout << reinterpret_cast<uintptr_t>(deserialize_ptr) << std::endl;
	return (0);
}
