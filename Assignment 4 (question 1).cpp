#include<iostream>
using namespace std;


class Time{

int hour;
int minute;
int second;

public:
Time(){
hour = 0;
minute = 0;
second = 0;
}

Time(int h, int m, int s){
    hour = h;
    minute= m;
    second = s;
}

int getHour(){
return hour;
}

int getMinute(){
return minute;;
}

int getSeconds(){
return second;
}

int printTime(){
cout<<"Time is: "<<hour<<":"<<minute<<":"<<second<<endl;
}

int setHour(int hr){
hour = hr;
}

int setMinute(int min){
minute = min;
}

int setSeconds(int sec){
second = sec;
}

};

int main(){

Time* times[5];

for(int i = 0; i < 5; i++){
    int h,m,s;
    cout <<"Enter hour, minute and second for time"<< (i+1) <<":";
    cin>>h>>m>>s;
    times[i] = new Time(h,m,s);
}

for(int i = 0; i< 5; i++) {
    cout<< "Time " << (i+1) <<":";
    times[i]->printTime();
}

    return 0;
}