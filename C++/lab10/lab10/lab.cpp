#include "lab.h"
//попробуй не считывать комментарии

char* getStr(FILE* file) {
    char chr, chr1;
    char* str1 = 0;
    int len = 0;
    if ((chr1 = getc(file)) != '\n') {
        while ((chr = getc(file)) != '\n') {
            if (chr == -1)
                break;
            if (chr1 == '/' && chr == '*') {
                flag:
                if((chr1 = getc(file)) != '\n')
                    if((chr = getc(file)) != '\n')
                        while (!(chr1 == '*' && chr == '/')) {
                            chr1 = chr;
                            chr = getc(file);
                        }
            }
            if (chr1 == '/' && chr == '/') {
                while (chr1 != '\n')chr1 = getc(file);
            }
            str1 = (char*)realloc(str1, len + sizeof(char) + 2);
            str1[len++] = chr1;
            chr1 = chr;
        }
    }
    if (len == 0)
        str1 = (char*)malloc(2 * sizeof(char));
    str1[len++] = '\n';
    str1[len] = 0;
    return str1;
}

int number(char* str) {
    int l = 0, k = 0;
    while (str[l] != '\0') {
        if (str[l] == '"')k++;
        l++;
    }
    return k;
}

int comment(char* str) {
    int l = 0, k = 0;
    while (str[l + 1] != '\0') {
        if (str[l] == '/' && str[l + 1] == '/')return ++k;
        l++;
    }
    return k;
}

void analyzeString(char* src) {
    if (strlen(src) < 3) return;
    char* str = NULL;
    char sep[2] = "(";
    str = strtok(src, sep);
    
    int k = number(str);
    int k2 = comment(str), k1;
    while (true) {
        flag:
        str = strtok(NULL, sep);
        if (str == NULL) return;
        else {
            if (*(str - 1) == ' ')goto flag;
            else {
                k = number(str);
                if (k % 2 == 1 && k != 0)goto flag;
                k1 = comment(str);
                if (k1 < k2)return;
                int i = 0;
                while (*(str - i - 1) != ' ' && *(str - i - 1) != ')' && *(str - i - 1) != '\t' && *(str - i - 1) != '/')i++;
                while (i != 1) {
                    printf("%c", *(str - i));
                    i--;
                    if (i == 1)printf("\n");
                }
               // printf("\n");
            }
        }
    }
}
