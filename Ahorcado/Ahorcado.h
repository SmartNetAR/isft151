#ifndef AHORCADO_H
#define AHORCADO_H

	enum { MAXLEN = 30 } ;
	//const int MAXLEN = 30 ;
	class Ahorcado {
		private:
			char letras[MAXLEN];
			char lastChar ;
			int lastCharPos ;
			int cantLetras ;
			AnsiString palabras[MAXLEN] ;
			AnsiString palabra ;
			char palabraParcial[MAXLEN] ;
			int idPalabra ;
			int cantPalabras ;
			void PasarAGuiones () ;
			int posOfChar ( char ch );
			int lenPalabra ;
			int letrasResueltas ;
		public:
			Ahorcado () ;
			void setPalabras ( AnsiString Palabras[7], int nroPalabras ) ;
			void Nueva ();
			//int posOfChar ( AnsiString ch );
			AnsiString getGuiones () ;
			int addChar ( AnsiString ch ) ;
			char getLastChar () ;
			int getLastCharPos () ;
			int getCantLetras () ;
			AnsiString getLetras() ;
			int getIdPalabra () ;
			AnsiString getPalabra () ;                         // devuelve la palabra
			AnsiString getPalabraParcial ( bool espaciado ) ;
			void MostrarConsonantes () ;
			bool isComplete () ;
			int getCantLetrasResueltas () ;
			int getCantLetrasFaltantes () ;
	};

	Ahorcado::Ahorcado () {
		 cantLetras = 0 ;
		 cantPalabras = 0 ;
		 idPalabra = -1 ;
		 lenPalabra = -1 ;
		 letrasResueltas = 0 ;
		 for (int i = 0; i < MAXLEN; i++) {
			letras[i] = '\n' ;
		 }
	}

	void Ahorcado::setPalabras ( AnsiString nuevasPalabras[7], int nroPalabras ) {
		for (int i = 0; i < nroPalabras; i++) {
			palabras[i] = nuevasPalabras[i] ;
		}
		cantPalabras = nroPalabras ;
	}

	void Ahorcado::Nueva () {
		srand (time(NULL));
		int posicion;
		cantLetras = 0 ;
		posicion = rand()% cantPalabras;
		idPalabra = posicion;
		palabra = palabras[posicion];
		PasarAGuiones();
		letrasResueltas = 0 ;
		for (int i = 0; i < MAXLEN; i++) {
			letras[i] = '\n' ;
		}
	}

	int Ahorcado::getIdPalabra () {
		return idPalabra;
	}

	AnsiString Ahorcado::getPalabra () {
		return palabra;
    }

	int Ahorcado::posOfChar ( char ch ) {
		int pos = -1;
		int len = 0;

		//char tmpchar[2];
		char tmppalabra[256];


		//strcpy(tmpchar, ch.c_str());
		strcpy(tmppalabra, palabra.c_str());

		for (int i = 0; i < lenPalabra; i++) {
			if ( ch == tmppalabra[i] ) {
				pos = i;
				palabraParcial[pos] = ch ;
				letrasResueltas ++ ;
			}
		}
		lastCharPos = pos ;
		return pos;
	}

	int Ahorcado::addChar ( AnsiString ch ) {
		char tmpchar [2] ;
		strcpy(tmpchar, ch.c_str());
		lastChar = tmpchar[0] ;
		bool repetida = false ;
		for ( int i = 0 ; i < MAXLEN ; i++ ) {
			if ( letras[i] == lastChar ) {
				repetida = true ;
			}
		}
		if ( !repetida ) {
		   letras[cantLetras] = lastChar ;
		   letras[cantLetras + 1] = '\0' ;
		   cantLetras++ ;
		   posOfChar( tmpchar[0] ) != -1 ;
		}

		return cantLetras ;
	}

	char Ahorcado::getLastChar () {
		return lastChar ;
	}

	int Ahorcado::getLastCharPos () {
		return lastCharPos ;
	}

	int Ahorcado::getCantLetras () {
		return cantLetras ;
	}

	AnsiString Ahorcado::getLetras() {
		AnsiString ch = AnsiString( letras ) ;
		return ch ;
	}

	void Ahorcado::PasarAGuiones ( ) {
		int len=0 ;
		char tmpchar[256] ;
		int i=0 ;

		strcpy(palabraParcial, palabra.c_str()) ;
		char guion_bajo ;
		guion_bajo = '_' ;
		lenPalabra = strlen(palabraParcial) ;

		for ( i = 0 ; i < lenPalabra ; i++ ) {
			 palabraParcial[i] = guion_bajo ;
		}
	}

	AnsiString Ahorcado::getPalabraParcial ( bool espaciado = false ) {
		AnsiString resultado = "" ;
		char tmpchar[256] ;

		if ( espaciado ) {
			int j = 0 ;
			for (int i = 0; i < lenPalabra ; i++) {
				 tmpchar[j] = palabraParcial[i] ;
				 tmpchar[++j] = ' ' ;
				 j++ ;
			}
			tmpchar[j] = '\0' ;
			resultado = tmpchar ;
		}else {
			resultado = palabraParcial ;
		}
		return resultado ;
	}

	void Ahorcado::MostrarConsonantes () {

		char tmppalabra[256];
		strcpy(tmppalabra, palabra.c_str());

		char* consonantes = "QWRTYPSDFGHJKL�ZXCVBNM";
		int letrasConsonantes = 22 ;
		for (int j = 0; j < letrasConsonantes ; j++) {
			for (int i = 0; i < lenPalabra; i++) {
				if ( consonantes[j] == tmppalabra[i] ) {
					palabraParcial[i] = consonantes[j] ;
                    letrasResueltas ++ ;
				}
			}
		}

	}

	bool Ahorcado::isComplete () {
		return lenPalabra == letrasResueltas ;
	}

	int Ahorcado::getCantLetrasResueltas () {
		return letrasResueltas ;
	}

	int Ahorcado::getCantLetrasFaltantes () {
		return lenPalabra - letrasResueltas ;
	}

#endif

