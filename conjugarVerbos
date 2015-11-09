#include <iostream>
#include <fstream>

using namespace std;
bool Conjugar(char verbo[]);
int LongitudCadena(char *cadena);

int main()
{
    char verbo[30];
    cin >> verbo;
    Conjugar(verbo);

    return 0;
}

bool Conjugar(char verbo[])
{
    int len = LongitudCadena(verbo);
    len -=2;
    char letra = verbo[len];
    char nuevacadena[len];
    for (int i = 0; i < len; i++)
    {
        nuevacadena[i] = verbo[i];
        nuevacadena[i+1] = '\0';
    }
    ofstream Grabar("conjugados.txt");
    cout << "conjugando el verbo " << verbo << endl;
    cout << "uso " << nuevacadena << " identificando la " << letra << " longitud " << len << endl;
    switch (letra)
    {
        //reemplazar cout x Grabar para que lo guarde en el archivo de texto
        case 'i':
            cout << "yo " << nuevacadena << "o" << endl;
            cout << "tu " << nuevacadena << "es" << endl;
            cout << "el " << nuevacadena << "e" << endl;
            cout << "vosotros " << nuevacadena << "eis" << endl;
            cout << "nosotros " << nuevacadena << "imos" << endl;
            cout << "ellos " << nuevacadena << "en" << endl;
            break;
        case 'e':
            cout << "yo " << nuevacadena << "o" << endl;
            cout << "tu " << nuevacadena << "es" << endl;
            cout << "el " << nuevacadena << "e" << endl;
            cout << "vosotros " << nuevacadena << "eis" << endl;
            cout << "nosotros " << nuevacadena << "emos" << endl;
            cout << "ellos " << nuevacadena << "en" << endl;
            break;
        case 'a':
            cout << "yo " << nuevacadena << "o" << endl;
            cout << "tu " << nuevacadena << "as" << endl;
            cout << "el " << nuevacadena << "a" << endl;
            cout << "vosotros " << nuevacadena << "ais" << endl;
            cout << "nosotros " << nuevacadena << "amos" << endl;
            cout << "ellos " << nuevacadena << "an" << endl;
            break;
        default:
            cout << "no podemos procesar el texto" << endl;
            break;
    }
    Grabar.close();


    return true;
}

int LongitudCadena(char *cadena)
{
    int i =0;
    while (cadena[i] != '\0') {i++;}
    return i;
}
