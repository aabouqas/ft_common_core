//
// Created by Aissam Abouqassime-Eledrissi on 1/13/25.
//

#include "Data.h"

Data::Data() {
	this->data = 0;
}

Data::~Data() {

}

Data::Data(const Data &data) {
	*this = data;
}

Data &Data::operator=(const Data &data) {
	(void)data;
	return *this;
}

Data::Data(int data) {
	this->data = data;
}

int Data::getData() const {
	return this->data;
}
