#include "stdio.h"
#include "string.h"

struct t {
    const char* z[10];
};

void fun(struct t* v, const char* z) {
    printf("%s\n", v->z[0]);
    printf("%s\n", v->z[1]);
    printf("%s\n", z);
}

int main(int argc, char* argv[]) {
    struct t val;
    val.z[0] = "hello";
    val.z[1] = "world";
    fun(&val, "hello world");
    return 0;
}
