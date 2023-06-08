#include <stdio.h>

//слова выводить в алфавитном порядке
//после каждого слова выводить максимальное количество повторяющихся букв

int minMax(int* index, char* s, int g) {
    int i = 0, j = 0, k = 0, m;
    for (j = 0; j < g - 1; j++) {
        for (i = 0; i < g - j - 1; i++) {
            if (s[index[i] + 1] > s[index[i + 1] + 1]) {
                m = index[i];
                index[i] = index[i + 1];
                index[i + 1] = m;
            }
            else if (s[index[i] + 1] == s[index[i + 1] + 1]) {
                k = 2;
                while (s[index[i] + k] != ' ') {
                    if (s[index[i] + k] > s[index[i + 1] + k]) {
                        m = index[i];
                        index[i] = index[i + 1];
                        index[i + 1] = m;
                        break;
                    }
                    else if (s[index[i] + k] == s[index[i + 1] + k]) k++;
                    else break;
                }
            }
        }
    }
    return index;
}

void strConvert(char* s, char* words, int f){
    int i = 0;
    while (s[f] != '\0' && s[f] != ' ') {
        i = 0;
        if (s[f] != ' ') {
            do {
                *(words + i) = s[f];
                i++;
                f++;
            } while (s[f] != '\0' && s[f] != ' ');
            *(words + i) = '\0';
        }
        else
            if (s[f + 1] != '\0')f++;
    }
}

int checkLetters(char* words) {
    int z = 0, h = 0, k = 0;
    while (*(words + z) != '\0') {
        while (*(words + h) != '\0') {
            if ((*(words + h) == *(words + z)) && (z != h)) goto next;
            else if ((*(words + z) != *(words + h)) && (*(words + h + 1) == '\0')) return 0;
            h++;
        }
        next:;
        z++;
        h = 0;
    }
    return 1;
}

int maxLetters(char *words) {
    int max = 1, m = 1, z = 0, h = 0;
    while (*(words + z) != '\0') {
        m = 1;
        while (*(words + h) != '\0') {
            if ((*(words + h) == *(words + z)) && (z != h)) m++;
            h++;
        }
        z++;
        h = 0;
        if (max < m)max = m;
    }
    return max;
}
int main() {
    char word[1001] = {0};
    char string[1001];
    printf("Enter string:");
    fgets(string, 1000, stdin);
    '\n';
    int k = 0, g = 0, l = 0, index[100];
    index[g] = -1;
    g++;
    k = 0;
    while (string[k] != '\0') {
        if (string[k] == ' ') {
            index[g] = k;
            g++;
        }
        k++;
    }
    minMax(index, string, g);
    k = 0;
    for (int i = 0; i < g; i++) {
	    strConvert(string, word, index[l] + 1); 
        l++;
        int d = checkLetters(word);
        if (d == 1) {
            int z = 0;
            while (word[z] != '\0') {
                printf("%c", word[z]);
                z++;
            }
            printf(" ");
            printf("%d ", maxLetters(word));
        }
    }
    
	
	return 0;
}