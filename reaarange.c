#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reaarange.h"

//git remote add origin url
//git push -u origin master
//git push]
//git commit -m "some information"
//some change

int main(void)
{
    int n_columns;
    int columns[MAX_COLS];
    char input[MAX_INPUT];
    char output[MAX_INPUT];
    n_columns = read_column_numbers(columns, MAX_COLS);

    //读取、处理和打印剩余的输入行
    while (gets(input) != NULL)
    {
        printf("original input:%s\n", input);
        rearrange(output, input, n_columns, columns);
        printf("Rearranged line:%s\n", output);
    }

    //printf("this is some problem to resolve.");
    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max)
{
    int num = 0;
    int ch;
    /*
    **获取列标号，如果读取到的值小于0，则马上停止 
    */
    while (num < max && scanf("%d", &columns[num]) && columns[num] >= 0)
    {
        num++;
    }

    if (num % 2 != 0)
    {
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }

    while ((ch = getchar()) != EOF && ch != '\n')
        ;
    return num;
}

void rearrange(char *output, char const *input, int n_columns, int const columns[])
{
    int col;
    int len;
    int output_col;
    output_col=0;
    len = (int)strlen(input);
    for (col = 0; col < n_columns; col += 2)
    {
        int nchars = columns[col + 1] - columns[col] + 1;
        if (columns[col] >= len || output_col == MAX_INPUT - 1)
            break;
        if (output_col + nchars > MAX_INPUT - 1)
            nchars = MAX_INPUT - output_col - 1;
        //复制数据
        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }
    output[output_col] = '\0';
}