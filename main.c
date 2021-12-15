#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define TXT 1024
#define WORD 30

int main(){
    char text[TXT];
    char word[WORD];
    char word_temp[WORD];
    char text_temp[TXT];
    makeWord(word);
    makeText(text);
    strcpy(word_temp, word);
    strcpy(text_temp, text);
    gematriaSequences(text_temp,word_temp);
    strcpy(word_temp, word);
    strcpy(text_temp, text);
    atbashSequences(text_temp,word_temp);
    strcpy(word_temp, word);
    strcpy(text_temp, text);
    Anagram_Sequences(word_temp,text_temp);
    return 0;
}