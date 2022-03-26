#include <iostream>
#include <array>
#include <vector>
#include "Notebook.hpp"
#include "Direction.hpp"

using namespace std;
using namespace ariel;

Notebook::Notebook() {

}
    
Notebook::~Notebook() {

}

// 1) write function:
void Notebook:: write(int page, int row, int col, Direction direction, string str){

    int len = str.size();

    // writing in the notebook in a horizontal way:
    if (direction == Direction::Horizontal){

         // do all the exeptions!!!!!

        if (this->note[page][row][col] == '~'){

        throw invalid_argument("Mat size is always odd");
        }
        

        for (int i = 0; i < len; i++){
            
            this->note[page][row][col + i] = str[i];
        }

    }

    //Writing in a notebook in a vertical way:
    if (direction == Direction::Vertical){

        // do all the exeptions!!!!!

         if (this->note[page][row][col] == '~'){

        throw invalid_argument("Mat size is always odd");
        }
      

        for (int i = 0; i < len; i++){
            
            this->note[page][row + i][col] = str[i];
        }

    }
    

}

// 2) read function:
string Notebook:: read(int page, int row, int col, Direction direction, int num) const {

    string ans;
    char c;

    // writing in the notebook in a horizontal way:
    if (direction == Direction::Horizontal){

         // do all the exeptions!!!!!

        if (this->note.at(page).at(row)[col] == '~'){

        throw invalid_argument("Mat size is always odd");
        }
        

        for (int i = 0; i < num; i++){
            
            c = this->note.at(page).at(row)[col + i];
            //check if something is writed in this place: 
            c = ( (isalpha(c) || isdigit(c) || c == '~') ) ? c : '_'; 
            ans += c;
        }

    }

    //Writing in a notebook in a vertical way:
    if (direction == Direction::Vertical){

        // do all the exeptions!!!!!

         if (this->note.at(page).at(row)[col] == '~'){

        throw invalid_argument("Mat size is always odd");
        }
      

        for (int i = 0; i < num; i++){
            
            c = this->note.at(page).at(row + i)[col];
            //check if something is writed in this place: 
            c = ( (isalpha(c) || isdigit(c) || c == '~') ) ? c : '_'; 
            ans += c;
        }

    }
			
    return ans;

}

// 3) erase function:
void Notebook:: erase(int page, int row, int col, Direction direction, int num){

    // writing in the notebook in a horizontal way:
    if (direction == Direction::Horizontal){

         // do all the exeptions!!!!!

        if (this->note[page][row][col] == '~'){

        throw invalid_argument("Mat size is always odd");
        }
        

        for (int i = 0; i < num; i++){
            
            this->note[page][row][col + i] = '~';
        }

    }

    //Writing in a notebook in a vertical way:
    if (direction == Direction::Vertical){

        // do all the exeptions!!!!!

         if (this->note[page][row][col] == '~'){

        throw invalid_argument("Mat size is always odd");
        }
      

        for (int i = 0; i < num; i++){
            
            this->note[page][row + i][col] = '~';
        }

    }

}
		
// 4) show function:    
void Notebook:: show(int page) {

    string ans;

    // Iterating the pages in the notebook
    for (auto page_iter = this->note.begin(); page_iter != this->note.end(); page_iter++) {
        
        // Iterating the rows in the notebook
        for (auto row_iter = page_iter->second.begin() ; row_iter != page_iter->second.end(); row_iter++){

            ans = read(page_iter->first, row_iter->first, 0, Direction::Horizontal, 100);

            cout << row_iter->first << "  " <<  ans << endl;

        }

    }

}
		
		