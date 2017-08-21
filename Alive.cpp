#include <stdio.h>
#include <conio.h>
#include <windows.h>
bool gameover,hit=true;
void Setup();
void Draw();
void Logic();
void Enemy();
int height=10,width=30,y,x=0,wx=width,ex,ey,score=0,f=0;
char dir;
void Setup()// Intialization
{
	y=height/2-1;
	gameover=false;

}
void Input()// Method to take input
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'w':
					dir='w';
					break;
			case 's':
					dir = 's';
					break;
			case 'd':
					dir ='d';
					break;
			case 'x' :
					gameover=true;
					break;
		}
	}
}
void Draw()// Method to print
{	
	dir='c';
	system("cls");
	for(int j=0;j<height;j++)
	{
		if(j==0||j==height-1)
		{
			for(int i=0;i<width;i++)
			{
				printf ("#");
			}
		}
		if(j==ey)
		{
			for(int i=0;i<ex;i++)
			{
				if(x==1||y==ey)
				{
					hit=true;
					f++;
					Enemy();
				}
				else if(i==ex-1)
				printf("E");
				else if(i<ex)
				printf(" ");
			}
		}
		if(j==y)
		{
			printf("A");
			if(x==1)
			{
					for (int i=0;i<ex;i++)
					{
						printf(">");
																				
					}
					x=0;
			}
		}
		if(j<height-1&&j!=y) 
		printf("\n#");
		
	/*	if(j>0||j<height-1)
		{
			for(int k=0;k<wx;k++)
			{
				if(k==wx-1)
				printf("|");
				else
				printf(" ");
				Sleep(5);
			}
		}*/
		
	}
	printf("\n\n Score = %d",score);
}
void Logic()// Logic of the game.
{
	switch (dir)
	{
		case 'w' :
				y--;
				break;
		case 's' :
				y++;
				break;
		case 'd' :
				x++;
	}
	
}
void Enemy()//Generates Enemy at random y coordinate
{
	if(hit==true||ex==0)
	{
		system("cls");
		ex=width;
		ey=rand()%(2,height-1);
		if(hit==true)
		{
			if(f!=0)
			score+=10;
		}
		hit=false;
		if(ey==0)
		{
		hit=true;
		Enemy();
		}
	}
}
int main() //Execution of Methods
{
	Setup();
	while(!gameover)
	{
		Enemy();
		Draw();
		Input();
		Logic();
		ex--;
		Sleep(250);
		//wx--;
	}
	printf("Game Over.Your Score was %d",score);
	return  0;
}
