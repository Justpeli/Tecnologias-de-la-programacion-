#include"Job.hh"
#include<iostream>

Job::Job(const char* name, float salary, JobArea jobArea)
{
    this->name = name;
    this->salary = salary;
    this->jobArea = jobArea; 
}

Job::~Job()
{
    std::cout<<"Job Deleted"<<std::endl;
}
const char* Job::GetName()const
{
    return name;
}
float Job::GetSalary()const
{
    return salary;
}
JobArea Job::GetJobArea()const
{
    return jobArea;
}
const char* Job::GetJobAreaStr()const
{
    return jobArea == IT ? "IT": jobArea == HR ? "HR" 
    : jobArea == Sales ? "Sales" : jobArea == Design ? "Design" : "Media";
}  