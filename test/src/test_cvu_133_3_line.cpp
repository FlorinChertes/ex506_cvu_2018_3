#include <iostream>

#include "../inc/test_cvu_133_3_line.h"
#include "../../lib/inc/cvu_133_3_line.h"

int test_cvu_33_3_line()
{
    line l;
    while (l.read(std::cin))
    {
        std::cout << "Length of first word: "
            << l.scan() << std::endl;
        std::cout << "Rest of line: "
            << l.scan(std::char_traits<char>::eof())
            << std::endl;
        std::cout << "Length of last word: "
            << l.scan(' ', false) << std::endl;
    }

    return 0;
}