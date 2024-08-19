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