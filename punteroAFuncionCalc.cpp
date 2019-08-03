//operaciones de cálculos con puntero a funcion
//leonardo casales

#include <iostream>
using namespace std;

typedef float Type;

float Suma (float x, float y) {return x + y; }

float Resta (float x, float y) {return x - y; }

float Exp (float x, float y) {
    float resultado = 0;
    if ( x >= 0.1 ) {
        resultado =x;
        for (int i = 0; i < int(y) -1; i++ ) {
            resultado = resultado * x;
        }
    }
    return resultado;
}

typedef float (*Operacion) (Type valor1, Type valor2) ;

float Operar(Operacion operacion, Type x, Type y) {
    float resultado =  operacion(x,y);
    return resultado;
}

int main()
{
    Type a,b;
    cout << "indique los valores " ;
    cin >> a >> b;
    cout << "Suma ";
    cout << Operar(Suma,a ,b) << endl;
    cout << "Exponente " ;
    cout << Operar(Exp,a ,b) << endl;
    cout << "Resta ";
    cout << Operar(Resta,a ,b) << endl;
    return 0;
}