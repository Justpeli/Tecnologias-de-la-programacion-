#include<iostream>
#include "Person.hh"

int main()
{
    Person* person1{new Person(2, "David", new Job("Developer", 15000.f, IT), none)};
    std:: cout<<person1->GetName()<<std::endl;
    std:: cout<<person1->GetArmsCount()<<std::endl;
    std:: cout<<person1->GetGenderStr()<<std::endl;
    std:: cout<<"Job details"<<std::endl;
    std:: cout<<person1->GetJob()->GetName()<<std::endl;
    std:: cout<<person1->GetJob()->GetJobAreaStr()<<std::endl;
    std:: cout<<person1->GetJob()->GetSalary()<<std::endl;
    delete person1;
    std:: cin.get();
    return 0;

}
