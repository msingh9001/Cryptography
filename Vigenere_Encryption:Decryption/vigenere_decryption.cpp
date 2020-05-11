//
//  vigenere_decryption.cpp
//  vigenere
//
//  Created by Mandeep Singh on 4/12/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//

#include "vigenere_decryption.hpp"
#include <iostream>
#include <string>
using namespace std;
void decryption(){
    string ciphertext, key;
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    
    //Getting inputs for ciphertext and key
    cout << "Please enter your ciphertext: " << endl;
    cin >> ciphertext;
    cout << "Please enter your key: " << endl;
    cin >> key;
    //Create a char array sizeof ciphertext
    char plaintext[ciphertext.length()];
    int i = 0, c = 0, c2 = 0, x, y, z;
    //Loop through all indices of ciphertext
    while(i < ciphertext.length()){
        //Search for number position of ciphertext character in alphabet
        for(int j = 0; j < 26; j++)
            if(alphabet[j] == ciphertext[i]){
                x = j;
                break;
            }
        //Search for number position of key character in alphabet
        for(int k = 0; k < 26; k++)
            if(alphabet[k] == key[c % key.length()]){
                y = k;
                break;
            }
        //Subtract number positions mod 26
        z = ((x - y) % 26 + 26) % 26;
        //Set plaintext[i] to corresponding encrypted character
        plaintext[c2] = alphabet[z];
        c2++;
        c++;
        i++;
    }
    //Output plaintext
    for(int t = 0; t < ciphertext.length(); t++)
        cout << plaintext[t] ;
}
