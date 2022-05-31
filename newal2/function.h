//Collection of File I/O function


#ifndef __function_h__
#define __function_h__

#define MAX_RAND_NUM 1000
#define MAX_STR 1000
#define _CRT_SECURE_NO_WARNINGS

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
}

void printarr_double(double* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf(" %lf ", arr[i]);
    }
}


bool check_correct(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("there is an error in sorting..\n");
            return false;
        }

    }
    printf("sorting success!\n");
    return true;
}


bool check_double_correct(double* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("there is an error in sorting..\n");
            return false;
        }

    }
    printf("sorting success!\n");
    return true;
}

#endif
