#include <bits/stdc++.h>
using namespace std;

#define d 256
#define q 1283 // Простое число для минимизации коллизий

void rabinkarp(string text, string pattern) {
    int n = text.length();  // Длина текста
    int m = pattern.length();  // Длина образца
    int i, j;

    int d_m_1 = 1;  // d^(m-1) % q

    // Вычисляем d^(m-1) % q
    for (i = 0; i < m - 1; i++) {
        d_m_1 = (d_m_1 * d) % q;
    }

    int p = 0;  // Хэш-значение образца
    int t = 0;  // Хэш-значение первого окна текста

    // Вычисляем хэш-значения для образца и первого окна текста
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Проверяем совпадения
    for (i = 0; i <= n - m; i++) {
        // Если хэши совпадают, проверяем посимвольно
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    break;
                }
            }
            if (j == m) { // Если все символы совпали
                cout << "Pattern is found at position: " << i << endl;
            }
        }

        // Обновляем хэш для следующего окна текста
        if (i < n - m) {
            t = (d * (t - text[i] * d_m_1) + text[i + m]) % q;
            if (t < 0) {
                t = t + q;  // Убираем отрицательное значение
            }
        }
    }
}

int main() {
    string text = "ABCCDDAEFG";
    string pattern = "CDD";
    rabinkarp(text, pattern);
    return 0;
}
