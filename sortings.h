//
// Created by Rylie  Seaberg  on 11/26/24.
//

#ifndef COMP218_SEABERG_RYLIE_P4_SORTINGS_H
#define COMP218_SEABERG_RYLIE_P4_SORTINGS_H

#include <vector>
using namespace std;

class Sortings {
public:

    /** sorting a list through iteratively placing each element from an unsorted list into
     * its appropriate position within the sorted portion of the list.
     * @params vec- a reference to a vector of integers to be sorted
     * @returns void function, N/A
     **/
    void insertionSort(vector<int> &arr);

    /** sorting a list through by swapping elements next to each other if they are in the
     * wrong order
     * @params vec- a reference to a vector of integers to be sorted
     * @returns void function, N/A
     **/
    void bubbleSort(vector<int>& arr);

    /** dividing the input array into two partitions around a pivot element,
     * recursively sorting each partition/section until the entire array is sorted
     * @params vec- a reference to a vector of integers to be sorted
     * low- starting index within the range of elements to be printed
     * high- ending index of the range within the vector up to which elements will be printed
     * @returns void function, N/A
     **/
    void quickSort(vector<int> &vec, int low, int high);

    /** dividing the input array into two partitions around a pivot element,
     * recursively sorting each partition/section until the entire array is sorted
     * the pivot element is specifically the median of the middle, first and last elements
     * @params vec- a reference to a vector of integers to be sorted
     * low- starting index within the range of elements to be printed
     * high- ending index of the range within the vector up to which elements will be printed
     * @returns void function, N/A
     **/
    void quickSortMed(vector<int>& v, int low, int high);

    /** Arranges the elements of an array by tallying the occurrences of each unique element
     * @params &arr- a reference to a vector of integers to be sorted
     * @returns void function, N/A
     **/
    void countSort(vector<int>& arr);

    /** sorts an array through creating binary trees called heaps by continously making the max
     * element the root and putting it at the end of the heap
     * @params &arr- a reference to a vector of integers
     * @returns void function, N/A
     **/
    void heapSort(vector<int>& arr);

private:
    /** this function separates a vector into two segments based on a pivot value, less than the pivot
     * are moved to its left, and all elements greater than or equal to the pivot are moved to its right
     * @params v- a reference to a vector of integers
     * low- starting index within the range of elements to be printed
     * high- ending index of the range within the vector up to which elements will be printed
     * @returns index of the pivot element after it has been placed in its correct sorted position
     **/
    int partition(vector<int> &vec, int low, int high);

    /**
     * selects a pivot element for QuickSort using the median-of-three technique
     * @params v- a reference to a vector of integers
     * low- starting index within the range of elements to be printed
     * high- ending index of the range within the vector up to which elements will be printed
     * @returns index of the pivot element after it has been placed in its correct sorted position
     **/
    int medianOfThree(vector<int>& v, int low, int high);

    /** this function separates a vector into two segments based on a pivot value,
     * less than the pivot are moved to its left, and all elements greater than or equal
     * to the pivot are moved to its right, the pivot in this case in the median of the first,
     * middle, and last elements
     * @params v- a reference to a vector of integers
     * low- starting index within the range of elements to be printed
     * high- ending index of the range within the vector up to which elements will be printed
     * @returns index of the pivot element after it has been placed in its correct sorted position
     **/
    int partitionMed(vector<int>& v, int low, int high);

    /** ensures that a subtree rooted at index i in the array satisfies the heap property to be used
     * in heapSort() function (this is a helper function for the heapSort() function)
     * @params &arr- a reference to a vector of integers
     * size- number of elements in the array arr[]
     * i- index of the root of the subtree to be used next in the heap
     * @returns index of the pivot element after it has been placed in its correct sorted position
     **/
    void heapify(vector<int>& arr, int size, int i);
};


#endif //COMP218_SEABERG_RYLIE_P4_SORTINGS_H
