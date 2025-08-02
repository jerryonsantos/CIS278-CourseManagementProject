# CIS278-CourseManagementProject
## Description
This C++ console application simulates a University Course Management System and allows users to:
1. Add students and courses
2. Enroll or drop students in courses
3. Maintain a waitlist for full courses
4. View course rosters and student schedules
5. Update course information
6. Track enrollment activity through a log

## Files
1. main.cpp -  Displays the menu, receives user input, and routes commands to the appropriate functions defined in
2. UniversitySystem.cpp - Contains the core logic of the system. Creates the functions to add students, update infromation, enroll students, etc.
3. UniversitySystem.h - Declares functions in UniveristySystem.cpp
4. Student.h - Defines student struc. Holds student infromation like student ID's and name
5. Course/h - Defines course sturct. Holds inputted course information like course code, title, intructor, etc.
6. course/student.txt - text file that contains mock/test student and course data. 

## STL Usage
1. std::map - Used for fast retrieval and storage of student and course records by ID or code.
2. std::set - Ensures students cannot be enrolled in the same course more than once.
3. std::queue - Maintains a waitlist for students trying to enroll in full courses.
4. std::deque - Stores an activity log (enrollments, drops, waitlist moves) for quick push operations.


## How to run
### ON IDE

1. Open CLion or any IDE
2. Create a new project or open the folder where your main.cpp file is.
3. Paste my code into each seperate files
4. Click the green "Run" triangle button at the top right.

### USING TERMINAL

1. Clone this GitHub repo
2. Navigate to project folder
3. Compile c++ code
4. Run Program
