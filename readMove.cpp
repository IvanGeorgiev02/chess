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
* <file to read move>
*
*/

#include<iostream>
#include<tuple>
#include<algorithm>
#include<vector>
#include "readMove.h"
using namespace std;

tuple <char, int, int> readMove()
{
    char fig;
    int r, c;
    cin >>  fig >> r >> c;
    return make_tuple(fig, r, c);
}
