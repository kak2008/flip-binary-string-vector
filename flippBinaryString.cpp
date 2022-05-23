#include <iostream> 
#include <vector>

using namespace std;

// flips the given integer value
int flip(int num) {
    return (num == 0) ? 1 : 0;
}

// prints values of given vector
void printVector(vector<int>*v) {
    for(int i=0; i<v->size(); i++){
        cout<<v->at(i)<<"";
    }
}

void findMinimumFlipStringAlteration(vector<int>*v) {
    int flipCounts[2];                      // Holds number of flips count for each iteration
    vector<int>*v0 = new vector<int>();     // Holds flipped vector for 0 iteration
    vector<int>*v1 = new vector<int>();     // Holds flipped vector for 1 iteration
    int binaryArray[2] = {0, 1};
    int numberOfIterations = 2;
    int miniValue;                  // Minimum flip index value 
    
    // Operation
    for (unsigned int i = 0; i < numberOfIterations; i++) {
        int expected = binaryArray[i]; 
        int flipCount = 0;
        
        for (int j = 0; j < v->size(); j++) {
            if (v->at(j) != expected) {         // check if vector has expected value
                flipCount++;
            }
            (i == 0) ? (v0->push_back(expected)) : (v1->push_back(expected)); // Save expected value to appropriate vector
            expected = flip(expected);          // flip expected value
        }
        flipCounts[i] = flipCount;
    }
    
    
    miniValue = (flipCounts[0] < flipCounts[1]) ? 0 : 1;
    
    cout << "The original string is ";
    printVector(v);
    cout << ", the minimum number of flips needed is: \n" << flipCounts[miniValue] << "\n";
    cout << "The flipped string is:\n"; 
    (miniValue == 0) ? printVector(v0) : printVector(v1);
}


int main() {
    vector<int>*v = new vector<int>();  // Vector creation
    string userEntry;                   // User entry string
    cout << "Enter a string:\n";        
    cin >> userEntry;

    // insert user entry into vector
    for(int i=0; i<userEntry.length(); i++) {
        int num = (int)userEntry[i] - '0';
        v->push_back(num);
    }

    findMinimumFlipStringAlteration(v);     // Flipping operation

    cout<<endl;
    return 0;
}
