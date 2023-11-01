#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int main(){
    FILE *fp,*fp2;
    fp=fopen("sample.txt", "r");
    fp2=fopen("sample3.txt", "w");

    char c;
    char word[100];
    printf("\n");

    while((c=fgetc(fp))!=EOF)
    {
        fprintf(fp2, "%c", c);
        printf("%c",c);
    }
    fclose(fp);
    fclose(fp2);
    printf("\n");

    


    


}