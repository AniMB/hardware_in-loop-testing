#include <stdio.h>

void printEvenNumbers(int n) {
    printf("Even numbers up to %d are: ", n);
    for (int i = 0; i <= n; i += 2) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int limit = 20;
    printEvenNumbers(limit);
    return 0;
}
