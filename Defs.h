#pragma once

#define NoOfRegions 4
#define MaxDistance  60         // the maximum distance between any enemy and its tower
#define MinDistance  2          // the minimum distance between any enemy and its tower
#define MaxVerticalEnemies  15   // the maximum number of enemies that can be drawn
		                        // if they are in the same region and same distance
								// (will be drawn vertical to each other)
#define MaxEnemyCount 300       // the maximum number of enemies the application can work on
//#define TowerInitHealth 200 It is given in the input file.

//The four regions: A, B, C , and D
enum REGION {	
	A_REG,
	B_REG,
	C_REG,
	D_REG
};

enum ENEMY
{
	fighter,
	healer,
	freezer
};

enum State
{
	inactive,
	active,
	frozen, 
	killed
};




enum MenuItem
{
	//Note: menu icons are ordered here as they appear in menu
	//If you want to change the menu icons order, change the order here

	MENU_LOAD,
	MENU_EXIT,

	//TODO: Add more items names here
	//      for the 3 modes of the application
				
	MENU_ITM_COUNT	//no. of menu icons ==> This should be the last line in this enum
};

struct Point
{
	int x;
	int y;
	Point(int a=0, int b=0)	//constructor
	{ x=a;	y=b;	}
};