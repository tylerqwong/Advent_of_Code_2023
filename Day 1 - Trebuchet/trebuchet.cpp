#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes and static variables
#include "trebuchet.h"

using namespace std;

/* File Description */
// We are given calibration document consisting of manny lines of text with some digits in them.
// The co-ordinate associated with each line of text is a 2-digit number where the first digit
// is the first digit present in a line of text and the second digit is the second digit 
// present in a line of text.

// What is the sum of every calibration number?

// 1. Load the first line into a temp string
// 2. Run get_coord()
// 3. Add the coord into an accummulator.
// 4. Repeat until EOF.
// 5. Print output.

/* Class Function Definitions */

int main()
{
    // Initialize filestream
    std::ifstream inf{"trebuchet.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize Variables
    int acc = 0;            // Accumulates...
    std::string line;       // Used to save each line of the input data text file 

    while(inf){
        // Get a line of the file...
        std::getline(inf, line);
        acc++;
    }
    

    std::cout << line << '\n';
    std::cout << acc << '\n';

}

/* Function Definitions */

