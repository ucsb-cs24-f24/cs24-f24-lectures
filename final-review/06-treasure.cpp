bool treasureFound(vector<vector<char>> map, pair<int, int> start) {
    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));
    return dfs(map, start.first, start.second, visited);
}

bool dfs(vector<vector<char>>& map, int row, int col, vector<vector<bool>>& visited) {
    int rows = map.size();
    int cols = map[0].size();

    if (row < 0 || col < 0 || row >= rows || col >= cols ||
        map[row][col] == 'W' || map[row][col] == 'O' || visited[row][col]) {
        return false;
    }

    if (map[row][col] == 'X') {
        return true;
    }

    visited[row][col] = true;

    bool found = dfs(map, row + 1, col, visited) || // Down
                 dfs(map, row - 1, col, visited) || // Up
                 dfs(map, row, col + 1, visited) || // Right
                 dfs(map, row, col - 1, visited);  // Left

    return found;
}
