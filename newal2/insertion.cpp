#include <stdio.h>
#include <stdlib.h> // rand()�Լ� ���� ���̺귯��
#include <time.h> // time()�Լ� ���� ���̺귯��
#include <string.h>
#include <stdbool.h>
#include <memory.h>
#include "function.h"

#define MAX_STR 1000
#define MAX_RAND_NUM 30000

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

void insertionSort(int arr[], int n)
{
    int i, key, j;
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

void insertionSort_double(double arr[], int n)
{
    int i, key, j;
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

    int insert_pos_arr[MAX_RAND_NUM];
    int insert_int_arr[MAX_RAND_NUM];
    double insert_double_arr[MAX_RAND_NUM];

    file_r(fname, insert_pos_arr);
    file_r(fname2, insert_int_arr);
    file_r_double(fname3, insert_double_arr);

    insertionSort(insert_pos_arr, size);
    insertionSort(insert_int_arr, size);
    insertionSort_double(insert_double_arr, size);

    double start_pos, end_pos, start_int, end_int, start_double, end_double;

    start_pos = (double)clock() / CLOCKS_PER_SEC;
    insertionSort(insert_pos_arr, size);
    end_pos = (((double)clock()) / CLOCKS_PER_SEC);
    printf("���� ���� ���α׷� ���� �ð� :%lf\n", (end_pos - start_pos));
    check_correct(insert_pos_arr, size);


    start_int = (double)clock() / CLOCKS_PER_SEC;
    insertionSort(insert_int_arr, size);
    end_int = (((double)clock()) / CLOCKS_PER_SEC);
    printf(" ������ ���α׷� ���� �ð� :%lf\n", (end_int - start_int));
    check_correct(insert_int_arr, size);
    printarr(insert_int_arr, size);



    start_double = (double)clock() / CLOCKS_PER_SEC;
    insertionSort_double(insert_double_arr, size);
    end_double = (((double)clock()) / CLOCKS_PER_SEC);
    printf("������ ���α׷� ���� �ð� :%lf\n", (end_double - start_double));
    check_double_correct(insert_double_arr, size);


    return 0;
}