//#include <stdio.h>
//#include <stdlib.h> // rand()함수 포함 라이브러리
//#include <time.h> // time()함수 포함 라이브러리
//#include <string.h>
//#include <stdbool.h>
//#include <memory.h>
//#include "function.h"
//
////#define MAX_STR 1000
////#define MAX_RAND_NUM 30000 // BE CAREFUL: It should be an even number (to make sure the random number's indexes are valid integer)
//
//
//
//
//int main() {
//
//
//    ARR* arr = (ARR*)malloc(sizeof(ARR));
//    ARR* insert_pos_arr = (ARR*)malloc(sizeof(ARR));
//   /* ARR* select_pos = (ARR*)malloc(sizeof(ARR));
//    ARR* bubble_pos = (ARR*)malloc(sizeof(ARR));
//    ARR* merge_pos = (ARR*)malloc(sizeof(ARR));
//    ARR* quick_pos = (ARR*)malloc(sizeof(ARR));
//    ARR* heap_pos = (ARR*)malloc(sizeof(ARR));
//    ARR* radix_pos = (ARR*)malloc(sizeof(ARR));*/
//    ARR *minusarr = (ARR*)malloc(sizeof(ARR));
//    DOUBLEARR *doublearr = (DOUBLEARR*)malloc(sizeof(DOUBLEARR));
//    CODE_ARR *code_str = (CODE_ARR*)malloc(sizeof(CODE_ARR));
//
//    srand(time(NULL)); // 매번 다른 시드값 생성
//    int random = 0; // 정수형 변수 선언
//    double randomf = 0.0; //실수형 변수 선언
//
//    for (int i = 0; i < MAX_RAND_NUM; i++) { // 10번 반복
//        random = rand(); // 난수 생성
//        //arr[i] = random / 100;
//        arr->arr[i] = random;
//        arr->idx[i] = i;
//    }
//
//    random = 0;
//
//    for (int i = 0; i < MAX_RAND_NUM / 2; i++)
//    {
//        random = rand();
//        minusarr->arr[i] = random;
//        minusarr->idx[i] = i;
//    }
//
//    for (int i = MAX_RAND_NUM / 2; i < MAX_RAND_NUM; i++)
//    {
//        random = -rand();
//        minusarr->arr[i] = random;
//        minusarr->idx[i] = i;
//    }
//
//    randomf = 0;
//    for (int i = 0; i < MAX_RAND_NUM; i++) {
//        randomf = rand();
//
//        doublearr->doublearr[i] = ((double)rand() * (2000)) / (double)RAND_MAX - 1000;
//        doublearr->idx[i] = i;
//    }
//
//
//    int type;
//
//    for (int k = 0; k < MAX_RAND_NUM; k++)
//    {
//        for (int i = 0; i < 5; i++)
//        {
//            type = rand() % 2;
//            if (type == 0)
//            {
//                code_str->code_str[k][i] = 'a' + rand() % 26;
//            }
//            else
//                code_str->code_str[k][i] = 'A' + rand() % 26;
//
//        }
//        code_str->code_str[k][5] = '\0';
//        code_str->idx[k] = k;
//    }
//
//
//
//    // File Write
//
//    int size = MAX_RAND_NUM;
//
//    char fname[20] = "testint.txt";
//    char fname2[20] = "testminus.txt";
//    char fname3[20] = "testdouble.txt";
//    char fname4[20] = "testtext.txt";
//
//    file_w(fname, size, arr->arr);
//    file_w(fname2, size, minusarr->arr);
//    file_w_double(fname3, size, doublearr->doublearr);
//    file_string_w(fname4, size, code_str->code_str);
//
//
//
//  
//
//    return 0;
//}