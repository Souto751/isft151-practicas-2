#include <iostream>
#include "./include/AttendanceManagement.hpp"
#include "./include/Student.hpp"
#include "./include/Course.hpp"

using namespace std;

int main()
{
    Student* juan = new Student();
    juan->setIdentifier(1);
    juan->setName("Juan");
    juan->setSurname("Perez");

    Course* algebra = new Course();
    algebra->setIdentifier(1);
    algebra->setName("Algebra");

    AttendanceManagement* attendanceManagement = new AttendanceManagement();
    attendanceManagement->showAttendance(juan, algebra, "2021-06-08", true);

    delete juan;
    delete algebra;
    delete attendanceManagement;

    std::cin.get();
    std::cin.ignore();

    return 0;
}