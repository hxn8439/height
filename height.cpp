// Hamilton Nguyen 1000538439 Problem 2 06/24/2019

#include <iostream>
#include <vector>

using namespace std;

class Rider //creating a class Rider
{
 
    string name;
    int height;
 
  public: //Rider constructors
  
    Rider(int h) 
	{
      name = " ";
      height = h;
    }
  
    Rider(string n, int h) 
    {
        name = n;
        height = h;
    }
    
    int GetHeight() 
    {
        return height;
    }
};

class Ride //creating a class Ride
{
 
    vector <Rider> Riders; //declaration of vector called Riders
    int minimum_Height;
    
  public: //Rider constructors
  
    void Set_Height(int h) 
    {
      minimum_Height = h;
    }
    
    void add_line(Rider r)
    {
        if (r.GetHeight() < minimum_Height) 
        {
            cout << "-Sorry can't add rider-too short"<<endl<<endl;
            return;
        }
        
        Riders.push_back(r);
        cout << "-Adding rider to line." << endl<<endl;
    }
};

class Amusement_park //creating a class called Amusement_park
{
 
    Ride* Rides;
    int num;
  
  public: //Amusement_park constructors
  
    Amusement_park(int n) 
    {
        num = n;
        Rides = new Ride[num];
        cout<<"\n~~~Amusement Park Info~~~"<<endl;
        for (int i = 0; i < num; i++) 
        {
            int h;
            string name;
            cout << "Ride " << i + 1 << "- Enter minimum ride height and ride name: "<<endl;
            cin >> h;
            cin >> name;
            Rides[i+1].Set_Height(h);
            cout<<endl;
        }
    }
 
    Ride get_ride(int i)
    {
        if (i < 0 || i >= num)
        {
            cout << "Not available!!!" << endl;
        }
        return Rides[i];
    }

};


int main() 
{
    Rider r1("Yaris", 45);//name, height in inches
    Rider r2(49); //height in inches
    
    Amusement_park a1(3); //3 is the number of rides in the amusement park
    a1.get_ride(1).add_line(r1); //add a rider to the line of a ride
    
    Amusement_park a2(2); //2 is the number of rides in the amusement park
    a2.get_ride(1).add_line(r2); //add a rider to the line of a ride
    
    return 0;
}
