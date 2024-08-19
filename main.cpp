#include <iostream>
#include <cstring>
#include <algorithm>

class String {
private:
	String(size_t size) : sz(size), cap(size + 1), arr(new char[cap]) {
		arr[sz] = '\0';
	}

	void swap(String& other) {
		std::swap(sz, other.sz);
		std::swap(cap, other.cap);
		std::swap(arr, other.arr);
	}

	void check(size_t idx) const {
		if(idx >= sz)
			throw std::runtime_error("index is out of range");
	}
public:
	String() {}

	String(const char* str) : String(strlen(str))  {
		std::copy(str, str + sz, arr);
	}

	String(size_t n, char c) : String(n) {
		std::fill(arr, arr + sz, c);
	}

	String(const String& other) : String(other.sz) {
		std::copy(other.arr, other.arr + sz, arr);
	}

	String& operator=(String other) {
		swap(other);
		return *this;
	}

	~String() {
		delete[] arr;
	}

	friend std::ostream& operator<<(std::ostream&, const String& str);

	const char& operator[](size_t idx) const {
		check(idx);
		return arr[idx];
	}

	char& operator[](size_t idx) {
		check(idx);
		return arr[idx];
	}

	size_t length() const {
		return sz;
	}

	size_t size() const {
		return sz;
	}

	size_t capacity() const {
		return cap - 1;
	}

	void pop_back() {
		--sz;
		arr[sz] = '\0';
	}

	void push_back(char c) {
		if(sz == cap - 1) {
			cap *= 2;
			char* new_arr = new char[cap];
			std::copy(arr, arr + sz, new_arr);
			delete[] arr;
			arr = new_arr;
		}

		arr[sz] = c;
		arr[++sz] = '\0';
	}

	const char& front() const {
		return arr[0];
	}

	char& front() {
		return arr[0];
	}

	const char& back() const {
		return arr[sz - 1];
	}

	char& back() {
		return arr[sz - 1];
	}

private:
	size_t sz = 0;
	size_t cap = 0;
	char* arr = nullptr;
};

std::ostream& operator<<(std::ostream& os, const String& str) {
	os << str.arr;
	return os;
}

int main() {

}