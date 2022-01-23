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
* <file to make move>
*
*/

#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
#include "makeMove.h"
using namespace std;

void makeMove(int h, int w, vector < vector < char > > &table, tuple <char, int, int> move)
{
    for (int i = 0; i < h; i ++)
    {
        for (int j = 0; j < w; j ++)
        {
            if (table[i][j] == get<0>(move))
            {
                swap(table[i][j], table[get<1>(move)][get<2>(move)]);
                return;
            }
        }
    }
}