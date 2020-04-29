#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "reaarange.h"

//git remote add origin url
//git push -u origin master
//git push]
//git commit -m "some information"

int main(void){
    int n_columns;
    int columns[MAX_COLS];
    n_columns = read_column_numbers(columns,MAX_COLS);
    //printf("this is some problem to resolve.");
    return EXIT_SUCCESS;
}

int read_column_numbers(int columns[], int max){
    int num =0;
    int ch;
    /*
    **获取列标号，如果读取到的值小于0，则马上停止 
    */
    while(num<max &&scanf("%d",&columns[num])&& columns[num]>=0){
        num++;
    }

    if(num %2 ==0){
        puts("Last column number is not paired.");
        exit(EXIT_FAILURE);
    }

    while((ch = getchar()) != EOF && ch != '\n');
    return num;
}

void rearrange(char *output,char const *input,int n_columns,int const columns[]){
    int col;
    int len;
    int output_col;
    int intput;
    len = strlen(intput);
    for(col=0;col<n_columns;col+=2){
        int nchars = columns[col+1] - columns[col]+1;
        if(columns[col] >= len || output_col == MAX_INPUT -1)
            break;
        if(output_col + nchars > MAX_INPUT -1)
            nchars = MAX_INPUT - output_col -1;
        //复制数据
        strncpy(output+output_col,intput+columns[col],nchars);
        output_col += nchars;
    }
    output[output_col] = '\0';
}