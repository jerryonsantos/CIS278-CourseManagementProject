#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <set>

// Struct representing a student in the system

struct Student {
    std::string id;
    std::string name;
    std::set<std::string> enrolledCourses;
};

#endif


