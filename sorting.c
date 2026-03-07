#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define SIZE 10


static int *arr, seq[SIZE] = {99, 56, 2, 3, 5, 7, 9, 22, 1, 3};
static void runsort(void (*)(int*, int*), int*, int*);
static inline void swap(int*, int*);
static void pprint(int*, int*);
void insertion(int*, int*);
void selection(int*, int*);


int main(void) {
    if (!(arr = malloc(SIZE * sizeof *arr))) {
        perror("malloc");
        return 1;
    }

    printf("INSERTION SORT\n");
    runsort(insertion, arr, arr + SIZE);

    printf("\nSELECTION SORT\n");
    runsort(selection, arr, arr + SIZE);

    free(arr);
    return 0;
}


static void runsort(void (*sort)(int*, int*), int *begin, int *end)
{
    size_t size = end - begin;
    memcpy(begin, seq, size * sizeof *begin);
    pprint(begin, end);

    sort(begin, end);
    pprint(begin, end);
}


static inline void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


static void pprint(int *begin, int *end)
{
    if (begin >= end) {
        printf("\n");
        return;
    }
    printf("%d ", *begin);
    pprint(begin + 1, end);
}


void insertion(int *begin, int *end)
{
    for (int *j = begin + 1; j < end; j++) {
        int *i, key = *j;
        for (i = j; i > begin && *(i-1) > key; i--)
            *i = *(i-1);
        *i = key;
    }
}


void selection(int *begin, int *end)
{
    for (int *i = begin; i < end - 1; i++) {
        int *min = i;
        for (int *j = i + 1; j < end; j++)
            if (*j < *min) min = j;
        swap(min, i);
    }
}
