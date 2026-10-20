//
// Created by Aissam Abouqassime-Eledrissi on 1/13/25.
//

#include "Serializer.h"

Serializer::Serializer() {

}

Serializer::~Serializer() {

}

Serializer::Serializer(const Serializer &serializer) {
	*this = serializer;
}

Serializer &Serializer::operator=(const Serializer &serializer) {
	(void) serializer;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t> (ptr);
}

Data*	Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *> (raw);
}
