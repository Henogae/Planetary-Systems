#include<iostream>
#include <string>
#include <fstream>
#include<iomanip>
using namespace std;

struct Planet
{
  string pl_name; //Planet Name

  string host_name; // host Name

  string discovery_method;

  string disc_facility;

  string update;

  string release_date;

  int default_flag;

  int sy_snum;
  int sy_pnum;
  int disc_year;
};

class PlanetList{
private:
  Planet *array;
  int max_size;
  int end_of_array = -1;
public:
  PlanetList(int size){
    array = new Planet[size];
    max_size = size;
    end_of_array = -1;
  }

 void Display(){ // 1.ogtask
    cout<<"\tPlanet Name "
      <<"\t\tHost Name "<<setw(16)
      <<" \t\t\t Number of Stars "<<setw(16)
      <<" \t\t Number of Planets "<<setw(16)
      <<" \t\t Discovery Method "<<setw(16)
      <<" \t\t Discovery Year "<<setw(16)
      <<" \t Discovery Facility "<<setw(16)
      <<" \t\t Last Update "<<setw(16)
      <<" \t\t Release Date"<<endl;
    cout<<endl;
    for(int i = 0; i <= end_of_array; i++)
      cout<<setw(3)<<i+1<<". "
      <<" "<<array[i].pl_name
      <<" \t\t\t"<<array[i].host_name
      <<" \t\t\t\t\t\t"<<array[i].sy_snum
      <<" \t\t\t\t\t\t"<<array[i].sy_pnum
      <<" \t\t\t\t\t  "<<array[i].discovery_method
      <<"\t\t\t\t"<<array[i].disc_year
      <<" \t\t  "<<array[i].disc_facility
      <<" \t\t\t\t"<<array[i].update
      <<" \t\t\t"<<array[i].release_date<<endl;
  }

  void Resize(int s){
    Planet *temp_array = array;
    array = new Planet[s];

    for(int i = 0; i < min(s, end_of_array+1); i++){
      array[i] = temp_array[i];
    }
    max_size = s;
  }

  void Insert(Planet pl){ // 2.ogtask
    if(end_of_array == max_size - 1)
      Resize(2*max_size);
    
    array[++end_of_array] = pl;
    //Emmanuel
  }

  void InsertAtIndex(int insertIndex, Planet pl){
    if(insertIndex > end_of_array+1)//Emmanuel
      insertIndex = end_of_array+1;
    if (end_of_array == max_size - 1)
      Resize(2*max_size);
    for (int i = end_of_array; i >= insertIndex; i--)
      array[i+1] = array[i];
    array[insertIndex] = pl;
    end_of_array++;
  }

  PlanetList SearchByDiscMethod(){ // 3.ogtask
    //Emmanuel and Khobe
    PlanetList discovered(1);
    int choice;
    //display menu
    cout<<"Discovery Methods"<<endl;
    cout<<"1. Radial Velocity"<<endl;
    cout<<"2. Transit"<<endl;
    cout<<"3. Imaging"<<endl;
    cout<<"4. Eclipse Timing Variations"<<endl;
    cout<<"Choose a discovery method (1-4): ";

    cin>>choice;

    switch(choice){
        case 1:{
            for(int i = 0; i < max_size; i++){
              if(array[i].discovery_method == "Radial Velocity")
                discovered.Insert(array[i]);
            }
            break;
        }
      
        case 2:{
            for(int i = 0; i < max_size; i++){
              if(array[i].discovery_method == "Transit")
                discovered.Insert(array[i]);
            }
            break;
        }
      

        case 3:{
            for(int i = 0; i < max_size; i++){
              if(array[i].discovery_method == "Imaging")
                discovered.Insert(array[i]);
            }
            break;
        }
        case 4:{
            for(int i = 0; i < max_size; i++){
              if(array[i].discovery_method == "Eclipse Timing Variations")
                discovered.Insert(array[i]);
            }
            break;
        }
    }
      
      return discovered;
  }

  void DeleteElement(int DeleteIndex){ // 4.og task
    //Mikayla
    for(int index = DeleteIndex; index < end_of_array; index++)
      array[index]=array[index+1];

    end_of_array--;
  }

  void Sort_swap()
  {

    int i = 0;
    int j = 0;
    int length = end_of_array;
    Planet temp;
    bool IsSorted;
    do
    {
        IsSorted = false;

        for (i=0; i < length; i++)
        {
            j = i+1;
            if (array[i].pl_name.length() > array[j].pl_name.length())
            {
              temp = array[i];
              array[i] = array[j];
              array[j] = temp;

              IsSorted = true;
            }
        }

    }while(IsSorted);
  }

  //Additional task 1
  void MostPopMethod(){
    string Methods[] = {"Radial Velocity","Transit","Imaging","Eclipse Timing Variation"};
    int method_count[4];
    int radial_sum = 0;
    
    for(int i = 0; i < max_size; i++){
      if(array[i].pl_name == "Radial Velocity")
        radial_sum += 1;
    }
    method_count[0] = radial_sum;

    int transit_sum = 0;
    for(int i = 0; i < max_size; i++){
      if(array[i].pl_name == "Transit")
        radial_sum += 1;
    }
    method_count[1] = transit_sum;

    int imag_sum = 0;
    for(int i = 0; i < max_size; i++){
      if(array[i].pl_name == "Imaging")
        imag_sum += 1;
    }
    method_count[2] = imag_sum;

    int etv_sum = 0;
    for(int i = 0; i < max_size; i++){
      if(array[i].pl_name == "Eclipse Time Variation")
        etv_sum += 1;
    }
    method_count[3] = etv_sum;

    int popular_index = 0;
    for(int i = 0; i < 4; i++){
      if(method_count[i] > method_count[i+1])
        popular_index = i;
    }

    cout<<"Most Popular Discovery Method: "<<Methods[popular_index]<<endl;
  }
  
  //Additional Task 2
  void Update(){
    string PlanetName;
    string NewDate;
    bool planet_found = false;
    char new_choice;
    do{
      new_choice = '\0';
      cout<<"Enter a planet name to update: ";
      getline(cin, PlanetName);
      cout<<"What is the new date? ";
      getline(cin, NewDate);
      for(int i = 0; i < max_size; i++){
          if(array[i].pl_name == PlanetName){
              planet_found = true;
              array[i].update = NewDate;
          }
      }
      
      if(planet_found == false){
          cout<<"Sorry. No planet with that name found in this dataset."<<endl;
          cout<<"Would you like to enter a different planet name?(Y/N) ";
          cin>>new_choice;
          new_choice = toupper(new_choice);
          cin.ignore();
      }
    }while(new_choice == 'Y');
  }
};