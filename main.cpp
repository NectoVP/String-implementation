#include <iostream>
#include <cstring>
#include <algorithm>
#include <compare>

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

	String& operator=(const String& other) & {
		if(other.sz <= sz) {
			std::copy(other.arr, other.arr + other.sz, arr);
			sz = other.sz;
			arr[sz] = '\0';
			return *this;
		}
		String copy = other;
		swap(copy);
		return *this;
	}

	~String() {
		delete[] arr;
	}

	const char& operator[](size_t idx) const {
		return arr[idx];
	}

	char& operator[](size_t idx) {
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

	String& operator+=(char c) {
		push_back(c);
		return *this;
	}

	String& operator+=(const String& other) {
		if(sz + other.sz >= cap) {
			cap = sz + other.sz + 1;
			char* new_arr = new char[cap];
			std::copy(arr, arr + sz, new_arr);
			delete[] arr;
			arr = new_arr;
		}

		std::copy(other.arr, other.arr + other.sz, arr + sz);
		sz = sz + other.sz;
		arr[sz] = '\0';

		return *this;
	}

	void clear() {
		sz = 0;
		arr[sz] = '\0';
	}

	bool empty() const {
		return ! sz;
	}

	String substr(size_t start, size_t count) const {
		if(start + count > sz)
			throw std::runtime_error("index is out of range");
		
		String substr(count);
		std::copy(arr + start, arr + start + count, substr.arr);

		return substr;
	}

	void shrink_to_fit() {
		if(sz + 1 == cap)
			return;
		
		cap = sz + 1;
		char* new_arr = new char[cap];
		std::copy(arr, arr + sz, new_arr);
		delete[] arr;
		arr = new_arr;
		arr[sz] = '\0';
	}

	char* data() {
		return arr;
	}

	const char* data() const {
		return arr;
	}

	size_t find(const String& substr) const {
		char* pos = strstr(arr, substr.arr);
		return (pos ? pos - arr : sz);
	}

	friend std::ostream& operator<<(std::ostream&, const String& str);
	
	std::weak_ordering operator<=>(const String& other) const {
		size_t max = std::max(sz, other.sz);
		for(size_t i = 0; i < max; ++i) {
			if(arr[i] == other.arr[i])
				continue;
			if(arr[i] < other.arr[i])
				return std::weak_ordering::less;
			return std::weak_ordering::greater;
		}

		return sz == other.sz ? std::weak_ordering::equivalent : (sz < other.sz ? std::weak_ordering::less : std::weak_ordering::greater);
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

String operator+(const String& str, char c) {
	String copy(str);
	copy += c;
	return copy;
}

String operator+(const String& first, const String& second) {
	String copy = first;
	copy += second;
	return copy;
}

String operator+(char c, const String& str) {
	char* pc = new char(c);
	String copy(pc);
	delete pc;
	copy += str;
	return copy;
}

bool operator==(const String& first, const String& second) {
	if(first.size() != second.size())
		return false;
	
	for(size_t i = 0; i < first.size(); ++i) {
		if(first[i] != second[i])
			return false;
	}

	return true;
}

bool operator!=(const String& first, const String& second) {
	return !(first == second);
}

int main() {
}