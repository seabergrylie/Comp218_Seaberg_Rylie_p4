//
// Created by Rylie  Seaberg  on 11/26/24.
//

#include "sortings.h"
#include <vector>
#include <algorithm>
using namespace std;

void Sortings::insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Sortings::bubbleSort(vector<int>& arr) {
    size_t n = arr.size();
    bool swapped;

    for (size_t i = 0; i < n - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int Sortings::partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void Sortings::quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int Sortings :: medianOfThree(vector<int>& v, int low, int high) {
    int mid = low + (high - low) / 2;

    if (v[low] > v[mid]) swap(v[low], v[mid]);
    if (v[low] > v[high]) swap(v[low], v[high]);
    if (v[mid] > v[high]) swap(v[mid], v[high]);

    return v[mid];
}


int Sortings :: partitionMed(vector<int>& v, int low, int high) {
    int pivotValue = medianOfThree(v, low, high); // Choose pivot
    int pivotIndex = low; // Find actual index of the pivot value


    for (int i = low; i <= high; ++i) {
        if (v[i] == pivotValue) {
            pivotIndex = i;
            break;
        }
    }
    swap(v[pivotIndex], v[high]);

    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (v[j] <= pivotValue) {
            ++i;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return i + 1;
}

void Sortings::quickSortMed(vector<int>& v, int low, int high) {
    if (low < high) {
        int pivotIndex = partitionMed(v, low, high);
        quickSortMed(v, low, pivotIndex - 1);
        quickSortMed(v, pivotIndex + 1, high);
    }
}

void Sortings::countSort(vector<int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range, 0), output(arr.size());

    for (int num : arr) {
        count[num - min]++;
    }

    for (size_t i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

void Sortings::heapify(vector<int>& arr, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}

void Sortings::heapSort(vector<int>& arr) {
    int size = arr.size();

    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(arr, size, i);

    for (int i = size - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}



