#include <iostream>

class A {
public:
	int* a;
	A(const A& rhs) {
		a = new int[10000];
		for (size_t i = 0; i < 10000; i++)
		{
			a[i] = rhs.a[i];
		}
	}
	A(A&& rhs) {
		a = rhs.a;
		rhs.a = nullptr;
	}
	A() {
		a = new int[10000];
	}
};

int main() {
	A a;
	while (true)
	{
		// copy
		//A i(a);
		// move
		A j(std::move(a));
		std::cout << a.a[5] << '\n';
	}
	return 0;
}