/*文件名：cc_mem_test.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char* p1;
char* p2;
char* p3;
char* p4;

void forloop() {
    // sleep(20); //让程序sleep
    // 20s是因为我们程序先起来之后，等待SystemTap启动设置探测点

    p1 = (char*)malloc(500);

    p2 = (char*)malloc(200);

    p3 = (char*)malloc(300);

    p4 = (char*)malloc(300);  //泄漏

    free(p1);

    free(p2);

    free(p3);

    // free(p2); //重复释放

    printf("p1: %p, p2: %p, p3: %p, p4: %p\n", p1, p2, p3, p4);
}

int main(int argc, char* argv[]) {
    while (true) {
        sleep(1);
        forloop();
    }
}
