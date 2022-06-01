//Collection of File I/O function


#ifndef __function_h__
#define __function_h__

#define MAX_RAND_NUM 10000
#define MAX_STR 1000
#define _CRT_SECURE_NO_WARNINGS

struct ARR {
    int arr[MAX_RAND_NUM];
    int idx[MAX_RAND_NUM];
};
/*struct MINUSARR {
    int minusarr[MAX_RAND_NUM];
    int idx[MAX_RAND_NUM];
};*/
struct DOUBLEARR {
    double doublearr[MAX_RAND_NUM];
    int idx[MAX_RAND_NUM];
};
struct CODE_ARR {
    char code_str[MAX_RAND_NUM][6];
    int idx[MAX_RAND_NUM];
};

bool file_w(char* filename, int size, int* arr)
{
    FILE* infile = fopen(filename, "w");
    if (infile == NULL)
    {
        printf("\n File cannot be opened\n");
        return false;
        exit(1);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(infile, "%d\n", arr[i]);
        }
    }
    fclose(infile);
    return true;
}

bool file_w_double(char* filename, int size, double* arr)
{
    FILE* infile = fopen(filename, "w");
    if (infile == NULL)
    {
        printf("\n File cannot be opened\n");
        return false;
        exit(1);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(infile, "%lf\n", arr[i]);
        }
    }
    fclose(infile);
    return true;
}

bool file_r(char* filename, int* arr)
{
    FILE* infile = fopen(filename, "r");
    if (infile == NULL)
    {
        printf("\n File cannot be opened\n ");
        exit(1);
        return false;

    }
    else
    {
        int num;
        int i = 0;
        while (fscanf(infile, "%d", &num) != EOF)
        {
            arr[i] = num;
            i++;
        }

    }
    fclose(infile);
    return true;
}

bool file_r_double(char* filename, double* arr)
{
    FILE* infile = fopen(filename, "r");
    if (infile == NULL)
    {
        printf("\n File cannot be opened\n ");
        exit(1);
        return false;

    }
    else
    {
        double num;
        int i = 0;
        while (fscanf(infile, "%lf", &num) != EOF)
        {
            arr[i] = num;
            i++;
        }

    }
    fclose(infile);
    return true;
}

bool file_string_w(char* filename, int size, char str[][6])
{
    FILE* infile;
    infile = fopen(filename, "w");
    if (infile == NULL)
    {
        printf("file cannot be opened\n");
        exit(0);
        return false;
    }

    else
    {
        for (int i = 0; i < size; i++)
        {
            fprintf(infile, " %s ", str[i]);
        }
        fclose(infile);
    }

    return true;
}

bool file_string_r(char* filename, char str[][6])
{
    FILE* infile;
    infile = fopen(filename, "r");
    if (infile == NULL)
    {
        printf("file cannot be oepened\n");
        exit(0);
        return false;
    }

    else
    {
        char randomstr[6];
        int i = 0;
        while (fscanf(infile, "%s", &str) == 1)
        {
            strcpy(str[i], randomstr);
            i++;
        }
        return true;
    }
}

void printarr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n\n");
}

void printarridx(ARR* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%-5d) %d \n", arr->idx[i], arr->arr[i]);
    }
    printf("\n\n");
}

void printarr_double(double* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %lf ", arr[i]);
    }
    printf("\n\n");
}

void printtext() {
    // 작성해야 함
}

bool check_correct(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("CHECK_CORRECT: False (there is an error in sorting..)\n");
            return false;
        }

    }
    printf("CHECK_CORRECT: True (sorting success!)\n");
    return true;
}


bool check_double_correct(double* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("CHECK_DOUBLE_CORRECT: False (there is an error in sorting..)\n");
            return false;
        }

    }
    printf("CHECK_CORRECT_DOUBLE: True (sorting success!)\n");
    return true;
}

/* Check stability of ascendingly ordering algorithm */
bool stability_as_arr(ARR* arr, int size) {
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        int left = arr->arr[j];
        int right = arr->arr[i];
        int idxl = arr->idx[j];
        int idxr = arr->idx[i];
        if (left == right && idxl >= idxr) {
            printf("\n[Unstable]\n");
            printf("value: [%5d][%5d]\n", left, right);
            printf("index: [%5d][%5d]\n", idxl, idxr);
            return false;
        }
    }

    printf("\n[Stability: True]\n");
    printf("[Cautions: Few data can cause stability error]\n");
    return true;
}



#endif
