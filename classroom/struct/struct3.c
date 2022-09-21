#include <stdio.h>
// Need for strcpy.
#include <string.h>

struct Data {
    int num;
    char str[5];
};

int main() {
    struct Data data1, data2;
    data1.num = 2019;
    // Set data1.str to "abc".
    // http://www.cplusplus.com/reference/cstring/strcpy/
    strcpy(data1.str, "abc");
    
    printf("data1.num = %d\n", data1.num);
    printf("data1.str = %s\n", data1.str);

    data2 = data1;
    printf("data2.num = %d\n", data2.num);
    printf("data2.str = %s\n", data2.str);

    return 0;
}