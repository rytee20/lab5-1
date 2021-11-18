#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

int chet(char* str) {
	int k = 0;
	int lenth = strlen(str);
	for (int i = 0; i < lenth; i++) {
		if (i == 0 && islower(str[i])) k++;
		if (str[i] == ' ' && islower(str[i + 1])) k++;
	}
	return k;
}

void chet2(char* str) {
	cout << "Индексы первых букв слов начинающихся с маленькой буквы: ";
	int lenth = strlen(str);
	for (int i = 0; i < lenth; i++) {
		if (i == 0 && islower(str[i])) cout << i << " ";
		if (str[i] == ' ' && islower(str[i + 1])) cout << i + 1 << " ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	char** text_with_chet;
	text_with_chet = (char**)malloc(sizeof(*text_with_chet) * 100);
	char buff[80];
	int  kount, c, j = 0;
	cout << "Введите строки, слово 'yes' является окончанием" << endl;
	gets_s(buff);
	while (strcmp(buff, "yes") != 0) {
		kount = chet(buff);
		cout << "Количество слов в строке начинающихся с маленькой буквы:  " << kount << endl;
		chet2(buff);
		c = 1;
		int lenth = strlen(buff);
		for (int i = 0; i < lenth; i++) {
			if (i == 0 && islower(buff[i + 1])) {
				for (int k = strlen(buff) + 1; k > 0; k--) {
					buff[k] = buff[k - 1];
				}
				buff[0] = to_string(c)[0];
				c++;
			}
			if (buff[i] == ' ' && islower(buff[i + 1])) {
				for (int k = strlen(buff) + 1; k > i + 2; k--) {
					buff[k] = buff[k - 1];
				}
				buff[i + 1] = to_string(c)[0];
				c++;
			}
		}
		text_with_chet[j] = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
		strcpy(text_with_chet[j], buff);
		j++;
		gets_s(buff);
	}
	cout << "Вывод строк с пронумерованными словами:" << endl;
	for (int i = 0; i < j; i++) {
		cout << text_with_chet[i] << endl;
	}
}