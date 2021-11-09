#ifndef ATTENDANCE_MANAGEMENT_H
#define ATTENDANCE_MANAGEMENT_H

#include <iostream>
#include <string>
#include "Student.hpp"
#include "Course.hpp"

using namespace std;

class AttendanceManagement
{
    private:

    public:
        AttendanceManagement();
        virtual ~AttendanceManagement();

        void showAttendance(Student* student, Course* course, string datetime, bool state);
};

#endif // ATTENDANCE_MANAGEMENT_H