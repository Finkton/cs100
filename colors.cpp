#include <iostream>
#include <windows.h>   // WinApi header
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
int main()
{
  HANDLE  hConsole;
	int k;
	
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  // you can loop k higher to see more color choices
  for(k = 1; k < 255; k++)
  {
    // pick the colorattribute k you want
    SetConsoleTextAttribute(hConsole, k);
    cout << k << " I want to be nice today!" << endl;
  }
  
  cin.get(); // wait
  return 0;
}

// https://www.daniweb.com/programming/software-development/code/216345/add-a-little-color-to-your-console-text