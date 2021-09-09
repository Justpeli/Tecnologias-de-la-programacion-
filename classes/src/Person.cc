#include "Person.hh"


Person::Person(unsigned int armsCount, std::string name, Job* job, Gender gender)
{
    this->armsCount = armsCount;
    this->name = name;
    this->job = job;
    this->gender = gender;
}

Person::~Person()
{
    std::cout<<"Person Deleted"<<std::endl;
    delete job;
}
unsigned int Person::GetArmsCount()const
{
    return armsCount;
}
std::string Person::GetName()const
{
    return name;
}
Job* Person::GetJob()const
{
    return job;
}
Gender Person::GetGender()const
{
    return gender;
}

const char* Person:: GetGenderStr() const
{
    return gender == 0 ? "Male" : gender == 1 ? "Female" : "None";
}