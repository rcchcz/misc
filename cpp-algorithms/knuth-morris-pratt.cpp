#include <iostream>
#include <string>
#include <vector>

void build_lps(std::string pattern, std::vector<int> &lps) {
    lps[0] = 0;
    int i = 0;
    int j = 1;

    while(j < pattern.length()) {
        if(pattern[i] != pattern[j]) {
            lps[j] = 0;
            j++;
        } else {
            lps[j] = i + 1;
            i++;
            j++; 
        }
    }

}

// first occurrence
int kmp_fo(std::string text, std::string pattern) {
    int tsize = text.length();
    int psize = pattern.length();
    std::vector<int> lps(psize);

    build_lps(pattern, lps);

    int i = 0;
    int j = 0;
    while(i < tsize) {
        if(text[i] == pattern[j]) { i++; j++; } // match
        if(j == psize) { return i - psize; } // pattern found
        else if(i < tsize && pattern[j] != text[i]) { // mismatch
            if(j == 0) { i++; }
            else { j = lps[j - 1]; }
        }
    }

    return -1; // pattern not found
}

// all occurrences
std::vector<int> kmp_ao(std::string text, std::string pattern) {
    int tsize = text.length();
    int psize = pattern.length();
    std::vector<int> lps(psize);
    std::vector<int> indexes;

    build_lps(pattern, lps);

    int i = 0;
    int j = 0;
    while(i < tsize) {
        if(text[i] == pattern[j]) { i++; j++; } // match
        if(j == psize) { indexes.push_back(i- psize); j = lps[j - 1]; } // pattern found
        else if(i < tsize && text[i] != pattern[j]) { // mismatch
            if(j == 0) { i++; }
            else { j = lps[j - 1]; }
        }
    }

    return indexes;
}

int main() {
    std::string text = "abcasdababcasdabsdabc";
    std::string pattern = "abc";

    // first occurrence
    std::cout << kmp_fo(text, pattern) << std::endl;

    // all occurrences
    std::vector<int> all_indexes = kmp_ao(text, pattern);
    if(all_indexes.size() == 0) { std::cout << -1; } // pattern not found
    else { for(auto i : all_indexes) { std::cout << i << ' '; } } // indexes
    std::cout << std::endl;    
}
