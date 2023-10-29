
#include <iostream>
#include <vector>

using namespace std;

void printVectorRangeBased(const vector<int>& vec) {
    for (const int& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

void printVectorIterator(const vector<int>& vec) {
    for (vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

void printVectorIndex(const vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5 };

    printVectorRangeBased(numbers);
    printVectorIterator(numbers);
    printVectorIndex(numbers);

    return 0;
}