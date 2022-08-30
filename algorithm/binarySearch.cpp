#include <iostream>
#include <cmath>
int binarySearch(int arr[], int target, int size)
{
    int l = 0;
    int r = size - 1;
    while (l <= r)
    {
        int mid = round((l+r)/2);
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return -1;
}
