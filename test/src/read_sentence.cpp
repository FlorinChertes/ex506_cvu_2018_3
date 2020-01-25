
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>

using namespace std;

void read_sentence()
{
    ifstream ifs("data_cvu_2020_v31_6.txt");
    const string s( (istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>() );

    const regex reg(R"(\S[\s\S]*?\.)");
    const sregex_iterator end;
    const regex whitespace("[\\s]+");

    for (sregex_iterator pos(s.cbegin(), s.cend(), reg); pos != end; ++pos)
    {
        const string sentence(pos->str());
        regex_replace(
            ostream_iterator<char>(cout),
            sentence.begin(), sentence.end(),
            whitespace, " ");
        cout << '\n';
    }

}