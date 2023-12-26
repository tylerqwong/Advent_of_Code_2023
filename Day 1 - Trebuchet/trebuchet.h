// This documented created following the Google C++ header style guide: https://google.github.io/styleguide/cppguide.html#C++_Version


#ifndef ADVENTOFCODE2023_NAME_H_
#define ADVENTOFCODE2023NAME_H_

/* Function Declarations */

// Takes a string representing a coordinate line.
// Returns 2-digit co-ordinate number. 
int get_coord(std::string line);

int get_coord2(std::string line);

// Takes a string representing a coordinate line.
// Takes an integer pointing to an index in the line.
// Returns -1 if that index does NOT point to the start of a number word.
// Returns a single digit integer IF it points to the start of a number word.
int isword(std::string line, int index);

/* Class Declarations */

#endif  // ADVENTOFCODE2023_NAME_H_