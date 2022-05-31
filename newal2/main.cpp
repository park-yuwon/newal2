#include <stdio.h>
#include <stdlib.h> // rand()함수 포함 라이브러리
#include <time.h> // time()함수 포함 라이브러리
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



int main() {


    int arr[MAX_RAND_NUM];
    int minusarr[MAX_RAND_NUM];
    double doublearr[MAX_RAND_NUM];
    char code_str[MAX_RAND_NUM][6];

    srand(time(NULL)); // 매번 다른 시드값 생성
    int random = 0; // 정수형 변수 선언
    double randomf = 0.0; //실수형 변수 선언

    for (int i = 0; i < MAX_RAND_NUM; i++) { // 10번 반복
        random = rand(); // 난수 생성
        //arr[i] = random / 100;
        arr[i] = random;
    }

    random = 0;

    for (int i = 0; i < MAX_RAND_NUM / 2; i++)
    {
        random = rand();
        minusarr[i] = random;

    }

    for (int i = MAX_RAND_NUM / 2; i < MAX_RAND_NUM; i++)
    {
        random = -rand();
        minusarr[i] = random;
    }

    randomf = 0;
    for (int i = 0; i < MAX_RAND_NUM; i++) {
        randomf = rand();

        doublearr[i] = ((double)rand() * (2000)) / (double)RAND_MAX - 1000;
    }


    int type;

    for (int k = 0; k < MAX_RAND_NUM; k++)
    {
        for (int i = 0; i < 5; i++)
        {
            type = rand() % 2;
            if (type == 0)
            {
                code_str[k][i] = 'a' + rand() % 26;
            }
            else
                code_str[k][i] = 'A' + rand() % 26;

        }
        code_str[k][5] = '\0';
    }



    // File Write

    int size = MAX_RAND_NUM;

    char fname[20] = "testint.txt";
    char fname2[20] = "testminus.txt";
    char fname3[20] = "testdouble.txt";
    char fname4[20] = "testtext.txt";

    file_w(fname, size, arr);
    file_w(fname2, size, minusarr);
    file_w_double(fname3, size, doublearr);
    file_string_w(fname4, size, code_str);

  

    return 0;
}