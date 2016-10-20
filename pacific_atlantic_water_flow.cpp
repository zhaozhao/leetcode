#include "catch.hpp"
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &matrix, queue<pair<int, int>> &fifo, vector<vector<bool>> &visited) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>> directions = {{0,  1},
                                         {0,  -1},
                                         {1,  0},
                                         {-1, 0}};
    while (!fifo.empty()) {
        auto point = fifo.front();
        visited[point.first][point.second] = true;
        for (auto direction: directions) {
            int i = direction.first + point.first;
            int j = direction.second + point.second;

            if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] ||
                matrix[point.first][point.second] > matrix[i][j])
                continue;
            fifo.push(make_pair(i, j));
        }

        fifo.pop();
    }
    return;
}


vector<pair<int, int>> pacificAtlantic(vector<vector<int>> &matrix) {
    vector<pair<int, int>> shared;
    if (matrix.empty()) return shared;
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<bool>> pacific_visited(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic_visited(m, vector<bool>(n, false));

    queue<pair<int, int>> pacific_fifo;
    queue<pair<int, int>> atlantic_fifo;

    for (int j = 0; j < n; ++j) {
        pacific_fifo.push(make_pair(0, j));
        atlantic_fifo.push(make_pair(m - 1, j));
    }
    for (int i = 0; i < m; ++i) {
        pacific_fifo.push(make_pair(i, 0));
        atlantic_fifo.push(make_pair(i, n - 1));
    }

    bfs(matrix, pacific_fifo, pacific_visited);
    bfs(matrix, atlantic_fifo, atlantic_visited);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (pacific_visited[i][j] && atlantic_visited[i][j])
                shared.push_back(make_pair(i, j));
        }
    }
    return shared;
}

TEST_CASE("pacific atlantic") {
    vector<vector<int>> continent = {{1, 2, 2, 3, 5},
                                     {3, 2, 3, 4, 4},
                                     {2, 4, 5, 3, 1},
                                     {6, 7, 1, 4, 5},
                                     {5, 1, 1, 2, 4}};

    vector<pair<int, int>> shared = {{0, 4},
                                     {1, 3},
                                     {1, 4},
                                     {2, 2},
                                     {3, 0},
                                     {3, 1},
                                     {4, 0}};

    REQUIRE(pacificAtlantic(continent) == shared);
}