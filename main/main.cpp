#include <iostream>
#include <string>

#include <read_sentence.h>
#include <test_type_A.h>

#include "../test/inc/test_cvu_33_3_line.h"

void call_test_type_A()
{
	test_type_A();
}

void call_read_sentence()
{
	read_sentence();
}

void call_read_sentence_hv()
{
	read_sentence_hv();
}


int main (int argc, char *argv[])
{
	std::cout << "test_main" << std::endl;

	//call_test_type_A();

    //call_read_sentence();
	//call_read_sentence_hv();

	test_cvu_33_3_line();

	return 0;
}

