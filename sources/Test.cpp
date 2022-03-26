
#include "doctest.h"
#include "Notebook.hpp"
#include <iostream>
#include <stdexcept>

using namespace ariel;
using namespace std;

TEST_CASE("Write Function"){
    
    Notebook notebook;

    // check that exception is thrown if the input of the page or row or colsum is a negative num.
    
    SUBCASE("Bad Input: Negative  Input"){

        CHECK_THROWS(notebook.write(-2, 31, 74, Direction::Horizontal, "test"));

        CHECK_THROWS(notebook.write(1, -1, 49, Direction::Horizontal, "test"));

        CHECK_THROWS(notebook.write(3, 56, -33, Direction::Horizontal, "test"));

        CHECK_THROWS(notebook.write(-3, 11, -33, Direction::Horizontal, "test"));

        CHECK_THROWS(notebook.write(-13, -1, -44, Direction::Horizontal, "test"));

    }

    // check that exception is thrown if the input of the colsum is bigger than 99.
    
    SUBCASE("Bad Input: Column Too Large"){

        CHECK_THROWS(notebook.write(1, 54, 98, Direction::Horizontal, "test"));

        CHECK_THROWS(notebook.write(0, 71, 100, Direction::Horizontal, "test"));

        CHECK_THROWS(notebook.write(2, 83, 100, Direction::Vertical, "test"));

    }

    // check that exception is thrown if something has already been written in the desired location.

    SUBCASE("Unable To Write: Something Else Is Already Written There"){

        notebook.write(1, 31, 74, Direction::Horizontal, "test");
        CHECK_THROWS(notebook.write(1, 31, 74, Direction::Horizontal, "test"));
        CHECK_THROWS(notebook.write(1, 31, 72, Direction::Horizontal, "test"));

        notebook.write(0, 67, 23, Direction::Vertical, "test");
        CHECK_THROWS(notebook.write(0, 67, 23, Direction::Vertical, "test"));
        CHECK_THROWS(notebook.write(0, 67, 21, Direction::Vertical, "test"));

    }

    // check that exception is thrown if there are deletions in the desired location.

    SUBCASE("Unable To Write: There Are Deletions There"){

        notebook.erase(1, 0, 3, Direction::Horizontal, 4);
        CHECK_THROWS(notebook.write(1, 0, 3, Direction::Horizontal, "test"));
        CHECK_THROWS(notebook.write(1, 0, 1, Direction::Horizontal, "test")); // befor
        CHECK_THROWS(notebook.write(1, 0, 5, Direction::Horizontal, "test")); // after

        notebook.erase(0, 3, 55, Direction::Vertical, 5);
        CHECK_THROWS(notebook.write(0, 3, 55, Direction::Vertical, "test"));
        CHECK_THROWS(notebook.write(0, 1, 55, Direction::Vertical, "test")); //befor
        CHECK_THROWS(notebook.write(0, 5, 55, Direction::Vertical, "test")); //after

    }
   
}

TEST_CASE("Read Function"){
    
    Notebook notebook;

    // check that exception is thrown if the input of the page or row or colsum is a negative num.
    
    SUBCASE("Bad Input: Negative  Input"){

        CHECK_THROWS(notebook.read(-2, 31, 74, Direction::Horizontal, 4));

        CHECK_THROWS(notebook.read(1, -1, 49, Direction::Horizontal, 3));

        CHECK_THROWS(notebook.read(3, 56, -33, Direction::Horizontal, 4));

        CHECK_THROWS(notebook.read(-3, 11, -33, Direction::Horizontal, 36));

        CHECK_THROWS(notebook.read(-13, -1, -44, Direction::Horizontal, 6));

    }

    // check that exception is thrown if the input of the colsum is bigger than 99.
    
    SUBCASE("Bad Input: Column Too Large"){

        CHECK_THROWS(notebook.read(1, 54, 98, Direction::Horizontal, 5));

        CHECK_THROWS(notebook.read(0, 71, 100, Direction::Horizontal, 8));

        CHECK_THROWS(notebook.read(2, 83, 100, Direction::Vertical, 7));

    }
}

TEST_CASE("Erase Function"){
    
    Notebook notebook;

    // check that exception is thrown if the input of the page or row or colsum is a negative num.
    
    SUBCASE("Bad Input: Negative  Input"){

        CHECK_THROWS(notebook.erase(-2, 31, 74, Direction::Horizontal, 4));

        CHECK_THROWS(notebook.erase(1, -1, 49, Direction::Horizontal, 3));

        CHECK_THROWS(notebook.erase(3, 56, -33, Direction::Horizontal, 4));

        CHECK_THROWS(notebook.erase(-3, 11, -33, Direction::Horizontal, 36));

        CHECK_THROWS(notebook.erase(-13, -1, -44, Direction::Horizontal, 6));

    }

    // check that exception is thrown if the input of the colsum is bigger than 99.
    
    SUBCASE("Bad Input: Column Too Large"){

        CHECK_THROWS(notebook.erase(1, 54, 98, Direction::Horizontal, 5));

        CHECK_THROWS(notebook.erase(0, 71, 100, Direction::Horizontal, 8));

        CHECK_THROWS(notebook.erase(2, 83, 100, Direction::Vertical, 7));

    }
}

TEST_CASE("Notebook Test"){
    
    Notebook notebook;

    notebook.write(1, 31, 74, Direction::Horizontal, "test");
    CHECK(notebook.read(1, 31, 74, Direction::Horizontal, 4) == "test");
    notebook.erase(1, 31, 76, Direction::Horizontal, 4);
    CHECK(notebook.read(1, 31, 74, Direction::Horizontal, 4) == "te~~");
    CHECK(notebook.read(1, 31, 74, Direction::Horizontal, 6) == "te~~~~");

    notebook.write(0, 31, 74, Direction::Vertical, "test");
    CHECK(notebook.read(0, 31, 74, Direction::Vertical, 4) == "test");
    notebook.erase(0, 33, 74, Direction::Vertical, 4);
    CHECK(notebook.read(0, 31, 74, Direction::Vertical, 4) == "te~~");
    CHECK(notebook.read(0, 31, 74, Direction::Vertical, 6) == "te~~~~");

}

