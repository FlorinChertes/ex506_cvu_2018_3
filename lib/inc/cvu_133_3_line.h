#pragma once


#include <string>
#include <iostream>

class line
{
    std::string line;
    int idx;

public:
    bool read(std::istream& is) {

        bool ret_val = false;

        idx = 0;

        if (const bool is_getline_good = std::getline(is, line).good();
            is_getline_good == true)
        {
            std::cout << line << std::endl;
            ret_val = true;
        }

        return ret_val;
    }

    // scan for the next 'delim', either forwards
    // or backwards
    auto scan(int delim = ' ', bool forward = true)
    {
        int len = 0;
        for (;;)
        {
            // are we at one end or the other?
            if (idx == (forward ? line.size() - 1 : 0))
            {
                return len + 1;
            }

            idx += forward ? 1 : -1;

            if (line[idx] == delim) return len + 1;
            len++;
        }
    }
};
