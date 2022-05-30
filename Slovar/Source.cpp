#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

struct Dict
{
    void add()
    {
        std::string w, t;
        std::cout << ">>> "; std::cin >> w;
        std::vector<std::string> v;
        while (std::cin.peek() != '\n')
        {
            std::cin >> t;
            v.emplace_back(std::move(t));
        }
        dict[w] = v;
        std::cin.ignore();
    }

    void to_file()
    {
        std::ofstream o("dict.txt");
        info_all(o);
    }

    void to_display()
    {
        info_all(std::cout);
    }

private:
    void info_all(std::ostream& o)
    {
        for (const auto& [word, trans] : dict)
        {
            o << word << " \t- ";
            int i = 0;
            for (const auto& t : trans)
            {
                o << t;
                if (i < trans.size() - 1) o << ", ";
                else                   o << "\n";
                i++;
            }
        }
    }

    std::map<std::string, std::vector<std::string>> dict;
};

int main()
{
    Dict dict;

    dict.add();
    dict.add();
    dict.add();

    dict.to_display();
    dict.to_file();
}