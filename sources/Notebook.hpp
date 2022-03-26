#pragma once

#include <iostream>
#include <map>
#include <typeinfo>
#include "Direction.hpp"

namespace ariel {
	
    class Notebook {

        map<int, map<int, char[100]>> note;
	
        public:
        
            void write(int page, int row, int column, ariel:: Direction direction, std:: string str);
		    
            std:: string read(int page, int row, int column, ariel:: Direction direction, int num) const;
		    
            void erase(int page, int row, int column, ariel:: Direction direction, int num);
		    
            void show(int page);

	};
}