#include "Person1.h"
#include<sstream>

Person1::Person1(int number, std::string sex, int weight, int height)
{
    this->number = number;
    this->sex = sex;
    this->weight = weight;
    this->height = height;
    
}

std::string Person1::to_string()const
{

    std::stringstream ss;


    ss << number << " \t" << sex << " \t" << weight << " \t" << height<<" \t"<< bmi();
    return ss.str();   //pripazi na ovu metodu bmi()   da bude s zagradama
}

double Person1::bmi()const
{
    return     weight / pow(height/100.00 , 2)  ;  //zasto mi neradi cast operator (double)  ???
}

