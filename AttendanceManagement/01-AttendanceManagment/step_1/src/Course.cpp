#include "../include/Course.hpp"

Course::Course()
{
}

Course::~Course()
{
}

int Course::getIdentifier() const
{
    return _identifier;
}

void Course::setIdentifier(int identifier)
{
    _identifier = identifier;
}

string Course::getName() const
{
    return _name;
}

void Course::setName(string name)
{
    _name = name;
}