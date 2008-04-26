#include "deck.h"

Deck::Deck()
{
   
}

void Deck::CreateDeck()
{
	card c1('A', 'S');
    deck.push_back(c1);
    card c2('K', 'S');     // SPADE CARDS 
    deck.push_back(c1);
    card c3('Q', 'S');
    deck.push_back(c1);
    card c4('J', 'S');
    deck.push_back(c1);
    card c5('T', 'S');
    deck.push_back(c1);
    card c6('9', 'S');
    deck.push_back(c1);
    card c7('8', 'S');
    deck.push_back(c1);
    card c8('7', 'S');
    deck.push_back(c1);
    card c9('6', 'S');
    deck.push_back(c1);
    card c10('5', 'S');
    deck.push_back(c1);
    card c11('4', 'S');
    deck.push_back(c1);
    card c12('3', 'S');
    deck.push_back(c1);
    card c13('2', 'S');
    deck.push_back(c1);
    

    card c14('A', 'H');
    deck.push_back(c1);
    card c15('K', 'H');     // Heart CARDS 
    deck.push_back(c1);
    card c16('Q', 'H');
    deck.push_back(c1);
    card c17('J', 'H');
    deck.push_back(c1);
    card c18('T', 'H');
    deck.push_back(c1);
    card c19('9', 'H');
    deck.push_back(c1);
    card c20('8', 'H');
    deck.push_back(c1);
    card c21('7', 'H');
    deck.push_back(c1);
    card c22('6', 'H');
    deck.push_back(c1);
    card c23('5', 'H');
    deck.push_back(c1);
    card c24('4', 'H');
    deck.push_back(c1);
    card c25('3', 'H');
    deck.push_back(c1);
    card c26('2', 'H');
    deck.push_back(c1);


    card c27('A', 'C');
    deck.push_back(c1);
    card c28('K', 'C');     // CLUB CARDS 
    deck.push_back(c1);
    card c29('Q', 'C');
    deck.push_back(c1);
    card c30('J', 'C');
    deck.push_back(c1);
    card c31('T', 'C');
    deck.push_back(c1);
    card c32('9', 'C');
    deck.push_back(c1);
    card c33('8', 'C');
    deck.push_back(c1);
    card c34('7', 'C');
    deck.push_back(c1);
    card c35('6', 'C');
    deck.push_back(c1);
    card c36('5', 'C');
    deck.push_back(c1);
    card c37('4', 'C');
    deck.push_back(c1);
    card c38('3', 'C');
    deck.push_back(c1);
    card c39('2', 'C');
    deck.push_back(c1);

    
    card c40('A', 'D');
    deck.push_back(c1);
    card c41('K', 'D');     // Dimamond CARDS 
    deck.push_back(c1);
    card c42('Q', 'D');
    deck.push_back(c1);
    card c43('J', 'D');
    deck.push_back(c1);
    card c44('T', 'D');
    deck.push_back(c1);
    card c45('9', 'D');
    deck.push_back(c1);
    card c46('8', 'D');
    deck.push_back(c1);
    card c47('7', 'D');
    deck.push_back(c1);
    card c48('6', 'D');
    deck.push_back(c1);
    card c49('5', 'D');
    deck.push_back(c1);
    card c50('4', 'D');
    deck.push_back(c1);
    card c51('3', 'D');
    deck.push_back(c1);
    card c52('2', 'D');
    deck.push_back(c1);


}

void Deck::ShuffleCard()
{
	Clear();
	CreateDeck();
    srand( time(NULL) );
    random_shuffle(deck.begin(), deck.end());
}

void Deck::Clear()
{
    deck.clear();
}