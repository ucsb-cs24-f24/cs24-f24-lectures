bool isAnagram(string s1, string s2) {
    unordered_map<char, int> charCount;

    for (char c : s1) {
        charCount[c]++;
    }

    for (char c : s2) {
        if (charCount.find(c) == charCount.end()) {
            return false;
        }
        charCount[c]--;
    }

    for (auto pair : charCount) {
        if (pair.second != 0) {
            return false;
        }
    }

    return true;
}
