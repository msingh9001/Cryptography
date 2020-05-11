//
//  main.cpp
//  SHA3
//
//  Created by Mandeep Singh on 5/9/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <fstream>
#include<string>
#include "sha3_functions.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    int v[1600], a[5][5][64], a_out[5][5][64], str[1600], v_out[1600],count = 0, c;
    FILE * pFile;
    pFile=fopen ("/Users/msingh9001/Desktop/CSCI\ 181/HW_5/SHA3/SHA3/sha3in.txt","r");
    if (pFile==NULL)
        perror ("Error opening file");
     while(count < 1600){
        c = fgetc(pFile);
        v[count] = c - 48;
        count++;
    }
    fclose (pFile);

//Since C++ does not allow me to return arrays, I pass them into functions
    inputSHA3(v, a);
//Run sha3 operations and output a_out[2][3][11->20] for each operation output
    theta(a, a_out);
    for(int i = 11; i < 21; i++)
        cout << a_out[2][3][i];
    cout << endl;
    rho(a, a_out);
    for(int i = 11; i < 21; i++)
        cout << a_out[2][3][i];
    cout << endl;
    pi(a, a_out);
    for(int i = 11; i < 21; i++)
        cout << a_out[2][3][i];
    cout << endl;
    for(int i = 9; i < 19; i++)
    cout << a_out[4][3][i];
    cout << endl;
    outputSHA3(a_out, v_out);
    return 0;
}
