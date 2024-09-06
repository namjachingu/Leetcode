#include <iostream>

class Substring {
public:
    int lengthOfLongestSubstring(const std::string & s) {
        return s.size();
    }

    std::string longest_substring(const & std::string s) {
        std::string current_string;
        std::vector<std::string> nonRepetitiveCharacters;

        // Iterate over string and find which char's are repetitive.
        // When repetitive characters are found, save to array the non-repetitive
        // substring found so far. Continue iterating from current position
        // and through the remaining uncovered characters of the string until
        // a new repetitive char is found. Repeat this process.
        for (int i = 0; i < s.size(); i++) {
            if (current_string.find(s[i]) == std::string::npos) {
                current_string = current_string + s[i];
            } else {
                nonRepetitiveCharacters.emplace_back(current_string);
                current_string = s[i];
            }
        }

        // Given there a no repetitive characters in the string
        if (nonRepetitiveCharacters.empty()) {
            return s;
        }

        std::string longest_substring = nonRepetitiveCharacters[0];
        for (const auto & substring : nonRepetitiveCharacters) {
            if (substring.size() > longest_substring.size()) {
                longest_substring = substring;
            }
        }

        return longest_substring;
    }
};

int main() {
    std::string s = "abcabcbb";
    // s = "bbbbb";
    // s = "pwwkew";
    // s = "abcdefg";
    Substring substring;
    std::string output_string = substring.longest_substring(s);
    std::cout << "The answer is: "
              << output_string
              << " with the lenght of: "
              << substring.lengthOfLongestSubstring(output_string)
              << std::endl;
    return 0;
}
