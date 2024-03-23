#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty())
      return 0;

    int height = grid.size();
    int width = grid[0].size();
    int count = 0;

    auto inside = [&](int row, int col) -> bool {
      return 0 <= row && row < height && 0 <= col && col < width;
    };

    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int row = 0; row < height; ++row)
      for (int col = 0; col < width; ++col) {
        if (grid[row][col] == '1') {
          ++count;
          grid[row][col] = '0';

          queue<pair<int, int>> land;
          land.push({row, col});

          while (!land.empty()) {
            pair<int, int> coordinate = land.front();
            land.pop();

            for (pair<int, int> direction : directions) {
              int new_row = coordinate.first + direction.first;
              int new_col = coordinate.second + direction.second;

              if (inside(new_row, new_col) && grid[new_row][new_col] == '1') {
                land.push({new_row, new_col});
                grid[new_row][new_col] = '0';
              }
            }
          }
        }
      }

    return count;
  }
};

int main() {}
