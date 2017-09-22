#pragma once


struct Options
{
	bool ace_high = true;
	int num_sacrifice = 1;
	bool negootiable_sacrifice = true;
	int num_decks = 1;
};
struct Game
{
	void step();
	void run();


	Options options;
	Deck deck;
	Player p1;
	Player p2;
	Pile pile;
	int turn;
};