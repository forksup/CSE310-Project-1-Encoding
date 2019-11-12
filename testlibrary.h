//
// Created by Mitch on 10/1/2019.
//

#ifndef PROJECT1_TESTLIBRARY_H
#define PROJECT1_TESTLIBRARY_H
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

class test1 {
public:

    //For Average Word length
//80% are between 4 and 10 letters long
    int AVERAGE_WORDLENGTH_MIN = 10;
    int AVERAGE_WORDLENGTH_MAX = 15;

//The amount of same charcters to generate 1 < x < 4
    int maxAmountOfSameCharacters;

//The amount of characters that we will generate maxAmountOfSameCharacters on.
    int amountWithSameCharacters;

//Amount of strings on each line
//45 / 5  = 9
// 8 words would  7 spaces,

    int random (int low, int high) {
        if (low > high) return high;
        return low + (std::rand() % (high - low + 1));
    }

    string generationString() {

        vector<char> result;
        std::vector<char> englishAlphabetUpper({'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                                                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'});

        for (int i = 0; i < maxAmountOfSameCharacters; i++) {

            // https://stackoverflow.com/a/12657984
            int index = random(0,englishAlphabetUpper.size()-1);

            for (int j = 0; j < amountWithSameCharacters; j++) {
                result.push_back(englishAlphabetUpper[index]);
            }

            englishAlphabetUpper.erase(englishAlphabetUpper.begin() + index);
        }

        int wordLength = random(AVERAGE_WORDLENGTH_MIN,AVERAGE_WORDLENGTH_MAX);

        for (int i = 0; i < wordLength - result.size(); i++) {
            int index = random(0,englishAlphabetUpper.size()-1);
            int index2 = random(0,result.size()-1);
            result.insert(result.begin() + index2, englishAlphabetUpper[index]);
            englishAlphabetUpper.erase(englishAlphabetUpper.begin() + index );
        }

        string final;
        for (int i = 0; i < result.size(); i++) {
            final += result[i];
        }
        return final;
    }

    string generate(int amountoflines, int stringsPerLine,int maxAmountOfSameCharacters1,int amountWithSameCharacters1) {

        this->maxAmountOfSameCharacters = maxAmountOfSameCharacters1;
        this->amountWithSameCharacters = amountWithSameCharacters1;

        string result;

        for (int j = 0; j < amountoflines;j++) {
            for (int i = 0; i < stringsPerLine; i++) {
                result += generationString();
                result += " ";
            }
            result += "\n";
        }

        return result;
    }
};




#endif //PROJECT1_TESTLIBRARY_H
