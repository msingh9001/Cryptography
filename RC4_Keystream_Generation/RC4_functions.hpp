//My code executes but does not run properly after i made some big changes to the array manipulation but i believe my logic is correct as it was working before
//  RC4_functions.hpp
//  RC4_keystream
//
//  Created by Mandeep Singh on 4/24/20.
//  Copyright © 2020 Mandeep Singh. All rights reserved.
//

#ifndef RC4_functions_hpp
#define RC4_functions_hpp

#include <stdio.h>
int convertBitArrayToInt(int n, int* key_bits, int loc);
void swap(int* S, int i, int j);
void decimalToBinary(int number, int n, int* temp);
#endif /* RC4_functions_hpp */
