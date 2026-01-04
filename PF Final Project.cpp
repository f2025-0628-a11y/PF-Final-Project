#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/* ================= STRUCTURES ================= */

struct Student {
    int roll;
    string name;
};

struct Book {
    int id;
    string title;
    bool issued;
};

struct Grade {
    int roll;
    float marks;
    char grade;
};

struct Attendance {
    int roll;
    int presentDays;
};

/* ================= VECTORS ================= */

vector<Student> students;
vector<Book> books;
vector<Grade> grades;
vector<Attendance> attendanceList;

/* ================= FUNCTION DECLARATIONS ================= */

void studentMenu();
void libraryMenu();
void gradingMenu();
void attendanceMenu();

void addStudent();
void displayStudents();

void addBook();
void issueBook();
void displayBooks();

char calculateGrade(float marks);
void addGrade();

void addAttendance();

void saveData();
void loadData();

/* ================= MAIN ================= */

int main() {
    int choice;
    loadData();

    do {
        cout << "\n===== MAIN MENU =====";
        cout << "\n1. Student Management";
        cout << "\n2. Library Management";
        cout << "\n3. Grading System";
        cout << "\n4. Attendance System";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: studentMenu(); break;
            case 2: libraryMenu(); break;
            case 3: gradingMenu(); break;
            case 4: attendanceMenu(); break;
            case 5: saveData(); cout << "Program Ended\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while(choice != 5);

    return 0;
}

/* ================= STUDENT MANAGEMENT ================= */

void studentMenu() {
    int ch;
    cout << "\n--- Student Management ---";
    cout << "\n1. Add Student";
    cout << "\n2. Display Students";
    cout << "\nEnter choice: ";
    cin >> ch;

    if(ch == 1) addStudent();
    else if(ch == 2) displayStudents();
}

void addStudent() {
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.roll;
    cout << "Enter Name: ";
    cin >> s.name;
    students.push_back(s);
}

void displayStudents() {
    cout << "\nStudent List:\n";
    for(int i = 0; i < students.size(); i++) {
        cout << students[i].roll << " " << students[i].name << endl;
    }
}

/* ================= LIBRARY MANAGEMENT ================= */

void libraryMenu() {
    int ch;
    cout << "\n--- Library Management ---";
    cout << "\n1. Add Book";
    cout << "\n2. Issue Book";
    cout << "\n3. Display Books";
    cout << "\nEnter choice: ";
    cin >> ch;

    if(ch == 1) addBook();
    else if(ch == 2) issueBook();
    else if(ch == 3) displayBooks();
}

void addBook() {
    Book b;
    cout << "Enter Book ID: ";
    cin >> b.id;
    cout << "Enter Book Title: ";
    cin >> b.title;
    b.issued = false;
    books.push_back(b);
}

void issueBook() {
    int id;
    cout << "Enter Book ID: ";
    cin >> id;

    for(int i = 0; i < books.size(); i++) {
        if(books[i].id == id && !books[i].issued) {
            books[i].issued = true;
            cout << "Book Issued Successfully\n";
            return;
        }
    }
    cout << "Book Not Available\n";
}

void displayBooks() {
    cout << "\nBook List:\n";
    for(int i = 0; i < books.size(); i++) {
        cout << books[i].id << " "
             << books[i].title << " "
             << (books[i].issued ? "Issued" : "Available") << endl;
    }
}

/* ================= GRADING SYSTEM ================= */

void gradingMenu() {
    addGrade();
}

void addGrade() {
    Grade g;
    cout << "Enter Roll No: ";
    cin >> g.roll;
    cout << "Enter Marks: ";
    cin >> g.marks;
    g.grade = calculateGrade(g.marks);
    grades.push_back(g);
    cout << "Grade: " << g.grade << endl;
}

char calculateGrade(float marks) {
    if(marks >= 80) return 'A';
    else if(marks >= 60) return 'B';
    else if(marks >= 40) return 'C';
    else return 'F';
}

/* ================= ATTENDANCE SYSTEM ================= */

void attendanceMenu() {
    addAttendance();
}

void addAttendance() {
    Attendance a;
    cout << "Enter Roll No: ";
    cin >> a.roll;
    cout << "Enter Present Days: ";
    cin >> a.presentDays;
    attendanceList.push_back(a);
    cout << "Attendance Recorded\n";
}

/* ================= FILE HANDLING ================= */

void saveData() {
    ofstream file("students.txt");
    for(int i = 0; i < students.size(); i++) {
        file << students[i].roll << " " << students[i].name << endl;
    }
    file.close();
}

void loadData() {
    ifstream file("students.txt");
    Student s;
    while(file >> s.roll >> s.name) {
        students.push_back(s);
    }
    file.close();
}

