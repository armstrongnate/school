#include <time.h>
#include <iostream>
#include <vector>
#include "rectangle.h"
#include "circle.h"

class Board
{
public:
	Board();
		// set all 42 squares to empty
		// set current player (turn) to red.
	int GameOver();
		// Returns 0 if game still going, 1 if red wins, 2 if black wins, 3 on a draw.
		// for wins, check all 24 horizontal wins, all 21 vertical wins, all 24 diagonal wins
		// for a tie, check if there are no empty squares left.
	bool Draw();
		// Draw the board boundary
		// Draw the 42 squares as red, black, or empty
		// Draw the 7 drop boxes red or black, according to whose turn it is.
		// Maybe also print whose turn it is.

	void HandleMouseClick(double x, double y);
		// If the click is not in one of the 7 drop boxes, ignore and return
		// If the clicked on drop box is full, ignore and return
		// Update the appropriate board square from empty to red or black
		// toggle the current player

	bool DrawCircle(double x1, double y1);

	void DrawCircles();

	void CheckForWin(int row, int col);

	static int turn; // 1 for red, 2 for black
	static int pieces[8][7]; // 0 for empty, 1 for red, 2 for black
private:
	// Storing what is in each of the 42 squares: red, black, or empty

	// Current player: red or black
	std::vector<Rectangle*> v_lines;
	std::vector<Rectangle*> h_lines;
	std::vector<Circle*> circles;
};
