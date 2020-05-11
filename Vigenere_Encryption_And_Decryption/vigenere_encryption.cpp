//
//  vigenere_encryption.cpp
//  vigenere
//
//  Created by Mandeep Singh on 4/12/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//

#include "vigenere_encryption.hpp"
#include <iostream>
#include <string>
using namespace std;
void encryption(){
    string plaintext, key;
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    //Getting inputs for plaintext and key
    cout << "Please enter your plaintext: " << endl;
    cin >> plaintext;
    cout << "Please enter your key: " << endl;
    cin >> key;
    //Create a char array sizeof plaintext
    char ciphertext[plaintext.length()];
    int i = 0, c = 0, x, y, z;
    //Loop through all indices of plaintext
    while(i < plaintext.length()){
        //Search for number position of plaintext character in alphabet
        for(int j = 0; j < 26; j++)
            if(plaintext[i] == alphabet[j]){
                x = j;
                break;
            }
        //Search for number position of key character in alphabet
        for(int k = 0; k < 26; k++)
            if(key[c % key.length()] == alphabet[k]){
                y = k;
                break;
            }
        //Add number positions mod 26
        z = (x + y) % 26;
        //Set ciphertext[i] to corresponding encrypted character
        ciphertext[i] = alphabet[z];
        c++;
        i++;
    }
    //Output ciphertext
    for(int t = 0; t < plaintext.length(); t++)
    cout << ciphertext[t] ;
}
