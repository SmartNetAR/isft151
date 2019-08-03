#include <iostream>
using namespace std;

struct Hora {
    int h, m;
};

void lee_hora(Hora& H) {
    char c;
    cin >> H.h >> c >> H.m;

}

void incrementa_hora(Hora& H) {
    H.m = H.m + 1;
    if (H.m >= 60) {
        H.m = 0;
        H.h = H.h + 1;
        if (H.h >= 24 ) H.h = 0;
    }
}

void muestra_hora(Hora H) {
    if (H.h < 10) cout << 0;
    cout << H.h;
    cout << ':';
    if (H.m < 10) cout << 0;
    cout << H.m << endl;
}

int main()
{
    Hora x;
    lee_hora(x);
    incrementa_hora(x);
    muestra_hora(x);

    return 0;
}