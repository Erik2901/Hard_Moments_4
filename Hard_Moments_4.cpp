#include <iostream>
#include <string>
#include <utility>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <deque>
#include <math.h>
#include <numeric>

////////// exercise 1

template < typename T , typename S>
void insert_sorted(T&narr, S& number) {
	auto it = find_if(narr.begin(), narr.end(), [number](S i) { return i > number;  });
	narr.insert(it, number);

}

////////

//////// exercise 2

double double_gen()
{
	double i;
	i = rand() % 100;
	i = i / 10;
	return i;
}

auto double_to_int = [](double i) {
	int q = i;
	i = i - q;
	q = i * 10;
	if (q == 0)
	{
		return 1;
	}
	else
	{
		return q;
	}
};

double myfunct1(double a, double b) {
	return a*b;
}
double myfunct2(double a, int b) {
	return (a * a) - (2 * a * b) + (b * b);
}

//////////

int main()
{
	
	///////// exercise 1

	std::vector<double> arr{ 1.21,2.33,4.25 };
	double d = 5.25;
	
	insert_sorted(arr, d);

	for (auto x : arr) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	
	///////////

	//////// exercise 2

	std::vector<double> a(100);
	std::vector<int> b;
	std::generate(a.begin(), a.end(), double_gen);
	std::transform(a.begin(), a.end(), back_inserter(b), double_to_int);
	for(auto x:a) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	for (auto x : b) {
		std::cout << x << " ";
	}
	std::cout << std::endl;

	std::cout << std::inner_product(a.begin(), a.end(), b.begin(), a.size() - 1, myfunct1, myfunct2) << std::endl;

	/////////

	system("pause");
	return 0;
}

