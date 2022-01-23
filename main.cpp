/**
*
* Solution to course project # 12
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Ivan Georgiev
* @idnumber 6MI0600074
* @compiler VC
*
* <main file>
*
*/

#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
#include "startGame.h"
using namespace std;
int main()
{
    int h = 8, w = 8;
    while (true) {
        cout << "Choose Start/End/Change\n";
        string input;
        cin >> input;
        if (input == "Start") {
            startGame(h, w);
        }
        else if (input == "End") {
            break;
        }
        else if (input == "Change") {
            cout << "Input new height and width respectively\n";
            int h1, w1;
            cin >> h1 >> w1;

            if (h1 >= 6 && w1 >= 6 && h1 <= 20 && w1 <= 20)
            {
                h = h1;
                w = w1;
            }
            else 
            {
                cout << "Invalid dimensions\n";
            }
        }
        else
        {
            cout << "Invalid input";
        }
    }
    return 0;
}