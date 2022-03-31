#include <iostream>
#include <string>
#include <cassert>

#include "entry_finder.h"
#include "constants.h"

void SIMPLE_TEST() {
    std::string file_name = "/home/sonches/1C_admission/tests/simple_test.txt",
    search_pattern;

    std::ifstream file(file_name);
    EntryFinder finder(file_name);

    search_pattern = "МФТИ";
    size_t entries =  finder.FindEntry(search_pattern);
    assert(entries == SIMPLE_TEST_MIPT);

    std::cout << "Всего вхождений: " << entries << '\n';
    finder.ResetFilePosition();

    search_pattern = "физик";
    entries =  finder.FindEntry(search_pattern);
    assert(entries == SIMPLE_TEST_PHYSIC);

    std::cout << "Всего вхождений: " << entries << '\n';
    finder.ResetFilePosition();

}

void GOT_TEST() {
    std::string file_name = "/home/sonches/1C_admission/tests/GameOfThrones.txt",
            search_pattern;

    std::ifstream file(file_name);
    EntryFinder finder(file_name);

    search_pattern = "die";
    size_t entries =  finder.FindEntry(search_pattern);
    assert(entries == GOT_TEST_DIE);

    std::cout << "Всего вхождений: " << entries << '\n';
    finder.ResetFilePosition();

    search_pattern = "Robert";
    entries =  finder.FindEntry(search_pattern);
    assert(entries == GOT_TEST_ROBERT);

    std::cout << "Всего вхождений: " << entries << '\n';
    finder.ResetFilePosition();

}

void WAP_TEST() {
    std::string file_name = "/home/sonches/1C_admission/tests/WarAndPeace.txt",
            search_pattern;

    std::ifstream file(file_name);
    EntryFinder finder(file_name);

    search_pattern = "Natasha";
    size_t entries =  finder.FindEntry(search_pattern);
    assert(entries == WAP_TEST_NATASHA);

    std::cout << "Всего вхождений: " << entries << '\n';
    finder.ResetFilePosition();

    search_pattern = "Rostov";
    entries =  finder.FindEntry(search_pattern);
    assert(entries == WAP_TEST_ROSTOV);

    std::cout << "Всего вхождений: " << entries << '\n';
    finder.ResetFilePosition();

    search_pattern = "русский";
    entries =  finder.FindEntry(search_pattern);
    assert(entries == WAP_TEST_RUSSIAN);

    std::cout << "Всего вхождений: " << entries << '\n';
    finder.ResetFilePosition();
}

void HP_TEST() {
    std::string file_name = "/home/sonches/1C_admission/tests/HarryPotter.txt",
            search_pattern;

    std::ifstream file(file_name);
    EntryFinder finder(file_name);

    search_pattern = "Weasley";
    size_t entries =  finder.FindEntry(search_pattern);
    assert(entries == HP_TEST_WEASLEY);

    std::cout << "Всего вхождений: " << entries << '\n';
    finder.ResetFilePosition();

    search_pattern = "Hagrid";
    entries =  finder.FindEntry(search_pattern);
    assert(entries == HP_TEST_HAGRID);

    std::cout << "Всего вхождений: " << entries << '\n';
    finder.ResetFilePosition();

    search_pattern = "Malfoy";
    entries =  finder.FindEntry(search_pattern);
    assert(entries == HP_TEST_MALFOY);

    std::cout << "Всего вхождений: " << entries << '\n';
    finder.ResetFilePosition();
}

int main() {
    SIMPLE_TEST();
    GOT_TEST();
    WAP_TEST();
    HP_TEST();

    return 0;
}
