#ifndef TEXTLIB_H
#define TEXTLIB_H

#include <sstream>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

fstream file;
char fileName[200];

void checkExisting();
void addNewText();
void displayContent();
void deleteContent();
void encryptContent();
void decryptContent();
void mergeFile();
void countWordsNumber();
void countCharNumber();
void countLinesNumber();
void searchWord();
void countWordExists();
void upperCase();
void lowerCase();
void firstCaps();
void saveFile();

#endif //UNTITLED21_TEXTLIB_H