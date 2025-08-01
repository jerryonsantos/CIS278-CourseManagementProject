#include <iostream>
#include "UniversitySystem.h"

int main() {
    int choice;

    // Main menu loop continues until the user selects "0" to exit
    do {
        // Displays the main menu options
        std::cout << "\n=== University Course Management System ===\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Add Course\n";
        std::cout << "3. Enroll Student in a Course\n";
        std::cout << "4. Drop Student from a Course\n";
        std::cout << "5. Update Course Information\n";
        std::cout << "6. List All Courses a Student is Enrolled In\n";
        std::cout << "7. List All Students in a Course\n";
        std::cout << "8. Show Enrollment Activity Log\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose an option: ";

        std::cin >> choice;

        // Process the user's selection
        switch (choice) {
            case 1: addStudent(); break;
            case 2: addCourse(); break;
            case 3: enrollStudent(); break;
            case 4: dropStudent(); break;
            case 5: updateCourse(); break;
            case 6: listStudentCourses(); break;
            case 7: listCourseStudents(); break;
            case 8: showActivityLog(); break;
            case 0: std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0); // Repeat the menu until the user chooses to exit

    return 0;
}


