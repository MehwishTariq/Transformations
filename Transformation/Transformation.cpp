#include "stdafx.h"
#include<iostream>

#include<SFML\Graphics.hpp>
using namespace std;
class object
{
private:
	int x[3], y[3];	//array for x and y to take 3 values for x and y and to get 3 values as well.
	int a = 0, b = 0, Sx = 0, Sy = 0;	//variables defined in matrices 
	double theta;
	//defining all transformation matrices
	int Tr[3][3] = { {1,0,a},{0,1,b},{0,0,1} };
	double R[3][3] = {{0,0,0},{0,0,0},{0,0,1}};
	int Mx[3][3] = { {1,0,0},{0,-1,0},{0,0,1} };
	int My[3][3] = { {-1,0,0},{0,1,0},{0,0,1} };
	int S[3][3] = { {Sx,0,0},{0,Sy,0 }, {0, 0, 1}};
	//defining matrix for inputed x and y values
	int P[3][3];
	//defining matrix for outputed x and y values
	int P_[3][3];
public:
	//taking three points to draw a triangle
	void setxy()
	{
		for (int i = 0;i < 3;i++)
		{
			cout << "Enter x coordinate of your object: ";
			cin >> x[i];
			cout << "Enter y coordinate of your object: ";
			cin >> y[i];
		}
		//initializing values in the 'P' matrix where these variables were defined
		for (int i = 0;i < 3;i++)
		{
			P[0][i] = x[i];
			P[1][i] = y[i];
			P[2][i] = 1;
		}		
		//printing P matrix
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				cout << P[i][j] << "\t";
			}
			cout << "\n";
		}
	}
	//taking ai and bj for translation
	void setTrans()
	{
		cout << "Enter 'ai' of your translated object: ";
		cin >> a;
		cout << "Enter 'bj' of your translated object: ";
		cin >> b;
		//initializing values in the 'Tr' matrix where these variables were defined
		Tr[0][2] = a;
		Tr[1][2] = b;
	}
	//Getting value of theta for rotation
	void setTheta()
	{
		cout << "Entezr angle to rotate your object: ";
		cin >> theta;
		theta = theta * 3.14 / 180;
		//initializing values in the 'R' matrix where these values are to be put
		R[0][0] = cos(theta);
		R[0][1] = sin(theta);
		R[1][0] = -sin(theta);
		R[1][1] = cos(theta);
	}
	//Getting scaling values of Sx and Sy
	void setScale()
	{
		cout << "Enter X coordinate of your scaled object: ";
		cin >> Sx;
		cout << "Enter Y coordinate of your scaled object: ";
		cin >> Sy;
		//initializing values in the 'S' matrix where these variables were defined
		S[0][0] = Sx;
		S[1][1] = Sy;
	}
	//getting x and y from array of x and y defined above
	int getx(int i)
	{
		return x[i];
	}
	int gety(int i)
	{
		return y[i];
	}
	//getting values of x' and y' from matrix
	int getx_(int i)
	{
		return P_[0][i];
	}
	int gety_(int i)
	{
		return P_[1][i];
	}
	//applying the transformation equation for translation of object
	void translate()
	{
		int count;
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				count = 0;
				for (int k = 0;k < 3;k++)
				{
					count = count + (Tr[i][k] * P[k][j]);
				}
				P_[i][j] = count;
				
			}		
		}
		//printing the values of x' and y' from P_[][] matrix 
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				cout << P_[i][j] << "\t";
			}
			cout << "\n";
		}
		
	}
	//applying the transformation equation for rotation of object
	void rotate()
	{
		int count;
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				count = 0;
				for (int k = 0;k < 3;k++)
				{
					count = count + (R[i][k] * P[k][j]);
				}
				P_[i][j] = count;
			}
		}
		//printing the values of x' and y' from P_[][] matrix 
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				cout << P_[i][j] << "\t";
			}
			cout << "\n";
		}
	}
	//applying the transformation equation for mirroring along X of object
	void mirrorX()
	{
		int count;
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				count = 0;
				for (int k = 0;k < 3;k++)
				{
					count = count + (Mx[i][k] * P[k][j]);
				}
				P_[i][j] = count;
			}
		}
		//printing the values of x' and y' from P_[][] matrix 
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				cout << P_[i][j] << "\t";
			}
			cout << "\n";
		}
	}
	//applying the transformation equation for mirroring along Y of object
	void mirrorY()
	{
		int count;
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				count = 0;
				for (int k = 0;k < 3;k++)
				{
					count = count + (My[i][k] * P[k][j]);
				}
				P_[i][j] = count;
			}
		}
		//printing the values of x' and y' from P_[][] matrix 
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				cout << P_[i][j] << "\t";
			}
			cout << "\n";
		}
	}
	//applying the transformation equation for scaling of object
	void scale()
	{
		int count;
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				count = 0;
				for (int k = 0;k < 3;k++)
				{
					count = count + (S[i][k] * P[k][j]);				
				}
				P_[i][j] = count;
			}			
		}
		//printing the values of x' and y' from P_[][] matrix 
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				cout << P_[i][j] << "\t";
			}
			cout << "\n";
		}
	}
	//asking for the choice of transformation by the user
	void choice()
	{
		int c;
		cout << "What do you want to do?" << "\nPress:\n1 for Translation\n" <<
			"2 for Rotation\n3 for Mirroring along x-axis\n 4 for Mirroring" <<
			" along y-axis\n5 for Scaling\n" << endl;
		cin >> c;
		switch (c)
		{
		case 1:
			//first taking input
			setTrans();
			//then applying the equation
			translate();
			break;
		case 2:
			//first taking input
			setTheta();
			//then applying the equation
			rotate();
			break;
		case 3:
			//applying the equation
			mirrorX();
			break;
		case 4:
			//applying the equation
			mirrorY();
			break;
		case 5:
			//first taking input
			setScale();
			//then applying the equation
			scale();
			break;
		default:
			cout << "Invalid";
			break;
		}
	}
};
int main()
{	
	sf::Event event;
	object o;
//asking for x and y values
	o.setxy();
	//choosing the transformation
	o.choice();
	//setting window size
	sf::RenderWindow window(sf::VideoMode(700, 600), "Box");
	//defining the object
	sf::ConvexShape triangle, triangle1;
	//defining the sides of a triangle
	triangle.setPointCount(3);
	//defining transformed triangle sides
	triangle1.setPointCount(3);
	//setting the color
	triangle.setFillColor(sf::Color::White);
	triangle1.setFillColor(sf::Color::Red);
	//putting values of each side
	for (int i = 0;i < 3;i++)
	{
		triangle.setPoint(i, sf::Vector2f(o.getx(i), o.gety(i)));
		triangle1.setPoint(i, sf::Vector2f(o.getx_(i), o.gety_(i)));
	}
		while (window.pollEvent(event))
		{
			while (window.isOpen())
			{
				//drawing the object
				window.clear();
				window.draw(triangle);
				window.draw(triangle1);
				window.display();
				if (sf::Event::Closed)
				{
					window.close();
				}
			}
		}	
}