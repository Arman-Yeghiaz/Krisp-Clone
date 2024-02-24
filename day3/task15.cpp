#include <iostream>
#include <vector>
#include <string>
#include <fstream>

enum Choice {BUBBLE,SELECTION};

class SortingStrategy{
    public:
        virtual void sort(std::vector<int>& arr) const  = 0;
        virtual ~SortingStrategy(){}
};

class BubbleSort:public SortingStrategy{
    public:
        void sort(std::vector<int>& arr) const override;
        virtual ~BubbleSort(){}
};

class SelectionSort:public SortingStrategy{
    public:
        void sort(std::vector<int>& arr) const override;
        virtual ~SelectionSort(){}
};
class FileHandler {
    public:
        //FileHandler(std::string IFile,std::string OFile):InpFile(IFile),OutFile(OFile){}
        
        void readArrayFromFile(std::vector<int>& arr){
            std::ifstream iFile(InpFile);
            if (!iFile.is_open()) {
                std::cerr << "Error opening input file." << std::endl;
                return;
            }
            int num = 0;
            while(iFile>>num){
                arr.push_back(num);
            }
            iFile.close();
        }
        void saveArrayToFile(std::vector<int>& arr){
            std::ofstream Ofile(OutFile);
            if (!Ofile.is_open()) {
                std::cerr << "Error opening output file." << std::endl;
                return;
            }
            for(int num:arr){
                Ofile<<num<<'\n';
            }
            Ofile.close();
        }

        void setInpFile(std::string& Iname){
            InpFile = Iname;
        }
        void setOutFile(std::string& Oname){
            OutFile = Oname;
        }
    private:
        std::string InpFile;
        std::string OutFile;
};

class SortingApplication{
    private:
        SortingStrategy* ptr;
        FileHandler ob;
        std::vector<int> arr;
    public:
        void userInput(){
            std::string InputFile;
            std::string OutputFile;
            std::cout<<"Enter the filename to read: ";
            std::cin>>InputFile;
            std::cout<<"Enter the filename to write: ";
            std::cin>>OutputFile;

            ob.setInpFile(InputFile);
            ob.setOutFile(OutputFile);

            int userChoice;
            std::cout<<"Enter the sorting algorithm you want (0->BUBBLE,1->SELECTION) : ";
            std::cin>>userChoice;

            if(userChoice == BUBBLE){
                ptr = new BubbleSort;
            }else if(userChoice == SELECTION){
                ptr = new SelectionSort;
            }else{
                std::cout<<"Wrong choice!!!"<<std::endl;
                ptr = nullptr;
            }


        }
        void executeSort(){
            ob.readArrayFromFile(arr);
            ptr->sort(arr);
            ob.saveArrayToFile(arr);
        }
        ~SortingApplication(){
            delete ptr;
        }
};

int main(){
    SortingApplication obj;
    obj.userInput();
    obj.executeSort();
    return 0;
}
void BubbleSort::sort(std::vector<int>& arr) const {
    int len = arr.size();
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

void SelectionSort::sort(std::vector<int>& arr) const {
    int len = arr.size();
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
