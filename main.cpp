#include <iostream>
#include <string>
#include "entry_finder.h"


int main() {
    std::string file_name, search_pattern;
    std::cin >> file_name;

    // Считываем кол-во запросов.
    size_t K;
    std::cin >> K;

    // Начинаем работу с файлом.
    std::ifstream file(file_name);
    EntryFinder finder(file_name);

    for (size_t i = 0; i < K; ++i) {

        // Считываем подстроку для поиска.
        std::cin >> search_pattern;

        size_t entries =  finder.FindEntry(search_pattern);

        std::cout << "Всего вхождений: " << entries << '\n';

        // Перебрасываем позицию для считывания в начало файла.
        finder.ResetFilePosition();
    }
    return 0;
}