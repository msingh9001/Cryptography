//My code executes but does not run properly after i made some big changes to the array manipulation but i believe my logic is correct as it was working before
//  RC4_algorithm.cpp
//  RC4_keystream
//
//  Created by Mandeep Singh on 4/24/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//
#include <iostream>
#include <cmath>
#include <vector>
#include "RC4_functions.hpp"
//Knowing that at position n of a binary number, if the value is 1, we can add 2^n and loop through the entire binary number to find the decimal value
int convertBitArrayToInt(int n, int* key_bits, int loc){
    int decimal = 0, power = 1;
    for(int i = 0; i < n; i++){
        decimal += key_bits[loc - i] * power;
        power *= 2;
    }
    return decimal;
}
//Function to swap two integers in S array
void swap(int* S, int i, int j){
    int temp = S[j];
    S[j] = S[i];
    S[i] = temp;
}
//Mod number with 2 and remainder is bit but it is stored backwards
void decimalToBinary(int number, int n, int* temp){
    int i = 0, num = number;
    while(num > 0){
        //Storing remainder in binary array
        temp[i] = num % 2;
        num = num / 2;
        i++;
    }
}
/*void convertBitArrayToInt(int n, int* key_bits, int* key, int key_bits_length){
    int keyPos = 0;
    for(int i = n-1; i < key_bits_length; i+=n){
        int decimal = 0, power = 1, j = i, c = n;
        while(c > 0){
            decimal += key_bits[j] * power;
            power *= 2;
            j--;
            c--;
        }
        key[keyPos] = decimal;
        keyPos++;
    }
}*/
