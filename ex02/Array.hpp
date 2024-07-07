#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<class T> class Array {
	private:
		size_t len;
		T *array;
	public:
		Array(void) {
			this->array = new T[0];
			this->len = 0;
		}

		Array(size_t len) {
			this->array = new T[len];
			this->len = len;
		}

		Array(const Array &copy) {
			try {
				this->array = new T[copy.len];
				for (size_t cursor = 0; cursor < copy.len; cursor++)
					this->array[cursor] = copy.array[cursor];
				this->len = copy.len;
			} catch (std::exception &error) {
				std::cerr << error.what() << std::endl;
				throw("unable to copy the array");
			}
		}

		~Array(void) {
			delete[] this->array;
		}

		Array &operator=(const Array &copy) {
			delete[] this->array;
			this->array = new T[copy.len];
			for (int cursor = 0; cursor < copy.len; cursor++)
				this->array[cursor] = copy.array[cursor];
			this->len = copy.len;
			return *this;
		}

		T &operator[](const size_t index) {
			if (index < 0 || index >= this->len)
				throw OutOfBounds();
			return (this->array[index]);
		}
		
		class OutOfBounds : public std::exception {
			public:
				virtual	const char *what(void) const throw() {
					return ("Index out of bound");
				}
		};
};

#endif
