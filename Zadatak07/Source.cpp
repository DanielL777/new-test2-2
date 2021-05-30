#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>
#include"Person1.h"




using namespace std;


/*
 Napisite program koji koristi prioritetni red ili heap te ispisuje sve osobe
 iz itm.csv od visih indeksa BMI prema nizim. Indeks  BMI dobije se prema formuli:
     
     BMI = tezina/ pow(visina,2)

*/
template<typename T>

T conv(string& nesto) 
{

    T t;  //objekt na T je  t
    stringstream s(nesto);

    s >> t;

    return t;

}




void  fill_pq(ifstream& in, priority_queue < Person1, vector<Person1>,  bmi_comparator> &pq)
{
    string line, temp, sex;

    getline(in, line);

    while (getline(in, line))
    {
        stringstream ss(line);

        getline(ss, temp, ',');
        int number = conv<int>(temp);

        getline(ss, temp, ',');
        sex = temp;

        getline(ss, temp, ',');
        int weight = conv<int>(temp);

        getline(ss, temp, ',');
        int height= conv<int>(temp);

       
        
        
        pq.emplace(number,  sex, weight, height);

    }

}



int main() 
{
    //ADT person

    ifstream in("itm.csv");
    if (!in) { cout << "Error loading"; return 1; }

    priority_queue<Person1, vector<Person1>,  bmi_comparator> pq;

    fill_pq(in,  pq);

    in.close();



    while (!pq.empty())
    {
        cout << pq.top().to_string() << endl;
        pq.pop();
    }

    return 0;
}