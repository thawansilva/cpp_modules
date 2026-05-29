/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaperei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 17:54:41 by thaperei          #+#    #+#             */
/*   Updated: 2026/05/29 18:08:22 by thaperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data(): data("Data") {}

Data::~Data() {}

Data::Data(const Data &src): data("Data")
{
	*this = src;
}

Data &Data::operator=(const Data &src)
{
	this->data = src.getData();
	return *this;
}

const char *Data::getData() const
{
	return data;
}
