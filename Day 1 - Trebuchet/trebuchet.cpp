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
    int acc, temp = 0;      // Accumulates...
    std::string line;       // Used to save each line of the input data text file 

    do{
        // Get a line of the file...
        std::getline(inf, line);

        // Extract the coordinate from the line and add to acc
        temp = get_coord(line);
        acc += temp;

        // std::cout << line << '\n';
        // std::cout << temp << '\n';

        temp = 0;
    } while(inf);
    
    std::cout << acc << '\n';
    

    // Test Cases
    // line = "asd1oijlkml";
    // std::cout << get_coord(line) << " expected 11\n";
    // line = "aisdjsakjd";
    // std::cout << get_coord(line) << " expected 0\n";
    // line = "9128374adsasd6987";
    // std::cout << get_coord(line) << " expected 97\n";

}

/* Function Definitions */
int get_coord(std::string line){
    std::string output, first, last = "";
    int iter = 0;

    for(int i = 0; i<line.length(); i++){
        if (isdigit(line[i])){
            if (first == ""){
                first = line[i];
            };
            last = line[i];
        }
    };

    if (last == ""){
        return 0;
    }
    else{
        output = first + last;
        return stoi(output);
    }

    
}
