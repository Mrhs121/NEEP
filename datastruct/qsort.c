#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void swap(const void* a, const void* b, int size)
{
    assert(a != NULL && b != NULL);
    char tmp = 0;
    int i = 0;
    while (size > 0) {
        tmp = *((char*)a + i);
        *((char*)a + i) = *((char*)b + i);
        *((char*)b + i) = tmp;
        ++i;
        --size;
    }
}

void Qsort(void* base, int left, int right, int size, int (*cmp)(const void* a, const void* b))
{
    assert(base != NULL && size >= 1 && cmp != NULL);    /* left may be < 0 because of the last - 1 */
    if (left >= right) return;
    char* pleft = (char*)base + left * size;
    char* pkey = (char*)base + (left + (right - left) / 2) * size;
    swap(pleft, pkey, size);
    int last = left;
    char* plast = (char*)base + last * size;
    for (int i = left + 1; i <= right; ++i) {
        char* pi = (char*)base + i * size;
        if (cmp(pi, pleft) < 0) {
            ++last;
            plast = (char*)base + last * size;
            swap(pi, plast, size);
        }
    }
    swap(pleft, plast, size);
    Qsort(base, left, last - 1, size, cmp);
    Qsort(base, last + 1, right, size, cmp);
}

int cmp_string(const void* a, const void* b)
{
    assert(a != NULL && b != NULL);
    const char** lhs = (const char**)a;
    const char** rhs = (const char**)b;
    return strcmp(*lhs, *rhs);
}

int cmp_int(const void* a, const void* b)
{
    assert(a != NULL && b != NULL);
    const int* lhs = (const int*)a;
    const int* rhs = (const int*)b;
    if (*lhs < *rhs) {
        return -1;
    } else if (*lhs == *rhs) {
        return 0;
    } else {
        return 1;
    }
}

int cmp_float(const void* a, const void* b)
{
    assert(a != NULL && b != NULL);
    const double* lhs = (const double*)a;
    const double* rhs = (const double*)b;
    if (*lhs < *rhs) {
        return -1;
    } else if (*lhs == *rhs) {
        return 0;
    } else {
        return 1;
    }
}



int main(int argc, char* argv[])
{
    int a[] = {-2, 0, 5, 1, 10, 8, 5, 4, 3, 9};
    int len1 = sizeof(a) / sizeof(a[0]);
    fprintf(stdout, "before sort:\n");
    for (int i = 0; i < len1; ++i) {
        fprintf(stdout, "%d ", a[i]);
    }
    fprintf(stdout, "\n");

    Qsort(a, 0, len1 - 1, sizeof(a[0]), cmp_int);
    fprintf(stdout, "after sort:\n");
    for (int i = 0; i < len1; ++i) {
        fprintf(stdout, "%d ", a[i]);
    }
    fprintf(stdout, "\n");

    double a1[] = {1.2f,1.1f,1.4f};
    int len11 = (int)sizeof(a1) / sizeof(a1[0]);
    fprintf(stdout, "\nbefore sort:\n");
    for (int i = 0; i < len11; ++i) {
        fprintf(stdout, "%f ", a1[i]);
    }
    fprintf(stdout, "\n");

    Qsort(a1, 0, len11 - 1, sizeof(a1[0]), cmp_float);
    fprintf(stdout, "after sort:\n");
    for (int i = 0; i < len11; ++i) {
        fprintf(stdout, "%f ", a1[i]);
    }
    fprintf(stdout, "\n");

    const char* b[] = {"what", "chenwei", "skyline", "wel", "dmr"};
    int len2 = sizeof(b) / sizeof(b[0]);
    fprintf(stdout, "\nbefore sort:\n");
    for (int i = 0; i < len2; ++i) {
        fprintf(stdout, "%s-->", b[i]);
    }
    fprintf(stdout, "\n");

    Qsort(b, 0, len2 - 1, sizeof(b[0]), cmp_string);
    fprintf(stdout, "after sort:\n");
    for (int i = 0; i < len2; ++i) {
        fprintf(stdout, "%s-->", b[i]);
    }
    fprintf(stdout, "\n");
}