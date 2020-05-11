//My code executes but does not run properly after i made some big changes to the array manipulation but i believe my logic is correct as it was working before
//  main.cpp
//  RC4_keystream
//
//  Created by Mandeep Singh on 4/24/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//
//Since C++ doesn't allow you to return arrays from a funtion, I had to change decimalToBinary and convertBitArrayToInt a little to get it to work. Instead of returning an array, I passed a pointer to an array I created in main and all operations in each function were done to that array
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "RC4_functions.hpp"

using namespace std;
int main() {
    //Take all inputs and inputStream is stream of binary bits with no spaces
    int n, l;
    cout << "Please enter your n: ";
    cin >> n;
    cout << "Please enter the length of your plaintext/ciphertext: ";
    cin >> l;
    string inputStream;
    cout << "Please enter the values for the key: " << endl;
    cin >> inputStream;
    //Initialize integer arrays and variables
    int key_bits_length = inputStream.length();
    int key_bits[key_bits_length], vectorLength = static_cast<int>(pow(2, n) - 1), keyLength = key_bits_length/n, ks[l], keystream[n*l], key[keyLength], keyPos = 0, S[vectorLength], T[vectorLength];
    
    //Transfer inputStream bits to an integer array key_bits
    for(int i = 0; i < key_bits_length; i++)
        key_bits[i] = inputStream[i] - 48;
    //Convert binary array to a decimal and put in key array
    for(int i = n - 1; i < key_bits_length; i += n){
        int decimal = convertBitArrayToInt(n, key_bits, i);
        key[keyPos] = decimal;
        keyPos++;
    }
    for(int k = 0; k < keyLength; k++)
        cout << key[k] << " ";
    //Fill S vector from 0 -> 2^n-1 and vector T with key bits repeatedly
    for(int i = 0; i < static_cast<int>(pow(2, n)); i++){
        S[i] = i;
        T[i] = key[i % (key_bits_length)];
    }
    
    //Do swapping
    int j = 0;
    for(int i = 0; i < static_cast<int>(pow(2, n)); i++){
        j = (j + S[i] + T[i]) % static_cast<int>(pow(2, n));
        swap(S, i, j);
    }
    
    //Key Generation
    int a = 0, b = 0, t;
    for(int i = 0; i < l; i++){
        a = (a+1) % static_cast<int>(pow(2, n));
        b = (b + S[a]) % static_cast<int>(pow(2, n));
        swap(S, a, b);
        t = (S[a] + S[b]) % static_cast<int>(pow(2, n));
        ks[i] = S[t];
    }
    
    //Convert entire ks array from decimal to binary and binary values are stored in keystream. Since the binary representation in temp is backwards we store it into keystream correctly through tempArray
    int keystreamPos = 0, temp[n];
    for(int i = 0; i < l; i++){
        int tempArr[n];
        //Initialize arrays to 0 just to prevent any garbage values
        for(int j = 0; j < n; j++){
            temp[j] = 0;
            tempArr[j] = 0;
        }

        decimalToBinary(ks[i], n, temp);
        //Put values from temp backwards into tempArr
        for(int k = 0; k < n; k++)
            tempArr[k] = temp[(n - 1) - k];
        //Put values from tempArr into keystream array
        for(int l = 0; l < n; l++){
            keystream[keystreamPos] = tempArr[l];
            keystreamPos++;
        }
    }
    
    //Output values of keystream
    cout << "\n[";
    for(int j = 0; j < (n*l) - 1; j++)
        cout << keystream[j] << ", ";
    cout << keystream[(n*l)-1] << "]" << endl;
    return 0;
}
