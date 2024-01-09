#include "TAiPlayer.hpp"
#define MAX_P 100				//max liczba graczy w rankingu
class TPlayer_Wins {				//klasa do przechowywania rankingu 
public:
	std::string w_name;					//imie wygranego
	int wins;							//ilosc jego wygranych
	TPlayer_Wins();							//konstruktor domyslny
	TPlayer_Wins(std::string& playerName, int playerWins);	//konstruktor arguemntowy

};
class TGame {
private:
	bool end;						//czy gra sie skonczyla
	bool draw;						//czy remis
	THumanPlayer player;			//gracz
	THumanPlayer* ai;				//komputer
	
	TPlayer_Wins ranking[MAX_P];	// tablica zawierajaca ranking
	int ile_graczy;					//zawiera ilosc graczy w rankingu
public:
	
	std::string winner;				//kto wygral
	TPentagoBoard board;			//plansza gry
	TGame();						//konstruktor domyslny
	TGame(std::string nick, char znak); //konstruktor z nickiem i znakiem gracza
	void gameStart();				//przeprowadza gre
	void create_ranking();			//tworzy ranking i go sortuje
	void wypisz_ranking();			//wypisuje ranking
	void clear_ranking();			//sluzy by nie wypisywac tablicy podwojnie
	bool is_draw();					//getter pola draw
};



