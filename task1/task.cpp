#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

void writing_in_file(const std::string& file_name, const std::string& str);
void reading_from_file(const std::string& file_name); 
void remove_second_line(const std::string& file_name); 
void reverse_words_in_lines(const std::string& file_name);


int main(){

    writing_in_file("file.txt","Hello there \npordznakan text \nevs mek pordznakan text");
    reading_from_file("file.txt");
    remove_second_line("file.txt");
    reverse_words_in_lines("file.txt");
}

void writing_in_file(const std::string& file_name, const std::string& str){
    std::ofstream file(file_name);
    file<<str<<'\n';
    file.close();

}

void reading_from_file(const std::string& file_name){
    std::ifstream file(file_name);
    std::string text;

    while(getline(file,text)){
        std::cout<<text<<std::endl;
    }
}
void remove_second_line(const std::string& file_name){
    std::vector<std::string> tmp;
    std::ifstream file(file_name);
    std::string line;
    
    while(getline(file,line)){
        tmp.push_back(line);
    }
    file.close();

    std::ofstream Outfile(file_name);
    for(int i = 0; i<tmp.size();i++){
        if (i%2 == 0 ){
            Outfile<<tmp[i]<<std::endl;
        }
    }
    Outfile.close();

}

void reversedLine(std::string& line){
    std::string tmp;
    std::vector<std::string> vec;

    for(int i = 0; i<line.size();i++){
        if(line[i] != ' '){
            tmp+=line[i];
        }
        else{
            vec.push_back(tmp);
            tmp = "";
        }
    }
    line = "";
    std::reverse(vec.begin(),vec.end());
    for(int i = 0; i<vec.size();i++){
        line+=vec[i] + " ";
    }
    vec.pop_back();
}

void reverse_words_in_lines(const std::string& file_name){
    std::ifstream InFile(file_name);
    std::vector<std::string> tmp;
    std::string line;

    while(getline(InFile,line)){
        reversedLine(line);
        tmp.push_back(line);
    }

    InFile.close();

    std::ofstream OutFile(file_name);
    for(int i = 0; i<tmp.size();i++){
        OutFile<<tmp[i]<<std::endl;
    }
    OutFile.close();
}


