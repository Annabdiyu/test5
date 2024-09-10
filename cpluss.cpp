#include<iostream>
#include<fstream>
using namespace std;

struct studentinfo {
    int id;
    string name;
    float mark;
    char grade;
};

void getdata(studentinfo s1[], int &n){
    for(int i=0; i<n; ++i){
        cout<<i+1<<", Enter your name: \n";
        cin>>s1[i].name;
        cout<<"Enter your ID: \n";
        cin>>s1[i].id;
        cout<<"Enter your mark: \n";
        cin>>s1[i].mark;
        if(s1[i].mark>=80 && s1[i].mark<100){
            s1[i].grade='A';
        }
        else if(s1[i].mark>=70 && s1[i].mark<80){
            s1[i].grade='B';
        }
        else if(s1[i].mark>=50 && s1[i].mark<70){
            s1[i].grade='C';
        }
        else if(s1[i].mark>=40 && s1[i].mark<50){
            s1[i].grade='D';
        }
        else if(s1[i].mark<40){
            s1[i].grade='F';
        }
    }
}

void writeToStudentFile(studentinfo s1[], int& n) {
    ofstream outFile("student.txt");
    if(outFile.is_open()) {
        outFile << "ID\tName\tMark\tGrade\n";
        for(int i = 0; i < n; ++i) {
            outFile << s1[i].id << "\t" << s1[i].name << "\t" << s1[i].mark << "\t" << s1[i].grade << endl;
        }
        outFile.close();
        cout << "Student data has been written to student.txt\n";
    } else {
        cout << "Unable to open student.txt for writing\n";
    }
}

void displayFromFile() {
    ifstream inFile("student.txt");
    if(inFile.is_open()) {
        string line;
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open student.txt for reading\n";
    }
}

void updateMarksAndGrades(studentinfo s1[], int& n) {
    int idToUpdate;
    cout << "Enter the ID of the student to update marks and grades: ";
    cin >> idToUpdate;
    for(int i = 0; i < n; ++i) {
        if(s1[i].id == idToUpdate) {
            cout << "Enter updated mark for " << s1[i].name << ": ";
            cin >> s1[i].mark;
            if(s1[i].mark >= 80 && s1[i].mark < 100) {
                s1[i].grade = 'A';
            } else if(s1[i].mark >= 70 && s1[i].mark < 80) {
                s1[i].grade = 'B';
            } else if(s1[i].mark >= 50 && s1[i].mark < 70) {
                s1[i].grade = 'C';
            } else if(s1[i].mark >= 40 && s1[i].mark < 50) {
                s1[i].grade = 'D';
            } else if(s1[i].mark < 40) {
                s1[i].grade = 'F';
            }
            cout << "Updated mark and grade for " << s1[i].name << " has been saved.\n";
            break;
        }
    }
}

int main(){
    int n;
    cout << "Enter the number of students: \n";
    cin >> n;
    studentinfo s1[n]; // Assuming there are 'n' students
    getdata(s1, n);
    writeToStudentFile(s1, n);
    displayFromFile();

    updateMarksAndGrades(s1, n);
    writeToStudentFile(s1, n);
    displayFromFile();

    return 0;
}