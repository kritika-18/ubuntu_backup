#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    FILE *fp = NULL;
    char str[50];
    fp = fopen("text3.txt", "r");
    if(fp == NULL)
    {
        perror("fopen() failed\n");
        exit(1);
    }

    while( !feof(fp))
    {
        fgets(str , 9, fp);
        printf("%s" , str);
    }

    fclose(fp);

}
