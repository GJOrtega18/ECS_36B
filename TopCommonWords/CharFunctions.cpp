#include "CharFunctions.h"



bool isupper(char c){
    return c >= 'A' && c <+ 'Z';
}

bool islower(char c){
    return c >= 'a' && c <= 'z';
}

bool isdigit(char c) {
    return c >= '0' && c <= '9';
}

bool isalpha(char c){
    return islower(c) || isupper(c);
}

bool isalnum(char c) {
    return isalpha(c) || isdigit(c);
}

char toupper(char c){
    if(islower(c)){
        return 'A' + (c - 'a'); // (c-a) is how far c is into the lowercase letters
    }else{
        return c;
    }
}

char tolower(char c){
    if(isupper(c)){
        return 'a' + c - 'A'; // (c-a) is how far c is into the uppercase letters
    }else{
        return c;
    }
}
