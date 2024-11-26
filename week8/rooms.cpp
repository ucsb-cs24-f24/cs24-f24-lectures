#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>> &rooms, vector<bool> &visited,
         int &numvisited) {
  visited[u] = true;
  numvisited++;
  for (auto w : rooms[u]) {
    if (!visited[w]) {
      dfs(w, rooms, visited, numvisited);
    }
  }
}

bool canVisitAllRooms_dfs(vector<vector<int>> &rooms) {
  vector<bool> visited(rooms.size(), false);
  int numvisited = 0;
  dfs(0, rooms, visited, numvisited);
  return numvisited == rooms.size();
}

bool canVisitAllRooms_bfs(vector<vector<int>> &rooms) {
  queue<int> explorekeys;
  vector<bool> visited(rooms.size(), false);
  visited[0] = true;
  explorekeys.push(0);
  int numvisited = 1;

  while (!explorekeys.empty()) {
    int u = explorekeys.front();
    explorekeys.pop();
    for (auto e : rooms[u]) {
      if (!visited[e]) {
        visited[e] = true;
        numvisited++;
        explorekeys.push(e);
      }
    }
  }

  return numvisited == rooms.size();
}

int main() {
  // Example rooms setup, can be modified for different test cases
  vector<vector<int>> rooms = {
      {1},    // Room 0 has a key to room 1
      {2, 0}, // Room 1 has a key to room 2
      {3},    // Room 2 has a key to room 3
      {}      // Room 3 has no keys
  };

  // Test the BFS function
  if (canVisitAllRooms_bfs(rooms)) {
    cout << "Yes, all rooms can be visited using BFS." << endl;
  } else {
    cout << "No, not all rooms can be visited using BFS." << endl;
  }

  // Test the DFS function
  if (canVisitAllRooms_dfs(rooms)) {
    cout << "Yes, all rooms can be visited using DFS." << endl;
  } else {
    cout << "No, not all rooms can be visited using DFS." << endl;
  }

  return 0;
}
