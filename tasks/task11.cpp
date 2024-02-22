#include <iostream>
#include <vector>
#include <fstream>
#include <string>

typedef void (*sortAlg)(std::vector<int>&,int);

void print(const std::vector<int>& arr,int len);
void selection_sort(std::vector<int>& arr, int len);
void bubble_sort(std::vector<int>& arr,int len);

void readFromFile(const std::string& filename,std::vector<int>& arr){
    std::ifstream ifile(filename);
    int num = 0;
    while(ifile>>num){
        arr.push_back(num);
    }
    ifile.close();
}
void writeToFile(const std::string& filename,std::vector<int>& arr){
    std::ofstream ofile(filename);
    for(int num:arr){
        ofile<<num<<'\n';    
    }
    ofile.close();
}

enum SortingStrategy{BUBBLE_SORT,SELECTION_SORT};

struct SortingOption{
    SortingStrategy alg;
    sortAlg op;
};

int main(){
    std::string filename;
    std::cout<<"Enter the filename of integers"<<std::endl;
    std::cin>>filename;

    std::vector<int> arr;
    readFromFile(filename,arr);
    int len = arr.size();    
    
    const int size = 2; // size for struct
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
    writeToFile(filename,arr);
    print(arr,len);
    return 0;
}

void bubble_sort(std::vector<int>& arr,int len){
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

void selection_sort(std::vector<int>& arr, int len) {
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

void print(const std::vector<int>& arr,int len){
    for(int i = 0;i < len;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
