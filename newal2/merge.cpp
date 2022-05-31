#include <stdio.h>
#include <stdlib.h> // rand()함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리
#include <string.h>
#include <stdbool.h>
#include <memory.h>a
#include "function.h"

#define MAX_STR 1000
#define MAX_RAND_NUM 10000

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void swap_double(double* xp, double* yp)
{
    double temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void merge(int data[], int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[MAX_RAND_NUM]; // 새 배열
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while (i <= q) tmp[k++] = data[i++];
    while (j <= r) tmp[k++] = data[j++];
    for (int a = p; a <= r; a++) data[a] = tmp[a];
}


void mergeSort(int data[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(data, p, q);
        mergeSort(data, q + 1, r);
        merge(data, p, q, r);
    }
}


void merge_double(double data[], int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    int tmp[MAX_RAND_NUM]; // 새 배열
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while (i <= q) tmp[k++] = data[i++];
    while (j <= r) tmp[k++] = data[j++];
    for (int a = p; a <= r; a++) data[a] = tmp[a];
}


void mergeSort_double(double data[], int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort_double(data, p, q);
        mergeSort_double(data, q + 1, r);
        merge_double(data, p, q, r);
    }
}

int main()
{


    char fname[20] = "testint.txt";
    char fname2[20] = "testminus.txt";
    char fname3[20] = "testdouble.txt";
    char fname4[20] = "testtext.txt";


    int size = MAX_RAND_NUM;

    int merge_pos_arr[MAX_RAND_NUM];
    int merge_int_arr[MAX_RAND_NUM];
    double merge_double_arr[MAX_RAND_NUM];

    file_r(fname, merge_pos_arr);
    file_r(fname2, merge_int_arr);
    file_r_double(fname3, merge_double_arr);

    mergeSort(merge_pos_arr, 0, size - 1);
    mergeSort(merge_int_arr, 0, size - 1);
    mergeSort_double(merge_double_arr, 0, size - 1);

    double start_pos, end_pos, start_int, end_int, start_double, end_double;

    start_pos = (double)clock() / CLOCKS_PER_SEC;
    mergeSort(merge_pos_arr, 0, size-1);
    end_pos = (((double)clock()) / CLOCKS_PER_SEC);
    printf("양의 정수 프로그램 수행 시간 :%lf\n", (end_pos - start_pos));
    check_correct(merge_pos_arr, size);


    start_int = (double)clock() / CLOCKS_PER_SEC;
    mergeSort(merge_int_arr, 0, size - 1);
    end_int = (((double)clock()) / CLOCKS_PER_SEC);
    printf(" 정수형 프로그램 수행 시간 :%lf\n", (end_int - start_int));
    check_correct(merge_int_arr, size);



    start_double = (double)clock() / CLOCKS_PER_SEC;
    mergeSort_double(merge_double_arr,0, size-1);
    end_double = (((double)clock()) / CLOCKS_PER_SEC);
    printf("더블형 프로그램 수행 시간 :%lf\n", (end_double - start_double));
    check_double_correct(merge_double_arr, size);


    return 0;
}