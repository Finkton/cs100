#include <iostream>
#include <windows.h>   // WinApi header
using namespace std;    // std::cout, std::cin
int main()
{
	//0 = Black	8 = Gray
	//1 = Blue	9 = Light Blue
	//2 = Green a = Light Green
	//3 = Aqua	b = Light Aqua
	//4 = Red	c = Light Red
	//5 = Purple	d = Light Purple
	//6 = Yellow	e = Light Yellow
	//7 = White	f = Bright White

	//you put two characters, first one is background color, second is text color:
	system("color 87"); //colors background to light red, with black text
	  
	cin.get(); // wait
	return 0;
}
