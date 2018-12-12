/* 
 * File:   main.cpp
 * Author: Jrrobert Jabonillo
 * Created on December 11, 2018, 9:57 PM
 * Purpose: GOLF, the card game.
 *          
 *          
 */

//System Libraries
#include <iostream> //I/O Library -> cout, endl
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;//namespace I/O stream library created

//User Libraries

//Global Constants

//Function Prototypes
void filcard(int[], int);
void print(int[], int);
void drawn(int[], int);
int hand(int[], int);
void change(int[], int);
void change2(int*, int);
char knock(char);
int draw(int);
void para(int[], int, int[]);
void para2(int[], int, int[], int[]);
void para3(int[], int, int[], int[], int[]);
float avg(float, float unuse = 52);
void square(float);
void square(int);
void bubsort(int[], int);
void select(int[], int);
int search(int[], int, int);
int total(int[], int);
void winner(int, string);

//Execution Begins 
int main(int argc, char** argv) {
    //Seed random generator
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int SIZE = 3;
    float average;
    float used = 0;
    string name;
    char start;
    int value;
    int number;
    int turns;
    int result;
    int total1, total2, total3, total4, grand;
    int player1[SIZE+1];
    int player2[SIZE+1];
    int player3[SIZE+1];
    int player4[SIZE+1];
    float squaref;
    int intsqu;
    
    //Initialize variables
    total1 = 0;
    total2 = 0;
    total3 = 0;
    total4 = 0;
    grand = 0;
    turns = 0;
    
    //Function to allow player to want to play the game or exit the game
    
    cout<<"Welcome to the card game known as Golf! The objective of the game is to obtain the hand with the lowest value of cards."<<endl;
    cout<<endl;
    cout<<"The Rules: One card is drawn from the deck. Cards are valued from 0-10, king is a zero, Ace is 1 point, numeral cards are valued at their card number. Jack or Queen are 10 points! Cards that are equal will cancel each other out! There are 9 turns in the game! Play well!"<<endl;
    cout<<endl;
    
    //Randomly fills the deck of players
    filcard(player1, SIZE);
    filcard(player2, SIZE);
    filcard(player3, SIZE);
    filcard(player4, SIZE);
    
    cout<<"Would you like to play the game? (y/n): ";
    cin>>start;
   
    if(start == 'y'){
        cout<<"Enter the amount of players (2-4): ";
        cin>>number;
        while(number < 2 || number > 4){
            cout<<"Error! Invalid amount of players! Enter again: ";
            cin>>number;
        }
    }
    else if(start == 'n'){
        exit(0);
    }
    switch(number){
        case 2:{ //Function to draw from deck and to have the players see two cards from deck.
                cout<<"Player 1 select a card to view: "<<endl;
                drawn(player1, SIZE);
                cout<<"Player 2 select a card to view: "<<endl;
                drawn(player2, SIZE);
                
                //Function to swap a card within the player deck
                do{
                    used = used + 1;
                    cout<<"Player 1 Decision to swap a card: "<<endl;
                    change(player1, SIZE);
                    //Swap cards using by reference
                    cout<<"Player 2 Decision to swap a card: "<<endl;
                    change2(player2, SIZE);
                    turns = turns + 1;
                }while(turns != 9);
                
                //Function to find the average amount of cards left in the deck
                avg(used);
                average = avg(used);
                cout<<"Percent of cards used "<<setprecision(3)<<average*100<<"%"<<endl;
                
                //Function to create a parallel array
                para(player1, SIZE, player2);
                
                //Function to show the hands of the players
                cout<<"Player 1 hand: "<<endl;
                hand(player1, SIZE);
                cout<<"Player 2 hand: "<<endl;
                hand(player2, SIZE);
                
                //Bubble sort the array of player 1
                bubsort(player1, SIZE);
                cout<<"Sorted array: "<<endl;
                print(player1, SIZE);
                
                //Selection sort the array of player 2
                select(player2, SIZE);
                cout<<"Sorted array: "<<endl;
                print(player2, SIZE);
                
                //Binary search an array for a certain card the player is interested in viewing
                for(int i = 0; i <= 1; i++){
                    if(i == 1){
                        cout<<"Player 1 Enter a value to see in deck: ";
                        cin>>value;
                        result = search(player1, SIZE, value);
                        cout<<endl;
                        if(result == -1){
                            cout<<"Value does not exist in array."<<endl;
                        }
                        else{
                            cout<<"Value "<<value<<" found at position "<<result+1<<endl;
                        }
                    }
                    if(i == 2){
                        cout<<"Player 2 Enter a value to see in deck: ";
                        cin>>value;
                        result = search(player2, SIZE, value);
                        cout<<endl;
                        if(result == -1){
                            cout<<"Value does not exist in array."<<endl;
                        }
                        else{
                            cout<<"Value "<<value<<" found at position "<<result+1<<endl;
                        }
                    }
                }
                
                //Function to display the winner of the game
                total1 = total(player1, SIZE);
                total2 = total(player2, SIZE);
                if(total1 < total2){
                    cout<<"Player 1 value total is: "<<total1<<endl;
                    name = "player 1";
                    winner(total1, name);
                }
                else{
                    cout<<"Player 2 value total is: "<<total2<<endl;
                    name = "player 2";
                    winner(total2, name);
                }
                
                //Function to calculate the square of the totals
                //Overloading
                intsqu = total1;
                squaref = total1/5;
                square(squaref);
                square(intsqu);
                
        }
        case 3:{ //Function to draw from deck and to have the players see two cards from deck.
                cout<<"Player 1 select a card to view: "<<endl;
                drawn(player1, SIZE);
                cout<<"Player 2 select a card to view: "<<endl;
                drawn(player2, SIZE);
                cout<<"Player 3 select a card to view: "<<endl;
                drawn(player3, SIZE);               
                
                
                //Function to swap a card within the player deck
                do{
                    used = used + 1;
                    cout<<"Player 1 Decision to swap a card: "<<endl;
                    change(player1, SIZE);
                    //Swap cards using by reference
                    cout<<"Player 2 Decision to swap a card: "<<endl;
                    change2(player2, SIZE);
                    cout<<"Player 3 Decision to swap a card: "<<endl;
                    change(player3, SIZE);
                    turns = turns + 1;
                }while(turns != 9);
                
                //Function to find the average amount of cards left in the deck
                avg(used);
                average = avg(used);
                cout<<"Percent of cards used "<<setprecision(3)<<average*100<<"%"<<endl;
                
                //Function to create a parallel array
                para2(player1, SIZE, player2,player3);
                
                //Function to show the hands of the players
                cout<<"Player 1 hand: "<<endl;
                hand(player1, SIZE);
                cout<<"Player 2 hand: "<<endl;
                hand(player2, SIZE);
                cout<<"Player 3 hand: "<<endl;
                hand(player3, SIZE);
                
                //Bubble sort the array of player 1
                bubsort(player1, SIZE);
                cout<<"Sorted array: "<<endl;
                print(player1, SIZE);
                
                //Selection sort the array of player 2
                select(player2, SIZE);
                cout<<"Sorted array: "<<endl;
                print(player2, SIZE);
                
                //Bubble sort the array of player 3
                bubsort(player3, SIZE);
                cout<<"Sorted array: "<<endl;
                print(player3, SIZE);
                
                //Binary search an array for a certain card the player is interested in viewing
                for(int i = 0; i <= 2; i++){
                    if(i == 1){
                        cout<<"Player 1 Enter a value to see in deck: ";
                        cin>>value;
                        result = search(player1, SIZE, value);
                        cout<<endl;
                        if(result == -1){
                            cout<<"Value does not exist in array."<<endl;
                        }
                        else{
                            cout<<"Value "<<value<<" found at position "<<result+1<<endl;
                        }
                    }
                    if(i == 2){
                        cout<<"Player 2 Enter a value to see in deck: ";
                        cin>>value;
                        result = search(player2, SIZE, value);
                        cout<<endl;
                        if(result == -1){
                            cout<<"Value does not exist in array."<<endl;
                        }
                        else{
                            cout<<"Value "<<value<<" found at position "<<result+1<<endl;
                        }
                    }
                    if(i == 2){
                        cout<<"Player 3 Enter a value to see in deck: ";
                        cin>>value;
                        result = search(player3, SIZE, value);
                        cout<<endl;
                        if(result == -1){
                            cout<<"Value does not exist in array."<<endl;
                        }
                        else{
                            cout<<"Value "<<value<<" found at position "<<result+1<<endl;
                        }
                    }
                }
                
                //Function to display the winner of the game
                total1 = total(player1, SIZE);
                total2 = total(player2, SIZE);
                total3 = total(player3, SIZE);
                if(total1 < total2){
                    cout<<"Player 1 value total is: "<<total1<<endl;
                    name = "player 1";
                    winner(total1, name);
                }
                else{
                    cout<<"Player 2 value total is: "<<total2<<endl;
                    name = "player 2";
                    winner(total2, name);
                }
                if(total3 < total1 && total3 < total2){
                    cout<<"Player 3 value total is: "<<total3<<endl;
                    name = "player 3";
                    winner(total3, name);
                    
                }
                
                //Function to calculate the square of the totals
                //Overloading
                grand = total1 + total2 + total3;
                intsqu = grand;
                squaref = grand/5;
                square(squaref);
                square(intsqu);
            
        }
        case 4:{ //Function to draw from deck and to have the players see two cards from deck.
                cout<<"Player 1 select a card to view: "<<endl;
                drawn(player1, SIZE);
                cout<<"Player 2 select a card to view: "<<endl;
                drawn(player2, SIZE);
                cout<<"Player 3 select a card to view: "<<endl;
                drawn(player3, SIZE); 
                cout<<"Player 4 select a card to view: "<<endl;
                drawn(player4, SIZE);
                
                
                //Function to swap a card within the player deck
                do{
                    used = used + 1;
                    cout<<"Player 1 Decision to swap a card: "<<endl;
                    change(player1, SIZE);
                    //Swap cards using by reference
                    cout<<"Player 2 Decision to swap a card: "<<endl;
                    change2(player2, SIZE);
                    cout<<"Player 3 Decision to swap a card: "<<endl;
                    change(player3, SIZE);
                    cout<<"Player 4 Decision to swap a card: "<<endl;
                    change(player4, SIZE);
                    turns = turns + 1;
                }while(turns != 9);
                
                //Function to find the average amount of cards left in the deck
                avg(used);
                average = avg(used);
                cout<<"Percent of cards used "<<setprecision(3)<<average*100<<"%"<<endl;
                
                //Function to create a parallel array
                para(player1, SIZE, player2);
                
                //Function to show the hands of the players
                cout<<"Player 1 hand: "<<endl;
                hand(player1, SIZE);
                cout<<"Player 2 hand: "<<endl;
                hand(player2, SIZE);
                cout<<"Player 3 hand: "<<endl;
                hand(player3, SIZE);
                cout<<"Player 4 hand: "<<endl;
                hand(player4, SIZE);
                
                //Bubble sort the array of player 1
                bubsort(player1, SIZE);
                cout<<"Sorted array: "<<endl;
                print(player1, SIZE);
                
                //Selection sort the array of player 2
                select(player2, SIZE);
                cout<<"Sorted array: "<<endl;
                print(player2, SIZE);
                
                //Bubble sort the array of player 3
                bubsort(player3, SIZE);
                cout<<"Sorted array: "<<endl;
                print(player3, SIZE);
                
                //Bubble sort the array of player 4
                bubsort(player4, SIZE);
                cout<<"Sorted array: "<<endl;
                print(player4, SIZE);
                
                //Binary search an array for a certain card the player is interested in viewing
                for(int i = 0; i <= 3; i++){
                    if(i == 1){
                        cout<<"Player 1 Enter a value to see in deck: ";
                        cin>>value;
                        result = search(player1, SIZE, value);
                        cout<<endl;
                        if(result == -1){
                            cout<<"Value does not exist in array."<<endl;
                        }
                        else{
                            cout<<"Value "<<value<<" found at position "<<result+1<<endl;
                        }
                    }
                    if(i == 2){
                        cout<<"Player 2 Enter a value to see in deck: ";
                        cin>>value;
                        result = search(player2, SIZE, value);
                        cout<<endl;
                        if(result == -1){
                            cout<<"Value does not exist in array."<<endl;
                        }
                        else{
                            cout<<"Value "<<value<<" found at position "<<result+1<<endl;
                        }
                    }
                    if(i == 2){
                        cout<<"Player 3 Enter a value to see in deck: ";
                        cin>>value;
                        result = search(player3, SIZE, value);
                        cout<<endl;
                        if(result == -1){
                            cout<<"Value does not exist in array."<<endl;
                        }
                        else{
                            cout<<"Value "<<value<<" found at position "<<result+1<<endl;
                        }
                    }
                    if(i == 3){
                        cout<<"Player 4 Enter a value to see in deck: ";
                        cin>>value;
                        result = search(player4, SIZE, value);
                        cout<<endl;
                        if(result == -1){
                            cout<<"Value does not exist in array."<<endl;
                        }
                        else{
                            cout<<"Value "<<value<<" found at position "<<result+1<<endl;
                        }
                    }
                }
                
                //Function to display the winner of the game
                total1 = total(player1, SIZE);
                total2 = total(player2, SIZE);
                total3 = total(player3, SIZE);
                total4 = total(player4, SIZE);
                if(total1 < total2){
                    cout<<"Player 1 value total is: "<<total1<<endl;
                    name = "player 1";
                    winner(total1, name);
                }
                else{
                    cout<<"Player 2 value total is: "<<total2<<endl;
                    name = "player 2";
                    winner(total2, name);
                }
                if(total3 < total1 && total3 < total2){
                    cout<<"Player 3 value total is: "<<total3<<endl;
                    name = "player 3";
                    winner(total3, name);
                }
                else if(total4 < total1 && total4 < total2 && total4 < total3){
                    cout<<"Player 4 value total is:  "<<total4<<endl;
                    name = "player 4";
                    winner(total4, name);
                }
                
                //Function to calculate the square of the totals
                //Overloading
                grand = total1 + total2 + total3 + total4;
                intsqu = grand;
                squaref = grand/5;
                square(squaref);
                square(intsqu);
            
        }
                
        
    }
    
    
    //Exit program!
    return 0;
}


void filcard(int array[], int a){
    int nline;
    fstream value;
    value.open("value.dat");
    nline = rand()%12+1;
    for(int line = 0; line <= nline; line++){
        value>>array[line];
    }
    value.close();
}

void drawn(int array[], int a){
    int card, seen, saw;
    saw = 0;
    while(saw <= 1){
        cout<<"Choose a card to see (1-4): ";
        cin>>card;;
        while(card < 1 || card > 4){
            cout<<"Error! choose a card 1-4 ";
            cin>>card;
        }
        for(int n = 0; n <= card; n++){
            seen = array[card-1];
        }
        saw = saw + 1;
        cout<<seen<<endl;
        cout<<endl;
    }
}

void print(int array[], int a){
    for(int i = 0; i <= a; i++){
        cout<<array[i]<<endl;
    }
    cout<<endl;
}

void change(int array[], int a){
    int temp, n;
    char choose;
    cout<<"Do you want to swap a card: (y/n): ";
    cin>>choose;
    if(choose == 'y'){
        temp = draw(temp);
        cout<<"The card drawn is a "<<temp<<endl;
        cout<<"Enter the card value to swap: ";
        cin>>n;
        array[a];
        for(int i = 0; i <= n; i++){
            array[n-1] = temp;
        }
        cout<<endl;
    }
    
}

void change2(int *array, int a){
    int temp, n;
    char choose;
    cout<<"Do you want to swap a card: (y/n): ";
    cin>>choose;
    if(choose == 'y'){
        temp = draw(temp);
        cout<<"The card drawn is a "<<temp<<endl;
        cout<<"Enter the card value to swap: ";
        cin>>n;
        array[a];
        for(int i = 0; i <= n; i++){
            array[n-1] = temp;
        }
        cout<<endl;
    }
}

int draw(int value){
    value = rand()%10+1;
    return value;
}

void para3(int array1[], int a, int array2[], int array3[], int array4[]){
    cout<<"Player 1 Deck: "<<"     "<<"Player 2 Deck: "<<"     "<<"Player 3 Deck: "<<"     "<<"Player 4 Deck: "<<endl;
    for(int i = 0; i <= a; i++){
        cout<<array1[i]<<setw(20)<array2[i]<<setw(20)<<array3[i]<<setw(20)<<array4[i]<<endl;
    }
    cout<<endl;
}

void para2(int array1[], int a, int array2[], int array3[]){
    cout<<"Player 1 Deck: "<<"     "<<"Player 2 Deck: "<<"     "<<"Player 3 Deck: "<<endl;
    for(int i = 0; i <= a; i++){
        cout<<array1[i]<<setw(20)<<array2[i]<<setw(20)<<array3[i]<<endl;
    }
    cout<<endl;
}

void para(int array1[], int a, int array2[]){
    cout<<"Player 1 Deck: "<<"     "<<"Player 2 Deck: "<<endl;
    for(int i =0; i <= a; i++){
        cout<<array1[i]<<setw(20)<<array2[i]<<endl;
    }
    cout<<endl;
}

float avg(float left, float unuse){
    float average;
    average = left/unuse;
    return average;
}

void square(float total){
    total*total;
    cout<<total<<endl;
}

void square(int total){
    pow(total, 2);
    cout<<total<<endl;
}

int hand(int array[], int a){
    string name;
    for(int i = 0; i <= a; i++){
        cout<<array[i]<<endl;
        if(array[i] == 10){
            int nline;
            fstream ten;
            ten.open("ten.dat");
            nline = rand()%4+1;
            for(int line = 0; line <= nline; line++){
                ten>>name;
            }
            if(name == "jack"){
                cout<<"The 10 card is a Jack"<<endl;
            }
            if(name == "queen"){
                cout<<"The 10 card is a Queen"<<endl;
            }
            if(name == "face"){
                cout<<"The 10 card is a Face"<<endl;
            }
            ten.close();
        }
    }
    cout<<endl;    
}

int total(int array[], int a){
    int total = 0;
    for(int i = 0; i <= a; i++){
        total = total + array[i];
    }
    return total;
}

void winner(int total, string name){
    fstream result;
    result.open("result.dat");
    result<<"Player "<<name<<" with "<<total<<endl;
    result.close();
}

void bubsort(int array[], int a){
    int temp;
    for(int i = 0; i <= a-1; i++){
        for(int j = 0; j <= a-i-1; j++){
            if(array[j] > array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void select(int array[], int a){
    for(int i = 0; i <= a; i++){
        for(int j = i+1; j <= a; j++){
            if(array[i] > array[j]){
                array[i] = array[i] + array[j];
                array[j] = array[i] - array[j];
                array[i] = array[i] - array[j];
            }
        }
    }
}

int search(int array[], int a, int val){
    int first = 0;
    int last = a - 1;
    int middle;
    int position = -1;
    bool found = false;
    while(!found && first <= last){
        middle = (first + last)/2;
        if(array[middle] == val){
            found = true;
            position = middle;
        }
        else if(array[middle] > val){
            last = middle - 1;
        }
        else{
            first = middle + 1;
        }
        return position;
    }
}