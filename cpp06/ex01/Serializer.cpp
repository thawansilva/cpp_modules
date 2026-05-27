#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	return (dynamic_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (dynamic_cast<Data *>(raw));
}
