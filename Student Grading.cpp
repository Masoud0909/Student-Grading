/*a program to calculate students’ grades for n students (where n is
entered by the user). The program starts by getting the number of students, and all the students
names, midterm and final grades. It then computes for each student their average (both exams carry
equal weight), and their letter grades (‘F’=0..49,‘C’=50..64,‘B’=65..79,‘A’= 80..100. At the end, the
program prints all the information in a tabular format).
*/
#include <iostream>

using namespace std;

const int MAX = 10;     //constant gloabal variable for the array size
//Function to get info from the user

void getInfo(int& n, string names[], double mid[], double final[]) {
    cout << "How many students' grade to calculate? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int StudentNum = i + 1;
        cout << "Enter stduent #" << StudentNum << " name: " << endl;
        cin >> names[i];
        cout << "His/Her Final Grade: " << endl;
        cin >> final[i];
    }
}

//Function to CALCUlATE THE STUDENTS TOTAL MARK 
void averages(int n, double mid[], double final[], double ave[]) {
    double both = 0;
    for (int i = 0; i < n; i++) {
        ave[i] = (mid[i] + final[i]) / 2;
    }
}

//Function to convert grades to Letters
void calcgrade(int n, double ave[], char grades[]) {
    for (int i = 0; i < n; i++) {
        if (ave[i] >= 80)
            grades[i] = 'A';
        else if (ave[i] >= 65)
            grades[i] = 'B';
        else if (ave[i] >= 50)
            grades[i] = 'C';
        else
            grades[i] = 'F';
        }
    }
//Function to print everything
void print(int n, string names[], double mid[], double final[], double ave[], char grades[]) {
    cout << "Student        Final          Average          Grade" << endl;
    for (int i = 0; i < n; i++) {
        cout << names[i] << "            " << mid[i] << "          " << final[i] << "            " << ave[i] << "             " << grades[i] << endl;
    }
}

int main()
{
    int n;
    string names[MAX];
    double mid[MAX];
    double final[MAX];
    double ave[MAX];
    char grades[MAX];
    getInfo(n, names,mid, final);
    averages(n, mid, final, ave);
    calcgrade(n, ave, grades);
    print(n, names, mid, final, ave, grades);

}