//#include <stdio.h>
//#include <stdlib.h> // rand()함수 포함 라이브러리
//#include <time.h> // time()함수 포함 라이브러리
//#include <string.h>
//#include <stdbool.h>
//#include <memory.h>
//#include "function.h"
//
////#define MAX_STR 1000
////#define MAX_RAND_NUM 10000
//
//void swap(int* xp, int* yp)
//{
//    int temp = *xp;
//    *xp = *yp;
//    *yp = temp;
//}
//
//void swap_double(double* xp, double* yp)
//{
//    double temp = *xp;
//    *xp = *yp;
//    *yp = temp;
//}
//
//
//void selectionSort(int arr[], int n)
//{
//    int i, j, min_idx;
//
//    // One by one move boundary of unsorted subarray
//    for (i = 0; i < n - 1; i++)
//    {
//        // Find the minimum element in unsorted array
//        min_idx = i;
//        for (j = i + 1; j < n; j++)
//            if (arr[j] < arr[min_idx])
//                min_idx = j;
//
//        // Swap the found minimum element with the first element
//        swap(&arr[min_idx], &arr[i]);
//    }
//}
//
//
//void selectionSort_double(double arr[], int n)
//{
//    int i, j, min_idx;
//
//    // One by one move boundary of unsorted subarray
//    for (i = 0; i < n - 1; i++)
//    {
//        // Find the minimum element in unsorted array
//        min_idx = i;
//        for (j = i + 1; j < n; j++)
//            if (arr[j] < arr[min_idx])
//                min_idx = j;
//
//        // Swap the found minimum element with the first element
//        swap_double(&arr[min_idx], &arr[i]);
//    }
//}
//
//int main()
//{
//
//
//    char fname[20] = "testint.txt";
//    char fname2[20] = "testminus.txt";
//    char fname3[20] = "testdouble.txt";
//    char fname4[20] = "testtext.txt";
//
//    int size = MAX_RAND_NUM;
//
//    int select_pos_arr[MAX_RAND_NUM];
//    int select_int_arr[MAX_RAND_NUM];
//    double select_double_arr[MAX_RAND_NUM];
//
//
//    file_r(fname, select_pos_arr);
//    file_r(fname2, select_int_arr);
//    file_r_double(fname3, select_double_arr);
//
//    selectionSort(select_pos_arr, size);
//    selectionSort(select_int_arr, size);
//    selectionSort_double(select_double_arr, size);
//
//    double start_pos, end_pos, start_int, end_int, start_double, end_double;
//
//    start_pos = (double)clock();
//    selectionSort(select_pos_arr, size);
//    end_pos = (double)clock();
//    double micro_sec = (end_pos - start_pos) / CLOCKS_PER_SEC;
//    printf("양의 정수 프로그램 수행 시간 :%lf\n", micro_sec);
//    check_correct(select_pos_arr, size);
//    printarr(select_pos_arr, size);
//
//
//    start_int = (double)clock() / CLOCKS_PER_SEC;
//    selectionSort(select_int_arr, size);
//    end_int = (((double)clock()) / CLOCKS_PER_SEC);
//    printf(" 정수형 프로그램 수행 시간 :%lf\n", (end_int - start_int));
//    check_correct(select_int_arr, size);
//    printarr(select_int_arr, size);
//
//
//
//    start_double = (double)clock() / CLOCKS_PER_SEC;
//    selectionSort_double(select_double_arr, size);
//    end_double = (((double)clock()) / CLOCKS_PER_SEC);
//    printf("더블형 프로그램 수행 시간 :%lf\n", (end_double - start_double));
//    check_double_correct(select_double_arr, size);
//    printarr_double(select_double_arr, size);
//
//    return 0;
//}