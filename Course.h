#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <set>
#include <queue>

struct Course {
    std::string code;                  // Unique course code (e.g., CS101)
    std::string title;                 // Full course title (e.g., Intro to C++)
    std::string instructor;            // Instructor's name
    int capacity;                      // Maximum number of enrolled students
    std::set<std::string> enrolledStudents; // Student IDs of enrolled students
    std::queue<std::string> waitlist;       // Waitlisted student IDs
};

#endif // COURSE_H



