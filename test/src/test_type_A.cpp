
#include <type_A.h>

#include <iostream>
#include <stdexcept>


void test_type_A()
{
	try 
	{
		std::cout << "test type A" << std::endl;
		A a;
		a.print();

		sequence<int>();

		triangular<int>();
		fibonacci<int>();
		sum_squares<int>();
		sum_squares<char>(); // overflow expected

	}
	catch (std::out_of_range&)
	{
		std::cout << "out_of_range exception" << std::endl;
	}

}