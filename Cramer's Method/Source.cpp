#include <iostream>
#include <string>

using namespace std;

static double A[2][3] = { 0 };

string s = "solution = > \n";
string sx = "x = ";
string sy = "\ty = ";

void Input()
{
	
	cout << "enter corresponding matrix:" << endl;
	cout << "a1 = "; cin >> A[0][0];
	cout << "b1 = "; cin >> A[0][1];
	cout << "c1 = "; cin >> A[0][2];
	cout << "a2 = "; cin >> A[1][0];
	cout << "b2 = "; cin >> A[1][1];
	cout << "c2 = "; cin >> A[1][2];
	cout << "entered system :" << endl << A[0][0] << "*x+" << A[0][1] << "*y=" << A[0][2] << endl << A[1][0] << "*x+" << A[1][1] << "*y=" << A[1][2] << endl;
}

int main()
{
	int sw = 0;
	while (sw != -1)
	{
		cout << "|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_|_" << endl;
		Input();
		double D = A[0][0] * A[1][1] - A[0][1] * A[1][0];
		if (D != 0)
		{
			double Dx = A[0][2] * A[1][1] - A[1][2] * A[0][1];
			double Dy = A[0][0] * A[1][2] - A[1][0] * A[0][2];

			cout << s << sx << Dx / D << "\n" << sy << Dy / D << endl;
			
		}
		else
		{
			if ((A[0][0] == 0) && (A[0][1] == 0) && (A[1][0] == 0) && (A[1][1] == 0))
			{
				if ((A[0][2] == 0) && (A[1][2] == 0))
				{
					cout << s << sx << "any value" << sy << "any value" << endl;
					
				}
				else
				{
					cout << "invalid matrix" << endl;
					
				}
			}
			else if ((A[0][0] == 0) && (A[1][0] == 0))
			{
				double y1 = A[0][2] / A[0][1];
				double y2 = A[1][2] / A[1][1];
				if (y1 == y2)
				{
					cout << s << sx << "any value" << sy << y1 << endl;
					
				}
				else
				{
					cout << "no Solutions" << endl;
					
				}
			}
			else if ((A[0][1] == 0) && (A[1][1] == 0))
			{
				double x1 = A[0][2] / A[0][0];
				double x2 = A[1][2] / A[1][0];
				if (x1 == x2)
				{
					cout << s << sx << x1 << sy << "any value" << endl;
					
				}
				else
				{
					cout << "no Solutions" << endl;
					
				}
			}
			else if ((A[0][0] == A[1][0]) && (A[0][1] == A[1][1]))
			{
				if (A[0][2] == A[1][2])
				{
					cout << s << sx << "any value" << sy << A[0][2] / A[0][1] << "+" << A[0][0] / A[0][1] << "*x" << endl;
					
				}
				else
				{
					cout << "no Solutions" << endl;
					
				}
			}
			else if (A[0][0] == A[1][0])
			{
				cout << s << sx << "any value" << sy << (A[0][2] + A[1][2]) / (A[0][1] + A[1][1]) << endl;
				

			}
			else if (A[0][1] == A[1][1])
			{
				cout << s << sx << (A[0][2] + A[1][2]) / (A[0][0] + A[1][0]) << sy << "any value" << endl;
				
			}
			else
			{
				cout << "smth went wrong" << endl;
				
			}
		}
		cin >> sw;
	}
	return 0;
}
