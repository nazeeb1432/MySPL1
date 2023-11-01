#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>


int main(){
    // FILE *fp,*fp2;
    // fp=fopen("sample.txt", "r");
    // fp2=fopen("sample2.txt", "w");

    // char c;
    // char word[100];
    // printf("\n");

    // while((c=fgetc(fp))!=EOF)
    // {
    //     fprintf(fp2, "%c", c);
    //     printf("%c",c);
    // }
    // fclose(fp);
    // fclose(fp2);
    // printf("\n");

    FILE *f;
    f=fopen("sample.txt", "r");
    char buffer[255];
    int words=0;
    char c;
    while((c=getc(f))!=EOF){
        fscanf(f, "%s ", buffer);
        printf("%s", buffer);
        if(isspace(c) || c=='\t') words++;
    }
    printf("\n%d\n", words);



    


}