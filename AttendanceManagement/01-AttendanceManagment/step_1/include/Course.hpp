#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

class Course
{
    private:
        int _identifier;
        string _name;
        string _surname;

    public:
        Course();
        virtual ~Course();

        int getIdentifier() const;
        void setIdentifier(int identifier);
        string getName() const;
        void setName(string name);
};

#endif // COURSE_H