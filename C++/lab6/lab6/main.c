#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define defLen 1001

struct node;

typedef struct node {
	char* word;
	int wordLen;
	int wordCount;
	struct node* prev;
	struct node* next;
} nodeT;

typedef struct {
	nodeT* head;
	int size;
} list;

void init(list* l) {
	l->head = NULL;
	l->size = 0;
}

void pushBack(list* list, char* word, int len, int count) {
	nodeT* new, * bf;
	new = (nodeT*)malloc(sizeof(nodeT));
	new->word = word;
	new->wordLen = len;
	new->wordCount = count;
	new->next = NULL;
	if (list->head == NULL) {
		new->prev = NULL;
		list->head = new;
	}
	else {
		bf = list->head;
		while (bf->next != NULL)    bf = bf->next;
		bf->next = new;
		new->prev = bf;
	}
	list->size++;
}

void pushFront(list* list, char* word, int len, int count) {
	nodeT* new, * bf;
	new = (nodeT*)malloc(sizeof(nodeT));
	new->word = word;
	new->wordLen = len;
	new->wordCount = count;
	new->prev = NULL;
	if (list->head == NULL) {
		list->head = new;
		new->next = NULL;
	}
	else {
		new->next = list->head;
		list->head->prev = new;
		list->head = new;
	}
	list->size++;
}

void checkWord(list* list, char* word, int len) {
	int lim, check, close = 0;
	char* value;
	nodeT* wordNode = list->head;
	while (wordNode != NULL) {
		check = 0;
		value = wordNode->word;
		lim = wordNode->wordLen;
		for (int i = 0; i < lim; i++) {
			if (value[i] == word[i]) check++;
			else break;
		}
		if (check == len && check == lim) {
			wordNode->wordCount++;
			close = 1;
			break;
		}
		wordNode = wordNode->next;
	}
	if (close == 0) pushBack(list, word, len, 1);
}

int createList(char* wordStr, list* list) {
	int i = 0, inWord = 0, startPos = 0, endPos = 0, len = 0, first = 0;
	char* word;
	while (wordStr[i] != 0) {
		if (wordStr[i] != ' ' && wordStr[i] != '\t' && wordStr[i] != '\n' && inWord == 0) {
			startPos = i;
			endPos = i;
		}
		if (wordStr[i] != ' ' && wordStr[i] != '\t' && wordStr[i] != '\n') {
			inWord = 1;
			len++;
			endPos++;
		}
		if ((wordStr[i] == ' ' || wordStr[i] == '\t' || wordStr[i] == '\n') && inWord == 1) {
			int num = 0;
			word = (char*)malloc((len + 1) * sizeof(char));
			for (int bf = startPos; bf < endPos; bf++) word[num++] = wordStr[bf];
			word[num] = 0;
			checkWord(list, word, len);
			len = 0;
			startPos = 0;
			endPos = 0;
			inWord = 0;
		}
		i++;
	}
	if (inWord == 1) {
		int num = 0;
		word = (char*)malloc((len + 1) * sizeof(char));
		for (int bf = startPos; bf < endPos; bf++) word[num++] = wordStr[bf];
		word[num] = 0;
		checkWord(list, word, len);
	}
}

void swap(char** s1, char** s2) {
	char* tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
void swapLen(int* s1, int* s2) {
	int tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
void swapCount(int* s1, int* s2) {
	int tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int myStrcmp(char* s1, char* s2) {
	char a = "", b = "";
	while (*s1 != '\0') {
		a = *s1, b = *s2;
		if (a >= 'A' && a <= 'Z')
			a = a + 32;
		if (b >= 'A' && b <= 'Z')
			b = b + 32;
		if (a != b)break;
		s1++;
		s2++;
	}
	return a - b; 
}

void mySert(list* l) {
	nodeT* cur = l->head;

	char* s1 = NULL;
	char* s2 = NULL;
	int i = 0;
	s1 = cur->word;
	for (i = 0; i <= l->size; i++) {
		while (cur->next != NULL) {

			if (myStrcmp(cur->word, cur->next->word) > 0) {
				swap(&(cur->word), &(cur->next->word));
				swapLen(&(cur->wordLen), &(cur->next->wordLen));
				swapCount(&(cur->wordCount), &(cur->next->wordCount));
			}
			cur = cur->next;
		}
		cur = l->head;
	}
}

void copyList(list* l, list* endL) {
	nodeT* cur = l->head;
	while (cur != NULL) {
		pushFront(endL, cur->word, cur->wordLen, 1);
		cur = cur->next;
	}
}

void printList(list* l) {
	nodeT* cur = l -> head;
	while (cur != NULL) {
		printf("%s ", cur -> word);
		cur = cur -> next;
	}
	printf("\n");
}

void forFile(list* l, FILE* f) {
	nodeT* cur = l->head;
	while (cur != NULL) {
		fputs(cur->word, f);
		fprintf(f, " ");
		cur = cur->next;
	}
}

void destroyList(list* l) {
	nodeT* cur = l->head;
	nodeT* prev = NULL;
	while (cur != NULL) {
		prev = cur;
		cur = cur->next;
		free(prev);
	}
}
//void print(list* l, int q) {
//	nodeT* cur = l->head;
//	int i = 0;
//	printf("word wordCount wordLen next prev\n");
//	while (cur != NULL && i < q) {
//		printf("%s ", cur->word);
//		printf("%d ", cur->wordCount);
//		printf("%d ", cur->wordLen);
//		printf("%p ", cur->next);
//		printf("%p ", cur->prev);
//		cur = cur->next;
//		if(++i != q)
//		printf("\n          <=> \n");
//	}
//	printf("\n");
//}
int lengthOfNumber(int k) {
	int l = 0;
	while (k != 0) {
		l++;
		k /= 10;
	}
	return l;
}
void print(list* l, int q) {
	nodeT* cur = l->head;
	int i = 0, length[3] = { 8, 8, 8 };
	printf("\n");
	while (cur != NULL && i < q) {
		if (cur->wordLen > length[i])length[i] = cur->wordLen;
		cur = cur->next;
		i++;
	}
	i = 0;
	cur = l->head;
	while (cur != NULL && i < q) {
		printf("|");
		printf("%s ", cur->word);
		if (cur->wordLen < length[i])
			for (int j = 0; j < length[i] - cur->wordLen; j++) {
				printf(" ");
			}
		cur = cur->next;
		i++;
		printf("|");
		for (int h = 0; h < 5; h++) {
			printf(" ");
		}
	}
	i = 0;
	printf("\n");
	cur = l->head;
	while (cur != NULL && i < q) {
		printf("|");
		printf("%d ", cur->wordCount);
		int l = lengthOfNumber(cur->wordCount);
		if (l < length[i])
			for (int j = 0; j < length[i] - l; j++) {
				printf(" ");
			}
		cur = cur->next;
		i++;
		printf("|");
		for (int h = 0; h < 5; h++) {
			printf(" ");
		}
	}
	i = 0;
	printf("\n");
	cur = l->head;
	while (cur != NULL && i < q) {
		printf("|");
		printf("%d ", cur->wordLen);
		int l = lengthOfNumber(cur->wordLen);
		if (l < length[i])
			for (int j = 0; j < length[i] - l; j++) {
				printf(" ");
			}
		cur = cur->next;
		i++;
		printf("|");
		if(i != q)
		printf(" <=> ");
	}
	i = 0;
	printf("\n");
	cur = l->head;
	while (cur != NULL && i < q) {
		printf("|");
		printf("%p ", cur->next);
		if (8 < length[i])
			for (int j = 0; j < length[i] - 8; j++) {
				printf(" ");
			}
		cur = cur->next;
		i++;
		printf("|");
		for (int h = 0; h < 5; h++) {
			printf(" ");
		}
	}
	i = 0;
	printf("\n");
	cur = l->head;
	while (cur != NULL && i < q) {
		printf("|");
		printf("%p ", cur->prev);
		if (8 < length[i])
			for (int j = 0; j < length[i] - 8; j++) {
				printf(" ");
			}
		cur = cur->next;
		i++;
		printf("|");
		for (int h = 0; h < 5; h++) {
			printf(" ");
		}
	}
	printf("\n");
}

int main() {
	FILE* f1 = fopen("file1.txt", "r");
	if (f1 == NULL) {
		printf("File1 not opened ");
		FILE* f2 = fopen("file2.txt", "r");
		if (f2 == NULL) {
			printf("File2 not opened ");
			return 0;
		}
		else {
			char string2[defLen] = "";
			fgets(string2, defLen - 1, f2);
			list l2;
			init(&l2);
			createList(string2, &l2);
			mySert(&l2);
			printList(&l2);
			list endL;
			init(&endL);
			copyList(&l2, &endL);
			mySert(&endL);
			printf("Result: ");
			printList(&endL);
			destroyList(&l2);
			FILE* f3 = fopen("file3.txt", "w");
			if (f3 == NULL) {
				printf("File3 not opened ");
				return 0;
			}
			else{
				forFile(&endL, f3);
				print(&endL, 3);
				destroyList(&endL);
				fclose(f3);
			}
			fclose(f2);
		}
	}
	else {
		char string1[defLen] = "";
		FILE* f2 = fopen("file2.txt", "r");
		if (f2 == NULL) {
			printf("File2 not opened ");
			fgets(string1, defLen - 1, f1);
			list l1;
			init(&l1);
			createList(string1, &l1);
			mySert(&l1);
			printList(&l1);
			list endL;
			init(&endL);
			copyList(&l1, &endL);
			mySert(&endL);
			printf("Result: ");
			printList(&endL);
			destroyList(&l1);
			FILE* f3 = fopen("file3.txt", "w");
			if (f3 == NULL) {
				printf("File3 not opened ");
				return 0;
			}
			else {
				forFile(&endL, f3);
				print(&endL, 3);
				destroyList(&endL);
				fclose(f3);
			}
		}
		else{
			char string2[defLen] = "";
			fgets(string1, defLen - 1, f1);
			fgets(string2, defLen - 1, f2);
			list l1, l2;
			init(&l1);
			init(&l2);
			createList(string1, &l1);
			createList(string2, &l2);
			mySert(&l1);
			mySert(&l2);
			printList(&l1);
			printList(&l2);
			list endL;
			init(&endL);
			copyList(&l1, &endL);
			copyList(&l2, &endL);
			mySert(&endL);
			printf("Result: ");
			printList(&endL);
			destroyList(&l1);
			destroyList(&l2);
			FILE* f3 = fopen("file3.txt", "w");
			if (f3 == NULL) {
				printf("File3 not opened ");
				return 0;
			}
			else{
				forFile(&endL, f3);
				print(&endL, 3);
				destroyList(&endL);
				fclose(f3);
			}
			fclose(f2);
		}
		fclose(f1);
	}
	return 0;
}
//Проверка, что файл открылся. Исправить баг с неправильным выводом 4 допа
//
// в сортировку добавить работу с заглавными буквами
//
// список слов считывать из двух файлов(2 списка объединить в 1 и отсортировать)
//
// выводить cписок на экран и в новый файл 
//
// выводить графическое представление списка для первых 3-х узлов
