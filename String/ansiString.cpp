#ifndef ANSISTRING_H_INCLUDED
#define ANSISTRING_H_INCLUDED

class ansiString {
public:
    ansiString() ;
    ansiString( char* str ) ;
    int Length();
    int Pos (int start, char ch ) ;
    bool EqualTo ( const ansiString & ansiString ) const ;
    const char* Concat ( const char* str ) ;
    const char* Ret() ;
    char* Mid ( int start, int len ) ;

private:
    enum { SIZE = 128 };
    int length;
    char rep[ SIZE ];
    bool init ;
    bool empty ;
    bool full ;
};


#endif // ANSISTRING_H_INCLUDED