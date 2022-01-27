#include <iostream>
#include <cmath>
#include <conio.h> //for _getch
#include <vector>
#include "Parser.h"

Parser parser;

int scale;
bool scaling=false;
std::string fname;
std::string formula;

int w = 192; //width of render
int h = 44;  //height of render

int choice;

float f(float x);
int main() {
    select:
    system("cls");

    std::cout<<"function graph drawer"<<std::endl<<"not suitable for any research"<<std::endl<<"recreational purposes only"<<std::endl<<"please enable the fullscreen mode"<<std::endl;
    std::cout<<"choose a function:"<<std::endl
    <<"1. x^2"<<std::endl
    <<"2. x^3"<<std::endl
    <<"3. |x|"<<std::endl
    <<"4. 1/x"<<std::endl
    <<"5. sqrt of x"<<std::endl
    <<"6. log(x)"<<std::endl
    <<"7. sin(x)"<<std::endl
    <<"8. cos(x)"<<std::endl
    <<"9. tan(x)"<<std::endl
    <<"10. custom function"<<std::endl
    <<"0. config"<<std::endl;
    std::cout<<"pick a number from 1 to 10 and press enter: ";
    std::cin>>choice;

    scale=1;
    if (choice == 0){
        system("cls");
        std::cout<<"the current width is "<<w<<std::endl<<"the current height is "<<h<<std::endl<<"enter the new width: ";
        std::cin>>w;
        std::cout<<"enter the new height: ";
        std::cin>>h;
        std::cout<<"the new width is "<<w<<", the new height is "<<h<<std::endl;
        system("pause");
        goto select;
    }
    else if (choice==9){
        scale++;
    }
    else if (choice == 10){
        std::cout<<"type the function formula"<<std::endl;
        std::cout<<"available operations: +, -, *, /, ^"<<std::endl;
        std::cout<<"y = ";
        std::cin.ignore(256, '\n');
        getline(std::cin, formula);
        formula = parser.removeSpaces(formula);
    }

    char key; //for _getch

	std::vector<std::vector <char>> graph;
    graph.resize(h);
    for (int i = 0; i < h; i++) {
        graph[i].resize(w);
    }
	int x, y;
	start:
    system("cls");

    std::cout<<"scale: "<<scale<<"    UP ARROW/DOWN ARROW to adjust";
    if (scaling) std::cout<<"     [[ZOOMING]]";
    std::cout<<std::endl;
    std::cout<<"SPACEBAR to draw another function"<<std::endl;
	for (int i = h-1; i >= 0; i--) {
		y = i - h/2;
		for (int j = 0; j < w; j++) {
			x = j - w/2;
			if (scaling && abs(x) == w/4 )
				graph[i][j] = '|';
			else if (scaling && abs(y) == h/4 )
				graph[i][j] = '-';
			else if (y == round( f(x/pow(2,scale+1)) ) )
				graph[i][j] = '*';
            else if (x == 0 && y/pow(2,scale) < 10 && y/pow(2,scale) > -10 && y/pow(2,scale) == round(y/pow(2,scale)))
                graph[i][j] = abs(y/pow(2,scale))+48;
            else if (y == 0 && x/pow(2,scale+1) < 10 && x/pow(2,scale+1) > -10 && x/pow(2,scale+1) == round(x/pow(2,scale+1)))
                graph[i][j] = abs(x/pow(2,scale+1))+48;
			else if (y == 0)
				graph[i][j] = '-';
			else if (x == 0)
				graph[i][j] = '|';
			else
				graph[i][j] = ' ';
			std::cout << graph[i][j];
		}
		std::cout << std::endl;
	}
    std::cout << "y = " << fname << std::endl;
	if(scaling){
        scaling = false;
        scale++;
        goto start;
	}
	if(scaling){
        scaling = false;
        scale++;
        goto start;
	}
        if(_getch() == 32)
            goto select;
        key=_getch();
        if (key == 0 || key == 0xE0)
            key=_getch();
        switch(key){
        case 72:
            scaling=true;
            break;
        case 80:
            scale--;
            break;
        }

        goto start;

}

float f(float x){
    float result;
switch(choice){
case 1:
    result = x*x;
    fname = "x^2";
    break;
case 2:
    result = x*x*x;
    fname = "x^3";
    break;
case 3:
    result = abs(x);
    fname = "abs(x)";
    break;
case 4:
    result = 1/x;
    fname = "1/x";
    break;
case 5:
    result = sqrt(x);
    fname = "sqrt(x)";
    break;
case 6:
    result = log10(x);
    fname = "log(x)";
    break;
case 7:
    result = sin(x);
    fname = "sin(x)";
    break;
case 8:
    result = cos(x);
    fname = "cos(x)";
    break;
case 9:
    result = tan(x);
    fname = "tan(x)";
    break;
case 10:
    result = parser.compute(formula, x);
    fname = formula;
    break;
}


return result * pow(2,scale);
}