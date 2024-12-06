int substring_removal(string s) {
    stack<char> letters;
    letters.push(s[0]);

    for(int i = 1; i < s.size(); i++){
        if(s[i] == 'A') {
            letters.push('A');
        } else if(s[i] == 'B') {
            if(letters.empty()) {
                letters.push('B');
            } else {
                letters.pop();
            }
        }
    }

    return letters.size();
}
