#include<bits/stdc++.h>
using namespace std;

class vehicle{ 
    private:
    string make,model;
    int year;
    public:
    void inputData(){
        cout<<"Enter the make of the vehicle: ";
        cin>>make;
        cout<<"Enter Model :";
        cin>>model;
        cout<<"Enter year :";
        cin>>year;
    }
    void display(){
        cout<<"Make: "<<make<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;   
    }
};

class car : public vehicle{
    private:
    int num_doors;
    public:
    void inputData(){
        vehicle::inputData();
        cout<<"Enter Number of Doors :";
        cin>>num_doors;
    }
    void display(){
        vehicle::display();
        cout<<"Number of Doors: "<<num_doors<<endl;
    }
};

class ToyotaCar: public car{ 
    private:
    string timeLevel;
    public:
    void inputData(){
        car::inputData();
        cout<<"Enter Time Level :";
        cin>>timeLevel;
    }
    void display(){
        car::display();
        cout<<"Time Level: "<<timeLevel<<endl;
    }
};

int main(){
    ToyotaCar mycar;
    cout<<"-----------Input Car Info---------"<<endl;
    mycar.inputData();
    cout<<"-----------Onput Car Info---------"<<endl;
    mycar.display();
}