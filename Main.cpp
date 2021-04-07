/**
 * Demo program for message-board exercise.
 *
 * Author: Erel Segal-Halevi
 * Since : 2021-03
 */

#include "Board.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	uint row;
	uint col;
	string str;

	int Choose=0;

	ariel::Board board;
	while (Choose!=-1) {
		cout << "post-1 read-2 show-3 exit-4" << endl;
		cin >> Choose;

		if(Choose==1){
				cout << "Choose line on the board to post the ad:" << endl;
				cin >> row;
				cout << "Choose column on the board to post the ad:" << endl;
				cin >> col;
				cout << "get string" << endl;
				cin >> str;
				int v_h=0;
				cout << "Vertical-1  Horizontal-2"<< '\n';
				cin >> v_h;
			if(v_h==1){
					board.post(/*row=*/row, /*column=*/col, Direction::Vertical, str);
			}else if(v_h==2){
					board.post(/*row=*/row, /*column=*/col, Direction::Horizontal, str);
			}

		}else if(Choose==2){
			cout << "Choose line on the board to post the ad:" << endl;
			cin >> row;
			cout << "Choose column on the board to post the ad:" << endl;
			cin >> col;
			uint len=0;
			cout << "get length" << endl;
			cin >> len;
			int v_h=0;
			cout << "Vertical-1  Horizontal-2"<< '\n';
			cin >> v_h;
		if(v_h==1){
				cout <<board.read(/*row=*/row, /*column=*/col, Direction::Vertical, len) <<endl;
		}else if(v_h==2){
				cout <<board.read(/*row=*/row, /*column=*/col, Direction::Horizontal, len)<<endl;
		}

		}else if(Choose==3){
			board.show();
		}else if(Choose==4){
			Choose=-1;
		}
}
}
