# include "help.h"
# include <iostream>
# include <conio.h>
# include <stdio.h>
using namespace std;
int shape[8][8];
int score = 0;
void triangle(int x1, int y1) //creates a triangle
{
	x1 = x1 + 20;
	myLine(x1, y1, x1 - 20, y1 + 40, 6, 255, 6);
	myLine(x1, y1, x1 + 20, y1 + 40, 6, 255, 6);
	myLine(x1 - 20, y1 + 40, x1 + 20, y1 + 40, 6, 255, 6);
}
void circle(int x1, int y1) //creates a circle
{
	myEllipse(x1 + 40, y1 + 40, x1, y1, 249, 100, 249);
}
void cross(int x1, int y1)//makes a cross shape
{
	x1 = x1 + 5;
	myLine(x1, y1, x1 + 30, y1 + 40, 255, 0, 0);
	myLine(x1 + 30, y1, x1, y1 + 40, 255, 0, 0);
}
void diamond(int x1, int y1) //creates a dimond
{
	x1 = x1 + 20;
	myLine(x1, y1, x1 + 20, y1 + 20, 0, 0, 255);
	myLine(x1, y1, x1 - 20, y1 + 20, 0, 0, 255);
	myLine(x1, y1 + 40, x1 - 20, y1 + 20, 0, 0, 255);
	myLine(x1, y1 + 40, x1 + 20, y1 + 20, 0, 0, 255);
}
void square(int x1, int y1) //creates a square 
{
	myRect(x1, y1, x1 + 40, y1 + 40, 255, 128, 0);
}
void specialTriangle(int x1, int y1) //creates a special triangle
{
	x1 = x1 + 20;
	myLine(x1, y1, x1 - 20, y1 + 40, 6, 255, 6);
	myLine(x1, y1, x1 + 20, y1 + 40, 6, 255, 6);
	myLine(x1 - 20, y1 + 40, x1 + 20, y1 + 40, 6, 255, 6);
	myLine(x1, y1, x1, y1 + 40, 6, 255, 6);
}
void specialCircle(int x1, int y1)//creates a special circle
{
	myEllipse(x1 + 40, y1 + 40, x1, y1, 249, 100, 249);
	myLine(x1 + 20, y1, x1 + 20, y1 + 40, 249, 100, 249);
	myLine(x1, y1 + 20, x1 + 40, y1 + 20, 249, 100, 249);
}
void specialCross(int x1, int y1) // creates a special cross 
{
	x1 = x1 + 5;
	myLine(x1, y1, x1 + 30, y1 + 40, 255, 0, 0);
	myLine(x1 + 30, y1, x1, y1 + 40, 255, 0, 0);
	myLine(x1 + 15, y1, x1 + 15, y1 + 40, 255, 0, 0);
	myLine(x1, y1 + 20, x1 + 30, y1 + 20, 255, 0, 0);
}
void specialDiamond(int x1, int y1)//creates a special diamond
{
	x1 = x1 + 20;
	myLine(x1, y1, x1 + 20, y1 + 20, 0, 0, 255);
	myLine(x1, y1, x1 - 20, y1 + 20, 0, 0, 255);
	myLine(x1, y1 + 40, x1 - 20, y1 + 20, 0, 0, 255);
	myLine(x1, y1 + 40, x1 + 20, y1 + 20, 0, 0, 255);
	myLine(x1, y1, x1, y1 + 40, 0, 0, 255);
	myLine(x1 + 20, y1 + 20, x1 - 20, y1 + 20, 0, 0, 255);
}
void specialSquare(int x1, int y1)// creates a special square
{
	myRect(x1, y1, x1 + 40, y1 + 40, 255, 128, 0);
	myLine(x1 + 20, y1, x1 + 20, y1 + 40, 255, 128, 0);
	myLine(x1, y1 + 20, x1 + 40, y1 + 20, 255, 128, 0);
}
void specialstar(int x1, int y1) //collider shape
{
	x1 = x1 + 20;
	y1 = y1 - 5;
	myLine(x1, y1, x1 + 25, y1 + 50, 0, 255, 255);
	myLine(x1, y1, x1 - 25, y1 + 50, 0, 255, 255);
	myLine(x1 + 25, y1 + 50, x1 - 25, y1 + 20, 0, 255, 255);
	myLine(x1 - 25, y1 + 20, x1 + 25, y1 + 20, 0, 255, 255);
	myLine(x1 + 25, y1 + 20, x1 - 25, y1 + 50, 0, 255, 255);
}
void gridprint() //prints vertical/horizontal lines that makes the grid
{
	int row = 50, col = 50;
	for (int r = 0; r < 9; r++)
	{
		myLine(row, col, 690, col, 255, 255, 255);
		col = col + 80;
	}
	row = 50, col = 50;
	for (int c = 0; c < 9; c++)
	{
		myLine(row, col, row, 690, 255, 255, 255);
		row = row + 80;
	}
}
void setboard(int array[][8], bool flag) // creates a board and sets the grid with different integral values and add shapes
{
	int pos1 = 70/*x cordinate*/, pos2 = 70/*y cordinate*/;//starting position of board
	for (int row = 0; row < 8; row++)
	{
		for (int colum = 0; colum < 8; colum++)
		{
			if (flag == true)
			{
				array[row][colum] = int(rand() % 5);
			}
			if (array[row][colum] == 1)
				square(pos1, pos2);
			else if (array[row][colum] == 2)
				triangle(pos1, pos2);
			else if (array[row][colum] == 3)
				diamond(pos1, pos2);
			else if (array[row][colum] == 4)
				cross(pos1, pos2);
			else if (array[row][colum] == 0)
				circle(pos1, pos2);
			else if (array[row][colum] == 6)
				specialSquare(pos1, pos2);
			else if (array[row][colum] == 7)
				specialTriangle(pos1, pos2);
			else if (array[row][colum] == 5)
				specialCircle(pos1, pos2);
			else if (array[row][colum] == 8)
				specialDiamond(pos1, pos2);
			else if (array[row][colum] == 9)
				specialCross(pos1, pos2);
			else if (array[row][colum] == 10)
				specialstar(pos1, pos2);//collider
			pos1 = pos1 + 80;// x-axis position moves 80 units forward
		}
		pos1 = 70;//restart the position
		gridprint();//calls to print the grid
		pos2 = pos2 + 80;//y-axis position moves 80 units down
	}
}
void cursor(int pos1/*x coordinate*/, int pos2/*y coordinate*/, int color, int color2) //prints cursor
{
	myLine(pos1, pos2, pos1, pos2 + 80, color2, color2, color);
	myLine(pos1, pos2, pos1 + 80, pos2, color2, color2, color);
	myLine(pos1 + 80, pos2 + 80, pos1, pos2 + 80, color2, color2, color);
	myLine(pos1 + 80, pos2 + 80, pos1 + 80, pos2, color2, color2, color);
}
bool check(int array[][8], int shape, int row, int colum, int button, int& where/*indicates if left || right || up || down swap possible*/)//checks if swapping of shapes arer possible
{
	bool flag1 = false;
	bool flag = false;
	int leftshape = array[row][colum - 1];
	int rightshape = array[row][colum + 1];
	int upshape = array[row - 1][colum];
	int downshape = array[row + 1][colum];
	if (button == 1)//left button pressed
	{
		if ((leftshape % 5) == (array[row][colum + 1] % 5) && leftshape % 5 == array[row][colum + 2] % 5 || shape % 5 == array[row][colum - 2] % 5 && shape % 5 == array[row][colum - 3] % 5 || shape % 5 == array[row + 1][colum - 1] % 5 && shape % 5 == array[row + 2][colum - 1] % 5 || shape % 5 == array[row - 1][colum - 1] % 5 && shape % 5 == array[row + 1][colum - 1] % 5 || shape % 5 == array[row - 1][colum - 1] % 5 && shape % 5 == array[row - 2][colum - 1] % 5 || leftshape % 5 == array[row + 2][colum] % 5 && leftshape % 5 == array[row + 1][colum] % 5 || leftshape % 5 == array[row - 1][colum] % 5 && leftshape % 5 == array[row - 2][colum] % 5 || leftshape % 5 == array[row][colum - 1] % 5 && leftshape % 5 == array[row][colum + 1] % 5)
		{
			flag = true;//if all possible conditions are satisfied then shapes are swapped to the left
			where = 1;//indicates that swap is done to the left
		}
	}
	else if (button == 3)//right button pressed
	{
		if (shape % 5 == array[row][colum + 2] % 5 && shape % 5 == array[row][colum + 3] % 5 || rightshape % 5 == array[row][colum - 1] % 5 && rightshape % 5 == array[row][colum - 2] % 5 || shape % 5 == array[row + 1][colum + 1] % 5 && shape % 5 == array[row + 2][colum + 1] % 5 || shape % 5 == array[row - 1][colum + 1] % 5 && shape % 5 == array[row - 2][colum + 1] % 5 || rightshape % 5 == array[row + 1][colum] % 5 && rightshape % 5 == array[row + 2][colum] % 5 || rightshape % 5 == array[row - 1][colum] % 5 && rightshape % 5 == array[row + 1][colum] % 5 || shape % 5 == array[row + 1][colum + 1] % 5 && shape % 5 == array[row - 1][colum + 1] % 5 || rightshape % 5 == array[row - 1][colum] % 5 && rightshape % 5 == array[row - 2][colum] % 5)
		{
			flag = true;//if all possible conditions are satisfied then shapes are swapped to the right
			where = 3;//indicates that swap is done to the right
		}
	}
	else if (button == 2)
	{
		if (shape % 5 == array[row - 2][colum] % 5 && shape % 5 == array[row - 3][colum] % 5 || upshape % 5 == array[row + 1][colum] % 5 && upshape % 5 == array[row + 2][colum] % 5 || shape % 5 == array[row - 1][colum + 1] % 5 && shape % 5 == array[row - 1][colum + 2] % 5 || shape % 5 == array[row - 1][colum - 1] % 5 && shape % 5 == array[row - 1][colum - 2] % 5 || upshape % 5 == array[row][colum + 1] % 5 && upshape % 5 == array[row][colum + 2] % 5 || upshape % 5 == array[row][colum - 1] % 5 && upshape % 5 == array[row][colum - 2] % 5 || shape % 5 == array[row - 1][colum - 1] % 5 && shape % 5 == array[row - 1][colum + 1] % 5 || upshape % 5 == array[row][colum - 1] % 5 && upshape % 5 == array[row][colum + 1] % 5)
		{
			flag = true;//if all possible conditions are satisfied then shapes are swapped up
			where = 2;//indicates that swap is done upwards
		}
	}
	else if (button == 4)
	{
		if (shape % 5 == array[row + 2][colum] % 5 && shape % 5 == array[row + 3][colum] % 5 || downshape % 5 == array[row - 1][colum] % 5 && downshape % 5 == array[row - 1][colum] % 5 || shape % 5 == array[row + 1][colum - 1] % 5 && shape % 5 == array[row + 1][colum - 2] % 5 || downshape % 5 == array[row][colum - 1] % 5 && downshape % 5 == array[row][colum - 2] % 5 || shape % 5 == array[row + 1][colum + 1] % 5 && shape % 5 == array[row + 1][colum + 2] % 5 || downshape % 5 == array[row][colum + 1] % 5 && downshape % 5 == array[row][colum + 2] % 5 || shape % 5 == array[row + 1][colum - 1] % 5 && shape % 5 == array[row + 1][colum + 1] % 5 || downshape % 5 == array[row][colum - 1] % 5 && downshape % 5 == array[row][colum + 1] % 5)
		{
			flag = true;//if all possible conditions are satisfied then shapes are swapped down
			where = 4;//indicates that swap is done downwards
		}
	}
	return flag;
}
void collider()//if special gem exsists grid values change
{
	for (int r1 = 0; r1 < 8; r1++)
	{
		for (int c1 = 0; c1 < 8; c1++)
		{
			if (shape[r1][c1] == 10)
			{
				shape[r1][c1] = -1;
				for (int r = 0; r < 8; r++)
				{
					shape[r][c1] = -1;
				}
				for (int c = 0; c < 8; c++)
				{
					shape[r1][c] = -1;
				}
			}
		}
	}

}
void deleteshape()//delete shapes if matched
{
	bool flag = false;
	int whatshape = -1;
	/*nested loop below check horizontal*/
	for (int r = 0; r < 8; r++)//r=rows of grid
	{
		for (int x = 0; x < 8; x++)//x=colums of grid
		{
			int c = x;
			if (shape[r][c] % 5 == shape[r][c + 1] % 5 && shape[r][c + 1] % 5 == shape[r][c + 2] % 5 && shape[r][c + 2] % 5 == shape[r][c + 3] % 5 && shape[r][c + 3] % 5 == shape[r][c + 4] % 5 && (c + 1 && c + 2 && c + 3 && c + 4) < 8)//check for 5 consecitive shapes
			{
				whatshape = shape[r][c];//indicates where special gem should be placed
				shape[r][c + 1] = -1;
				shape[r][c + 2] = -1;
				shape[r][c + 3] = -1;
				shape[r][c + 4] = -1;
				flag = true;
				score = score + 20;
			}
			if (shape[r][c] % 5 == shape[r][c + 1] % 5 && shape[r][c + 1] % 5 == shape[r][c + 2] % 5 && shape[r][c + 2] % 5 == shape[r][c + 3] % 5 && (c + 1 && c + 2 && c + 3) < 8)//checks for 3 cosecitive 
			{
				whatshape = shape[r][c];//indicates where special gem should be placed
				shape[r][c + 1] = -1;
				shape[r][c + 2] = -1;
				shape[r][c + 3] = -1;
				score = score + 10;
			}
			else if (shape[r][c] % 5 == shape[r][c + 1] % 5 && shape[r][c + 1] % 5 == shape[r][c + 2] % 5 && (c + 1 && c + 2) < 8)
			{
				shape[r][c] = -1;
				shape[r][c + 1] = -1;
				shape[r][c + 2] = -1;
				score = score + 5;
			}
			if (whatshape != -1)//places special gems in the grid
			{
				if (whatshape == 0)
					shape[r][c] = 5; //special gem circle
				else if (whatshape == 1)
					shape[r][c] = 6; //special gem square
				else if (whatshape == 2)
					shape[r][c] = 7; //special gem triangle
				else if (whatshape == 3)
					shape[r][c] = 8; //special gem diamond
				else if (whatshape == 4)
					shape[r][c] = 9; //special gem cross
				if (flag == true)
					shape[r][c] = 10;
			}
			whatshape = -1;
		}
	}
	flag = false;
	whatshape = -1;
	/*nested loop below check vertically*/
	for (int c = 0; c < 8; c++)
	{
		for (int x = 0; x < 8; x++)
		{
			int r = x;
			if (shape[r][c] % 5 == shape[r + 1][c] % 5 && shape[r + 1][c] % 5 == shape[r + 2][c] % 5 && shape[r + 2][c] % 5 == shape[r + 3][c] % 5 && shape[r + 3][c] % 5 == shape[r + 4][c] % 5 && (r + 1 && r + 2 && r + 3 && r + 4) < 8)//check for 5 consecitive shapes
			{
				whatshape = shape[r][c];//indicates where special gem should be placed
				shape[r][c + 1] = -1;
				shape[r][c + 2] = -1;
				shape[r][c + 3] = -1;
				shape[r][c + 4] = -1;
				flag = true;
				score = score + 20;
			}
			if (shape[r][c] % 5 == shape[r + 1][c] % 5 && shape[r + 1][c] % 5 == shape[r + 2][c] % 5 && shape[r + 2][c] % 5 == shape[r + 3][c] % 5 && (r + 1 && r + 2 && r + 3) < 8)
			{
				whatshape = shape[r][c];//indicates where special gem should be placed
				shape[r + 1][c] = -1;
				shape[r + 2][c] = -1;
				shape[r + 3][c] = -1;
				score = score + 10;
			}
			else if (shape[r][c] % 5 == shape[r + 1][c] % 5 && shape[r + 1][c] % 5 == shape[r + 2][c] % 5 && (r + 1 && r + 2) < 8)
			{
				shape[r][c] = -1;
				shape[r + 1][c] = -1;
				shape[r + 2][c] = -1;
				score = score + 5;
			}
			if (whatshape != -1)//places special gems in the grid
			{
				if (whatshape == 0)
					shape[r][c] = 5; //special gem circle
				else if (whatshape == 1)
					shape[r][c] = 6; //special gem square
				else if (whatshape == 2)
					shape[r][c] = 7; //special gem triangle
				else if (whatshape == 3)
					shape[r][c] = 8; //special gem diamond
				else if (whatshape == 4)
					shape[r][c] = 9; //special gem cross
				if (flag == true)
					shape[r][c] = 10;
			}
			whatshape = -1;
		}
	}
	collider();
	for (int i = 0; i < 8; i++)//this loop deletes the shape by placing -1 in their position
	{
		for (int j = 0; j < 8; j++)
		{
			if (shape[i][j] == -1)
			{
				for (int k = i; k > 0; k--)
				{
					shape[k][j] = shape[k - 1][j];
				}
				shape[0][j] = rand() % 5;
			}
		}
	}

}
void swapshapes(int array[][8], int pos1, int pos2, int button)
{
	int whereswap;//indicates at which side of shape swapping is possible
	int temp = 0;
	pos1 = (pos1 - 50) / 80;//converts x-axis cordinates to array index 
	pos2 = (pos2 - 50) / 80;//converts x-axis cordinates to array index 
	temp = array[pos2][pos1];//shape that has been clicked by user is checked 
	bool flag = check(shape, temp, pos2, pos1, button, whereswap);//calls check function that checks if swapping is possible
	if (button == 1 || button == 3)//if left or right key pressed
	{
		if (flag == true)//returned value by function(check)
		{//if true the swapp shapes
			if (whereswap == 1)
			{
				array[pos2][pos1] = array[pos2][pos1 - 1];
				array[pos2][pos1 - 1] = temp;

			}
			else if (whereswap == 3)
			{
				array[pos2][pos1] = array[pos2][pos1 + 1];
				array[pos2][pos1 + 1] = temp;
			}
		}
	}
	if (button == 2 || button == 4)//if up or down key preesed
	{
		if (whereswap == 2)
		{
			array[pos2][pos1] = array[pos2 - 1][pos1];
			array[pos2 - 1][pos1] = temp;
		}
		else if (whereswap == 4)
		{
			array[pos2][pos1] = array[pos2 + 1][pos1];
			array[pos2 + 1][pos1] = temp;
		}
	}
}
void select(int key)
{
	int cord1 = 50/*x-cordinate of grid*/, cord2 = 50/*y-cordinate of grid*/;
	bool check = 0;
	int button = 0;//which button is pressed
	while (true)
	{
		cursor(cord1, cord2, 0, 255);//calls cursor that moves on the grid
		check = isCursorKeyPressed(key);
		if (check == 1)
		{
			deleteshape();//delete shapes in grid
			if (key == 1)//if left arrow key pressed cursor moves to the left
			{
				cord1 = cord1 - 80;//x coordinates of cursor changes
				if (cord1 >= 50 && cord1 <= 640)
				{
					cursor(cord1, cord2, 0, 255);
					cursor(cord1 + 80, cord2, 255, 255);
				}
				else
					cord1 = 50;
			}
			else if (key == 3) //if right arrow key pressed cursor moves to the right
			{
				cord1 = cord1 + 80;//x cordinates of cursor changes
				if (cord1 >= 50 && cord1 <= 640)
				{
					cursor(cord1, cord2, 0, 255);
					cursor(cord1 - 80, cord2, 255, 255);
				}
				else
					cord1 = cord1 - 80;
			}
			else if (key == 2)//if up arrow key pressed cursor moves up
			{
				cord2 = cord2 - 80;//y cordinate changes
				if (cord2 >= 50 && cord2 <= 640)
				{
					cursor(cord1, cord2, 0, 255);
					cursor(cord1, cord2 + 80, 255, 255);
				}
				else
					cord2 = cord2 + 80;
			}
			else if (key == 4)//if down arrow key pressed cursor moves dwon
			{
				cord2 = cord2 + 80;//y coordinate changes
				if (cord2 >= 50 && cord2 <= 640)
				{
					cursor(cord1, cord2, 0, 255);
					cursor(cord1, cord2 - 80, 255, 255);
				}
				else
					cord2 = cord2 - 80;
			}
			else if (key == 5)//enter key pressed
			{
				Beep(1200, 200); // 523 hertz (C5) for 500 milliseconds     
				cin.get(); // wait
				button = 0;
				bool enteragain = true;
				while (enteragain == true)
				{
					cursor(cord1, cord2, 255, 0);//cusror position locks
					check = isCursorKeyPressed(key);//allow cusror to move in resticted area
					if (check == 1)
					{
						if (key == 5)//checks if enter is clicked again
						{
							cursor(cord1, cord2, 0, 255);//unlocks cursor 
							swapshapes(shape, cord1, cord2, button);//swapping done
							system("CLS");//screen is cleared
							setboard(shape, false);//new grid printed with changed swapped shapes
							button = 0;
							enteragain = false;//used to terminate the while loop
							deleteshape();//after swapping consecitive shape delete
							system("CLS");//console screen is cleared
							setboard(shape, false);//new shapes are added
							cout << score;
							Beep(2000, 300); // 523 hertz (C5) for 500 milliseconds     
							cin.get(); // wait
						}
						else if (key == 1)//left key pressed
						{
							if (cord1 >= cord1 - 80 && (cord1 - 80 >= 50))
							{
								button = 1;
								cursor(cord1 - 80, cord2, 255, 0);
								if (cord1 + 80 <= 610)
									cursor(cord1 + 80, cord2, 255, 255);
							}
						}
						else if (key == 3)//right key pressd
						{

							if (cord1 <= cord1 + 80 && (cord1 + 80) <= 610)
							{
								button = 3;
								cursor(cord1 + 80, cord2, 255, 0);
								if (cord1 - 80 >= 50)
									cursor(cord1 - 80, cord2, 255, 255);
							}
						}
						else if (key == 2) //up key pressed
						{
							if ((cord2 - 80) >= 50 && (cord2 - 80) <= cord2)
							{
								button = 2;
								cursor(cord1, cord2 - 80, 255, 0);
								if (cord2 - 80 <= 50 && cord2 - 80 <= 610)
									cursor(cord1, cord2 + 80, 255, 255);
							}
						}
						else if (key == 4) //down key pressed
						{
							if ((cord2 + 80) <= 610 && (cord2 + 80) >= cord2)
							{
								button = 4;
								cursor(cord1, cord2 + 80, 255, 0);
								if (cord2 + 80 <= 610 && cord2 - 80 >= 50)
									cursor(cord1, cord2 - 80, 255, 255);
							}
						}
					}
				}
			}
		}

	}
}

int main()
{
	int num = 0, key = 0;
	deleteshape();
	setboard(shape, true);
	select(key);
}