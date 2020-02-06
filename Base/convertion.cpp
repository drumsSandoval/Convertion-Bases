//
//  convertion.cpp
//  Base
//
//  Created by Oscar Sandoval on 02/02/20.
//  Copyright © 2020 Oscar Sandoval. All rights reserved.
//

#include "convertion.hpp"
#include <cmath>
using namespace std;
Convertion::Convertion(){}
void Convertion::setInitialBase(string myStr){
    this->entryBase =  stoi(myStr);
    if(this->entryBase > 30 || this->entryBase < 2)
        throw invalid_argument("Bases no validas");
}
void Convertion::setNumber(string myStr){
    const int aux = (this->entryBase - 10);
    const int asci_min = 97;
    const int asci_may = 65;
    string mystr;
    bool band;
    for(int i = 0; myStr[i]; i++){
        mystr = myStr[i];
        try{
            band = false;
            stoi(mystr);
            if(stoi(mystr)>=this->entryBase){
                band = true;
                throw invalid_argument("Expresion no valida\n");
            }
            continue;
        }catch(invalid_argument& ex){
            if(band)
                throw invalid_argument(ex.what());
        }
       if(int(myStr[i])<65 || int(myStr[i]) >= asci_may + aux || int(myStr[i]) >= asci_min+aux){
             throw invalid_argument("Expresion no valida\n");
        }
    }
    this->number = myStr;
}
void Convertion::setExitBase(string myStr){
    this->exitBase = stoi(myStr);
    if(this->exitBase > 30 || this->exitBase < 2)
        throw invalid_argument("Bases no validas");
}
string Convertion::process(){
    int decimal = this->toBase10();
    string result="";
    int residuo = decimal % exitBase;
    decimal = decimal/exitBase;
    result+=getValue(residuo);
    while(decimal > exitBase){
        residuo = decimal % exitBase;
        decimal = decimal/exitBase;
        result+=getValue(residuo);
    }
    if(getValue(decimal) != "0")
        result+=getValue(decimal);
    reverse(result.begin(), result.end());
    return "El numero: " + number + " escrito en base: " + to_string(entryBase) + " es igual a: " + result + " en base: " + to_string(exitBase) + "\n";;
}
int Convertion::toBase10(){
    reverse(number.begin(), number.end());
    unsigned base_10 = 0, cont  = 0;
    string aux;
    for(int i = 0;this->number[i];i++){
        aux = number[i];
        cont = getValue(aux);
        base_10+=cont*pow(entryBase,i);
    }
    return base_10;
}
int Convertion::getValue(string n){
    const unsigned asci_min = 97,asci_may = 65;
    if(this->entryBase<11){
        return stoi(n);
    }else if(int(n[0]) >= asci_min){
        const unsigned aux = (int((n[0]) - asci_min))+10;
        return aux;
    }else if(int(n[0]) >= asci_may){
        const unsigned aux = (int((n[0]) - asci_may))+10;
        return aux;
    }
    return stoi(n);
}

string Convertion::getValue(int n){
    if(n<10){
        return to_string(n);
    }
    const int aux = n + 55;
    char a = char(aux);
    string mystr="";
    mystr+=a;
    return mystr;
}
