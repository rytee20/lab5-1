#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace std;

void massiv(float* fstart, int fsize) {
    srand(time(NULL));
    for (float* ru = fstart; ru < fstart + fsize; ru++) {
        *ru = (rand() % 100) / 10.0;
    }
}

void print_massiv(float* fstart, int fsize, int fM) {
    float* ru;
    int i;
    for (ru = fstart, i = 1; ru < (fstart + fsize); ru++, i++) {
        cout.width(5);
        cout << *ru;
        if (i % fM == 0) cout << endl;
    }
}

void fmin(float* fstart, int fsize, int ffM) {
    float* ru, min;
    int i, n = 0, m = 0;
    for (ru = fstart, i = 0; ru < (fstart + fsize); ru++, i++) {
        if (i == 0) min = *ru;
        else {
            if (m >= n && *ru <= min)min = *ru;
        }
        m++;
        if (m == ffM) {
            n++;
            m = 0;
        }
    }
    n = 0, m = 0;
    cout << endl << "??????????? ???????: " << min << endl << ", ??? ???????: ";
    for (ru = fstart; ru < (fstart + fsize); ru++) {
        if (m >= n && *ru == min) {
            cout << "(" << n << ", " << m << ") ";
        }
        m++;
        if (m == ffM) {
            m = 0;
            n++;
        }
    }
}

int main() {
    int N, M;
    setlocale(LC_ALL, "Russian");
    cout << "??????? ???????? N ? M: ";
    cin >> N >> M;
    float* A = new float[N * M];
    float* start = A;
    int size = N * M;
    massiv(start, size);
    cout << endl << "???????: " << endl;
    print_massiv(start, size, M);
    fmin(start, size, M);
}