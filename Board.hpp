#include <string>
#include "Direction.hpp"
#include <unordered_map>
using namespace std;
namespace ariel
{
    class Board
    {

    private:
      // key:1 -> min_row key:2 -> max_row
      // key:3 -> min_row key:4 -> max_row
      unordered_map<uint,uint> _size;
      unordered_map<uint,unordered_map<uint,char>> board;

        public:
            Board(){
              _size[1]=UINT16_MAX;
              _size[2]=0;
              _size[3]=UINT16_MAX;
              _size[4]=0;
            };
            void post(uint row, uint col, ariel::Direction d,const std::string & str);
            std::string read(uint row, uint col, ariel::Direction d, uint len);
            void show();
    };
}
