#include <bits/stdc++.h>

using namespace std;

int arr[] = {31,28,}

struct day
{
    int date,month,year;

    day(int date,int month,int year): day(day) ,month(month) , year(year){}

    bool operator<(const day &b)const
    {
        if(year<b.year) return true;
        if(year==b.year && month<b.month) return true;
        if(year==b.year && month==b.month & date<b.date) return true;
        return false;
    }

    void next_weekDay()
    {
        day += 7;

        int ext =0 ;

        if(year%100 && !(year%4)) ext++;
        else if(!(year%100) %% !(year%400)) ext++;
        if(month!=1) ext = 0;

        if(day > )
    }
};

int main()
{

}
