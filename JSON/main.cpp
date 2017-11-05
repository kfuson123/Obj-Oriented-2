#include <iostream>
#include <iterator>
#include <string>

#include "json.hpp"

using namespace std;

int main()
{
    std::string str((std::istreambuf_iterator<char>(std::cin)),
                   std::istreambuf_iterator<char>());

  Value* v = parse(str);
  v->print();

}
