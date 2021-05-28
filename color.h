#ifndef _COLOR_H_
#define _COLOR_H_
#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class chooseRed
{
  public:
    void setColors();  // this function is used to size and fill in the matrix declared below this line.
    void showColors();  //this function is used to output all of the colors in the matrix.
    void tutorial();  //this function lets the user play a tutorial before playing the base game.
    void game(); //this function starts the game and stops when the user wishes to quit or if the user gets a wrong answer.
  private:
    vector<vector<string> > colors;
    int randomBetween (int, int); //this function generates a random number between two given numbers.
    string scramble (string); //this function is used to rearrange the letters in the colors.
};


#endif
