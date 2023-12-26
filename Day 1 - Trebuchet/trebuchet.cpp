#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes and static variables
#include "trebuchet.h"

using namespace std;

/* File Description */

// Part 1
// We are given calibration document consisting of manny lines of text with some digits in them.
// The co-ordinate associated with each line of text is a 2-digit number where the first digit
// is the first digit present in a line of text and the second digit is the second digit 
// present in a line of text.

// What is the sum of all of the calibration values?

// 1. Load the first line into a temp string
// 2. Run get_coord()
// 3. Add the coord into an accummulator.
// 4. Repeat until EOF.
// 5. Print output.

// Part 2
// "one", "two", "three", "four", "five", "six", "seven", "eight", and "nine" are now also
// valid digits.

// What is the sum of all of the calibration values?

// 1. 

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
        temp = get_coord2(line);
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

int get_coord2(std::string line){
    std::string output, first, last = "";
    int iter = 0;

    for(int i = 0; i<line.length(); i++){
        if (isdigit(line[i])){
            if (first == ""){
                first = line[i];
            };
            last = line[i];
        }
        else if (isword(line, i) != -1){
            if (first == ""){
                first = to_string(isword(line, i));
            };
            last = to_string(isword(line, i));
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

int isword(std::string line, int index){
    // Instantiate Variables
    int ret_value = -1;

    // Check for word
    switch(line[index]){
        case 'o':
            if(line[index+1] == 'n' && line[index+2] == 'e'){
                ret_value = 1;
            }
            break;
        case 't':
            if(line[index+1] == 'w' && line[index+2] == 'o'){
                ret_value = 2;
            }
            if(line[index+1] == 'h' && line[index+2] == 'r' && line[index+3] == 'e' && line[index+4] == 'e'){
                ret_value = 3;
            }
            break;
        case 'f':
            if(line[index+1] == 'o' && line[index+2] == 'u' && line[index+3] == 'r'){
                ret_value = 4;
            }
            if(line[index+1] == 'i' && line[index+2] == 'v' && line[index+3] == 'e'){
                ret_value = 5;
            }
            break;
        case 's':
            if(line[index+1] == 'i' && line[index+2] == 'x'){
                ret_value = 6;
            }
            if(line[index+1] == 'e' && line[index+2] == 'v' && line[index+3] == 'e' && line[index+4] == 'n'){
                ret_value = 7;
            }
            break;
        case 'e':
            if(line[index+1] == 'i' && line[index+2] == 'g' && line[index+3] == 'h' && line[index+4] == 't'){
                ret_value = 8;
            }
            break;
        case 'n':
            if(line[index+1] == 'i' && line[index+2] == 'n' && line[index+3] == 'e'){
                ret_value = 9;
            }
            break;
    }
    
    return ret_value;
}
