#include <iostream>
#include <array>
#include <vector>
#include "Notebook.hpp"
#include "Direction.hpp"

using namespace std;
using namespace ariel;

const int ROW = 100;
const int MIN_CHAR = 32;
const int MAX_CHAR = 126;

Notebook::Notebook() {

}
    
Notebook::~Notebook() {

}

// 1) write function:
void Notebook:: write(int page, int row, int col, Direction direction, string const &str){

     int len = str.length();

    // exception is thrown if the input of the page or row or colsum is a negative num.
    if (page < 0 || row < 0 || col < 0){
        
        throw invalid_argument("Negative Input");
    }

    // exception is thrown if the string is to long.
    if ( ( len + col ) > ROW && direction == Direction::Horizontal){
            
        throw out_of_range("String Is To Long");
    }

    // exception is thrown if the col index is to big.
    if (col >= ROW){
            
        throw out_of_range("Colsum Index Is To Big");
    }

    // exception is thrown if the string contains not printable char.
    for (int i = 0; i < len; i++){
            
        if (isprint(str.at((unsigned int)i)) == 0 || str.at((unsigned int)i) == '~'){
            
            throw invalid_argument("String Contains Not Printable Char");
        }
    }

    // exception is thrown if the string is empty.
    if(len == 0){
        
        throw invalid_argument("String Is Empty");
    }
    

    // writing in the notebook in a horizontal way:
    if (direction == Direction::Horizontal){
        
        for (int i = 0; i < len; i++){

            if ( isprint(this->note[page][row][col + i]) != 0 && this->note[page][row][col + i] != '_' ){
                
                throw runtime_error("Something Else Is Already Written There");
                exit(0);
            }
            
            this->note[page][row][col + i] = str.at((unsigned int)i);
        }

    }

    //Writing in a notebook in a vertical way:
    if (direction == Direction::Vertical){      

        for (int i = 0; i < len; i++){

             if ( isprint(this->note[page][row + i][col]) != 0 && this->note[page][row + i][col] != '_' ){
                
                throw runtime_error("Something Else Is Already Written There");
                exit(0);
             }
            
            this->note[page][row + i][col] = str.at((unsigned int)i);
        }

    }
    
}

// 2) read function:
string Notebook:: read(int page, int row, int col, Direction direction, int num) {

    // exception is thrown if the input of the page or row or colsum is a negative num.
    if (page < 0 || row < 0 || col < 0 || num <= 0){

            throw invalid_argument("Negative Input");
    }

    // exception is thrown if the string is to long.
    if ( ( num + col ) > ROW && direction == Direction::Horizontal){
            
        throw out_of_range("String Is To Long");
    }

    // exception is thrown if the col index is to big.
    if (col >= ROW){
            
        throw out_of_range("Colsum Index Is To Big");
    }
    
    string ans = string("");
    char c = 0;

    // writing in the notebook in a horizontal way:
    if (direction == Direction::Horizontal){

        for (int i = 0; i < num; i++){
            
            if (MIN_CHAR <= this->note[page][row][col + i] && this->note[page][row][col + i] <= MAX_CHAR){

                c = this->note.at(page).at(row)[col + i];
            
            } else {
                
                c = '_';
            } 
             
            ans.push_back(c);
        }

    }

    //Writing in a notebook in a vertical way:
    if (direction == Direction::Vertical){      

        for (int i = 0; i < num; i++){
            
            if (MIN_CHAR <= this->note[page][row + i][col] && this->note[page][row + i][col] <= MAX_CHAR){

                c = this->note.at(page).at(row + i)[col];
            
            } else {
                
                c = '_';
            } 
             
            ans.push_back(c);
        }

    }
			
    return ans;

}

// 3) erase function:
void Notebook:: erase(int page, int row, int col, Direction direction, int num){

    // exception is thrown if the input of the page or row or colsum is a negative num.
    if (page < 0 || row < 0 || col < 0 || num <= 0){

            throw invalid_argument("Negative Input");
    }

    // exception is thrown if the string is to long.
    if ( ( num + col ) > ROW && direction == Direction::Horizontal){
            
        throw out_of_range("String Is To Long");
    }

    // exception is thrown if the col index is to big.
    if (col >= ROW){
            
        throw out_of_range("Colsum Index Is To Big");
    }

    // writing in the notebook in a horizontal way:
    if (direction == Direction::Horizontal){
        
        for (int i = 0; i < num; i++){
            
            this->note[page][row][col + i] = '~';
        }

    }

    //Writing in a notebook in a vertical way:
    if (direction == Direction::Vertical){
      
        for (int i = 0; i < num; i++){
            
            this->note[page][row + i][col] = '~';
        }

    }

}
		
// 4) show function:    
void Notebook:: show(int page) {

    if ( page < 0 ){
            
        throw out_of_range("Page Not Exixst");
    }

    string ans;

    // Iterating the pages in the notebook
    for (auto page_iter = this->note.begin(); page_iter != this->note.end(); page_iter++) {
        
        // Iterating the rows in the notebook
        for (auto row_iter = page_iter->second.begin() ; row_iter != page_iter->second.end(); row_iter++){

            ans = read(page_iter->first, row_iter->first, 0, Direction::Horizontal, ROW);

            cout << row_iter->first << "  " <<  ans << endl;

        }

    }

}
		
		