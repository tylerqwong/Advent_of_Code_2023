#include <iostream>
#include <vector>
#include <string>
#include <fstream>
//User Includes and static variables
#include "cubes.h"

using namespace std;

/* File Description */

// Part 1
// Given a numbered set of games where we look at handfuls of coloured cubes from a bag. In which of
// these games is it possible that the total number of cubes in the bag is (R:12, G:13 B:14)?

// 1. Load a game (1 line) + note the ID
// 2. Iterate through the line and load the 1st handful
// 3. IF handful DOES NOT disqualify game...
//      ... go to next handful (and if it's the last handful then add ID to acc)
//      ... ELSE: simply load next game

/* Class Function Definitions */

int main()
{
    // Initialize filestream
    std::ifstream inf{"cubes.txt"};
    if(!inf){                   // Check that ifstream opened the file correctly:
        std::cout << "Error: File Not Opened!";
        return 1;
    }

    // Initialize Variables
    int acc, id = 0;            // Accumulates IDs, holds current ID
    int index, flag;
    std::string line;           // Used to save each line of the input data text file 

    while(inf){
        std::getline(inf, line);// Get a line of the file...
        if (line.length() < 1){
            break;
        }
        id++;// Update the ID#
        flag = 0;
            
        // Iteratre through all "red" numbers in the first line
        index = 0;
        while (flag == 0){
            index = line.find("red", index+1);
            if (index == -1){
                break;
            }
            else if (get_num(line, index) > 12){
                flag++;
                break;
            }
        }

        // Iteratre through all "green" numbers in the first line
        index = 0;
        while (flag == 0){
            index = line.find("green", index+1);
            if (index == -1){
                break;
            }
            else if (get_num(line, index) > 13){
                flag++;
                break;
            }
        }

        // Iteratre through all "blue" numbers in the first line
        index = 0;
        while (flag == 0){
            index = line.find("blue", index+1);
            if (index == -1){
                break;
            }
            else if (get_num(line, index) > 14){
                flag++;
                break;
            }
        }
        
        if (flag == 1){
            std::cout << "Game " << id << " breaks the rules\n";
        }
        else{
            acc += id;
            std::cout << "Game " << id << " is valid\n";
        }
    }

    std::cout << "Sum of Valid games: " << acc << '\n';
    
}

/* Function Definitions */
bool is_valid(int r, int g, int b){
    bool ret_value = true;

    if (r > 12 || g > 13 || b > 14){
        ret_value = false;
    }

    return ret_value;
}

int get_num(std::string line, int index){
    int ret_value = 0;
    
    if(isdigit(line[index-3])){
        ret_value = stoi(line.substr(index-3, 2));
    }
    else{
        ret_value = stoi(line.substr(index-2, 1));
    }

    return ret_value;
}
