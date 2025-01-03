/*
 * Assignment: Sorting Algorithms (COMP 218- Data Structures) (Assignment Number): 4
 * Author(s):Rylie Seaberg
 * Due Date: Wednesday, 12/4/2024 11:59:00 PM
 * Description: In this project, we are working with sorting algorithms in order to sort a
 * vector or array of integers. The second part of the project is an assesment of performance on
 * the sorting algorithms to test their execution times based on files of varying numbers integers
 * (100, 1000, 10000).
 * Comments:
 * Honor Pledge: I have abided by the Wheaton Honor Code and
all work below was performed by Rylie Seaberg .*/

#include <iostream>
#include "sortings.h"
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <stdexcept>
using namespace std;


/** printing all the elements from the sorted vector
 * * @params &v- a reference to a vector of integers to be printed
 * * @returns void function, N/A
**/
void print(const vector<int>& v) {
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}


//TESTING FOR THE SORTING ALGORITHMS


/**
 * Test Plan:
 *
 * 1) check if insertion sort works with a small number of integers in the vector
 * 2) check if insertion sort works with a large number of integers in the vector
 * 3) check how insertion sort deals with duplicates
 * 4) check how insertion sort deals with negative integers
 * 5) check how insertion sort deals with an already sorted vector
 *
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency: insertionSort()
 * */
void test_insertion(Sortings& sorter) {
    // Test 1: Small number of integers
    vector<int> v1 = {7, 2, 5, 3};
    cout << "Original array: ";
    print(v1);

    sorter.insertionSort(v1);
    cout << "Sorted array: ";
    print(v1);
    cout << "Expected: 2 3 5 7" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v1.begin(), v1.end());
    for (int & it : v1){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 2: Large number of integers
    vector<int> v2 = {15, 3, 12, 6, 9, 17, 5, 20, 8, 2, 10, 1};
    cout << "Original array: ";
    print(v2);

    sorter.insertionSort(v2);
    cout << "Sorted array: ";
    print(v2);
    cout << "Expected: 1 2 3 5 6 8 9 10 12 15 17 20" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v2.begin(), v2.end());
    for (int & it : v2){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 3: Handling duplicates
    vector<int> v3 = {4, 2, 7, 7, 3, 4, 1};
    cout << "Original array: ";
    print(v3);

    sorter.insertionSort(v3);
    cout << "Sorted array: ";
    print(v3);
    cout << "Expected: 1 2 3 4 4 7 7" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v3.begin(), v3.end());
    for (int & it : v3){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 4: Handling negative integers
    vector<int> v4 = {-5, -2, -8, 3, 0, -1};
    cout << "Original array: ";
    print(v4);

    sorter.insertionSort(v4);
    cout << "Sorted array: ";
    print(v4);
    cout << "Expected: -8 -5 -2 -1 0 3" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v4.begin(), v4.end());
    for (int & it : v4){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 5: Already sorted vector
    vector<int> v5 = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    print(v5);

    sorter.insertionSort(v5);
    cout << "Sorted array: ";
    print(v5);
    cout << "Expected: 1 2 3 4 5" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v5.begin(), v5.end());
    for (int & it : v5){
        cout << ' ' << it;
    }

    cout << '\n' << endl;
}

/**
 * Test Plan:
 *
 * 1) check if bubble sort works with a small number of integers in the vector
 * 2) check if bubble sort works with a large number of integers in the vector
 * 3) check how bubble sort deals with duplicates
 * 4) check how bubble sort deals with negative integers
 * 5) check how bubble sort deals with an already sorted vector
 *
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency: bubbleSort()
 * */
void test_bubble(Sortings& sorter){
    vector<int> v1 = {7, 2, 5, 3};
    cout << "Original array: ";
    print(v1);

    sorter.bubbleSort(v1);
    cout << "Sorted array: ";
    print(v1);
    cout << "Expected: 2 3 5 7" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v1.begin(), v1.end());
    for (int & it : v1){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 2: Large number of integers
    vector<int> v2 = {15, 3, 12, 6, 9, 17, 5, 20, 8, 2, 10, 1};
    cout << "Original array: ";
    print(v2);

    sorter.bubbleSort(v2);
    cout << "Sorted array: ";
    print(v2);
    cout << "Expected: 1 2 3 5 6 8 9 10 12 15 17 20" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v2.begin(), v2.end());
    for (int & it : v2){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 3: Handling duplicates
    vector<int> v3 = {4, 2, 7, 7, 3, 4, 1};
    cout << "Original array: ";
    print(v3);

    sorter.bubbleSort(v3);
    cout << "Sorted array: ";
    print(v3);
    cout << "Expected: 1 2 3 4 4 7 7" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v3.begin(), v3.end());
    for (int & it : v3){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 4: Handling negative integers
    vector<int> v4 = {-5, -2, -8, 3, 0, -1};
    cout << "Original array: ";
    print(v4);

    sorter.bubbleSort(v4);
    cout << "Sorted array: ";
    print(v4);
    cout << "Expected: -8 -5 -2 -1 0 3" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v4.begin(), v4.end());
    for (int & it : v4){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 5: Already sorted vector
    vector<int> v5 = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    print(v5);

    sorter.bubbleSort(v5);
    cout << "Sorted array: ";
    print(v5);
    cout << "Expected: 1 2 3 4 5" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v5.begin(), v5.end());
    for (int & it : v5){
        cout << ' ' << it;
    }

    cout << '\n' << endl;
}

/**
 * Test Plan:
 *
 * 1) check if quick sort works with a small number of integers in the vector
 * 2) check if quick sort works with a large number of integers in the vector
 * 3) check how quick sort deals with duplicates
 * 4) check how quick sort deals with negative integers
 * 5) check how quick sort deals with an already sorted vector
 *
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency: quickSort()
 * */
void test_quicksort(Sortings& sorter) {
    // Test 1: Small number of integers
    vector<int> v1 = {1, 7, 6, 12};
    cout << "Original array: ";
    print(v1);

    sorter.quickSort(v1, 0, v1.size() - 1);
    cout << "Final sorted array: ";
    print(v1);
    cout << "Expected: 1 6 7 12" <<endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v1.begin(), v1.end());
    for (int & it : v1){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 2: Large number of integers
    vector<int> v2 = {1, 8, 19, 12, 67, 89, 96, 120, 13, 77, 2, 9};
    cout << "Original array: ";
    print(v2);

    sorter.quickSort(v2, 0, v2.size() - 1);
    cout << "Final sorted array: ";
    print(v2);
    cout << "Expected: 1 2 8 9 12 13 19 67 77 89 96 120" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v2.begin(), v2.end());
    for (int & it : v2){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 3: Handling duplicates
    vector<int> v3 = {1, 7, 12, 19, 7, 65, 16};
    cout << "Original array: ";
    print(v3);

    sorter.quickSort(v3, 0, v3.size() - 1);
    cout << "Final sorted array: ";
    print(v3);
    cout << "Expected: 1 7 7 12 16 19 65" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v3.begin(), v3.end());
    for (int & it : v3){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 4: Negative integers
    vector<int> v4 = {-3, -1, -7, 4, 0, -2};
    cout << "Original array: ";
    print(v4);

    sorter.quickSort(v4, 0, v4.size() - 1);
    cout << "Final sorted array: ";
    print(v4);
    cout << "Expected: -7 -3 -2 -1 0 4" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v4.begin(), v4.end());
    for (int & it : v4){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 5: Already sorted vector
    vector<int> v5 = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    print(v5);

    sorter.quickSort(v5, 0, v5.size() - 1);
    cout << "Final sorted array: ";
    print(v5);
    cout << "Expected: 1 2 3 4 5" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v5.begin(), v5.end());
    for (int & it : v5){
        cout << ' ' << it;
    }

    cout << '\n' << endl;
}

/**
 * Test Plan:
 *
 * 1) check if quick sort (with median of 3) works with a small number of integers in the vector
 * 2) check if quick sort (with median of 3) works with a large number of integers in the vector
 * 3) check how quick sort (with median of 3) deals with duplicates
 * 4) check how quick sort (with median of 3) deals with negative integers
 * 5) check how quick sort (with median of 3) deals with an already sorted vector
 *
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency: quickSortMed()
 * */
void test_quicksortMed(Sortings& sorter) {
    // Test 1: Small number of integers
    vector<int> v1 = {1, 7, 6, 12};
    cout << "Original array: ";
    print(v1);

    sorter.quickSortMed(v1, 0, v1.size() - 1);
    cout << "Final sorted array: ";
    print(v1);
    cout << "Expected: 1 6 7 12" <<endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v1.begin(), v1.end());
    for (int & it : v1){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 2: Large number of integers
    vector<int> v2 = {1, 8, 19, 12, 67, 89, 96, 120, 13, 77, 2, 9};
    cout << "Original array: ";
    print(v2);

    sorter.quickSortMed(v2, 0, v2.size() - 1);
    cout << "Final sorted array: ";
    print(v2);
    cout << "Expected: 1 2 8 9 12 13 19 67 77 89 96 120" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v2.begin(), v2.end());
    for (int & it : v2){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 3: Handling duplicates
    vector<int> v3 = {1, 7, 12, 19, 7, 65, 16};
    cout << "Original array: ";
    print(v3);

    sorter.quickSortMed(v3, 0, v3.size() - 1);
    cout << "Final sorted array: ";
    print(v3);
    cout << "Expected: 1 7 7 12 16 19 65" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v3.begin(), v3.end());
    for (int & it : v3){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 4: Negative integers
    vector<int> v4 = {-3, -1, -7, 4, 0, -2};
    cout << "Original array: ";
    print(v4);

    sorter.quickSortMed(v4, 0, v4.size() - 1);
    cout << "Final sorted array: ";
    print(v4);
    cout << "Expected: -7 -3 -2 -1 0 4" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v4.begin(), v4.end());
    for (int & it : v4){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 5: Already sorted vector
    vector<int> v5 = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    print(v5);

    sorter.quickSortMed(v5, 0, v5.size() - 1);
    cout << "Final sorted array: ";
    print(v5);
    cout << "Expected: 1 2 3 4 5" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v5.begin(), v5.end());
    for (int & it : v5){
        cout << ' ' << it;
    }

    cout << '\n' << endl;
}

/**
 * Test Plan:
 *
 * 1) check if count sort works with a small number of integers in the vector
 * 2) check if count sort works with a large number of integers in the vector
 * 3) check how count sort deals with duplicates
 * 4) check how count sort deals with negative integers
 * 5) check how count sort deals with an already sorted vector
 *
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency: countSort()
 * */
void test_count(Sortings& sorter){
    // Test 1: Small number of integers
    vector<int> v1 = {7, 2, 5, 3};
    cout << "Original array: ";
    print(v1);

    sorter.countSort(v1);
    cout << "Sorted array: ";
    print(v1);
    cout << "Expected: 2 3 5 7" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v1.begin(), v1.end());
    for (int & it : v1){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 2: Large number of integers
    vector<int> v2 = {15, 3, 12, 6, 9, 17, 5, 20, 8, 2, 10, 1};
    cout << "Original array: ";
    print(v2);

    sorter.countSort(v2);
    cout << "Sorted array: ";
    print(v2);
    cout << "Expected: 1 2 3 5 6 8 9 10 12 15 17 20" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v2.begin(), v2.end());
    for (int & it : v2){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 3: Handling duplicates
    vector<int> v3 = {4, 2, 7, 7, 3, 4, 1};
    cout << "Original array: ";
    print(v3);

    sorter.countSort(v3);
    cout << "Sorted array: ";
    print(v3);
    cout<< "Expected: 1 2 3 4 4 7 7" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v3.begin(), v3.end());
    for (int & it : v3){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 4: Negative integers
    vector<int> v4 = {-5, -2, -8, 3, 0, -1};
    cout << "Original array: ";
    print(v4);

    sorter.countSort(v4);
    cout << "Sorted array: ";
    print(v4);
    cout << "Expected: -8 -5 -2 -1 0 3" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v4.begin(), v4.end());
    for (int & it : v4){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 5: Already sorted vector
    vector<int> v5 = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    print(v5);

    sorter.countSort(v5);
    cout << "Sorted array: ";
    print(v5);
    cout << "Expected: 1 2 3 4 5" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v5.begin(), v5.end());
    for (int & it : v5){
        cout << ' ' << it;
    }

    cout << '\n' << endl;
}

/**
 * Test Plan:
 *
 * 1) check if heap sort works with a small number of integers in the vector
 * 2) check if heap sort works with a large number of integers in the vector
 * 3) check how heap sort deals with duplicates
 * 4) check how heap sort deals with negative integers
 * 5) check how heap sort deals with an already sorted vector
 *
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency: heapSort()
 *
 * */
void test_heap(Sortings& sorter){
    // Test 1: Small number of integers
    vector<int> v1 = {7, 2, 5, 3};
    cout << "Original array: ";
    print(v1);

    sorter.heapSort(v1);
    cout << "Sorted array: ";
    print(v1);
    cout << "Expected: 2 3 5 7" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v1.begin(), v1.end());
    for (int & it : v1){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 2: Large number of integers
    vector<int> v2 = {15, 3, 12, 6, 9, 17, 5, 20, 8, 2, 10, 1};
    cout << "Original array: ";
    print(v2);

    sorter.heapSort(v2);
    cout << "Sorted array: ";
    print(v2);
    cout << "Expected: 1 2 3 5 6 8 9 10 12 15 17 20" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v2.begin(), v2.end());
    for (int & it : v2){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 3: Handling duplicates
    vector<int> v3 = {4, 2, 7, 7, 3, 4, 1};
    cout << "Original array: ";
    print(v3);

    sorter.heapSort(v3);
    cout << "Sorted array: ";
    print(v3);
    cout << "Expected: 1 2 3 4 4 7 7" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v3.begin(), v3.end());
    for (int & it : v3){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 4: Negative integers
    vector<int> v4 = {-5, -2, -8, 3, 0, -1};
    cout << "Original array: ";
    print(v4);

    sorter.heapSort(v4);
    cout << "Sorted array: ";
    print(v4);
    cout << "Expected: -8 -5 -2 -1 0 3" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v4.begin(), v4.end());
    for (int & it : v4){
        cout << ' ' << it;
    }

    cout << '\n' << endl;

    // Test 5: Already sorted vector
    vector<int> v5 = {1, 2, 3, 4, 5};
    cout << "Original array: ";
    print(v5);

    sorter.heapSort(v5);
    cout << "Sorted array: ";
    print(v5);
    cout << "Expected: 1 2 3 4 5" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v5.begin(), v5.end());
    for (int & it : v5){
        cout << ' ' << it;
    }

    cout << '\n' << endl;
}


//TESTING EFFICIENCY OF SORTING ALGORITHMS

/**
 * Reads data from a file and returns a vector of integers.
 * @param filename - Name of the file to read from.
 * @return A vector containing the integers read from the file.
 */
vector<int> readfile(const string &filename) {
    ifstream infile(filename);
    vector<int> data;

    if (!infile.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
            return {};
        }

    string number;
    while (getline(infile, number)) {
        data.push_back(stoi(number));
    }

    infile.close();
    return data;
}

/**
 * Writes data to an output file.
 * @param filename - Name of the file to write to.
 * @param data - Vector of integers to write to the file.
 */
void writefile(string filename, const vector<int>& data) {
    ofstream outfile(filename);

    if (!outfile) {
        cerr << "Error: Could not open file " << filename << " for writing." << endl;
        return;
    }

    for (size_t i = 0; i < data.size(); ++i) {
        outfile << data[i];
        if (i != data.size() - 1) {
            outfile << " ";
        }
    }

    outfile.close();
}

/** test insertion sort on various files and receive how long the computation time was
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency- insertionSort()
 * */
void test_file_insertion(Sortings& sorter, string filename) {
    vector<int> v = readfile(filename);

    if (v.empty()) {
        cerr << "Error: No data read from the file or file is empty." << endl;
        return;
    }

    cout << "Original Array: " << endl;
    print(v);

    vector<int> v_insertion = v;

    auto startInsertion = chrono::high_resolution_clock::now();

    sorter.insertionSort(v_insertion);

    auto endInsertion = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    print(v_insertion);

    chrono::duration<double, micro> time_insertion = endInsertion - startInsertion;

    cout << "Insertion computation time: " << time_insertion.count() << " microseconds" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v.begin(), v.end());
    for (int & it : v){
        cout << ' ' << it;
    }
}

/** test bubble sort on various files and receive how long the computation time was
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency- bubbleSort()
 * */
void test_file_bubble(Sortings& sorter, string filename) {
    vector<int> v = readfile(filename);

    if (v.empty()) {
        cerr << "Error: No data read from the file or file is empty." << endl;
        return;
    }

    cout << "Original Array: " << endl;
    print(v);

    vector<int> v_insertion = v;

    auto startBubble = chrono::high_resolution_clock::now();

    sorter.bubbleSort(v_insertion);

    auto endBubble = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    print(v_insertion);

    chrono::duration<double, micro> time_bubble = endBubble - startBubble;

    cout << "Bubble computation time: " << time_bubble.count() << " microseconds" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v.begin(), v.end());
    for (int & it : v){
        cout << ' ' << it;
    }

}

/** test quick sort on various files and receive how long the computation time was
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency- quickSort()
 * */
void test_file_quick(Sortings& sorter, string filename) {
    vector<int> v = readfile(filename);

    if (v.empty()) {
        cerr << "Error: No data read from the file or file is empty." << endl;
        return;
    }

    cout << "Original Array: " << endl;
    print(v);

    vector<int> v_quick = v;

    auto startQuick = chrono::high_resolution_clock::now();

    sorter.quickSort(v_quick,0, v.size() - 1);

    auto endQuick = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    print(v_quick);

    chrono::duration<double, micro> time_quick = endQuick - startQuick;

    cout << "Quick computation time: " << time_quick.count() << " microseconds" << endl;
}

/** test quick sort with median of 3 on various files and receive how long the computation time was
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency- quickSortMed()
 * */
void test_file_quickMed(Sortings& sorter, string filename) {
    vector<int> v = readfile(filename);

    if (v.empty()) {
        cerr << "Error: No data read from the file or file is empty." << endl;
        return;
    }

    cout << "Original Array: " << endl;
    print(v);

    vector<int> v_quickMed = v;

    auto startQuickMed = chrono::high_resolution_clock::now();

    sorter.quickSortMed(v_quickMed,0, v.size() - 1);

    auto endQuick = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    print(v_quickMed);

    chrono::duration<double, micro>  time_quickMed = endQuick - startQuickMed;

    cout << "Quick Medium of 3 computation time: " << time_quickMed.count() << " microseconds" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v.begin(), v.end());
    for (int & it : v){
        cout << ' ' << it;
    }
}

/** test count sort on various files and receive how long the computation time was
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency- countSort()
 * */
void test_file_count(Sortings& sorter, string filename) {
    vector<int> v = readfile(filename);

    if (v.empty()) {
        cerr << "Error: No data read from the file or file is empty." << endl;
        return;
    }

    cout << "Original Array: " << endl;
    print(v);

    vector<int> v_count = v;

    auto startCount = chrono::high_resolution_clock::now();

    sorter.insertionSort(v_count);

    auto endCount = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    print(v_count);

    chrono::duration<double, micro> time_count = endCount - startCount;

    cout << "Count computation time: " << time_count.count() << " microseconds" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v.begin(), v.end());
    for (int & it : v){
        cout << ' ' << it;
    }
}

/** test heap sort on various files and receive how long the computation time was
 * @params: sorter- object to access the Sortings class
 * @returns: N/A, void function
 * dependency- heapSort()
 * */
void test_file_heap(Sortings& sorter, string filename) {
    vector<int> v = readfile(filename);

    if (v.empty()) {
        cerr << "Error: No data read from the file or file is empty." << endl;
        return;
    }

    cout << "Original Array: " << endl;
    print(v);

    vector<int> v_heap = v;

    auto startHeap = chrono::high_resolution_clock::now();

    sorter.insertionSort(v_heap);

    auto endHeap = chrono::high_resolution_clock::now();

    cout << "Sorted array: ";
    print(v_heap);

    chrono::duration<double, micro> time_heap = endHeap - startHeap;

    cout << "Heap computation time: " << time_heap.count() << " microseconds" << endl;

    cout << "Sorting using output of std::sort " << endl; //is the same
    sort (v.begin(), v.end());
    for (int & it : v){
        cout << ' ' << it;
    }

}




int main() {
    Sortings sorter; //object of Sortings

    test_insertion(sorter);
    test_bubble(sorter);
    test_quicksort(sorter);
    test_quicksortMed(sorter);
    test_count(sorter);
    test_heap(sorter);

    test_file_insertion(sorter, "data-100.in");
    test_file_bubble(sorter, "data-100.in");
    test_file_quick(sorter, "data-100.in");
    test_file_quickMed(sorter, "data-100.in");
    test_file_count(sorter, "data-100.in");
    test_file_heap(sorter, "data-100.in");

    return 0;
}
