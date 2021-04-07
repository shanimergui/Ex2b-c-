#include "doctest.h"
#include "Board.hpp"
#include <string>

using namespace std;
using namespace ariel;

TEST_CASE("POST HORIZONTAL AND READ")
{
    string ans;
    Board board;
    board.post(/*row=*/100, /*column=*/202, Direction::Horizontal, "ab cd");
    ans = board.read(100,202, Direction::Horizontal,5);
    CHECK(ans == "ab cd");
    ans = board.read(100,202, Direction::Vertical,5);
    CHECK(ans == "a____");
    ans = board.read(100,203, Direction::Vertical,4);
    CHECK(ans == "b___");
    ans = board.read(100,204, Direction::Vertical,5);
    CHECK(ans == " ____");
    ans = board.read(100,205, Direction::Vertical,5);
    CHECK(ans == "c____");
    ans = board.read(98,202, Direction::Vertical,5);
    CHECK(ans == "__a__");
    board.post(/*row=*/100, /*column=*/202, Direction::Horizontal, "???d");
    ans = board.read(100,202, Direction::Horizontal,5);
    CHECK(ans == "???dd");
    ans = board.read(100,202, Direction::Vertical,5);
    CHECK(ans == "?____");
    ans = board.read(100,203, Direction::Vertical,4);
    CHECK(ans == "?___");
    ans = board.read(100,204, Direction::Vertical,5);
    CHECK(ans == "?____");
    ans = board.read(100,205, Direction::Vertical,5);
    CHECK(ans == "d____");
    ans = board.read(98,202, Direction::Vertical,5);
    CHECK(ans == "__?__");
    board.post(/*row=*/100, /*column=*/202, Direction::Horizontal, "_____");
    ans = board.read(100,202, Direction::Horizontal,5);
    CHECK(ans == "_____");
    ans = board.read(100,202, Direction::Vertical,5);
    CHECK(ans == "_____");
    ans = board.read(100,203, Direction::Vertical,4);
    CHECK(ans == "____");
    ans = board.read(100,204, Direction::Vertical,5);
    CHECK(ans == "_____");
    ans = board.read(100,205, Direction::Vertical,5);
    CHECK(ans == "_____");
    ans = board.read(98,202, Direction::Vertical,5);
    CHECK(ans == "_____");

}

TEST_CASE("POST VERTICAL AND READ")
{
    Board board;
    string ans;
    board.post(/*row=*/0, /*column=*/0, Direction::Vertical, "?ab cd?");
    ans = board.read(0,0, Direction::Horizontal,5);
    CHECK(ans == "?____");
    ans = board.read(0,0, Direction::Vertical,5);
    CHECK(ans == "?ab c");
    ans = board.read(0,0, Direction::Vertical,8);
    CHECK(ans == "?ab cd?_");
    ans = board.read(2,0, Direction::Horizontal,8);
    CHECK(ans == "b_______");
    board.post(/*row=*/0, /*column=*/0, Direction::Vertical, "_______");
    ans = board.read(0,0, Direction::Vertical,8);
    CHECK(ans == "________");
}

