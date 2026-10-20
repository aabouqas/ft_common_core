#pragma once

template <typename T>
class Array {
	private:
		T *elements;
		unsigned int _size;
	public:

		Array() {
			elements = NULL;
			_size = 0;
		}

		Array(const unsigned int n) {

			elements = NULL;

			if (n != 0) {
				elements = new T[n];
				for (unsigned int i = 0; i < n; i++)
					elements[i] = T();
			}
			_size = n;
		}

		Array &operator=(const Array &otherArray) {

			if (this == &otherArray)
				return *this;

			delete[] this->elements;

			this->_size = otherArray._size;
			this->elements = new T[_size];

			for (unsigned int n = 0; n < _size; n++) {
				this->elements[n] = otherArray.elements[n];
			}

			return *this;
		}

		Array(const Array &otherArray) {

			this->_size = otherArray._size;
			this->elements = new T[_size];

			for (unsigned int n = 0; n < _size; n++) {
				this->elements[n] = otherArray.elements[n];
			}
		}

		T& operator[](size_t n)  {
            if (this->elements == NULL) {
                throw std::runtime_error("The container is empty");
            }
			if (n >= _size) {
				throw std::out_of_range("Index is out of bounds");
			}
			return elements[n];
		}

		const T& operator[](size_t n) const {

            if (this->elements == NULL) {
                throw std::runtime_error("The container is empty");
            }
			if (n >= _size) {
				throw std::out_of_range("Index is out of bounds");
			}
			return elements[n];
		}

		unsigned int size() const {
			return this->_size;
		}

		~Array() {
			delete[] elements;
		}
};