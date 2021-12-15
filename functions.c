#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

#define TXT 1024
#define WORD 30


void makeWord(char word[WORD]){
    char curr;
    int counter = 0;
    while(curr != ' ' && curr != '\t' && curr != '\n' && counter < 30){
        scanf("%c" , &curr);
        word[counter] = curr;
        counter++;
    }
}

void makeText(char text[TXT]){
    char curr;
    int counter = 0;
    while(curr != '~' && counter < 1024){
        scanf("%c" , &curr);
        text[counter] = curr;
        counter++;
    }
}


//-------------Q1 begin---------------------
char lowerCase(char c){
    if(c >= 'A' && c <= 'Z'){
        c = c + 32;
    }
    return c;
}

int gematria(char c){
    if(c >= 'a' && c <= 'z'){
        return c-96;
    }
    if(c>='A' && c<='Z'){
        return c-64;
    }
    return 0;
}

void gematriaSequences(char text[], char word[]){
    int allocCounter=0;
    int totalCounter=0;
    int wordGematriaValue=0;
    int subTextValue=0;
    int wordLen = strlen(word);
    char *beginPnt, *endPnt;
    char resultArr[TXT];
    beginPnt = text;
    endPnt = text;
    for (int i=0;i<wordLen;i++){
        wordGematriaValue = wordGematriaValue + gematria(word[i]);
    }
    subTextValue+= gematria(*beginPnt);
    while (*endPnt != '~')
    {
        if(!gematria(*beginPnt)){
            beginPnt++;
        }
        else if(subTextValue < wordGematriaValue){
            endPnt++;
            subTextValue += gematria(*endPnt);
        }
        else if (subTextValue > wordGematriaValue)
        {
            beginPnt++;
            subTextValue =0 + gematria(*beginPnt);
            endPnt =beginPnt;
        }
        else{
            allocCounter = (endPnt-beginPnt)+2; 
            totalCounter += allocCounter; 
            for (int i=0;i<allocCounter;i++){
                resultArr[totalCounter- allocCounter + i] = *(beginPnt+i);
            }
            resultArr[totalCounter-1] = '~';
            beginPnt++;
            endPnt = beginPnt;
            subTextValue=0 +gematria(*beginPnt);
            allocCounter++;
        }
    }
    resultArr[totalCounter-1] ='\0';
    printf("Gematria Sequences: %s\n",resultArr);
}
//-------------End of Q1------------------------


//-------------Begin of Q2----------------------
void atbash(char arr[]){
    arr[strlen(arr) - 1] = '\0';
    char *ptr=arr;
    while (*ptr){
        if(*ptr >= 'A' && *ptr<= 'Z'){
            int diff = 25 - ((*ptr - 'A')*2);
            *ptr = (*ptr+diff);
        }
        else if(*ptr >= 'a' && *ptr <='z'){
        int diff =25 - ((*ptr - 'a')*2);
        *ptr = (*ptr+diff);
        }
        ptr++;
    }
}

void revers(char arr[]){
    char temp;
    for(int i=0;i< strlen(arr)/2;i++){
        temp = arr[strlen(arr)-i-1];
        arr[strlen(arr)-i-1] = arr[i];
        arr[i] = temp;
    }
}

void atbashSequences(char text[], char word[]){
    atbash(word);
    char *beginPtr=text , *endPtr=text ,*ret;
    char resultArr[TXT] = "" ,temp[strlen(word)], reversedTemp[strlen(word)],tempword[strlen(word)], reversedWord[strlen(word)];
    strcpy(reversedWord,word);
    revers(reversedWord);
    int resultCounter=0;
    resultArr[0]='\0';
    for (int i = 0; i < strlen(word); ++i) {
        tempword[i] = *(word+i);
    }
    for (int i = 0; i < strlen(word); ++i) {
        reversedTemp[i] = *(reversedWord+i);
    }
    tempword[strlen(word)] ='\0';
    reversedTemp[strlen(word)] ='\0';
    while (*endPtr != '~'){
        if(*beginPtr == word[0]){
            //check if regular sequence
            for(int i=0;i< strlen(word);i++){
                temp[i] = *endPtr;
                endPtr++;
            }
            temp[strlen(word)] ='\0';
            ret = strstr(tempword,temp);
            if(ret != NULL){
                strcat(resultArr,temp);
                strcat(resultArr,"~");
                resultCounter+= strlen(temp)+1;
            }
        }
        else if(*beginPtr == word[strlen(word)-1]){
            //check if reversed sequence
            for(int i=0;i<strlen(word);i++){
                temp[i] = *(endPtr);
                endPtr++;
            }
            temp[strlen(word)] ='\0';
            ret = strstr(reversedTemp,temp);
            if(ret != NULL){
                strcat(resultArr,temp);
                strcat(resultArr,"~");
                resultCounter+= strlen(temp)+1;
            }
        }
        beginPtr++;
        endPtr=beginPtr;
    }
    resultArr[resultCounter-1]='\0';
    printf("Atbash Sequences: %s\n",resultArr);
}

//------------End of Q2--------------------



//------------Begin of Q3------------------

int isAnagram(char* a, char* b){
    //b[strlen(b)-1] = '\0';
    int checkAnagram[177] = {0};
    for(int i = 0 ; a[i] != '\0'; i++){
        if(a[i] != ' '){
            checkAnagram[(int)*(a+i)] += 1;
        }
        if(b[i] != ' ' && strlen(b)>i){
            checkAnagram[(int)*(b+i)] -= 1;
        }
    }
    for(int i = 0; i < 177; i++){
        if(checkAnagram[i] != 0){
            return 0;
        }
    }
    return 1;
}

void Anagram_Sequences(char a[], char b[]){
    a[strlen(a)-1] = '\0';
    char *begb_ptr, *endb_ptr, *a_ptr;
    begb_ptr = b; 
    char ans[TXT] = "";
    
    
    while(*begb_ptr){
        char helper[TXT] = "";
        int counter = 0; 
        endb_ptr = begb_ptr;
        a_ptr = a;
        while(counter < strlen(a_ptr)){
        if(*endb_ptr == 32 && !strlen(helper)){
            break;
        }
        else if (*endb_ptr != 32){
            counter ++;
        }
        strncat(helper, endb_ptr,1);
        endb_ptr++;

        if(strlen(a_ptr) == counter){
            if(isAnagram(helper, a_ptr)){
                strcat(ans, helper);
                ans[strlen(ans)] = '~';
                counter = 0; 
            }
        }
        
        }
        begb_ptr++;
    }
    ans[strlen(ans)-1] = '\0'; 
    printf("Anagram Sequences: %s", ans);
}

//------------End of Q3--------------------
