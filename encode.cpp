#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//Variable for testing
bool TESTING = false;

//True for Insersion, false for merge
bool sort1 = true;

//Declare this globally
int originalIndex = -1;

int newFunction();

//Function to perform a left shift on a string
string leftShift(string InputWord) {
    //Temp variable to save character that will be deleted by the shift
    char key = InputWord[0];

    for (int i = 0; i < InputWord.length(); i++) {
        std::swap(key, InputWord[InputWord.length() - 1 - i]);
    }

    return InputWord;
}

// Insertion sort1 vector implementation passed by reference to save memory
void insertionsort(string *arr, int n) {
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

void merge(string *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;


    string *L = new string[n1];
    string *R = new string[n2];

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

void mergesort(string *arr, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int encrypt(string input) {
    int length = input.length();
    //Declare an array to hold each cyclic shift
    string* variations = new string[length];

    int clustercount = 1;

	//For empty lines
	if(input.empty()) {
		cout << endl;
		return 0;
	}
    
    //Add the original string to the list
    variations[0] = input;

    //Loop through variations array filling it with each leftshift
    for (int i = 1; (unsigned) i < input.size(); i++) {
        variations[i] = (leftShift(variations[i - 1]));
    }

    //Decide which sort1 to perform
    (sort1) ? (insertionsort(variations, input.size() - 1)) : (mergesort(variations, 0, input.size() - 1));

    //String to hold final answer
    string result;

    //Variable to hold index of original string
    int original = 0;

    //For loop to parse end of string into clusters
    for (int i = 0, amount = 1;
         (unsigned) i < input.size(); i++) {

        //Save index of original string
        if (variations[i] == input) {
            original = i;
        }

        //check to see if the end has been reached yet
        if ((unsigned) i < input.size() - 1) {
            //If there are two equal characters increase count of cluster by 1
            if (variations[i + 1][input.size() - 1] == variations[i][input.size() - 1]) {
                amount++;
            } else {
                //Otherwise reset amount count and add the cluster information to the result string
                result += to_string(amount) + " " + variations[i][input.size() - 1] + " ";
                amount = 1;
                if (TESTING) {
                    clustercount++;
                }
            }
        } else {
            //For the end of the string
            result += to_string(amount) + " " + variations[i][input.size() - 1];
        }
    }

    if (TESTING) {
        if (length > 0) {
            return ((length - clustercount) * 100 / length);
        }
    } else {
        //Print the results
        cout << original << endl << result << endl;
    }
    return 0;
}


int main(int argc, char * argv[]) {
    if (argc > 1) {
        if (string(argv[1]) == "insertion") {
            sort1 = true;
        } else if (string(argv[1]) == "mergesort") {
            sort1 = false;
        }
    }

    for (string input; getline(cin, input);encrypt(input)) {}
    return 0;
}