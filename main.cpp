#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "PlanetList.cpp"
using namespace std;
 
Planet GetPlanetInfo(istream &File);
void ResetList(istream &File);  //function to return to beginning of excel file
void DisplayArt();
char GetResponse();

PlanetList planets(1);

int main(){
    ifstream Spreadsheet;
    Spreadsheet.open("Planetary Systems.csv", ios_base::in);
    string Header; //dummy variable to read header columns
    getline(Spreadsheet, Header);
    
    for(int i = 0; i < 100; i++){
      planets.Insert(GetPlanetInfo(Spreadsheet));
    }
    
    DisplayArt();
    
    char option = '\0';
    do{
        int choice;
        //create menu
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"|                    Menu                      |"<<endl;
        cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
        cout<<"| 1. Sort Planets by Word Length               |"<<endl;
        cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
        cout<<"| 2. Search Planets By Discovery Method        |"<<endl;
        cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
        cout<<"| 3. Find the Most Popular Discovery Method    |"<<endl;
        cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
        cout<<"| 4. Change Last Update                        |"<<endl;
        cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
        cout<<"| 5. Delete Random Planet                      |"<<endl;
        cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
        cout<<"| 6. Display Current List                      |"<<endl;
        cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
        cout<<"| 0. Quit Application                          |"<<endl;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
        cout<<"Chose a task to complete, chose 0 to quit application: ";
        cin>>choice;
        while(choice < 0 || choice > 6){
            cout<<"Not a valid choice. "
            <<"Please enter a choice 0-5: ";
            cin>>choice;
        }
        cout<<"\n"<<endl;
        cin.ignore();
        
        switch(choice){
            case 1:{
                char see;
                clock_t t1 = clock();
                planets.Sort_swap();
                clock_t t2 = clock();
                cout<<"Sorting took "<<t2-t1<<" ticks"<<endl;
                cout<<"Do you want to display the sorted planets?(Y/N) ";
                cin>>see;
                see = toupper(see);
                if(see == 'Y')
                  planets.Display();
                break;
            }
            case 2:{
                char see;
                clock_t t1 = clock();
                PlanetList discovered_list = planets.SearchByDiscMethod();
                clock_t t2 = clock();
                cout<<"Discovery Method Search took: "<<t2-t1<<" ticks\n"<<endl;
                cout<<"Would you like to display this list? (Y/N) ";
                cin>>see;
                see = toupper(see);
                if(see == 'Y')
                    discovered_list.Display();
                break;
            }
            case 3:{
                clock_t t1 = clock();
                planets.MostPopMethod();
                clock_t t2 = clock();
                cout<<endl;
                cout<<"Finding the most popular discovery method took "<<t2-t1<<" ticks"<<endl;
                break;
            }
            case 4:{
                char see;
                clock_t t1 = clock();
                planets.Update();
                clock_t t2 = clock();
                cout<<"Update took "<<t2-t1<<endl;
                cout<<"Would you like to see the updated list?(Y/N) ";
                cin>>see;
                see = toupper(see);
                if(see == 'Y')
                    planets.Display();
                break;
            }
            case 5:{
                srand(time(NULL));
                char see;
                int rand_index = rand()%100;
                clock_t t1 = clock();
                planets.DeleteElement(rand_index);
                clock_t t2 = clock();
                cout<<"Deletion took "<<t2-t1<<" ticks"<<endl;
                cout<<"Index deleted: "<<rand_index+1<<endl;
                cout<<endl;
                cout<<"Would you like to see the new list?(Y/N) ";
                cin>>see;
                see = toupper(see);
                if(see == 'Y')
                    planets.Display();
                break;
            }
            case 6:{
                planets.Display();
                break;
            }
            case 0:{
                cout<<"Goodbye!"<<endl;
                return 0;;
            }
        }
        
        if(choice != 0){
            option = GetResponse();
            toupper(option);
            if(option != 'Y')
                cout<<"Goodbye!"<<endl;
            else
                ResetList(Spreadsheet);
        }
        
        
        
    }while(option == 'Y');
    return 0;
}

Planet GetPlanetInfo(istream &File){
  Planet this_planet;
  char dummy; //dummy variable to read commas after integer types
  getline(File,this_planet.pl_name, ',');
  //cout<<this_planet.pl_name<<endl;
  getline(File,this_planet.host_name, ',');
  File>>this_planet.default_flag;
  File>>dummy;
  File>>this_planet.sy_snum;
  File>>dummy;
  File>>this_planet.sy_pnum;
  File>>dummy;
  getline(File, this_planet.discovery_method,',');
  File>>this_planet.disc_year;
  File>>dummy;
  getline(File, this_planet.disc_facility, ',');
  getline(File, this_planet.update, ',');
  getline(File, this_planet.release_date);
  return this_planet;
}



void ResetList(istream &File){
    File.clear();
    File.seekg(0);
    
}

char GetResponse(){
    //initialize return variable
    char response = '\0';
    //Get Response
    cout<<"\nWould you like to choose another task?(Y/N) ";
    cin>>response;
    response = toupper(response);
    return response;
    
}



























void DisplayArt(){
    
    cout<<string(175, '=')<<endl;
    cout<<endl;
    
    cout<<"~+"<<endl;
    cout<<endl;
    cout<<"                *       +    "<<endl;
    cout<<"        '                  | "<<endl;
    cout<<"    ()    .-.,=\"``\"=.    - o -"<<endl;
    cout<<"          '=/_       \\     | "<<endl;
    cout<<"       *   |  '=._   |  "<<endl;
    cout<<"            \\     `=./`,        '"<<endl;
    cout<<"         .   '=.__.=' `='      *"<<endl;
    cout<<"+                         +  "<<endl;
    cout<<"     O      *        '       ."<<endl;
    
    cout<<"\n"<<endl;
    
    cout <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t        .                      ."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t       !   "<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t        .                      ;"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t       !"<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t        :                  - --+- -"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t       ^"<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t        !           .          !"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t      / \\"<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t        |        .             ."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t     /___\\"<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t        |_         +"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    |=   =|" <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     ,  | `."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    |     |" <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t--- --+-<#>-+- ---  --  -"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    |     |" <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t      `._|_,'"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    |     |" <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t         T"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    |     |" <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t         |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    |     |" <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t         !"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    |     |" <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t         :         . :"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    |     |" <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t         .       *"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    |     |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    |     |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t   /|##!##|\\"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t  / |##!##| \\"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t /  |##!##|  \\"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t|  / ^ | ^ \\  |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t| /  ( | )  \\ |"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t|/   ( | )   \\|"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    ((   ))"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t   ((  :  ))"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t   ((  :  ))"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t    ((   ))"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t     (( ))"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t      ( )"<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t       ."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t       ."<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t       ."<<endl;
    
    
    
    cout<<"    .______    __          ___      .__   __.  _______ .___________.    ___      .______     ____    ____         _______.____    ____  _______.___________. _______ .___  ___.      _______."<<endl;
    cout<<"    |   _  \\  |  |        /   \\     |  \\ |  | |   ____||           |   /   \\     |   _  \\    \\   \\  /   /        /       |\\   \\  /   / /       |           ||   ____||   \\/   |     /       |"<<endl;
    cout<<"    |  |_)  | |  |       /  ^  \\    |   \\|  | |  |__   `---|  |----`  /  ^  \\    |  |_)  |    \\   \\/   /        |   (----` \\   \\/   / |   (----`---|  |----`|  |__   |  \\  /  |    |   (----`"<<endl;
    cout<<"    |   ___/  |  |      /  /_\\  \\   |  . `  | |   __|      |  |      /  /_\\  \\   |      /      \\_    _/          \\   \\      \\_    _/   \\   \\       |  |     |   __|  |  |\\/|  |     \\   \\    "<<endl;
    cout<<"    |  |      |  `----./  _____  \\  |  |\\   | |  |____     |  |     /  _____  \\  |  |\\  \\----.   |  |        .----)   |       |  | .----)   |      |  |     |  |____ |  |  |  | .----)   |"<<endl;
    cout<<"    |__|      |_______/__/     \\__\\ |__| \\__| |_______|    |__|    /__/     \\__\\ | _| `._____|   |__|        |_______/        |__| |_______/       |__|     |_______||__|  |__| |_______/ "<<endl;
     
    cout<<string(3, '\n');
    
    
    cout<<"\t\t\t\t                                                                   ...;===+. "<<endl;
    cout<<"\t\t\t\t                                                                 .:=iiiiii=+="<<endl;
    cout<<"\t\t\t\t                                                               .=i))=;::+)i=+,"<<endl;
    cout<<"\t\t\t\t                                                           ,=i);)I)))I):=i=;"<<endl;
    cout<<"\t\t\t\t                                                         .=i==))))ii)))I:i++"<<endl;
    cout<<"\t\t\t\t                                                       +)+))iiiiiiii))I=i+:'"<<endl;
    cout<<"\t\t\t\t                                  .,:;;++++++;:,.       )iii+:::;iii))+i='"<<endl;
    cout<<"\t\t\t\t                               .:;++=iiiiiiiiii=++;.    =::,,,:::=i));=+'"<<endl;
    cout<<"\t\t\t\t                             ,;+==ii)))))))))))ii==+;,      ,,,:=i))+=:"<<endl;
    cout<<"\t\t\t\t                           ,;+=ii))))))IIIIII))))ii===;.    ,,:=i)=i+"<<endl;
    cout<<"\t\t\t\t                          ;+=ii)))IIIIITIIIIII))))iiii=+,   ,:=));=,"<<endl;
    cout<<"\t\t\t\t                        ,+=i))IIIIIITTTTTITIIIIII)))I)i=+,,:+i)=i"<<endl;
    cout<<"\t\t\t\t                        ,+i))IIIIIITTTTTTTTTTTTI))IIII))i=::i))i='"<<endl;
    cout<<"\t\t\t\t                      ,=i))IIIIITLLTTTTTTTTTTIITTTTIII)+;+i)+i`"<<endl;
    cout<<"\t\t\t\t                      =i))IIITTLTLTTTTTTTTTIITTLLTTTII+:i)ii:'"<<endl;
    cout<<"\t\t\t\t                     +i))IITTTLLLTTTTTTTTTTTTLLLTTTT+:i)))=,"<<endl;
    cout<<"\t\t\t\t                     =))ITTTTTTTTTTTLTTTTTTLLLLLLTi:=)IIiii;"<<endl;
    cout<<"\t\t\t\t                    .i)IIITTTTTTTTLTTTITLLLLLLLT);=)I)))))i;"<<endl;
    cout<<"\t\t\t\t                    :))IIITTTTTLTTTTTTLLHLLLLL);=)II)IIIIi=:"<<endl;
    cout<<"\t\t\t\t                   :i)IIITTTTTTTTTLLLHLLHLL)+=)II)ITTTI)i="<<endl;
    cout<<"\t\t\t\t                   .i)IIITTTTITTLLLHHLLLL);=)II)ITTTTII)i+"<<endl;
    cout<<"\t\t\t\t                    =i)IIIIIITTLLLLLLHLL=:i)II)TTTTTTIII)i'"<<endl;
    cout<<"\t\t\t\t                  +i)i)))IITTLLLLLLLLT=:i)II)TTTTLTTIII)i;"<<endl;
    cout<<"\t\t\t\t                +ii)i:)IITTLLTLLLLT=;+i)I)ITTTTLTTTII))i;"<<endl;
    cout<<"\t\t\t\t               =;)i=:,=)ITTTTLTTI=:i))I)TTTLLLTTTTTII)i;"<<endl;
    cout<<"\t\t\t\t             +i)ii::,  +)IIITI+:+i)I))TTTTLLTTTTTII))=,"<<endl;
    cout<<"\t\t\t\t           :=;)i=:,,    ,i++::i))I)ITTTTTTTTTTIIII)=+'"<<endl;
    cout<<"\t\t\t\t         .+ii)i=::,,   ,,::=i)))iIITTTTTTTTIIIII)=+"<<endl;
    cout<<"\t\t\t\t        ,==)ii=;:,,,,:::=ii)i)iIIIITIIITIIII))i+:'"<<endl;
    cout<<"\t\t\t\t       +=:))i==;:::;=iii)+)=  `:i)))IIIII)ii+'"<<endl;
    cout<<"\t\t\t\t     .+=:))iiiiiiii)))+ii;"<<endl;
    cout<<"\t\t\t\t    .+=;))iiiiii)));ii+"<<endl;
    cout<<"\t\t\t\t   .+=i:)))))))=+ii+"<<endl;
    cout<<"\t\t\t\t  .;==i+::::=)i=;"<<endl;
    cout<<"\t\t\t\t  ,+==iiiiii+,"<<endl;
    cout<<"\t\t\t\t  `+=+++;`"<<endl;

    cout<<string(3,'\n');
    cout<<string(175, '=')<<endl;
    
}
