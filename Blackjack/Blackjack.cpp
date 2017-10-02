#include "Blackjack.h"

#include <list>


void print_winner(int pscore, int dscore)
{
	std::cout << "Your final score: " << pscore << std::endl;
	if (pscore > 21)
	{
		std::cout << "Bust, you lose.\n";
	}
	else if (pscore > dscore)
	{
		std::cout << "You win!\n";
	}
	else if (dscore > 21)
	{
		std::cout << "Dealer bust, you win\n";
	}
	else if (dscore > pscore)
	{
		std::cout << "Dealer scored higher, you lose\n";
	}
	else
	{
		std::cout << "It seems to be a draw\n";
	}
}


Blackjack::Blackjack()
	:Number_of_Decks(1), Number_of_Cards(52), d()
{
	// reserve deck space, make a standard deck of cards
	d.reserve(52);
	for (int i = 0; i < 52; ++i)
	{
		d.push_back(static_cast<Rank>(i % 13), static_cast<Suit>(i / 13));
	}
	// shuffle deck
	shuffle(d);
}

int Blackjack::evaluate_hand(Deck eval)
{
	int hand_score = 0;
	bool ace = false; // check for aces in hand
	for (auto c : eval)
	{
		hand_score += c.Blackjack_Value();
		if (c.rank == Ace)
		{ // if there is an ace in the hand, set bool for later use
			ace = true;
		}
	}
	// ace is valued at 11 depending on the value of the rest of the hand
	if (ace == true && hand_score <= 11)
	{
		hand_score += 10;
	}
	return hand_score;
}

void Blackjack::print_hand(Deck print_out)
{	// loops through entire vector of dealer/player hands
	for (auto c : print_out)
	{	// prints the proper prefix and punctuation for the card
		if (c != print_out.front() && c != print_out.back())
		{
			std::cout << ", ";
		}
		if (c == print_out.back() && print_out.size() > 1)
		{
			std::cout << " and ";
		}
		std::cout << "a";
		if (c.rank == Eight || c.rank == Ace)
		{
			std::cout << "n";
		}
		std::cout << " ";
		c.print_card(); // actually prints the Rank and Suit of the card
	}
}

void Blackjack::run_game()
{
	// create two decks for use in game
	std::vector<Deck> player;
	Deck add_to;
	player.push_back(add_to);
	Deck dealer;

	char ch;
	bool keep_playing = true;
	while (keep_playing == true)
	{
		for (int i = 0; i < 2; ++i) // deal two cards each to Player and Dealer
		{
			Card c1 = d.back();
			d.pop_back();
			dealer.push_back(c1);

			Card c2 = d.back();
			d.pop_back();
			//player.push_back(c2);
			player.front().push_back(c2);
		}
		// print contents of hand: nothing hidden
		std::cout << "Your hand: ";
		print_hand(player.front());
		std::cout << std::endl;

		std::cout << "Dealer hand: ";
		print_hand(dealer);
		std::cout << std::endl;

		// dealer turn - done automatically: gets a hand of a score 17 or greater
		int dealer_score = evaluate_hand(dealer);
		while (dealer_score < 17)
		{
			dealer.push_back(d.back());
			d.pop_back();
			dealer_score = evaluate_hand(dealer);
		}
		// print cards in dealer's hand and their score
		std::cout << "Dealer has finalized their hand.\n";
		if (dealer_score > 21)
		{
			std::cout << "Dealer has a bust, hand is ";
		}
		else
		{
			std::cout << "Dealer's hand is ";
		}
		print_hand(dealer);
		std::cout << " with a score of " << dealer_score << std::endl;
		
		// player turn
		for (int i = 0; i < player.size(); ++i)
		{
			bool hit = true;
			int player_score = evaluate_hand(player[i]);
			while (hit == true && player_score <= 21)
			{
				std::cout << "H for Hit, S for Stay.\n";
				std::cout << "Your current hand: ";
				print_hand(player[i]);
				std::cout << "\nCurrent score is " << player_score << std::endl;
				std::cin >> ch;
				if (ch == 'H' || ch == 'h')
				{ // give player another card
					player[i].push_back(d.back());
					d.pop_back();
					std::cout << "New card, ";
					player[i].back().print_card();
					std::cout << std::endl;
					player_score = evaluate_hand(player[i]);
					if (player_score > 21)
					{
						std::cout << "Your score is " << player_score << ", that's a bust!\n";
					}
				}
				else if (ch == 'S' || ch == 's')
				{ // keep current hand
					hit = false;
				}
			}
		}
		// score evaluation
		std::cout << "For this hand: \n";
		print_winner(evaluate_hand(player.front()), dealer_score);

		if (player.size() > 1)
		{
			std::cout << "For your other hand: \n";
			print_winner(evaluate_hand(player.back()), dealer_score);
		}

	}
}
