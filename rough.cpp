#include <iostream>
#include <windows.h>

using namespace std;    // std::cout, std::cin
/*
bit 0 - foreground blue
bit 1 - foreground green
bit 2 - foreground red
bit 3 - foreground intensity

bit 4 - background blue
bit 5 - background green
bit 6 - background red
bit 7 - background intensity
*/

int main(){
	const WORD colors[] = {
		0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
		0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	};

	HANDLE  hConsole;
	int k;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// you can loop k higher to see more color choices
	for(k = 1; k < 8; k++){
		// pick the colorattribute k you want
		SetConsoleTextAttribute(hConsole, colors[k]);
		cout << " " << endl;
	}
	return 0;
}