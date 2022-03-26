#pragma once

#include <iostream>
#include "Direction.hpp"

namespace ariel {
	
    class Notebook {
	
        public:
        
            void write(int page, int row, int column, ariel:: Direction direction, std:: string str);
		    
            std:: string read(int page, int row, int column, ariel:: Direction direction, int num);
		    
            void erase(int page, int row, int column, ariel:: Direction direction, int num);
		    
            void show(int page);

	};
}