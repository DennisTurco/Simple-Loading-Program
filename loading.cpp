#include <iostream>
#include <unistd.h> //libreria per sleep
#include <random> //libreria per randomizer
#include <windows.h>
#include <conio.h>

using namespace std;

void color(int x){
    HANDLE hCon;
    hCon = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, x);
}

void StampaVettore(int contatore, char loading[]){
    color(7);
    cout<<contatore<<"% ";
    for (int i=0; i<23; i++){
        if(loading[i] == '#'){
            color(10);
            cout<<loading[i];
        }
        else{
            color(7);
            cout<<loading[i];
        }
    }
    color(7);
}

int main (){
    int random; //il valore randomico va da 0 a 2
    int random2;
    int contatore = 0;
    int controllo = 0;
    int traccia = 0;
    char loading[23] = {'[','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',']'};

    do {
        random = rand() % 2;
        random2 = rand() % 6 + 1;
        
        contatore = contatore + random2;
        if (contatore > 100) contatore = 100;

        if(contatore/5 > traccia){
            traccia = contatore/5;
            loading[traccia] = '#';
        }

        StampaVettore(contatore, loading);
        
        sleep(random);
        system ("cls");
    
    } while (contatore < 100);

    StampaVettore(contatore, loading);
    
    cout<<"\nLoading Completed!"<<endl;
    
    return 0;
}