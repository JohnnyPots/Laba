#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
using namespace std;


int main()
{
    setlocale(LC_ALL, "Rus");
    string s1, s2;
    int a, b, c, d, e, f;
    cout << "Выражение f = (a || b || !c) &&(!d || e)" << endl;
    cout << "a| \tb| \tc| \td| \te| \tf|" << endl;
    for (a = 0; a < 2; a++)
    {
        for ( b = 0; b < 2; b++)
        {
            for ( c = 0; c < 2; c++)
            {
                for ( d = 0; d < 2; d++)
                {
                    for (e = 0; e < 2; e++)
                    {
                        f = (a || b || !c) && (!d || e);
                        if (f == 1) {
                            cout << a << "|\t" << b << "|\t" << c << "|\t" << d << "|\t" << e << "|\t" << f << "\t" << endl;
                            if (!a) { s1 += "(!a&&"; }
                            else { s1 += "(a&&"; }
                            if (!b) { s1 += "!b&&"; }
                            else { s1 += "b&&"; }
                            if (!c) { s1 += "!c&&"; }
                            else { s1 += "c&&"; }
                            if (!d) { s1 += "!d&&"; }
                            else { s1 += "d&&"; }
                            if (!e) { s1 += "!e)||"; }
                            else { s1 += "e)||"; }
                        }
                        if (f == 0)
                        {
                            cout << a << "|\t" << b << "|\t" << c << "|\t" << d << "|\t" << e << "|\t" << f << "\t" << endl;
                            if (a) { s2 += "(!a||"; }
                            else { s2 += "(a||"; }
                            if (b) { s2 += "!b||"; }
                            else { s2 += "b||"; }
                            if (c) { s2 += "!c||"; }
                            else { s2 += "c||"; }
                            if (d) { s2 += "!d||"; }
                            else { s2 += "d||"; }
                            if (e) { s2 += "!e)&&"; }
                            else { s2 += "e)&&"; }
                        }

                    }
                }
            }
        }
    }
    cout << "f = " << s1 << "- СДНФ" << endl;
    cout << "f = " << s2 << "- СКНФ" << endl;
    return 0;
}