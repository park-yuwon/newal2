#include <stdio.h>
#include <stdlib.h> // rand()함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리
#include <string.h>
#include <stdbool.h>
#include <memory.h>
#include "function.h"

//#define MAX_STR 1000
//#define MAX_RAND_NUM 30000

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



int partition(ARR* arr, int low, int high)
{
    int pivot = arr->arr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr->arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr->arr[i], &arr->arr[j]);
            swap(&arr->idx[i], &arr->idx[j]);
        }
    }
    swap(&arr->arr[i + 1], &arr->arr[high]);
    swap(&arr->idx[i + 1], &arr->idx[high]);
    return (i + 1);
}

void quickSort(ARR* arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int partition_double(DOUBLEARR *arr, int low, int high)
{
    double pivot = arr->doublearr[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr->doublearr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap_double(&arr->doublearr[i], &arr->doublearr[j]);
            swap(&arr->idx[i], &arr->idx[j]);
        }
    }
    swap_double(&arr->doublearr[i + 1], &arr->doublearr[high]);
    swap(&arr->idx[i + 1], &arr->idx[high]);
    return (i + 1);
}

void quickSort_double(DOUBLEARR * arr, int low, int high) {
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition_double(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort_double(arr, low, pi - 1);
        quickSort_double(arr, pi + 1, high);
    }
}

int main()
{


    char fname[20] = "testint.txt";
    char fname2[20] = "testminus.txt";
    char fname3[20] = "testdouble.txt";
    char fname4[20] = "testtext.txt";

    int size = MAX_RAND_NUM;


    ARR* quick_pos_arr = (ARR*)malloc(sizeof(ARR));
    //int quick_pos_arr[MAX_RAND_NUM];
    ARR* quick_int_arr = (ARR*)malloc(sizeof(ARR));
    //int quick_int_arr[MAX_RAND_NUM];
    DOUBLEARR* quick_double_arr = (DOUBLEARR*)malloc(sizeof(DOUBLEARR));
    //double quick_double_arr[MAX_RAND_NUM];

    for (int i = 0; i < size; i++) {
        quick_pos_arr->idx[i] = i;
        quick_int_arr->idx[i] = i;
        quick_double_arr->idx[i] = i;
    }

    file_r(fname, quick_pos_arr->arr);
    file_r(fname2, quick_int_arr->arr);
    file_r_double(fname3, quick_double_arr->doublearr);

    quickSort(quick_pos_arr, 0, size - 1);
    quickSort(quick_int_arr, 0, size - 1);
    quickSort_double(quick_double_arr, 0, size - 1);

    double start_pos, end_pos, start_int, end_int, start_double, end_double;

    start_pos = (double)clock() / CLOCKS_PER_SEC;
    quickSort(quick_pos_arr,0, size-1);
    end_pos = (((double)clock()) / CLOCKS_PER_SEC);
    printf("양의 정수 프로그램 수행 시간 :%lf\n", (end_pos - start_pos));
    check_correct(quick_pos_arr->arr, size);
    if (size > MAX_PRINT_IDX && size <= MAX_PRINT) printarr(quick_pos_arr->arr, size);
    stability_as_arr(quick_pos_arr, size);

    start_int = (double)clock() / CLOCKS_PER_SEC;
    quickSort(quick_int_arr,0, size-1);
    end_int = (((double)clock()) / CLOCKS_PER_SEC);
    printf(" 정수형 프로그램 수행 시간 :%lf\n", (end_int - start_int));
    check_correct(quick_int_arr->arr, size);
    if (size > MAX_PRINT_IDX && size <= MAX_PRINT) printarr(quick_int_arr->arr, size);
    stability_as_arr(quick_int_arr, size);



    start_double = (double)clock() / CLOCKS_PER_SEC;
    quickSort_double(quick_double_arr, 0, size-1);
    end_double = (((double)clock()) / CLOCKS_PER_SEC);
    printf("더블형 프로그램 수행 시간 :%lf\n", (end_double - start_double));
    check_double_correct(quick_double_arr->doublearr, size);
    if (size > MAX_PRINT_IDX && size <= MAX_PRINT) printarr_double(quick_double_arr->doublearr, size);
    stability_as_double(quick_double_arr, size);

    return 0;
}
