#include <iostream>
#include <cstring>
#include <algorithm>

class String {
private:
	String(int size) : sz(size), cap(size + 1), arr(new char[cap]) {
		arr[sz] = '\0';
	}

public:
	String(const char* str) : String(strlen(str))  {
		std::copy(str, str + sz, arr);
	}

private:
	int sz;
	int cap;
	char* arr;
};

int main() {
}