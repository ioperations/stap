#include <iostream>
#include <utility>
#include <vector>

using offset = int;
using predicate = int;
using expression = int;
using type = int;

namespace vast {
std::vector<std::pair<offset, predicate>> resolve(const expression& expr,
                                                  const type& t) {
    std::vector<std::pair<offset, predicate>> ret;
    ret.push_back(std::make_pair(expr, t));
    return ret;
}
int resolve(int a) { return 10; }
}  // namespace vast

int hello(int a, int b) { return a + b; }

int main(int argc, char* argv[]) {
    auto ret = vast::resolve(1, 2);

    auto ret2 = vast::resolve(100);
    std::cout << ret.size() << std::endl;
    std::cout << ret2 << std::endl;
    std::cout << hello(1, 3) << std::endl;
    return 0;
}
