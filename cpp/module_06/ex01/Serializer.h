//
// Created by Aissam Abouqassime-Eledrissi on 1/13/25.
//
#pragma once
#include <stdint.h>
#include "Data.h"
#include <iostream>

class Serializer {
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &serializer);
		Serializer &operator=(const Serializer &serializer);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

