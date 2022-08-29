// return a pointer to arr
int* insertion_sort(int arr[], int arr_len, bool reverse = false){
    int temp;
    bool sort_order;
    for (int i = 1; i < arr_len; i++){
        for (int j = i; j > 0; j--){
            sort_order = (reverse == true)? arr[j] > arr[j-1] : arr[j] < arr[j-1];

            if (sort_order){
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;

            } else{
                break;
            }
        }
    }
    return arr;
}
