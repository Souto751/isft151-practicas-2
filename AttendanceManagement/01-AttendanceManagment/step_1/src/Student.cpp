#include "../include/Student.hpp"

Student::Student()
{
}

Student::~Student()
{
}

int Student::getIdentifier() const
{
    return _identifier;
}

void Student::setIdentifier(int identifier)
{
    _identifier = identifier;
}

string Student::getName() const
{
    return _name;
}

void Student::setName(string name)
{
    _name = name;
}

string Student::getSurname() const
{
    return _surname;
}

void Student::setSurname(string surname)
{
    _surname = surname;
}