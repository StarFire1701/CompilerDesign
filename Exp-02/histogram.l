%{
#include <stdio.h>
#include <string.h>
#define MAX 1000

int count = 0;
char words[MAX][MAX];
%}

%%
[a-zA-Z]+ {
    int i, flag = 0;
    for(i=0; i<count; i++) {
        if(strcmp(words[i], yytext) == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        strcpy(words[count++], yytext);
    }
}
. ;
%%

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: ./a.out <filename>\n");
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Cannot open file!\n");
        return 1;
    }
    yyin = fp;
    yylex();
    int i;
    printf("\nWord\t\tFrequency\n");
    for(i=0; i<count; i++) {
        int freq = 0;
        rewind(fp);
        while(fscanf(fp, "%s", words[MAX-1]) == 1) {
            if(strcmp(words[MAX-1], words[i]) == 0) {
                freq++;
            }
        }
        printf("%-15s %d\n", words[i], freq);
    }
    fclose(fp);
    return 0;
}