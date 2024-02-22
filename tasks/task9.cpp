#include <iostream>

typedef void (*sortAlg)(int*,int);

void print(int* arr,int len);
void selection_sort(int* arr, int len);
void bubble_sort(int* arr,int len);


enum SortingStrategy{BUBBLE_SORT,SELECTION_SORT};

struct SortingOption{
    SortingStrategy alg;
    sortAlg op;
};

int main(){
    int arr[] = {1,10,2,100,3,1,6,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    const int size = 2;
    SortingOption algs[size] = {{BUBBLE_SORT,bubble_sort},{SELECTION_SORT,selection_sort}};
    
    int userChoice;
    std::cout<<"Choose the type of algorithm (0 for Bubble Sort and 1 for the Selection Sort): ";
    std::cin>>userChoice;

    switch(userChoice){
        case BUBBLE_SORT:
            std::cout<<"Bubble Sort algorithm"<<std::endl;
            algs[0].op(arr,len);
            break;
        case SELECTION_SORT:
            std::cout<<"Selection Sort algorithm"<<std::endl;
            algs[1].op(arr,len);
            break;
        default:
            std::cout<<"Wrong option"<<std::endl;
            break;
    }
    print(arr,len);
    return 0;
}

void bubble_sort(int* arr,int len){
    for(int i = 0;i<len-1;i++){
        for(int j = 0; j<len-i-1;j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void selection_sort(int* arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void print(int* arr,int len){
    for(int i = 0;i < len;i++){
        std::cout<<*(arr+i)<<" ";
    }
    std::cout<<std::endl;
}
