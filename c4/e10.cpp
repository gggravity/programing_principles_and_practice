#include "../std_lib_facilities.h"

int main ()
{
  vector<char> hand = {'r', 'p', 's'};
  bool running = true;
  char player_hand;
  int player_score {0};
  int computer_score {0};

  while (running)
  {
	cout << "player: " << player_score
		 << " computer: " << computer_score << endl;
	cout << "Rock, Paper, Scissor [r/p/s]: " << endl;
	cin >> player_hand;

	srand(time(NULL));
	char computer_hand = hand[rand() % 3];

	switch (player_hand)
	{
	case 'r':
	  switch (computer_hand)
	  {
	  case 'r':
		cout << "ROCK vs. ROCK its a DRAW." << endl;
		break;
	  case 'p':
		cout << "ROCK vs. PAPER, you LOOSE." << endl;
		++computer_score;
		break;
	  case 's':
		cout << "ROCK vs. SCISSOR, you WIN." << endl;
		++player_score;
		break;
	  default:
		cerr << "Wrong input." << endl;
	  }
	  break;
	case 'p':
	  switch (computer_hand)
	  {
	  case 'r':
		cout << "PAPER vs. ROCK, you WIN." << endl;
		++player_score;
		break;
	  case 'p':
		cout << "PAPER vs. PAPER its a DRAW." << endl;
		break;
	  case 's':
		cout << "PAPER vs. SCISSOR, you LOOSE." << endl;
		++computer_score;
		break;
	  default:
		cerr << "Wrong input." << endl;
	  }
	  break;
	case 's':
	  switch (computer_hand)
	  {
	  case 'r':
		cout << "SCISSOR vs. ROCK, you LOOSE." << endl;
		++computer_score;
		break;
	  case 'p':
		cout << "SCISSOR vs. PAPER, you WIN." << endl;
		++player_score;
		break;
	  case 's':
		cout << "SCISSOR vs. SCISSOR, its a DRAW." << endl;
		break;
	  default:
		cerr << "Wrong input." << endl;
	  }
	  break;
	case 'q':
	  running = false;
	  break;
	default:
	  cerr << "Wrong input." << endl;
	}
  }
}