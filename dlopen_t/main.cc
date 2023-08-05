#include <dlfcn.h>
#include <stdio.h>

#define NUM 6
#define LIBPATH "./libcount.so"

int main() {
    void* handler = dlopen(LIBPATH, RTLD_LAZY);
    if (handler == NULL) {
        printf("ERROR:%s:dlopen\n", dlerror());
        return -1;
    }

    void (*inc)() = (void (*)())dlsym(handler, "_Z3incv");
    if (inc == NULL) {
        printf("ERROR:%s:dlsym\n", dlerror());
        return -1;
    }

    int i = 0;
    for (; i < NUM; i++) inc();

    int (*get)() = (int (*)())dlsym(handler, "_Z3getv");
    if (get == NULL) {
        printf("ERROR:%s:dlsym\n", dlerror());
        return -1;
    }
    printf("INFO:get() return %d\n", get());

    dlclose(handler);

    return 0;
}
