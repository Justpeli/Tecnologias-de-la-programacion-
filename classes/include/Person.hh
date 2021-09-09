#pragma once
#include<string>
#include<iostream>
#include "Gender.hh"
#include "Job.hh"

class Person
{
private:
   unsigned int armsCount{};
   std::string name;
   Job* job;
   Gender gender{male};
public:
    Person(unsigned int armsCount, std::string name, Job* job, Gender gender);
    ~Person();

    unsigned int GetArmsCount()const;
    std::string GetName()const;
    Job* GetJob()const;
    Gender GetGender()const;
    const char* GetGenderStr()const;
};

