#include <iostream>
#include <string>

#include <test_type_A.h>

void call_test_type_A()
{
	test_type_A();
}

int main (int argc, char *argv[])
{
	
	std::cout << "test_main" << std::endl;
	
	call_test_type_A();
	
	return 0;
}

