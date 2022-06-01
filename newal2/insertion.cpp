#include <stdio.h>
#include <stdlib.h> // rand()함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리
#include <string.h>
#include <stdbool.h>
#include <memory.h>
#include "function.h"

//#define MAX_STR 1000
//#define MAX_RAND_NUM 30

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

void insertionSort(ARR* sarr, int n)
{
    int i, key, j;
    sarr->idx[0] = 0;
    for (i = 1; i < n; i++) {
        key = sarr->arr[i];
        int tmpi = i;
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && sarr->arr[j] > key) {
            sarr->arr[j + 1] = sarr->arr[j];
            sarr->idx[j + 1] = sarr->idx[j];
            j = j - 1;
        }
        sarr->arr[j + 1] = key;
        sarr->idx[j + 1] = tmpi;
    }
}

void insertionSort_double(double arr[], int n)
{
    int i, j;
    double key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    char fname[20] = "testint.txt";
    char fname2[20] = "testminus.txt";
    char fname3[20] = "testdouble.txt";
    char fname4[20] = "testtext.txt";

    int size = MAX_RAND_NUM;


    ARR* arr = (ARR*)malloc(sizeof(ARR)); // original
    ARR* insert_pos_arr = (ARR*)malloc(sizeof(ARR)); //sorted

    //int insert_pos_arr[MAX_RAND_NUM];
    int insert_int_arr[MAX_RAND_NUM];
    double insert_double_arr[MAX_RAND_NUM];

    file_r(fname, arr->arr); //read and save to original
    insert_pos_arr = arr; // copy read original array to new array to order
    file_r(fname2, insert_int_arr);
    file_r_double(fname3, insert_double_arr);

    double start_pos, end_pos, start_int, end_int, start_double, end_double;

    printf("Before sorting: ");
    if (size <= 1000) printarridx(insert_pos_arr, size);
    start_pos = (double)clock() / CLOCKS_PER_SEC;
    insertionSort(insert_pos_arr, size); // do sort
    end_pos = (((double)clock()) / CLOCKS_PER_SEC);
    printf("양의 정수 프로그램 수행 시간 :%lf\n", (end_pos - start_pos));
    check_correct(insert_pos_arr->arr, size);
    if (size <= 1000) printarr(insert_pos_arr->arr, size);

    printf("After sorting: ");
    if (size <= 1000) printarridx(insert_pos_arr, size);
    stability_as_arr(insert_pos_arr, size);


    /*
    start_int = (double)clock() / CLOCKS_PER_SEC;
    insertionSort(insert_int_arr, size);
    end_int = (((double)clock()) / CLOCKS_PER_SEC);
    printf("\n 정수형 프로그램 수행 시간 :%lf\n", (end_int - start_int));
    check_correct(insert_int_arr, size);
    if (size <= 1000) printarr(insert_int_arr, size);
    */


    start_double = (double)clock() / CLOCKS_PER_SEC;
    insertionSort_double(insert_double_arr, size);
    end_double = (((double)clock()) / CLOCKS_PER_SEC);
    printf("\n더블형 프로그램 수행 시간 :%lf\n", (end_double - start_double));
    check_double_correct(insert_double_arr, size);
    if (size <= 1000) printarr_double(insert_double_arr, size);

    return 0;
}