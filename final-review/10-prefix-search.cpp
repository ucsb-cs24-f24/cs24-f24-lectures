vector<string> findWords(const unordered_set<string>& words, char firstLetter) {
    vector<string> result;

    for (const auto& word : words) {
        if (word[0] == firstLetter) {
            result.push_back(word);
        }
    }

    return result;
}
