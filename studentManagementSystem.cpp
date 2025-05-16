/* TODO : reusing the  data parsing  and student data displaying  codeblocks repeatedly,
turn it into a helper function*/

// TODO : refactor update_student() function with helper functions. updateAge(),updateCgpa()

#include<iostream>
#include<fstream>
#include<cctype>
#include<algorithm>
#include<iomanip>
#include<limits>
#include<sstream>

#define RESET   "\033[0m"      
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"   
#define YELLOW  "\033[1;33m"   
#define BLUE    "\033[1;34m"

struct student{

    int regNo;
    std::string name;
    int age;
    std::string department;
    double cgpa;
};

bool validString(std::string &name);
bool validChar(char &choice);

void add_student();
void display_student();
void search_student();
void update_student();
void delete_student();

int main(){

    int choice;
    student s;

    std::cout<<GREEN<<"**********************************\n"<<RESET;
    std::cout<<GREEN<<"Hello, Welcome to Student Management System Portal\n"<<RESET;
    std::cout<<GREEN<<"**********************************\n"<<RESET;

    while (true){

        std::cout<<"What do you want to perform: \n";
        std::cout<<"1.Add new Student\n";
        std::cout<<"2.Update Student\n";
        std::cout<<"3.Search Student by Roll No\n";
        std::cout<<"4.Display all Students\n";
        std::cout<<"5.Delete Student\n";

        std::cin>>choice;

        if(std::cin.fail() || choice < 1 || choice > 5){

            std::cin.clear();
            std::cin.ignore(100000,'\n');
            std::cout<<RED<<"Invalid Entry!"<<RESET<<"\n Choose an option from the given menu,\n";
            continue;
        }

        break;
    
    }

    switch(choice){

        case 1:
        add_student();
        break;
        
        case 2:
        update_student();
        break;

        case 3:
        search_student();
        break;

        case 4:
        display_student();
        break;

        case 5:
        delete_student();
        break;
    }
    
    return 0;
}
void add_student(){

    student s;
    char choice;
    
    while(true){
            
        // Entry validation

        while(true){   

            std::cout<<"Enter the student reg No. : ";
            std::cin>>s.regNo;

            if(std::cin.fail() ){

                std::cin.clear();
                std::cin.ignore(100000,'\n');
                std::cout<<RED<<"Invalid Entry! \n"<<RESET;
                continue;
            }
            std::cout<<std::endl;
            break;
        }
        while(true){

            std::cout<<"Enter the name of the student: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin,s.name);
            
            if(validString(s.name)){
                std::cout<<std::endl;
                break;
            }
            else{
                std::cout<<RED<<"Invalid entry!\n"<<RESET;
            }

        }
        while(true){

            std::cout<<"Enter "<<s.name<<"'s  age : ";
            std::cin>>s.age;

            if(std::cin.fail() || s.age < 0 ){

                std::cin.clear();
                std::cin.ignore(100000,'\n');
                std::cout<<RED<<"Invalid Entry! \n"<<RESET;
                continue;
            }
            std::cout<<std::endl;
            break;
        }
        while(true){

            std::cout<<"Which department does "<<s.name<<" belong to : ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin,s.department);
            
            if(validString(s.department)){
                std::cout<<std::endl;
                break;
            }
            else{
                std::cout<<RED<<"Invalid entry!\n"<<RESET;
            }

        }
        while(true){

            std::cout<<"Enter "<<s.name<<"'s current cgpa : ";
            std::cin>>s.cgpa;
        
            if(std::cin.fail() || s.cgpa > 10 || s.cgpa < 0 ){

                std::cin.clear();
                std::cin.ignore(100000,'\n');
                std::cout<<RED<<"Invalid Entry! \n"<<RESET;
                continue;
            }
            std::cout<<std::endl;
            break;
        }
        
        
        std::cout<<"Please verify the entered details \n";

        std::cout<<"reg No:"<<s.regNo<<std::endl;
        std::cout<<"Name: "<<s.name<<std::endl;
        std::cout<<"Age :" <<s.age<<std::endl;
        std::cout<<"department:"<<s.department<<std::endl;
        std::cout<<"cgpa :"<<std::fixed<<std::setprecision(2)<<s.cgpa<<std::endl;

        while(true){

            std::cout<<"Verified?  : [y/n] ?\n";
            std::cin>>choice;

            if(validChar(choice)){

                if(choice == 'y'){
                    std::ofstream dataOut("student.txt",std::ios::app);
                    if(!dataOut){
                        std::cerr<<RED<<"Error opening the file! \n"<<RESET;
                        return;
                    }
                    dataOut<<s.regNo<<","<<s.name<<","<<s.age<<","<<s.department<<","<<s.cgpa<<'\n';
                    std::cout<<GREEN<<"Student data saved!"<<RESET;
                    dataOut.close();
                    return;
                }
                else{
                    std::cout<<"Please  Enter Details Carefully;\n";
                    break;

                } 
            }
            else{
                std::cout<<"Please Enter either 'y' or 'n' , ";
                continue;
            }
    
        }
       
    }

}
bool validString(std::string &name){

    return !name.empty() && 
            std::all_of(name.begin(),name.end(),[](char c){
                return std::isalpha(c) || std::isspace(c);
            });

}
bool validChar(char &choice){

    return choice == 'y' || choice == 'n';
}
void display_student(){

    student s;

    // opening file to read from
    std::ifstream dataIn("student.txt");
    if(!dataIn){
        std::cerr<<RED<<"Error opening the file!"<<RESET;
        return ;
    }
    
    // drawing the table
    std::cout<<std::left<<std::setw(5)<<GREEN<<"Reg No"<<RESET
             <<std::left<<std::setw(11)<<GREEN<<"Name"<<RESET
             <<std::left<<std::setw(30)<<GREEN<<"Age"<<RESET
             <<std::left<<std::setw(9)<<GREEN<<"Department"<<RESET
             <<std::left<<std::setw(41)<<GREEN<<"Cgpa"<<RESET<<std::endl;
    std::cout<<GREEN<<std::string(90,'_')<<RESET<<std::endl;

    // displaying students

    std::string line;
    while(std::getline(dataIn,line)){

        std::stringstream ss(line);
        std::string regNostr, agestr, cgpastr;

        std::getline(ss,regNostr,',');
        std::getline(ss,s.name,',');
        std::getline(ss,agestr,',');
        std::getline(ss,s.department,',');
        std::getline(ss,cgpastr,',');


        s.regNo = std::stoi(regNostr);
        s.age   = std::stoi(agestr);
        s.cgpa  = std::stod(cgpastr);

        std::cout<<std::left<<std::setw(10)<<s.regNo
                            <<std::setw(27)<<s.name
                            <<std::setw(5)<<s.age
                            <<std::setw(45)<<s.department
                            <<std::setw(10)<<s.cgpa<<std::endl;

    }
    dataIn.close();
}
void search_student(){

    student s;
    std::string searchkey;
    bool found = false;

    std::cout<<"Enter the roll number (220565 - ) : ";
    std::cin>>searchkey;

    std::ifstream dataIn("student.txt");
    if(!dataIn){
        std::cerr<<RED<<"Error opening the file!"<<RESET;
        return;
    }

    std::string line;
   
    
    while(std::getline(dataIn,line)){

        std::stringstream ss(line);
        std::string regNostr, agestr, cgpastr;

        std::getline(ss,regNostr,',');
        
        if(regNostr == searchkey){

            found = true;

            std::cout<<GREEN<<"Student details found: \n"<<RESET;
            
            std::getline(ss,s.name,',');
            std::getline(ss,agestr,',');
            std::getline(ss,s.department,',');
            std::getline(ss,cgpastr,',');

            s.regNo = std::stoi(regNostr);
            s.age   = std::stoi(agestr);
            s.cgpa  = std::stod(cgpastr);

            std::cout<<std::left<<YELLOW<<"Reg No     : "<<RESET<<s.regNo<<std::endl
                                <<YELLOW<<"Name       : "<<RESET<<s.name<<std::endl
                                <<YELLOW<<"Age        : "<<RESET<<s.age<<std::endl
                                <<YELLOW<<"Department : "<<RESET<<s.department<<std::endl
                                <<YELLOW<<"Cgpa       : "<<RESET<<s.cgpa<<std::endl;

        }

    }
    if(!found){
        std::cout<<RED<<"No match found for the reg no: "<<searchkey<<RESET;
       
    }
    dataIn.close();
}
void update_student(){

    student s;

    std::string line;
    bool found = false;

    std::string searchkey;
    std::cout<<"Enter the Reg No : ";
    std::cin>>searchkey;

    std::ifstream readFile("student.txt");
    std::ofstream tempFile("temp.txt");

    if(!readFile || !tempFile){
        std::cerr<<RED<<"Error opening the file!"<<RESET;
        return;
    }

    while(std::getline(readFile,line)){

        std::stringstream ss(line);
        std::string regNostr,cgpastr,agestr;

        std::getline(ss,regNostr,',');
        std::getline(ss,s.name,',');
        std::getline(ss,agestr,',');
        std::getline(ss,s.department,',');
        std::getline(ss,cgpastr,',');

    
        s.age   = std::stoi(agestr);
        s.cgpa  = std::stod(cgpastr);

        if(searchkey == regNostr){

            int choice;
            found = true;
            s.regNo = std::stoi(regNostr);

            std::cout<<GREEN<<"Student data - Reg No - "<<s.regNo<<RESET<<std::endl;
            std::cout<<GREEN<<"**************************************************** \n"<<RESET;

            std::cout<<YELLOW<<"Reg No    :"<<RESET<<s.regNo<<std::endl;
            std::cout<<YELLOW<<"Name      : "<<RESET<<s.name<<std::endl;
            std::cout<<YELLOW<<"Age       :" <<RESET<<s.age<<std::endl;
            std::cout<<YELLOW<<"department:"<<RESET<<s.department<<std::endl;
            std::cout<<YELLOW<<"cgpa      :"<<RESET<<std::fixed<<std::setprecision(2)<<s.cgpa<<std::endl;
            std::cout<<GREEN<<"**************************************************** \n"<<RESET;

            std::cout<<"Choose to Update: \n"
                     <<"1. Age \n"
                     <<"2. Cgpa \n";
            std::cin>>choice;

            switch(choice){

                case 1:
                while (true)
                {
                   std::cout<<"Enter updated age: ";
                   std::cin>>s.age; 

                   // validating age

                    if(std::cin.fail() || s.age < 0 ){
                        std::cin.clear();
                        std::cin.ignore(100000,'\n');
                        std::cout<<RED<<"Invalid Entry! \n"<<RESET;
                        continue;
                    }
                   tempFile<<s.regNo<<","<<s.name<<","<<s.age<<","<<s.department<<","<<s.cgpa<<'\n';
                   break;
                }
                break;

                case 2:
                while(true){
                 std::cout<<"Enter updated cgpa : ";
                 std::cin>>s.cgpa;

                 // validating cgpa entry

                    if(std::cin.fail() || s.cgpa > 10 || s.cgpa < 0 ){ 

                        std::cin.clear();
                        std::cin.ignore(100000,'\n');
                        std::cout<<RED<<"Invalid Entry! \n"<<RESET;
                        continue;
                    }
                 tempFile<<s.regNo<<","<<s.name<<","<<s.age<<","<<s.department<<","<<s.cgpa<<'\n';
                 break;
                }
                break;

                default:
                std::cout<<RED<<"Invalid Option, No changes made.\n";
                tempFile<<line<<std::endl;
                break;

                
            }
        }
        else{
         tempFile<<line<<std::endl;
        }
    }
   if(!found){
        std::cout<<RED<<"Match not found !"<<RESET;
        return;
    }
    readFile.close();
    tempFile.close();
    remove("student.txt");
    rename("temp.txt","student.txt");

    std::cout<<GREEN<<"Student data updated! \n"<<RESET;
    return;
    
}
void delete_student(){

    student s;
    bool found = false;
    bool flag;

    std::ifstream readFile("student.txt");
    std::ofstream tempFile("temp.txt");

    if(!readFile || !tempFile){
        std::cerr<<RED<<"Error opening the file!"<<RESET;
        return;
    }


    std::string searchkey;
    std::cout<<"Enter the Reg No of the student (220565 - ) : ";
    std::cin>>searchkey;

    std::string line;
    
    while(std::getline(readFile,line)){

        std::stringstream ss(line);
        std::string regNostr,agestr,cgpastr;


        std::getline(ss,regNostr,',');
        std::getline(ss,s.name,',');
        std::getline(ss,agestr,',');
        std::getline(ss,s.department,',');
        std::getline(ss,cgpastr,',');

        s.age  = std::stoi(agestr);
        s.cgpa = std::stod(cgpastr);

        if(searchkey == regNostr){

            char choice;
            found = true;
            s.regNo = std::stoi(regNostr);
        

            std::cout<<GREEN<<"Student data - Reg No - "<<s.regNo<<RESET<<std::endl;
            std::cout<<GREEN<<"**************************************************** \n"<<RESET;

            std::cout<<YELLOW<<"Reg No    :"<<RESET<<s.regNo<<std::endl;
            std::cout<<YELLOW<<"Name      :"<<RESET<<s.name<<std::endl;
            std::cout<<YELLOW<<"Age       :" <<RESET<<s.age<<std::endl;
            std::cout<<YELLOW<<"department:"<<RESET<<s.department<<std::endl;
            std::cout<<YELLOW<<"cgpa      :"<<RESET<<std::fixed<<std::setprecision(2)<<s.cgpa<<std::endl;
            std::cout<<GREEN<<"**************************************************** \n"<<RESET;

            while(true){
             std::cout<<"Continue to Delete? : [y/n]? \n";
             std::cin>>choice;
             if(validChar(choice)){
             break;
             }
             else{
                std::cout<<RED<<"Please input a valid entry!"<<RESET<<std::endl;
             }
            }
            if(choice == 'y'){
             continue;
            }
            else if(choice == 'n'){
              flag = true;
             tempFile<<s.regNo<<","<<s.name<<","<<s.age<<","<<s.department<<","<<s.cgpa<<'\n';
             continue;
            }
        }
        else{
            tempFile<<line<<'\n';
            continue;
        }
       
    }
    if(!found){
        std::cout<<RED<<"No match found!"<<RESET<<std::endl;
        flag = true;
    }
    readFile.close();
    tempFile.close();
    remove("student.txt");
    rename("temp.txt","student.txt");

    if(flag){
        std::cout<<GREEN<<"No Changes  made."<<RESET<<std::endl;
        return;
    }
    else {
        std::cout<<GREEN<<"Student data deleted successfully."<<RESET<<std::endl;
        return;
    }

}