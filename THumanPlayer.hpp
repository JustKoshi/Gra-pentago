#ifndef THUMANPLAYER_HPP
#define THUMANPLAYER_HPP

#include "Tmove.hpp"
#include "TPentagoBoard.hpp"
#include <string>
class THumanPlayer: public Tmove {
protected:
	std::string nickname;					//nickname gracza
	char znak_gracza;					//znak pojawiajacy sie na planszy
	Tmove ruch;						//przechowuje wybor ruchu gracza 
public:
	THumanPlayer();							//konstruktor domyslny ustawia nick oraz znak na domyslny
	THumanPlayer(std::string nick, char znak);			//konstruktor z argumentami 
	virtual TPentagoBoard makeMove(TPentagoBoard board);	//gracz podejmuje decyzje o ruchu
	virtual TPentagoBoard rotate_quater(TPentagoBoard board);	//gracz wybiera cwiartke i ja obraca
	std::string get_name();
	char get_znak();										//odpowiednie gettery
	void set_nickname(std::string new_nick);
	void set_znak(char znak);							//odpowiednie settery

};

#endif 