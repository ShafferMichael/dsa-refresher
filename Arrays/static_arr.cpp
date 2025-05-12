#include <iostream>

using std::cout;
using std::endl;

// Insert n into arr at the next open position.
// Length is the number of 'real' values in arr, and capacity
// is the size (aka memory allocated for the fixed size array).
void insertEnd(int arr[], int n, int length, int capacity)
{
    if (length < capacity)
    {
        arr[length] = n;
    }
}

// Remove from the last position in the array if the array
// is not empty (i.e. length is non-zero).
void removeEnd(int arr[], int length)
{
    if (length > 0)
    {
        // Overwrite last element with some default value.
        // We would also consider the length to be decreased by 1.
        arr[length - 1] = 0;
    }
}

// Insert n into index i after shifting elements to the right.
// Assuming i is a valid index and arr is not full.
void insertMiddle(int arr[], int i, int n, int length)
{
    // Shift starting from the end to i.
    for (int index = length - 1; index >= i; index--)
    {
        arr[index + 1] = arr[index];
    }
    // Insert at i
    arr[i] = n;
}

// Remove value at index i before shifting elements to the left.
// Assuming i is a valid index.
void removeMiddle(int arr[], int i, int length)
{
    // Shift starting from i + 1 to end.
    for (int index = i + 1; index < length; index++)
    {
        arr[index - 1] = arr[index];
    }
    // No need to 'remove' arr[i], since we already shifted
}

void printArr(int arr[], int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    const int capacity = 10;
    int myArray[capacity] = {1, 3, 5}; // initialize with some values
    int length = 3;                    // number of meaningful elements

    cout << "Initial array: ";
    printArr(myArray, capacity);

    insertEnd(myArray, 7, length, capacity);
    length++;
    cout << "After insertEnd(7): ";
    printArr(myArray, capacity);

    insertMiddle(myArray, 1, 9, length);
    length++;
    cout << "After insertMiddle(1, 9): ";
    printArr(myArray, capacity);

    removeEnd(myArray, length);
    length--;
    cout << "After removeEnd(): ";
    printArr(myArray, capacity);

    removeMiddle(myArray, 2, length);
    length--;
    cout << "After removeMiddle(2): ";
    printArr(myArray, capacity);

    // Accessing an element:
    int i = 1;
    cout << "Element at index " << i << ": " << myArray[i] << endl;

    return 0;
}