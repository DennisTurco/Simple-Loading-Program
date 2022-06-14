/*
	Author	-> Dennis Turco 2022
	Email 	-> dennisturco@gmail.com
	WebSite	-> https://dennisturco.github.io/
	GitHub	-> https://github.com/DennisTurco
*/

#include <iostream>
#include <unistd.h> //library for sleep
#include <random> //library for randomizer
#include <windows.h>
#include <conio.h>

#define MAX_DIM 23

void color(int x){
    HANDLE hCon;
    hCon = GetStdHandle (STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon, x);
}

void vector_print(int counter, char loading[]){
    color(7);
    std::cout<<counter<<"% ";
    for (int i=0; i<MAX_DIM; i++){
        if(loading[i] == '#'){
            color(10);
            std::cout<<loading[i];
        }
        else{
            color(7);
            std::cout<<loading[i];
        }
    }
    color(7);
}

int main (){
    int random; //the value is between 0 and 2
    int random2;
    int counter = 0;
    int trace = 0;
    char loading[MAX_DIM] = {'[','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_','_',']'};

    do {
        random = rand() % 2;
        random2 = rand() % 6 + 1;
        
        counter = counter + random2;
        if (counter > 100) counter = 100;

        if(counter/5 > trace){
            trace = counter/5;
            loading[trace] = '#';
        }

        vector_print(counter, loading);
        
        sleep(random);
        system ("cls");
    
    } while (counter < 100);

    vector_print(counter, loading);
    
    std::cout<<"\nLoading Completed!"<<std::endl;
    
    return 0;
}