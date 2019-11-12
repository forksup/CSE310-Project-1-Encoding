#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

using namespace std;

//True for Insersion, false for merge
bool sort1 = true;

//Declare this globally
int originalIndex = -1;

// Insertion sort1 vector implementation passed by reference to save memory
void insertionsort(vector < string > & arr, int n) {
    string key;
    int i, j;
    for (i = 1; i <= n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].compare(key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(vector < string > &arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<string> L(n1,"");
    vector<string> R(n2,"");

    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector < string > & arr, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void decrypt(string input) {
    //Index used to distinguish between index and cluster lines. Set to -1 after decoding of cluster is complete
    if (originalIndex == -1) {
        originalIndex = stoi(input);
        return;
    }
    string line = input;
    vector < string > last;
    vector < string > first;

    //If statement to capture empty spaces
    if (line == " " && originalIndex == 0) {
        cout << " " << endl << endl;
        originalIndex = -1;
        return;
    }

    int distance = 0;

    for (int i = 0; i < line.length(); i = i + 4) {
        //Check to see if count is double digits
        string count;

        count = line[i + distance];

        while (line[i + 1 + distance] != ' ') {
            distance++;
            count += line[i + distance];
        }

        for (int j = stoi(count); j > 0; j--) {
            string s(1, line[i + 2 + distance]);
            last.push_back(s);
        }
    }

    //Below sort1 the first last characters
    first = last;
    (sort1) ? (insertionsort(first, first.size() - 1)) : (mergesort(first, 0, first.size() - 1));

    vector < int > next(first.size(), -1);

    string original;
    for (int j = 0; j < first.size() - 1; j++) {
        if (original == first[j]) {
            continue;
        }
        original = first[j];
        vector < int > indexes;

        //Find the indexes of characters ending with that letter
        for (int p = 0; p < first.size(); p++) {
            if (last[p] == original) {
                indexes.push_back(p);
            }
        }

        if (indexes.size() < 2) {
            continue;
        }

        //Loop through last array and assign the next values to those with matching first letters
        for (int l = 0; l < last.size() && indexes.size() > 0; l++) {
            if (first[l] == original) {
                next[l] = indexes[0];
                indexes.erase(indexes.begin());
            }
        }
    }

    //At this point all the matching letters have been assigned.
    //Now apply next to the rest of the characters
    for (int i = 0; i < first.size(); i++) {

        //Make sure the next value isn't already assigned
        if (next[i] == -1) {
            //Loop through first letters to find next
            for (int j = 0; j < first.size(); j++) {
                if (last[j] == first[i]) {
                    next[i] = j;
                    break;
                }
            }
        }
    }

    //Now assemble solution off next array and store it in result string
    string result;

    int i = originalIndex;
    while (true) {
        result += first[i];
        if (next[i] == originalIndex) {
            break;
        }
        else {
            i = next[i];
        }
    }
    originalIndex = -1;
    cout << result << endl;

}

int main(int argc, char * argv[]) {
    if (argc > 1) {
        if (string(argv[1]) == "insertion") {
            sort1 = true;
        }
        else if (string(argv[1]) == "mergesort") {
            sort1 = false;
        }
    }

    for (string input; getline(cin, input); decrypt(input)) {}

    return 0;
}