#include <iostream>
#include "student.h"
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;
        string name;
        int Age;
        string nameToFind;
        auto it = studentList.end();

        switch(selection)
        {
        case 0:

            cout<<"Anna uuden opiskelijan nimi: ";
            cin>>name;
            cout<<"Anna uuden opiskelijan ika: ";
            cin>>Age;
            studentList.push_back(Student(name, Age));
            cout<<"Opiskelija lisatty!"<<endl;
            break;



            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.


        case 1:
            cout<<"Opiskelijalista: "<<endl;
            for(const auto& student:studentList){
                student.printStudentInfo();
            }
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            break;


        case 2:
            sort(studentList.begin(), studentList.end(),[](const Student& a, const Student& b){
            return a.getName()<b.getName();
            });
            cout<<"Opiskelijat jarjestetty nimen mukaan: "<<endl;
            for (const auto& student:studentList){
                student.printStudentInfo();
            }

            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            break;


        case 3:
            sort(studentList.begin(), studentList.end(),[](const Student& a, const Student& b){
                return a.getAge()<b.getAge();
            });
             cout<<"Opiskelijat jarjestetty ian mukaan: "<<endl;
            for (const auto& student:studentList){
                student.printStudentInfo();
            }


            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            break;
        case 4:
            cout<<"Anna etsittavan opiskelijan nimi: ";
            cin>>nameToFind;
            it = find_if(studentList.begin(), studentList.end(),[&nameToFind](const Student& s){
              return s.getName()==nameToFind;
            });
            if (it != studentList.end()){
                it->printStudentInfo();
            }else{
                cout<<"Opiskelijaa ei löytynyt"<<endl;
            }

            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            break;

        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;

        }
    }
    while(selection < 5);

return 0;
}
