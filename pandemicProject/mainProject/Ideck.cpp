#include <vector>
#include <cstdlib>
#include <string>
#include<unordered_set>
#include "IDeck.h"
#include "ICard.h"
#include <time.h>
#include <cstdlib>
#include <fstream>
using namespace std;


void IDeck::buildDeck( vector<ICard*>& tmpDeck)
{
    srand((unsigned int)time(NULL));
    const time_t CARDS = 48;
    string infStr[CARDS]= {
        "Sydney","Bangkok","Tokyo","Manila","Beijing","Ho Chi Minh City","Hong Kong","Taipei",
        "Shanghai",    "Seoul","Osaka","Jakarta","Washington","St. Petersburg","Essen","Montreal","Chicago","Milan","San Francisco","Atlanta",
        "London","Paris","Madrid","New York","Miami","Mexico City","Los Angeles","Kinshasa","Lagos","Bogota","Lima","Santiago","Khartoum",
        "Sao Paulo","Buenos Aires","Johannesburg","Karachi","Istanbul","Delhi","Mumbai","Chennai","Moscow","Riyadh","Algiers","Baghdad","Kolkata",
        "Tehran","Cairo"};
    enum {red, yellow, blue, black};

    //
    //Total copy pasta, yo
    /* generate unordered set of random indices for cards id's */
    std::unordered_set<int> ids;
    std::unordered_set<int>::iterator iItr;
    while ( ids.size() < CARDS ) {
        int num = rand() % CARDS;
        ids.insert(num);
    }

    /* create Deck */
    //size_t ep = 0;
    iItr = ids.begin();
    int tempI;
    for ( size_t n = 0; n < CARDS; n++ ) {
        ICard* tmp;

        if(*iItr < 12)
            tempI = red;
        else if (*iItr < 24)
            tempI = blue;
        else if (*iItr < 36)
            tempI = yellow;
        else
            tempI = black;


        tmp = new ICard(infStr[*iItr], tempI);
        tmpDeck.push_back(tmp);
        ++iItr;
    }
}

/* Copypasta part deux */
ICard* IDeck::takeCard() {
    if ( deck.empty() ) {
        
        return NULL;
    }
    ICard* tmp;
    tmp = deck.front();                        //store front
    discard.push_back(tmp);                    //add it to discard
    deck.erase(deck.begin());                //remove from infected deck
    size--;                                    //reduce size of infected deck
    return tmp;
}

//Draws the bottom card from the deck (for epidemic)
ICard* IDeck::takeBottomCard()
{
    if (deck.empty() ){
        return NULL;
    }
    ICard* tmp;                                
    tmp = deck.back();                        //store bottom card
    discard.push_back(tmp);                    //discard it
    deck.pop_back();                        //remove it from the ideck
    size--;                                    //shrinkage
    return tmp;                                //return it
}

//
//Randomly places the discard pile at the top of the infection deck
void IDeck::shuffleDiscard()
{
    srand((unsigned int)time(NULL));        //lets get seedy
    ICard* ptr;
    while(!discard.empty())
    {
        int x = rand() % discard.size();    //random card in discard
        ptr = discard[x];                    //save a pointer
        deck.insert(deck.begin(),ptr);        //add it to the play deck
        discard.erase(discard.begin()+x);
        size++;
    }
}

void IDeck::saveGame(ofstream &fp) {
	//fp << "***** Infection Deck *****" << endl;
    fp << deck.size() << endl;
    for(int i = 0; i < int(deck.size()); i++) {
        fp << deck[i]->getName() << "," << deck[i]->getColor() << endl;
    }

    //fp << "***** Infection Discard Pile *****" << endl;
    fp << discard.size() << endl;
    for(int i = 0; i < int(discard.size()); i++) {
        fp << discard[i]->getName() << "," << discard[i]->getColor() << endl;
    }
}

void IDeck::loadGame(ifstream &fp) {
	string name,input,color;
	int deckSize;

	// Infection Deck
	std::getline(fp,input);
	deckSize = stoi(input);
	for(int i = 0; i < deckSize; i++) {
		std::getline(fp,name,',');
		std::getline(fp,color);
	    ICard* newCard = new ICard(name,stoi(color));
	    deck.push_back(newCard);
    }

	// Infection Discard Pile
	std::getline(fp,input);
	deckSize = stoi(input);
	for(int i = 0; i < deckSize; i++) {
		std::getline(fp,name,',');
		std::getline(fp,color);
	    ICard* newCard = new ICard(name,stoi(color));
	    discard.push_back(newCard);
    }
}