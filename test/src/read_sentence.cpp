
#include <regex>

#include <fstream>
#include <iostream>

#include <iterator>
#include <sstream>
#include <string>

void read_sentence()
{
    std::ifstream ifs("data_cvu_2020_v31_6.txt");
    const std::string s( (std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>() );

    const std::regex reg(R"(\S[\s\S]*?\.)");
    const std::sregex_iterator end;
    const std::regex whitespace("[\\s]+");
    for (std::sregex_iterator pos(s.cbegin(), s.cend(), reg); pos != end; ++pos)
    {
        const std::string sentence(pos->str());

        regex_replace(
            std::ostream_iterator<char>(std::cout),
            sentence.begin(), sentence.end(),
            whitespace, " ");

        std::cout << '\n';
    }
}

void read_sentence_hv()
{
    std::ifstream ifs("data_cvu_2020_v31_6.txt");
    std::stringstream ss;
    for (std::string word; ifs >> word;)
    {
        ss << ' ' << word;
    }
    const std::string s = ss.str();

    const std::regex re(R"(\S([^.]*\.))");
    const std::sregex_iterator end;
    for (std::sregex_iterator it(s.begin(), s.end(), re); it != end; ++it)
    {
        const std::smatch& match = *it;
        const std::string& match_str = match.str();
        std::cout << match_str << '\n';
    }
}
