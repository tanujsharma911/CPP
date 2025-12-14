#include <stdio.h>
#include <stdlib.h>

int main() {

    int *a = (int*) malloc(3 * sizeof(int));

    a[0] = 1;

    free(a);
    a = NULL;

    a[0] = 2;

    printf("%d %d %d", a[0], a[1], a[2]);
    
    return 0;
}