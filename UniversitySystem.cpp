#include "UniversitySystem.h"
#include "Student.h"
#include "Course.h"

#include <iostream>
#include <map>
#include <deque>
#include <fstream>
#include <sstream>

using namespace std;

// Global containers to manage all student and course records
map<string, Student> students;
map<string, Course> courses;
deque<string> activityLog; // Stores messages about enrollments and drops

// Adds a new student to the system
// Prompts the user to enter the student ID and full name
void addStudent() {
    Student s;
    cout << "Enter Student ID: ";
    cin >> s.id;

    if (students.count(s.id)) {
        cout << "Student ID already exists.\n";
        return;
    }

    cout << "Enter Full Name: ";
    cin.ignore(); // flush leftover newline
    getline(cin, s.name);
    students[s.id] = s;
    cout << "Student added.\n";
}

// Adds a new course to the system
// Prompts the user for course code, title, instructor, and capacity
void addCourse() {
    Course c;
    cout << "Enter Course Code: ";
    cin >> c.code;

    if (courses.count(c.code)) {
        cout << "Course code already exists. Cannot add duplicate.\n";
        return;
    }

    cout << "Enter Title: ";
    cin.ignore();
    getline(cin, c.title);
    cout << "Enter Instructor: ";
    getline(cin, c.instructor);
    cout << "Enter Capacity: ";
    cin >> c.capacity;
    courses[c.code] = c;
    cout << "Course added.\n";
}

// Allows updating the title and instructor of an existing course
void updateCourse() {
    string code;
    cout << "Enter Course Code to update: ";
    cin >> code;

    if (!courses.count(code)) {
        cout << "Course not found.\n";
        return;
    }

    Course& course = courses[code];

    // Prompt for new title
    cout << "Current title: " << course.title << "\n";
    cout << "Enter new title (press enter to keep current): ";
    cin.ignore();
    string newTitle;
    getline(cin, newTitle);
    if (!newTitle.empty()) {
        course.title = newTitle;
    }

    // Prompt for new instructor
    cout << "Current instructor: " << course.instructor << "\n";
    cout << "Enter new instructor (press enter to keep current): ";
    string newInstructor;
    getline(cin, newInstructor);
    if (!newInstructor.empty()) {
        course.instructor = newInstructor;
    }

    cout << "Course information updated.\n";
}

// Enrolls a student into a course
// If the course is full, the student is added to the waitlist
void enrollStudent() {
    string sid, cid;
    cout << "Enter Student ID: ";
    cin >> sid;
    cout << "Enter Course Code: ";
    cin >> cid;

    if (!students.count(sid) || !courses.count(cid)) {
        cout << "Invalid student or course.\n";
        return;
    }

    Course& course = courses[cid];
    Student& student = students[sid];

    if (course.enrolledStudents.count(sid)) {
        cout << "Student already enrolled.\n";
        return;
    }

    if (course.enrolledStudents.size() < course.capacity) {
        // Add student directly to course
        course.enrolledStudents.insert(sid);
        student.enrolledCourses.insert(cid);
        activityLog.push_back("Enrolled " + sid + " in " + cid);
        cout << "Enrollment successful.\n";
    } else {
        // Add to waitlist if course is full
        course.waitlist.push(sid);
        cout << "Course full. Student added to waitlist.\n";
    }
}

// Removes a student from a course
// If there are students on the waitlist, the next one is automatically enrolled
void dropStudent() {
    string sid, cid;
    cout << "Enter Student ID: ";
    cin >> sid;
    cout << "Enter Course Code: ";
    cin >> cid;

    if (!students.count(sid) || !courses.count(cid)) {
        cout << "Invalid student or course.\n";
        return;
    }

    Course& course = courses[cid];
    Student& student = students[sid];

    if (!course.enrolledStudents.count(sid)) {
        cout << "Student not enrolled in this course.\n";
        return;
    }

    // Remove student from course and student record
    course.enrolledStudents.erase(sid);
    student.enrolledCourses.erase(cid);
    activityLog.push_back("Dropped " + sid + " from " + cid);

    // If someone is on the waitlist, enroll them
    if (!course.waitlist.empty()) {
        string nextSid = course.waitlist.front();
        course.waitlist.pop();
        course.enrolledStudents.insert(nextSid);
        students[nextSid].enrolledCourses.insert(cid);
        activityLog.push_back("Enrolled from waitlist: " + nextSid + " in " + cid);
        cout << "Waitlisted student " << nextSid << " enrolled.\n";
    }

    cout << "Drop successful.\n";
}

// Displays all courses a given student is enrolled in
void listStudentCourses() {
    string sid;
    cout << "Enter Student ID: ";
    cin >> sid;

    if (!students.count(sid)) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Courses enrolled by " << students[sid].name << ":\n";
    for (const auto& cid : students[sid].enrolledCourses) {
        cout << "- " << cid << ": " << courses[cid].title << "\n";
    }
}

// Displays all students enrolled in a given course
void listCourseStudents() {
    string cid;
    cout << "Enter Course Code: ";
    cin >> cid;

    if (!courses.count(cid)) {
        cout << "Course not found.\n";
        return;
    }

    cout << "Students in " << courses[cid].title << ":\n";
    for (const auto& sid : courses[cid].enrolledStudents) {
        cout << "- " << sid << ": " << students[sid].name << "\n";
    }
}

// Shows a log of recent enrollment and drop activity
void showActivityLog() {
    if (activityLog.empty()) {
        cout << "No activity yet.\n";
        return;
    }

    cout << "Enrollment Activity Log:\n";
    for (const auto& entry : activityLog) {
        cout << entry << "\n";
    }
}





