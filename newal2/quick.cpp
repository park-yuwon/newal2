#include <stdio.h>
#include <stdlib.h> // rand()함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리
#include <string.h>
#include <stdbool.h>
#include <memory.h>
#include "function.h"

//#define MAX_STR 1000
//#define MAX_RAND_NUM 10000

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


void merge(ARR* data, int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    ARR* tmp = data;
    //ARR* tmp = (ARR*)malloc(sizeof(ARR)); // 새 배열
    /*for (int m = 0; m < MAX_RAND_NUM; m++) {
        tmp->idx[m] = m;
    }*/
    while (i <= q && j <= r) {
        if (data->arr[i] <= data->arr[j]) {
            tmp->idx[k] = data->idx[i];
            tmp->arr[k++] = data->arr[i++];
        }
        else {
            tmp->idx[k] = data->idx[j];
            tmp->arr[k++] = data->arr[j++];
        }
    }
    while (i <= q) {
        tmp->idx[k] = data->idx[i];
        tmp->arr[k++] = data->arr[i++];
    }
    while (j <= r) {
        tmp->idx[k] = data->idx[j];
        tmp->arr[k++] = data->arr[j++];
    }
    for (int a = p; a <= r; a++) {
        data->arr[a] = tmp->arr[a];
        data->idx[a] = tmp->idx[a];
    }
}


void mergeSort(ARR* data, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort(data, p, q);
        mergeSort(data, q + 1, r);
        merge(data, p, q, r);
    }
}


void merge_double(DOUBLEARR* data, int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    DOUBLEARR* stmp = data;
    /*DOUBLEARR* stmp = (DOUBLEARR*)malloc(sizeof(DOUBLEARR));
    for (int m = 0; m < MAX_RAND_NUM; m++) {
        stmp->idx[m] = m;
    }*/
    //double tmp[MAX_RAND_NUM]; // 새 배열
    while (i <= q && j <= r) {
        if (data->doublearr[i] <= data->doublearr[j]) {
            stmp->idx[k] = data->idx[i];
            stmp->doublearr[k++] = data->doublearr[i++];

        }
        else {
            stmp->idx[k] = data->idx[j];
            stmp->doublearr[k++] = data->doublearr[j++];
        }
    }
    while (i <= q) {
        stmp->idx[k] = data->idx[i];
        stmp->doublearr[k++] = data->doublearr[i++];
    }
    while (j <= r) {
        stmp->idx[k] = data->idx[j];
        stmp->doublearr[k++] = data->doublearr[j++];
    }
    for (int a = p; a <= r; a++) {
        data->doublearr[a] = stmp->doublearr[a];
        data->idx[a] = stmp->idx[a];
    }
}


void mergeSort_double(DOUBLEARR* data, int p, int r) {
    int q;
    if (p < r) {
        q = (p + r) / 2;
        mergeSort_double(data, p, q);
        mergeSort_double(data, q + 1, r);
        merge_double(data, p, q, r);
    }
}

void Merge_string(char arr[][6], int low, int mid, int high) //Merging the Array Function
{
    int nL = mid - low + 1;
    int nR = high - mid;

    char** L = (char**)malloc(sizeof(char*) * nL);
    char** R = (char**)malloc(sizeof(char*) * nR);
    int i;
    for (i = 0; i < nL; i++)
    {
        L[i] = (char*)malloc(sizeof(arr[low + i]));
        strcpy(L[i], arr[low + i]);
    }
    for (i = 0; i < nR; i++)
    {
        R[i] = (char*)malloc(sizeof(arr[mid + i + 1]));
        strcpy(R[i], arr[mid + i + 1]);
    }
    int j = 0, k;
    i = 0;
    k = low;
    while (i < nL && j < nR)
    {
        if (strcmp(L[i], R[j]) < 0)strcpy(arr[k++], L[i++]);
        else strcpy(arr[k++], R[j++]);
    }
    while (i < nL)strcpy(arr[k++], L[i++]);
    while (j < nR)strcpy(arr[k++], R[j++]);

}


void mergeSort_string(char arr[][6], int low, int high) //Main MergeSort function
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort_string(arr, low, mid);
        mergeSort_string(arr, mid + 1, high);
        Merge_string(arr, low, mid, high);
    }
}

int main()
{


    char fname[20] = "testint.txt";
    char fname2[20] = "testminus.txt";
    char fname3[20] = "testdouble.txt";
    char fname4[20] = "testtext.txt";


    int size = MAX_RAND_NUM;

    ARR* merge_pos_arr = (ARR*)malloc(sizeof(ARR));
    //int merge_pos_arr[MAX_RAND_NUM];
    ARR* merge_int_arr = (ARR*)malloc(sizeof(ARR));
    //int merge_int_arr[MAX_RAND_NUM];
    DOUBLEARR* merge_double_arr = (DOUBLEARR*)malloc(sizeof(DOUBLEARR));
    //double merge_double_arr[MAX_RAND_NUM];
    CODE_ARR* merge_string_arr = (CODE_ARR*)malloc(sizeof(CODE_ARR));
    //char merge_string_arr[MAX_RAND_NUM][6];



    file_r(fname, merge_pos_arr->arr);
    file_r(fname2, merge_int_arr->arr);
    file_r_double(fname3, merge_double_arr->doublearr);
    file_string_r(fname4, merge_string_arr->code_str);

    for (int i = 0; i < size; i++) {
        merge_pos_arr->idx[i] = i;
        merge_int_arr->idx[i] = i;
        merge_double_arr->idx[i] = i;
    }


    double start_pos, end_pos, start_int, end_int, start_double, end_double, start_string, end_string;

    start_pos = (double)clock() / CLOCKS_PER_SEC;
    mergeSort(merge_pos_arr, 0, size - 1);
    end_pos = (((double)clock()) / CLOCKS_PER_SEC);
    printf("양의 정수 프로그램 수행 시간 :%lf\n", (end_pos - start_pos));
    check_correct(merge_pos_arr->arr, size);
    stability_as_arr(merge_pos_arr, size);
    if (size > MAX_PRINT_IDX && size <= MAX_PRINT) printarr(merge_pos_arr->arr, size);
    if (size <= MAX_PRINT_IDX) {
        printf("After sorting: ");
        printarridx(merge_pos_arr, size);
    }

    start_int = (double)clock() / CLOCKS_PER_SEC;
    mergeSort(merge_int_arr, 0, size - 1);
    end_int = (((double)clock()) / CLOCKS_PER_SEC);
    printf("정수형 프로그램 수행 시간 :%lf\n", (end_int - start_int));
    check_correct(merge_int_arr->arr, size);

    stability_as_arr(merge_int_arr, size);


    start_double = (double)clock() / CLOCKS_PER_SEC;
    mergeSort_double(merge_double_arr, 0, size - 1);
    end_double = (((double)clock()) / CLOCKS_PER_SEC);
    printf("더블형 프로그램 수행 시간 :%lf\n", (end_double - start_double));
    check_double_correct(merge_double_arr->doublearr, size);
    if (size > MAX_PRINT_IDX && size <= MAX_PRINT) printarr_double(merge_double_arr->doublearr, size);
    stability_as_double(merge_double_arr, size);

    /*start_string = (double)clock() / CLOCKS_PER_SEC;
    mergeSort_string(merge_string_arr->code_str, 0, size);
    end_string = (((double)clock()) / CLOCKS_PER_SEC);
    printf("문자열 프로그램 수행 시간 :%lf\n", (end_string - start_string));
    check_string_correct(merge_string_arr->code_str, size);*/

    return 0;
}
