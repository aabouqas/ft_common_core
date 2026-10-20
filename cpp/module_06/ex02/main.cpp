#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <ctime>

Base * generate(void) {
	time_t now = time(0);

	int selected = (int) (now % 3);
	if (selected == 0) {
		return new A();
	} else if (selected == 1) {
		return new B();
	}
	return new C();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL) {
		std::cout << "Pointer to : A" << std::endl;
	} else if (dynamic_cast<B*>(p) != NULL) {
		std::cout << "Pointer to : B" << std::endl;
	} else if (dynamic_cast<C*>(p) != NULL) {
		std::cout << "Pointer to : C" << std::endl;
	}
}

void identify(Base& p) {
	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "Reference to : A" << std::endl;
	} catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
	}
	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "Reference to : B" << std::endl;
	} catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
	}
	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "Reference to : C" << std::endl;
	} catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
	}
}


int main() {
	try {
		Base *obj = generate();

		identify(obj);
		identify(*obj);

		delete obj;

	} catch (std::exception &e) {
		(void) e;
	}
	return 0;
}
