
//card.hpp
#ifndef card_hpp
#define card_hpp

// distribution two cards to players and dealers to at the beginning
void DealHand(int cards[]);

//initiate players hand 
int playerhand( int cards[]);

//initiate dealers hand 
int dealerhand( int cards[]);

//hit action: drawing one card
int hit(int hand[5]);

#endif
