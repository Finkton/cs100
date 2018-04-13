#include <iostream>
#include <unistd.h> //for clear console
#include <stdlib.h> // for sleep
#include <string>
#include <math.h>
#include <windows.h>

using namespace std;

void ShowConsoleCursor(bool showFlag){	// funtion taken from, this hides the annoying cursor 
	//https://stackoverflow.com/questions/18028808/blinking-underscore-with-console
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}


int main() { 
	ShowConsoleCursor(false);
	
	//declaring the sun -------------------------------
	char Sun = 'O'; 
	double Sun_mass = 50;
	
	double Sun_x = 15;
	double Sun_y = 15;
	
	double Sun_vx = 0;
	double Sun_vy = 0;
	
	double Sun_fx = 0;
	double Sun_fy = 0;
	
	double Sun_ax = 0;
	double Sun_ay = 0;
	
	//declaring the earth -----------------------------
	char Earth = '.'; 
	double Earth_mass = 0.5;
	
	double Earth_x = 15;
	double Earth_y = 7;
	
	double Earth_vx = 2.5;
	double Earth_vy = 0;
	
	double Earth_fx = 0;
	double Earth_fy = 0;
	
	double Earth_ax = 0;
	double Earth_ay = 0;
	
	//other variables -----------------------------
	double radius_pow2; //radius squared
	double Force; //Force
	
	char Space[45][90]; //declaring the empty space (literally as space lol);
	for(int i = 0; i<45; i++)
		for (int j = 0; j<90; j++){
			Space[i][j]= ' ';// defining each characheer it to space
		}
		
	for(int i = 0; i<10000; i++){// iterating a 10000 times--------
		
		// redifing chars to space --------
		int x = static_cast<int>(Earth_x*1.5);
		int y = static_cast<int>(Earth_y*2*1.5);
		if(x>-1 && x<45 && y>-1 && y<90);
			Space[x][y] = ' ';
			
		x = static_cast<int>(Sun_x*1.5);
		y = static_cast<int>(Sun_y*2*1.5);
		if(x>-1 && x<45 && y>-1 && y<90);
			Space[x][y] = ' ';
			
		
		// finding radius and force (literally the same formulas as in the mechanics course)
		
		radius_pow2 = pow((Earth_x-Sun_x),2) + pow((Earth_y-Sun_y),2);
		Force = ( Earth_mass * Sun_mass) / radius_pow2;
		
		// finding earth's change in position
		
		Earth_fx = ( Force * (Sun_x-Earth_x) ) / sqrt(radius_pow2);
		Earth_fy = ( Force * (Sun_y-Earth_y) ) / sqrt(radius_pow2);
		
		Earth_ax = Earth_fx/Earth_mass; //ax = Fx / m
		Earth_ay = Earth_fy/Earth_mass; //ay = Fy / m
		
		Earth_vx = Earth_vx + Earth_ax; //vx = vx + Δt ax
		Earth_vy = Earth_vy + Earth_ay; //vy = vy + Δt ay
		
		Earth_x = Earth_x + Earth_vx; //px = px + Δt vx, 
		Earth_y = Earth_y + Earth_vy; //py = py + Δt vy, 
		
		// finding sun's change in position
		
		Sun_fx = ( Force * (Earth_x - Sun_x) ) / sqrt(radius_pow2);
		Sun_fy = ( Force * (Earth_y - Sun_y) ) / sqrt(radius_pow2);
		
		Sun_ax = Sun_fx/Sun_mass; //ax = Fx / m
		Sun_ay = Sun_fy/Sun_mass; //ay = Fy / m
		
		Sun_vx = Sun_vx + Sun_ax; //vx = vx + Δt ax
		Sun_vy = Sun_vy + Sun_ay; //vy = vy + Δt ay
		
		Sun_x = Sun_x + Sun_vx; //px = px + Δt vx, 
		Sun_y = Sun_y + Sun_vy; //py = py + Δt vy, 
		
		
		// defining charachters at the location of the sun and earth to be those repectively
		x = static_cast<int>(Earth_x*1.5);
		y = static_cast<int>(Earth_y*2*1.5);
		if(x>-1 && x<45 && y>-1 && y<90);
			Space[x][y] = Earth;
			
		x = static_cast<int>(Sun_x*1.5);
		y = static_cast<int>(Sun_y*2*1.5);
		if(x>-1 && x<45 && y>-1 && y<90);
			Space[x][y] = Sun;
		
		//printing
		cout<<"\nradius: "<<sqrt(radius_pow2);
		cout<<"\nnet force: "<<Force;
		cout<<"\nposition of earth: "<<Earth_x<<","<<Earth_y;
		cout<<"\nposition of sun: "<<Sun_x<<","<<Sun_y<<"\n";
		for(int i = 0; i<45; i++){
			for (int j = 0; j<90; j++){
				cout<<Space[i][j];
			}cout<<endl;
		}
		
		unsigned int microseconds=2000;
		usleep(microseconds); //sleep for this many micro seconds
		system("cls");
	}
	return 0;
}