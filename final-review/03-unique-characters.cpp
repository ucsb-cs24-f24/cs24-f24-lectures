// unordered_set is the best choice because it directly stores only unique elements,
// minimizes memory usage by avoiding extra storage for values, and provides efficient
// O(1) average time complexity for insertions and lookups, making it ideal for counting
// unique characters.

int countUniqueCharacters(const string& password) {
    unordered_set<char> uniqueChars;

    for (char c : password) {
        uniqueChars.insert(c);
    }

    return uniqueChars.size();
}
