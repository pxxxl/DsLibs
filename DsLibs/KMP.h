#include<iostream>

namespace eds {
    namespace algorithm {
        using namespace std;
        auto Plain_string_match = [](string mstr, string sstr)->int {
            auto m_len = mstr.length();
            auto s_len = sstr.length();
            unsigned i = 0;
            unsigned j = 0;
            while (j < s_len && i < m_len) {
                if (mstr[i] == sstr[j]) {
                    i++;
                    j++;
                }
                else {
                    i = i - j + 1;
                    j = 0;
                }
            }
            if (j == s_len) {
                return i - j;
            }
            else {
                return -1;
            }
        };

        auto get_next = [](string str)->int* {
            int* next = new int[str.length()];
            int len = str.length();
            int k = -1;
            int j = 0;
            next[0] = -1;
            while (j < len - 1) {
                if (k == -1 || str[k] == str[j]) {
                    k++;
                    j++;
                    next[j] = k;
                }
                else {
                    k = next[k];
                }
            }
            return next;
        };

        auto KMP = [](string mstr, string sstr)->int {
            unsigned size = sstr.length();
            int* next = get_next(sstr);
            unsigned s = 0;
            unsigned m = 0;
            while (s < sstr.length() && m < mstr.length()) {
                if (mstr[m] == sstr[s] || s == 0) {
                    m++;
                    s++;
                }
                else {
                    s = next[s];
                }
            }
            if (s == sstr.length()) {
                return m - s;
            }
            else {
                return -1;
            }

        };
    }
}
