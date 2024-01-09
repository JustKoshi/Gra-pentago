#include "TPentagoBoard.hpp"

TPentagoBoard::TPentagoBoard() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j]='O';
			
		}
		
	}
}

TPentagoBoard::TPentagoBoard(TPentagoBoard& mk) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = mk.board[i][j];
		}

	}
}

void TPentagoBoard::wypisz() { //wypisanie stanu planszy
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			std::cout << board[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void TPentagoBoard::rotate_quater_clockwise(int quater) { //transpozycja macierzy potem zamiana kolumn skrajnych w cwiartce
	char temp='0';
	switch(quater){
	case 1:
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				temp = board[i][j];
				board[i][j] = board[j][i];
				board[j][i] = temp;
			}
		}

		for (int i = 0; i < 3; i++) {
			int j = 0;
			temp = temp = board[i][j];
			board[i][j] = board[i][2 + j];
			board[i][2 + j] = temp;

		}

		break;
	case 2:
		for (int i = 0; i < 3; i++) {
			for (int j = i+4 ; j < 6; j++) {
				temp = board[i][j];
				board[i][j] = board[j-3][i+3];
				board[j-3][i+3] = temp;
			}
		}

		for (int i = 0; i < 3; i++) {
			int j = 3;
			int temp = board[i][j];
			board[i][j] = board[i][2 + j];
			board[i][2 + j] = temp;
		}
		break;
	case 3:
		for (int i = 3; i < 6; i++) {
			for (int j = i - 2; j < 3; j++) {
				temp = board[i][j];
				board[i][j] = board[j+3][i-3];
				board[j+3][i-3] = temp;
			}
		}

		for (int i = 3; i < 6; i++) {
			int j = 0;
			temp = temp = board[i][j];
			board[i][j] = board[i][2 + j];
			board[i][2 + j] = temp;

		}

		break;
	case 4: 
		for (int i = 3; i < 6; i++) {
			for (int j = i + 1; j < 6; j++) {
				temp = board[i][j];
				board[i][j] = board[j][i];
				board[j][i] = temp;
			}
		}
		for (int i = 3; i < 6; i++) {
			int j = 3;
			temp = temp = board[i][j];
			board[i][j] = board[i][2 + j];
			board[i][2 + j] = temp;

		}
		break;

	}
}

void TPentagoBoard::rotate_quater_anticlockwise(int quater) { //wpierw zamiana kolumn skrajnych w cwiartce potem transpozycja macierzy
	char temp = '0';
	switch (quater) {
	case 1:
		for (int i = 0; i < 3; i++) {
			int j = 0;
			temp = temp = board[i][j];
			board[i][j] = board[i][2 + j];
			board[i][2 + j] = temp;

		}
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 3; j++) {
				temp = board[i][j];
				board[i][j] = board[j][i];
				board[j][i] = temp;
			}
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++) {
			int j = 3;
			int temp = board[i][j];
			board[i][j] = board[i][2 + j];
			board[i][2 + j] = temp;
		}
		for (int i = 0; i < 3; i++) {
			for (int j = i + 4; j < 6; j++) {
				temp = board[i][j];
				board[i][j] = board[j - 3][i + 3];
				board[j - 3][i + 3] = temp;
			}
		}
		break;
	case 3:

		for (int i = 3; i < 6; i++) {
			int j = 0;
			temp = temp = board[i][j];
			board[i][j] = board[i][2 + j];
			board[i][2 + j] = temp;

		}
		for (int i = 3; i < 6; i++) {
			for (int j = i - 2; j < 3; j++) {
				temp = board[i][j];
				board[i][j] = board[j + 3][i - 3];
				board[j + 3][i - 3] = temp;
			}
		}

		break;
	case 4:
		for (int i = 3; i < 6; i++) {
			int j = 3;
			temp = temp = board[i][j];
			board[i][j] = board[i][2 + j];
			board[i][2 + j] = temp;

		}
		for (int i = 3; i < 6; i++) {
			for (int j = i + 1; j < 6; j++) {
				temp = board[i][j];
				board[i][j] = board[j][i];
				board[j][i] = temp;
			}
		}
		break;
	}

}

bool TPentagoBoard::czy_wygrana(char znak_gracza) {
	for (int i = 0; i < M; i++) {
		int c_rzad = 0; 
		int c_columna = 0;
		for (int j = 0; j < M; j++) {
			if (board[i][j] == znak_gracza) {
				c_rzad++;
				if (c_rzad == 5)
					return true;
			}
			else {
				c_rzad = 0;
			}

			if (board[j][i] == znak_gracza) {
				c_columna++;
				if (c_columna == 5)
					return true;
			}
			else {
				c_columna = 0;
			}
		}
	}
	
	for (int i = 0; i < M - 4; i++) { // Sprawdzanie po przek¹tnej
		for (int j = 0; j < M - 4; j++) {
			bool na_skos1 = true;  // Od góry lewej do prawej dolnej
			bool na_skos2 = true;  // Od prawej góry do lewej dolnej
			for (int k = 0; k < 5; k++) {
				if (board[i + k][j + k] != znak_gracza) {
					na_skos1 = false;
				}
				if (board[i + k][j + 4 - k] != znak_gracza) {
					na_skos2 = false;
				}
			}
			if (na_skos1 || na_skos2)
				return true;
		}
	}

	return false;
}


int TPentagoBoard::make_move(Tmove ruch, char znak_gracza) { //umieszcza znak gracza w polu jesli jest to dozwolone
	int i = ruch.get_i();
	int j = ruch.get_j();
	if (board[i][j] == 'O') {
		board[i][j] = znak_gracza;
		return 1;
	}
	else
		return 0;
}

bool TPentagoBoard::is_full() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 'O')
				return false;
		}

	}
	return true;

}