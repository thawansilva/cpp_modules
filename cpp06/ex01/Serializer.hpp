/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:53:31 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/29 18:03:43 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Data.hpp"
#include <stdint.h>
#include <iostream>

class Serializer
{
	Serializer();
	~Serializer();
	Serializer(const Serializer &src);
	Serializer &operator=(const Serializer &src);

public:
	static uintptr_t serialize(Data *ptr);
	static Data* deserialize(uintptr_t raw);
};
