#include <iostream>
#include <string>
using namespace std;

// Функція для знаходження індексу четвертої від кінця крапки
int FindFourthLastDot(const string& str) {
    int dotCount = 0; // Лічильник кількості знайдених крапок
    // Проходимо рядок з кінця
    for (int i = str.length() - 1; i >= 0; --i) {
        // Перевіряємо, чи є символ крапкою
        if (str[i] == '.') {
            dotCount++; // Збільшуємо лічильник крапок
            // Якщо ми знайшли четверту крапку, повертаємо її індекс
            if (dotCount == 4) {
                return i; // Повертаємо індекс четвертої крапки
            }
        }
    }
    return -1; // Якщо четвертої крапки немає, повертаємо -1
}

// Функція для заміни всіх крапок на пару зірочок
string ReplaceDotsWithAsterisks(const string& str) {
    string modifiedStr = str; // Створюємо копію вихідного рядка для зміни
    // Проходимо кожен символ у рядку
    for (size_t i = 0; i < modifiedStr.length(); ++i) {
        // Якщо поточний символ - крапка
        if (modifiedStr[i] == '.') {
            // Замінюємо крапку на пару зірочок ""
            modifiedStr.replace(i, 1, "");
            // Пропускаємо наступний символ, оскільки ми вже вставили два символи замість одного
            i++; 
        }
    }
    return modifiedStr; // Повертаємо змінений рядок
}

int main() {
    string str;
    cout << "Введіть рядок: ";
    getline(cin, str); // Вводимо рядок з консолі

    // Викликаємо функцію для знаходження індексу четвертої від кінця крапки
    int fourthLastDotIndex = FindFourthLastDot(str);
    if (fourthLastDotIndex != -1) {
        // Якщо четверта крапка знайдена, виводимо її індекс
        cout << "Індекс четвертої від кінця крапки: " << fourthLastDotIndex << endl;
    } else {
        // Якщо крапок менше ніж чотири, виводимо відповідне повідомлення
        cout << "У рядку менше чотирьох крапок." << endl;
    }

    // Викликаємо функцію для заміни всіх крапок на пару зірочок
    string modifiedStr = ReplaceDotsWithAsterisks(str);
    // Виводимо змінений рядок
    cout << "Змінений рядок: " << modifiedStr << endl;

    return 0;
}