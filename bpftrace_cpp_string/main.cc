#include <iostream>
#include <string>

void T(const std::string& tt = "Hello") { std::cout << tt << std::endl; }

struct Dummy {
    std::string s;
};

int main(int argc, char* argv[]) {
    std::string s = "this is a long string literal";
    T(s);
    Dummy d;
    d.s = "Hello";

    return 0;
}
