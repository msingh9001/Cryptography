//  main.cpp
//  RC4
//  Created by Mandeep Singh on 4/23/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//Since C++ doesn't allow you to return arrays from a funtion, I had to change decimalToBinary and convertBitArrayToInt a little to get it to work. Instead of doing one number in base 10 or base 2 at a time, I converted them all at once
#include <iostream>
#include <string>
#include "keystream_generation.hpp"

using namespace std;
int main() {
    int n, l, key_bits_length;
    cout << "Please enter your n: ";
    cin >> n;
    cout << "Please enter the length of your plaintext/ciphertext: ";
    cin >> l;
    //Initialize array to hold ks values
    int ks[l];
    //Initialize array to hold ks values converted to binary
    int keystream[n*l];
    cout << "Please enter the length of your key: ";
    cin >> key_bits_length;
    //Initialize and take in bits for key
    int key_bits[key_bits_length];
    cout << "Please enter the values for the key: ";
    for(int i = 0; i < key_bits_length; i++)
        cin >> key_bits[i];
    
    //Convert the key bits to decimal
    int keyLength = key_bits_length/n;
    int key[keyLength], keyPos = 0, temp[keyLength];
    for(int i = 0; i < key_bits_length; i += n){
        
        //Convert binary array to a decimal and put in key array
        int decimal = convertBitArrayToInt(n, key_bits, i);
        temp[keyPos] = decimal;
        keyPos++;
    }
    for(int i = 0; i < keyLength; i++)
        temp
    //Generate keystream
    keystream_generation(n, l, key, ks, key_bits_length);
    //Convert entire ks array from decimal to binary and binary values are stored in keystream
    decimalToBinary(n, ks, keystream);
    //Output values of keystream
    cout << "[";
    for(int j = 0; j < (n*l) - 1; j++)
        cout << keystream[j] << ", ";
    cout << keystream[(n*l)-1] << "]";
    return 0;
}
