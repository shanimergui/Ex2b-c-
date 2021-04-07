#include "Board.hpp"
#include <iostream>
#include <ctype.h>
using namespace std;
namespace ariel
{
void Board::post(uint row, uint col, ariel::Direction d, const std::string & str)
{
const int min_row =1;
const int max_row=2;
const int min_row=3;
const int max_row=4;


this->_size[min_row] =  min(this->_size[min_row],row);
this->_size[max_row] = max(this->_size[max_row],row);
this->_size[min_row] =  min(this->_size[min_row],col);
this->_size[ max_row] =  max(this->_size[ max_row],col);

for(char ch : str) {
this->board[row][col]=ch;
if(d==Direction::Horizontal) {
        col++;
}else if(d==Direction::Vertical) {
        row++;
}
}
}
string Board::read(uint row, uint col, ariel::Direction d, uint len)
{
string answer;

for (size_t i = 0; i < len; i++) {
if(this->board[row][col]!='\0') {
        answer+=this->board[row][col];
}else{
        answer+='_';
}
if(d==Direction::Horizontal) {
        col++;
}else if(d==Direction::Vertical) {
        row++;
}
}
return answer;
}
void Board::show()
{
const uint name=10;
const int min_row=1;
const int max_row=2;
const int min_row=3;
const int  max_row=4;

string answer;
for (uint i = this->_size[min_row]-name; i < this->_size[max_row]+name; i++) {
for (uint j = this->_size[min_row]-name; j < this->_size[ max_row]+name; j++) {
        if(this->board[i][j]!='\0') {
                answer+=this->board[i][j];
        }else{
                answer+='_';
        }
}
answer+="\n";
}
std::cout << answer << '\n';
}
}
