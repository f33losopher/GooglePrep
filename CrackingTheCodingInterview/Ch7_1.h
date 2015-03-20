/*
 * Ch7_1.h
 *
 *  Created on: Mar 18, 2015
 *      Author: Felix
 */

#ifndef CH7_1_H_
#define CH7_1_H_

class queue;

struct Card {
	enum Suit {
		Heart =   1,
		Club =    1 << 1,
		Spade =   1 << 2,
		Diamond = 1 << 3
	};

	Card(int v, Suit s) : _value(v), _suit(s) {}

	int _value;
	Suit _suit;
};

class DeckOfCards {
public:
	DeckOfCards();

	const Card* card(int v, Card::Suit s) const;

	const Card* nextCard();

	void returnCard(int v, Card::Suit s);

	void shuffle();

private:
	static const int NUM_OF_CARDS = 52;
	static const int CARDS_PER_SUIT = 13;

	// Location of cards in memory
	Card* _cards;

	// Acts as top of the deck
	queue<Card*> _nextCards;
};


#endif /* CH7_1_H_ */
