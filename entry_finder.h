#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "pi_functions.h"
#include "constants.h"

class EntryFinder {
private:
    std::ifstream file;
public:
    explicit EntryFinder(std::string& file_name) {
        file = std::ifstream(file_name);
    }

    size_t FindEntry(std::string& search_pattern) {

        long long prev_pi_fuc_value = FIRST_PI_FUNC_VALUE;
        char symbol;
        size_t cnt = 0;

        // Получаем значения префикс функции для подстроки.
        std::vector<size_t> pi_func_for_pattern = PiFunc(search_pattern, search_pattern.size());

        // Считываем посимвольно из файла
        while (file.get(symbol)) {

            // Запускаем измененную префикс-функцию от символа текста, которая скажет, было ли вхождение.
            bool found = PiFuncUpdate(search_pattern, pi_func_for_pattern, prev_pi_fuc_value, symbol);

            if (found) {
                // Если нашли вхождение, то увеличим счетчик.
                ++cnt;

                // Также если вхождение первое, то выведем его контекст.
                if (cnt == 1) {

                    // Запоминаем текущий индекс считывания.
                    long long cur_ind = file.tellg();


                    long long start_pos_context = 0,
                            pat_sz = search_pattern.size();


                    // Устанавливаем стартовый индекс контекста. Либо 0, либо требуемое окно.
                    start_pos_context = std::max(start_pos_context, cur_ind - pat_sz - CONTEXT_SIZE);
                    file.seekg(start_pos_context);

                    // Заводим буффер для контекста.
                    long long context_size = pat_sz + 2 * CONTEXT_SIZE;
                    char context[context_size + 1];

                    file.read(context, context_size);
                    context[context_size] = 0;
                    std::cout << "Контекст первого вхождения подстроки \"" << search_pattern << "\":" << '\n';
                    std::cout << context << '\n';

                    // Возвращаем индекс.
                    file.seekg(cur_ind);
                }
            }
        }


        // Очищаем параметры файла, ибо дойдя до конца, он будет отмечен как прочитанный.
        file.clear();

        return cnt;
    }


    void ResetFilePosition() {
        file.seekg(0, std::ios::beg);
    }

    ~EntryFinder() {
        file.close();
    }
};