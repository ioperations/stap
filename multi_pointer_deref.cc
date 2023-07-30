#include <stdio.h>

#include <string>

#include <sys/sdt.h>

struct test {
    const char* a;
    int b;
};

void func(const char* pstr,const char** ppstr, struct test* pt,
                 struct test** ppt, struct test*** pppt) {
    printf("pstr: %s, *ppstr: %s\n", pstr, *ppstr);
    std::string s (pstr);
    STAP_PROBE2(prov, mark, s.c_str(), pstr);
    printf("pt->a: %s, pt->b: %d: \n", pt->a, pt->b);
    printf("(*ppt)->a: %s, (*ppt)->b: %d: \n", (*ppt)->a, (*ppt)->b);
    printf("(**pppt)->a: %s, (**pppt）->b: %d: \n", (**pppt)->a, (**pppt)->b);
}

int main(int argc, char* argv[]) {
    const char* pstr = "Hello World!";
    struct test t = {.a = R"(aabbcc)", .b = 11};
    struct test* pt = &t;
    struct test** ppt = &pt;

    func(pstr, &pstr, pt, ppt, &ppt);

    return 0;
}
