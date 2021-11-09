#include "../include/AttendanceManagement.hpp"
#include <iostream>
#include <fstream>

AttendanceManagement::AttendanceManagement()
{
}

AttendanceManagement::~AttendanceManagement()
{
}

void AttendanceManagement::showAttendance(Student* student, Course* course, string datetime, bool state)
{
    std::ofstream csv;
    csv.open("assistance.csv", std::ofstream::out | std::ofstream::app);
    csv << student->getIdentifier() << ", ";
    csv << student->getName() << ", ";
    csv << student->getSurname() << ", " ;
    csv << course->getIdentifier() << ", " ;
    csv << course->getName() << ", " ;
    csv << datetime << ", " ;
    csv << "present: " << state << ", " ;
    csv << endl;
    csv.close();
}