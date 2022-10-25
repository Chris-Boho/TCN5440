#include "linkedlist.h"

int main() {
    List *list = createList();
    int i, deletedIndex;
    for (i = 0; i < 5; i++) {
        listInsert(list, i);
    }
    printf("Add five values with listInsert: \n");
    printList(list);

    return 0;
}