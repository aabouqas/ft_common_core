#include "Serializer.h"

int main() {
	try {
		Data *data = new Data(100);

		std::cout << "Data ptr : " <<  data << std::endl;

		uintptr_t ptr = Serializer::serialize(data);

		Data *restoredData = Serializer::deserialize(ptr);

		std::cout << "Casted ptr : " << restoredData << std::endl << std::endl;

		std::cout << "Data : " << restoredData->getData() << std::endl;

		delete data;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
