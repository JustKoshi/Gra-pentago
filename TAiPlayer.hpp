#include "THumanPlayer.hpp"
#include <ctime>
#include <cstdlib>
class TAiPlayer : public THumanPlayer {
public:
	TAiPlayer();								//konstruktor domyslny ustawia nick oraz znak na domyslny
	TPentagoBoard makeMove(TPentagoBoard board); //komputere losuje ruchy decyzje o ruchu
	TPentagoBoard rotate_quater(TPentagoBoard board); //komputer losuje cwiartke i ja obraca
};