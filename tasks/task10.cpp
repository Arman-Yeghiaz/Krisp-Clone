#include <iostream>
#include <fstream>

int main(){
    std::ofstream ofile("file.txt");
    ofile<<"Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    ofile.close();

    std::ifstream ifile("file.txt");
    std::string line;
    while(getline(ifile,line)){
        std::cout<<line;
    }
    std::cout<<std::endl;
    ifile.close();
    return 0;
}
