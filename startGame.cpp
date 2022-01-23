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
* <file to start game>
*
*/

#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
#include "startGame.h"
#include "generateTable.h"
#include "printTable.h"
#include "readMove.h"
#include "validateMove.h"
#include "computerMove.h"
#include "makeMove.h"
using namespace std;

void startGame(int h, int w) 
{
    vector < vector < char > > table(h, vector<char> (w, 0));
    table = generateTable(h, w);
    while(true)
    {
        printTable(h, w, table);
        tuple<char, int, int> move;
        cout << "Input move\n";
        while(true) {
            move = readMove();
            if (validateMove(h, w, table, move)) { 
                break;
            }
            else {
                cout << "Invalid move, try again\n";
                continue;
            }
        }
        makeMove(h, w, table, move);
        int res = computerMove(h, w, table);
        if (res == -1)
        {
            cout << "##########\n";
            cout << "###MATE###\n";
            cout << "##########\n";
            return;
        }
        else if (res == -2)
        {
            cout << "#############\n";
            cout << "##STALEMATE##\n";
            cout << "#############\n";
            return;
        }
    }
}