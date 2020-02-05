//
//  main.cpp
//  Base
//
//  Created by Oscar Sandoval on 02/02/20.
//  Copyright © 2020 Oscar Sandoval. All rights reserved.
//

#include <iostream>
#include "convertion.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    bool band;
    string myStr;
    Convertion convertion;
    do{
        band = false;
        system("clear");
        cout<<"\t\tMenu Conversión \n"<<endl
        <<"1. New Process"<<endl
        <<"2. Salir"<<endl
        <<"Elige una opción: ";
        getline(cin, myStr);
        if(myStr=="1"){
            bool band2;
            system("clear");
            do{
                band2=false;
                cout<<"base de entrada (2 a 30) : ";
                getline(cin,myStr);
                try{
                    convertion.setInitialBase(myStr);
                }catch(invalid_argument& err){
                    band2=true;
                    system("clear");
                    cerr<<err.what()<<endl;
                }
            }while(band2);
            do{
                band2=false;
                cout<<"Caracteres :  : ";
                getline(cin,myStr);
                try{
                    convertion.setNumber(myStr);
                }catch(invalid_argument& err){
                    band2=true;
                    system("clear");
                    cerr<<err.what()<<endl;
                }
            }while(band2);
            do{
                band2=false;
                cout<<"base de salida (2 a 30)"<<endl;
                getline(cin,myStr);
                try{
                    convertion.setExitBase(myStr);
                }catch(invalid_argument& err){
                    band2=true;
                    system("clear");
                    cerr<<err.what()<<endl;
                }
            }while(band2);
            convertion.process();
        }
        else if(myStr=="2"){
            band=true;
        }
        else{
            system("clear");
            cout<<"Opcion no valida"<<endl;
        }
    }while(!band);
    return 0;
}
