#pragma once
#include "JobArea.hh"

class Job
{
private:
   const char* name;
   float salary;
   JobArea jobArea{IT};

public:
    Job(const char* name, float salary, JobArea jobArea);
    ~Job();
    const char* GetName()const;
    float GetSalary()const;
    JobArea GetJobArea()const;
    const char* GetJobAreaStr()const;
};


