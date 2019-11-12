
#include <ctime>
#include <ratio>
#include <chrono>
#include <fstream>

const int MAX = 26;

// Returns a string of random alphabets of
// length n.
string printRandomString(int n)
{
    char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                           'h', 'i', 'j', 'k', 'l', 'm', 'n',
                           'o', 'p', 'q', 'r', 's', 't', 'u',
                           'v', 'w', 'x', 'y', 'z' };
    string res = "";
    for (int i = 0; i < n; i++)
        res = res + alphabet[rand() % MAX];

    return res;
}

int range = 1000;
ofstream outputFile;
outputFile.open("test123.txt");
string input = "";

for(int i =1; i<=range;i++) {

int loopcount = 10;

int insertsion = 0;
int mergesort = 0;
input += printRandomString(1);

for(int j = 0;j<loopcount;j++) {

using namespace std::chrono;
sort1 = true;
auto start = high_resolution_clock::now();
encrypt(input);
auto stop = high_resolution_clock::now();
sort1 = false;
auto duration = duration_cast<microseconds>(stop - start);
mergesort += duration.count();
start = high_resolution_clock::now();
encrypt(input);
stop = high_resolution_clock::now();
duration = duration_cast<microseconds>(stop - start);
insertsion += duration.count();
}

outputFile << i << ", " << mergesort/loopcount << ", " << insertsion/loopcount << endl;