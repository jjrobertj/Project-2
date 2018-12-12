/* 
 * File:   main.cpp
 * Author: Jrrobert Jabonillo
 * Created on December 7, 2018, 12:53 PM
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
#include <vector>
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
const int COLS = 2, ROWS = 4;
void tworay(int[][COLS], int);
float avg(float, float unuse = 52);
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
    int cards = 52;
    float used = 0;
    string name;
    char knock;
    char start;
    int value;
    int number;
    int turns;
    int result;
    int total1, total2, total3, total4;
    int player1[SIZE+1];
    int player2[SIZE+1];
    int player3[SIZE+1];
    int player4[SIZE+1];
    vector<int> over(cards);
    
    //Initialize variables
    total1 = 0;
    total2 = 0;
    total3 = 0;
    total4 = 0;
    turns = 0;
    
    //Function to allow player to want to play the game or exit the game
    
    cout<<"Welcome to the card game known as Golf! The objective of the game is to obtain the hand with the lowest value of cards."<<endl;
    cout<<endl;
    cout<<"The Rules: One card is drawn from the deck. Cards are valued from 0-10, king is a zero, Ace is 1 point, numeral cards are valued at their card number. Jack or Queen are 10 points! Cards that are equal will cancel each other out!"<<endl;
    cout<<endl;
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
    
    //Randomly fills the deck of players
    filcard(player1, SIZE);
    filcard(player2, SIZE);
    filcard(player3, SIZE);
    filcard(player4, SIZE);
    
    //Test if the array is filled
    print(player1, SIZE);
    print(player2, SIZE);
    cout<<endl;
    
    
    //Function that will allow the player to see two cards from deck
    drawn(player1, SIZE);
    drawn(player2, SIZE);
    
    //Function to show the hand of the players
    hand(player1, SIZE);
    hand(player2, SIZE);
    
    
    //Function to swap a card within the player deck
    //loop players swapping cards
    change(player1, SIZE);
    //Swap cards using by reference
    change2(player2, SIZE);
    print(player1, SIZE);
    print(player2, SIZE);
    
    //Function to create a parallel array
    para(player1, SIZE, player2);
    
    //Function to create a 2-dimensional array
    
    
    //Bubble sort the array of player 1
    bubsort(player1, SIZE);
    print(player1,SIZE);
    
    //Selection sort the array of player 2
    select(player2, SIZE);
    print(player2, SIZE);
    
    //Binary search the array for a certain card the player is interested in viewing
    cout<<"Player 1 Enter a value to see in deck: ";
    cin>>value;
    result = search(player1, SIZE,value);
    cout<<endl;
    if(result == -1){
        cout<<"Value does not exist in array."<<endl;
    }
    else{
        cout<<"Value "<<value<<" found at position "<<result+1<<endl;
    }
    
    //Function to find the average amount of cards left in the deck
    avg(used);
    average = avg(used);
    cout<<average<<endl;
    
    //Function to display the winner of the game
    total1 = total(player1, SIZE);
    total2 = total(player2, SIZE);
    if(total1 < total2){
        name = "player 1";
        winner(total1,name);
    }
    else{
        name = "player 2";
        winner(total2,name);
    }
    //Delete memory
    
    
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
        cout<<"Enter the card value to swap: ";
        cin>>n;
        array[a];
        temp = draw(temp);
        cout<<temp<<endl;
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
        cout<<"Enter the card value to swap: ";
        cin>>n;
        array[a];
        temp = draw(temp);
        cout<<temp<<endl;
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

int hand(int array[], int a){
    string name;
    for(int i = 0; i <= a; i++){
        array[i];
        if(array[i] == 10){
            int nline;
            fstream ten;
            ten.open("ten.dat");
            nline = rand()%4+1;
            for(int line = 0; line <= nline; line++){
                ten>>name;
            }
            if(name == "jack"){
                cout<<"Jack"<<endl;
            }
            if(name == "queen"){
                cout<<"Queen"<<endl;
            }
            if(name == "face"){
                cout<<"Face"<<endl;
            }
            ten.close();
        }
    }    
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