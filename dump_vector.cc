#include <iostream>
#include <vector>

using namespace std;

void DumpVector(vector<int>& vec){
    for(auto &ptr  : vec ){
        std::cout<< ptr  << std::endl ;
    }
}

int main (int argc, char *argv[]) {
     std::vector<int> vec{1,2,3,4,5,6};

    DumpVector(vec);
    return 0;
}
