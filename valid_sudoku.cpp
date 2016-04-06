#include "catch.hpp"

using namespace std;

bool isValidSudoku(vector<vector<char>> &board) {
    bool row[9][9] = {false};
    bool column[9][9] = {false};
    bool sub_box[9][9] = {false};
    for (int i = 0; i != board.size(); ++i) {
        for (int j = 0; j != board[i].size(); ++j) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '0' - 1;
                int sub_box_idx = i / 3 * 3 + j / 3;
                if (row[i][num] || column[j][num] || sub_box[sub_box_idx][num])
                    return false;
                row[i][num] = column[j][num] = sub_box[sub_box_idx][num] = true;
            }
        }
    }
    return true;
}

TEST_CASE("valid sudoku") {
    SECTION("invalid row") {
        vector<vector<char>> input = {{'1', '1'}};
        REQUIRE(isValidSudoku(input) == false);
    }

    SECTION("invalid column") {
        vector<vector<char>> input = {{'1'},
                                      {'1'}};
        REQUIRE(isValidSudoku(input) == false);
    }
    SECTION("valid") {
        vector<vector<char>> input = {{'1', '2', '3', '4', '5', '6', '7', '8', '9'},
                                      {'.', '.', '.', '.', '.', '.', '.', '.', '.',},
                                      {'.', '.', '.', '.', '.', '.', '.', '.', '.',},
                                      {'.', '.', '.', '.', '.', '.', '.', '.', '.',},
                                      {'.', '.', '.', '.', '.', '.', '.', '.', '.',},
        };
        REQUIRE(isValidSudoku(input));
    }
}