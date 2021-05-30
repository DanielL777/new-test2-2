#pragma once
#include<string>


class Person1
{

private:
	int number;
	std::string sex;
	int weight;
	int height;


public:

	Person1(int number, std::string sex, int weight, int height);

	std::string to_string()const;

	double bmi()const ;
	
		


};


struct bmi_comparator
{
	bool operator() (const Person1 &p1, const Person1 &p2) const 
	{
		return 	p1.bmi() < p2.bmi();
 	}

};

