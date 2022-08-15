#include <iostream>
#include <stdlib.h>
#include <time.h>  
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;

#define NC "\e[0m"         // no colour


int check(string word, char newletter) {
    for (int j = 0; j < 5; j++) {
        if (newletter == word[j]) {
            return 0;
        } else {
            continue;
        }
    }
    return 1;
}



int main() {
    HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    srand (time(0));
    int random = rand() % 496 + 1;
    string word;
    string path = "C:\\Users\\aryan\\OneDrive\\Documents\\Computing\\C++\\wordle\\words\\words.txt";
    fstream file(path);
    for (int h = 0; h < random; h++) {
        file >> word;
    }
    string newword;
    int guess = 0;
    cout << "Welcome to wordle (but harder)!\n";
    while (guess < 7) {
        cout << "\nEnter a 5 letter word (all lower case)\nGuess " << guess+1 << ": ";
        cin >> newword;
        if (newword == word) {
            SetConsoleTextAttribute(hconsole,BACKGROUND_GREEN);
            for (int g = 0; g < 5; g++) {
                cout << " " <<  newword[g] << " ";
            }
            cout << NC "\nCongrats! You got it!";
            break;
        }
        for (int i = 0; i < 5; i++) {
            if (newword[i] == word[i]) {
                SetConsoleTextAttribute(hconsole,BACKGROUND_GREEN);
                cout << " " << newword[i] << " " << NC "";
            } else {
                char l = newword[i];
                int checky = check(word,l);
                if (checky == 0) {
                    SetConsoleTextAttribute(hconsole,BACKGROUND_RED | BACKGROUND_GREEN);
                    cout << " " << newword[i] << " " << NC "";
                } else if (checky == 1) {
                    cout << " " <<  newword[i] << " ";
                }
            }
        }
        guess = guess + 1;
        if (guess == 6 && newword != word) {
            cout << "\nOoh! So close! The word was ";
            SetConsoleTextAttribute(hconsole,BACKGROUND_GREEN);
            for (int f = 0; f < 5; f++) {
                cout << " " << word[f] << " ";
            }
            cout << NC "! Better luck next time!";
            break;
        }
    }
    return 0;
}