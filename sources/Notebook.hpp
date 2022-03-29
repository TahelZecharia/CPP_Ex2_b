#pragma once

#include <iostream>
#include <unordered_map>
#include <typeinfo>
#include "Direction.hpp"

namespace ariel {
	
    class Notebook {

        std::unordered_map<int, std::unordered_map<int, char[100]>> note;
	
        public:

            Notebook();
        
            ~Notebook();
        
            void write(int page, int row, int column, ariel:: Direction direction, std:: string const &str);
		    
            std:: string read(int page, int row, int column, ariel:: Direction direction, int num);
		    
            void erase(int page, int row, int column, ariel:: Direction direction, int num);
		    
            void show(int page);

	};
}