#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
// 18年qsort
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


enum TYPE{INT,FLOAT,CHAR,STR};
typedef enum TYPE Datatype;

// 适用于任何类型
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
    // 指向字符串的指针 *--->char * 
    const char** lhs = (const char**)a;
    const char** rhs = (const char**)b;
    // char ** 解一层引用就是char * 也就是字符串
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

void Qsort1(void* base, int left, int right, int size, Datatype type){
    //  可以根据 type的值来调用不用类型的compare
    if (type == INT)
    {
        printf("data type is int\n");
        Qsort(base, left, right, size, cmp_int);
    } else if(type == FLOAT){
        printf("float\n");
    } else if(type == CHAR){
        printf("char\n");
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

    // 长度 每个元素的长度   比较函数
    Qsort1(a, 0, len1 - 1, sizeof(a[0]), INT);

    fprintf(stdout, "after sort:\n");
    for (int i = 0; i < len1; ++i) {
        fprintf(stdout, "%d ", a[i]);
    }
    fprintf(stdout, "\n");

    // double a1[] = {1.2f,1.1f,1.4f};
    // int len11 = (int)sizeof(a1) / sizeof(a1[0]);
    // fprintf(stdout, "\nbefore sort:\n");
    // for (int i = 0; i < len11; ++i) {
    //     fprintf(stdout, "%f ", a1[i]);
    // }
    // fprintf(stdout, "\n");

    // Qsort(a1, 0, len11 - 1, sizeof(a1[0]), cmp_float);
    // fprintf(stdout, "after sort:\n");
    // for (int i = 0; i < len11; ++i) {
    //     fprintf(stdout, "%f ", a1[i]);
    // }
    // fprintf(stdout, "\n");

    // const char* b[] = {"what", "chenwei", "skyline", "wel", "dmr"};
    // int len2 = sizeof(b) / sizeof(b[0]);
    // fprintf(stdout, "\nbefore sort:\n");
    // for (int i = 0; i < len2; ++i) {
    //     fprintf(stdout, "%s-->", b[i]);
    // }
    // fprintf(stdout, "\n");

    // Qsort(b, 0, len2 - 1, sizeof(b[0]), cmp_string);
    // fprintf(stdout, "after sort:\n");
    // for (int i = 0; i < len2; ++i) {
    //     fprintf(stdout, "%s-->", b[i]);
    // }
    // fprintf(stdout, "\n");
}