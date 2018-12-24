#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Appointment
{
protected:
  string description;
  string date;
  string apt_time;
public:
  Appointment(string desc, string date, string apt_time):description(desc), date(date), apt_time(apt_time)
  {

  }
  virtual void show()
  {
    cout << endl;
    std::cout << "/************/" << '\n';
    std::cout << "Time: "<<apt_time<<" " <<description <<  " " << date << '\n';
    std::cout << "/************/" << '\n';
    cout << endl;
  }
  string getDesc()
  {
    return description;
  }
  string getTime()
  {
    return apt_time;
  }

};

class Daily : public Appointment{
public:
  Daily(string desc, string date, string apt_time):Appointment(desc , date , apt_time)
  {

  }
  void show()
  {
    cout << endl;
    std::cout << "/************/" << '\n';
    std::cout << "Time: "<<apt_time<<" "<<description << " " << date << " " << "daily " << '\n';
    std::cout << "/************/" << '\n';
    cout << endl;
  }
};

class Weekly : public Appointment{
public:
  Weekly(string desc, string date, string apt_time):Appointment(desc , date , apt_time)
  {

  }
  void show()
  {
    cout << endl;
    std::cout << "/************/" << '\n';
    std::cout << "Time: "<<apt_time<<" "<<description <<  " " << date << " " << "weekly " << '\n';
    std::cout << "/************/" << '\n';
    cout << endl;
  }
};

class Monthly : public Appointment{
public:
  Monthly(string desc, string date, string apt_time):Appointment(desc , date , apt_time)
  {

  }
  void show()
  {
    cout << endl;
    std::cout << "/************/" << '\n';
    std::cout << "Time: "<<apt_time<<" "<<description <<  " " << date << " " << "monthly " << '\n';
    std::cout << "/************/" << '\n';
    cout << endl;
  }
};

void allAppointments(std::vector<Appointment*> &apts)
{
  for(auto appoint:apts)
  appoint->show();
}
void addAppointment(std::vector<Appointment*> &apts)
{
  string description , date , apt_time;
  int type;
  cout << "description: ";

  getline(cin,description);
  getline(cin,description);

  cout << "date: ";
  getline(cin,date);

  cout << "time: ";
  getline(cin,apt_time);
  //Appointment obj(description , date , apt_time);
  //apts.push_back(new Appointment(description , date , apt_time));

  cout << "type: ";
  cin >> type;

  switch( type ){
    case 1:
    apts.push_back(new Daily(description , date , apt_time));
    break;

    case 2:
    apts.push_back(new Weekly(description , date , apt_time));
    break;

    case 3:
    apts.push_back(new Monthly(description , date , apt_time));
    break;

    default:
    cout << "enter a valid type " << endl;
    break;
  }
}

int main() {
    vector<Appointment*> apptRecord;

    char option;
    do {
       cout << "********** Appointment Book Application ************" << endl<< endl;
       cout << "(a) See all appointments on a given day." << endl;
       cout << "(b) Add an appointment." << endl << endl;
       cout << "Enter an option or 'q' to quit: ";

       cin >> option;
       switch(option){
  	    case 'a':
  			allAppointments(apptRecord);
              break;
  		case 'b':
  			addAppointment(apptRecord);
  		     break;
  		case 'q':
  		     break;
  		default:
  			cout << "You entered an invalid option.  Try again!";
       }
  	 cout << endl;
    }
    while(option != 'q');

  return 0;
}
