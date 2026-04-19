#include <iostream>
#include <string>
using namespace std;
class shape
{
    double width, height;

    public:
    //constructor 
    shape(double wid, double hei)
    {
        width = wid;
        height = hei;
    }

    double getarea()
    {
        return width * height;

    };
    double getPerimeter()
    {
        return 2 * (height + width);
    };
    bool isSquare()
    {
        return height == width;
    };
};

main (){

    double h, w;
    int r = 0;
    for(int i = 0;  i < 3; i++)
    {
        r += 1;
        cout << "Rectangel #"<< r << endl;
        cout << "w: ";
        cin >> w;
        cout << "h: ";
        cin >> h;
    


        shape Mendoza(h, w);
        {
            cout << "Area: " << Mendoza.getarea() << endl;
            cout << "Parameter: " << Mendoza.getPerimeter() << endl;
            cout << "IsSquare: " << (Mendoza.isSquare() ? "Square" : "NotSquare") <<endl;

        }
    }


    return 0;
}