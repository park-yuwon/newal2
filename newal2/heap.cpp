#include <stdio.h>
#include <stdlib.h> // rand()함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리
#include <string.h>
#include <stdbool.h>
#include <memory.h>
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


void heapify_double(double arr[], int n, int i) {

    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])

        largest = left;

    if (right < n && arr[right] > arr[largest])

        largest = right;


    if (largest != i) {

        swap_double(&arr[i], &arr[largest]);

 
        heapify_double(arr, n, largest);

    }
}

void heapSort_double(double arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)

        heapify_double(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {

        swap_double(&arr[0], &arr[i]);

        heapify_double(arr, i, 0);

    }
}

void heapify(int arr[], int n, int i) {


    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])

        largest = left;

    if (right < n && arr[right] > arr[largest])

        largest = right;

    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        heapify(arr, n, largest);

    }

}

void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)

        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);


        heapify(arr, i, 0);

    }
}

int main()
{


    char fname[20] = "testint.txt";
    char fname2[20] = "testminus.txt";
    char fname3[20] = "testdouble.txt";
    char fname4[20] = "testtext.txt";

    int size = MAX_RAND_NUM;

    int heap_pos_arr[MAX_RAND_NUM];
    int heap_int_arr[MAX_RAND_NUM];
    double heap_double_arr[MAX_RAND_NUM];

    file_r(fname, heap_pos_arr);
    file_r(fname2, heap_int_arr);
    file_r_double(fname3, heap_double_arr);

    heapSort(heap_pos_arr, size);
    heapSort(heap_int_arr, size);
    heapSort_double(heap_double_arr, size);


    double start_pos, end_pos, start_int, end_int, start_double, end_double;

    start_pos = (double)clock() / CLOCKS_PER_SEC;
    heapSort(heap_pos_arr, size);
    end_pos = (((double)clock()) / CLOCKS_PER_SEC);
    printf("양의 정수 프로그램 수행 시간 :%lf\n", (end_pos - start_pos));
    check_correct(heap_pos_arr, size);


    start_int = (double)clock() / CLOCKS_PER_SEC;
    heapSort(heap_int_arr, size);
    end_int = (((double)clock()) / CLOCKS_PER_SEC);
    printf(" 정수형 프로그램 수행 시간 :%lf\n", (end_int - start_int));
    check_correct(heap_pos_arr, size);




    start_double = (double)clock() / CLOCKS_PER_SEC;
    heapSort_double(heap_double_arr, size);
    end_double = (((double)clock()) / CLOCKS_PER_SEC);
    printf("더블형 프로그램 수행 시간 :%lf\n", (end_double - start_double));
    check_double_correct(heap_double_arr, size);


   

    return 0;
}