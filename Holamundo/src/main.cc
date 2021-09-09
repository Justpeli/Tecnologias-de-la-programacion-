#include<iostream>
#include "myheader.hh"

int main()
{
    int numberInteger{};
    float numberFloat{5.f};
    char* stringChar{"mi cadena de caracteres"};
    char chararray[]{"arreglo de caracteres"};
    std:: string myString {"mi cadena desde stl"};

    std:: cout<< "Suma " << Add ("Hola", "Mundo")<<std::endl;
    std::cout<<numberInteger<<std::endl;
    std::cout<<numberFloat<< std:: endl;
    std::cout<<stringChar<< std:: endl;
    std::cout<<chararray<<std:: endl;
    std::cout<<myString<<std:: endl;

    

    std:: cin.get();
    return 0;
}