//#include <stdio.h>
//#include <stdlib.h> // rand()함수 포함 라이브러리
//#include <time.h> // time()함수 포함 라이브러리
//#include <string.h>
//#include <stdbool.h>
//#include <memory.h>
//#include "function.h"
//
////#define MAX_STR 1000
////#define MAX_RAND_NUM 10000//5만은 됬고 10만은 안돼
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
//void bubbleSort(int arr[], int n) {
//    int i, j;
//    for (i = 0; i < n - 1; i++) {
//        // Last i elements are already
//        // in place
//        for (j = 0; j < n - i - 1; j++) {
//            if (arr[j] > arr[j + 1])
//                swap(&arr[j], &arr[j + 1]);
//        }
//    }
//}
//
//void bubbleSort_double(double arr[], int n) {
//    int i, j;
//    for (i = 0; i < n - 1; i++) {
//        // Last i elements are already
//        // in place
//        for (j = 0; j < n - i - 1; j++) {
//            if (arr[j] > arr[j + 1])
//                swap_double(&arr[j], &arr[j + 1]);
//        }
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
//    int bubble_pos_arr[MAX_RAND_NUM];
//    int bubble_int_arr[MAX_RAND_NUM];
//    double bubble_double_arr[MAX_RAND_NUM];
//
//    file_r(fname, bubble_pos_arr);
//    file_r(fname2, bubble_int_arr);
//    file_r_double(fname3, bubble_double_arr);
//
//    bubbleSort(bubble_pos_arr, size);
//    bubbleSort(bubble_int_arr, size);
//    bubbleSort_double(bubble_double_arr, size);
//
//    double start_pos, end_pos, start_int, end_int, start_double, end_double;
//
//    start_pos = (double)clock() / CLOCKS_PER_SEC;
//    bubbleSort(bubble_pos_arr, size);
//    end_pos = (((double)clock()) / CLOCKS_PER_SEC);
//    printf("양의 정수 프로그램 수행 시간 :%lf\n", (end_pos - start_pos));
//    check_correct(bubble_pos_arr, size);
//    printarr(bubble_pos_arr, size);
//
//
//    start_int = (double)clock() / CLOCKS_PER_SEC;
//    bubbleSort(bubble_int_arr, size);
//    end_int = (((double)clock()) / CLOCKS_PER_SEC);
//    printf(" 정수형 프로그램 수행 시간 :%lf\n", (end_int - start_int));
//    check_correct(bubble_int_arr, size);
//    printarr(bubble_int_arr, size);
//
//
//
//    start_double = (double)clock() / CLOCKS_PER_SEC;
//    bubbleSort_double(bubble_double_arr, size);
//    end_double = (((double)clock()) / CLOCKS_PER_SEC);
//    printf("더블형 프로그램 수행 시간 :%lf\n", (end_double - start_double));
//    check_double_correct(bubble_double_arr, size);
//    printarr_double(bubble_double_arr, size);
//
//    return 0;
//}