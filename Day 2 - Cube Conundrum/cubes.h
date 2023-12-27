// This documented created following the Google C++ header style guide: https://google.github.io/styleguide/cppguide.html#C++_Version


#ifndef ADVENTOFCODE2023_NAME_H_
#define ADVENTOFCODE2023_NAME_H_

/* Function Declarations */

// Check if a handful is valid.
// Takes three integers representing a number of r, g, and b cubes in a handful.
// Returns true if the handful of cubes is valid within the hypothesized rmax=12, gmax=13, bmax=14.
bool is_valid(int r, int g, int b);

// TODO: write function header
int get_num(std::string line, int index);

/* Class Declarations */

#endif  // ADVENTOFCODE2023_NAME_H_