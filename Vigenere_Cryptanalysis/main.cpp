//
//  main.cpp
//  vigenere_cryptanalysis
//
//  Created by Mandeep Singh on 4/12/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//
#include <stdio.h>
#include <iomanip>
#include <string>
#include <iostream>
#include "cryptanalyze.hpp"

using namespace std;
int main(int argc, const char * argv[]) {
    int x = 0;
    while(x != 1){
        vigenere_cryptanalyze();
        cout << "\nWould you like to cryptanalyze something else? Enter 0 for yes or 1 for no: " << endl;
        cin >> x;
    }
    return 0;
}
