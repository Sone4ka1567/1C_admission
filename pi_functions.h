#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "constants.h"

std::vector<size_t> PiFunc(const std::string& text, size_t sz) {
    std::vector<size_t> pi(sz, 0);
    for(size_t i = 1; i < sz; ++i) {
        size_t j = pi[i - 1];

        while( j > 0 && text[j] != text[i]) {
            j = pi[j - 1];
        }

        if(text[j] == text[i]) {
            ++j;
        }

        pi[i] = j;
    }
    return pi;
}

bool PiFuncUpdate(const std::string& pattern, std::vector<size_t>& pi_func_pattern, long long& prev_pi_func_value, char symbol) {

    size_t this_pi_func_value;

    if (prev_pi_func_value == FIRST_PI_FUNC_VALUE && symbol != pattern[0]) {
        this_pi_func_value = 0;
    }

    else if (prev_pi_func_value == FIRST_PI_FUNC_VALUE) {
        this_pi_func_value = 1;
    }

    else {
        size_t j = prev_pi_func_value;

        if (j >= pattern.size()) {
            j = pi_func_pattern[pattern.size() - 1];
        }

        while( j > 0 && pattern[j] != symbol) {
            j = pi_func_pattern[j - 1];
        }

        if(pattern[j] == symbol) {
            ++j;
        }

        this_pi_func_value = j;
    }

    prev_pi_func_value = this_pi_func_value;

    return this_pi_func_value == pattern.size();
}
