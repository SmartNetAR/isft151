//---------------------------------------------------------------------------

#include <fmx.h>
#include <System.IOUtils.hpp>
#pragma hdrstop

#include "Principal.h"
#include "Ahorcado.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)

TfrmPrincipal *frmPrincipal;
Ahorcado a ;
String Letras[5];
String Ganaste ;
String Perdiste ;
int nivel ;

void TfrmPrincipal::Nuevo (int Nivel) {
	a.Nueva();
	lblGanaste->Visible = false ;
	Glyph1->ImageIndex = -1 ;
	if (Nivel == 1 ) {
		a.MostrarConsonantes() ;
		Glyph1->ImageIndex = a.getIdPalabra() ;
	}
	if (Nivel == 2 ) {
		Glyph1->ImageIndex = a.getIdPalabra() ;
	}
	if (Nivel == 3 ) {

		#if defined(__ANDROID__)
			lblAyuda->Visible = true ;
		#endif
	}
	Label6->Text= a.getPalabraParcial( true ) ;
	Label6->Visible = true ;
	Label3->Text = a.getLetras() ;
    Label3->Visible = true ;
}

void TfrmPrincipal::buscarVocal( char v ) {
	a.addChar( v ) ;
	Label3->Text = a.getLetras() ;
	Label6->Text = a.getPalabraParcial( true ) ;
	if (v == 'A' ) Player->FileName = Letras[0] ;
	if (v == 'E' ) Player->FileName = Letras[1] ;
	if (v == 'I' ) Player->FileName = Letras[2] ;
	if (v == 'O' ) Player->FileName = Letras[3] ;
	if (v == 'U' ) Player->FileName = Letras[4] ;
	Player->Play();
	if ( a.isComplete() ) {
        lblGanaste->Visible = true ;
		Timer->Enabled = true ;
	}

}

//---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner)
	: TForm(Owner)
{

	gNivel->Visible = True ;
	AnsiString Palabras[]={"ABEJA","LEON","ELEFANTE","CHANCHO",
							"BAMBI","JIRAFA","MARIPOSA","CEBRA",
							"MONO","PULPO","DINOSAURIO","TIGRE",
							"TORTUGA","RINOCERONTE"};
	a.setPalabras( Palabras , 14) ;
	String ruta ;
#if defined(__ANDROID__)
	//ruta = IncludeTrailingPathDelimiter(System::Ioutils::TPath::GetTempPath());// + "Media/" ;				// movile
	//ruta = "/storage/emulated/0/Android/media/Media/" ;
	ruta = System::Ioutils::TPath::GetDocumentsPath() + "/" ;
	//lblAyuda->Visible = true ;
#else
	//ruta = System::Ioutils::TPath::GetDocumentsPath() + "\\" ;
	//Edit1->Text = ruta ;
	ruta = GetCurrentDir()  + "\\Media\\" ;	//pc

#endif
	Letras[0] = ruta + "a.mp3" ;
	Letras[1] = ruta + "e.mp3" ;
	Letras[2] = ruta + "i.mp3" ;
	Letras[3] = ruta + "o.mp3" ;
	Letras[4] = ruta + "u.mp3" ;
	Ganaste = ruta + "ganaste.mp3" ;
    Perdiste = ruta + "perdiste.mp3" ;
	/*a.Nueva() ;
	Glyph1->ImageIndex= a.getIdPalabra() ;
	Label4->Text= a.getPalabra() ;
	Label6->Text= a.getPalabraParcial( true ) ;
	*/



}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btAClick(TObject *Sender)
{
	buscarVocal ( 'A' ) ;
}

//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btEClick(TObject *Sender)
{
	buscarVocal ( 'E' ) ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btIClick(TObject *Sender)
{
	buscarVocal ( 'I' ) ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btOClick(TObject *Sender)
{
	buscarVocal ( 'O' ) ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btUClick(TObject *Sender)
{
	buscarVocal ( 'U' ) ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnNivel1Click(TObject *Sender)
{
	gNivel->Visible = False ;
	gLetras->Visible = True ;
	nivel = 1 ;
	Nuevo ( nivel ) ;

}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnNivel2Click(TObject *Sender)
{
	gNivel->Visible = False ;
	ePalabra->Visible = True ;
	nivel = 2 ;
	Nuevo ( nivel ) ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::btnNivel3Click(TObject *Sender)
{
	gNivel->Visible = False ;
	ePalabra->Visible = True ;
	nivel = 3 ;
	Nuevo ( nivel ) ;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::TimerTimer(TObject *Sender)
{
	if (nivel == 1) {
		Player->FileName = Ganaste ;
		Player->Play() ;
	}
	Nuevo( nivel ) ;
	Timer->Enabled = false ;
}
//---------------------------------------------------------------------------



void __fastcall TfrmPrincipal::ePalabraKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	/*#if defined(__ANDROID__)
		ePalabra->SelStart = 0 ;
		ePalabra->SelLength = 1 ;
		ePalabra->SetFocus() ;
	#else
		ePalabra->Text = "" ;
	#endif
    */
	//ePalabra->Text = "" ;

	//AnsiString Letra = ePalabra->Text.UpperCase() ;
	//ePalabra->Text = "" ;
	AnsiString Letra = "" ;
	#if defined(__ANDROID__)
		if (Key == vkHardwareBack) {
			/*
			lblAyuda->Visible = false ;
			gLetras->Visible = false ;
			Label6->Visible = false ;
			Label3->Visible = false ;
			gNivel->Visible = true ;
            */
		}
		if (Key == 13) {
			a.addChar( ePalabra->Text.UpperCase() ) ;
			ePalabra->SelStart = 0 ;
			ePalabra->SelLength = 1 ;
			ePalabra->Text = "" ;
		}
		//Letra = ePalabra->Text.UpperCase() ;
		//Letra = KeyChar ;

	#else
        Letra  = KeyChar ;
		ePalabra->Text = Letra;
		Letra = ePalabra->Text.UpperCase() ;
		a.addChar( Letra ) ;
	#endif


	//a.addChar( Letra ) ;

	Label3->Text = a.getLetras() ;
	Label6->Text = a.getPalabraParcial( true ) ;

	ePalabra->Text = "" ;

	if (a.isComplete()) {
		Glyph1->ImageIndex= a.getIdPalabra() ;
		if ( nivel == 3 ) {
			lblAyuda->Visible = false ;

		}
		lblGanaste->Visible = true ;
		Timer->Enabled = true ;
	}

}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift)
{
	#if defined(__ANDROID__)
		if (Key == vkHardwareBack) {
			if ( !gNivel->Visible ) {
				Key = 0 ;
			}
			lblAyuda->Visible = false ;
			gLetras->Visible = false ;
			Label6->Visible = false ;
			Label3->Visible = false ;
            ePalabra->Visible = false ;
			gNivel->Visible = true ;
		}
	#endif
}
//---------------------------------------------------------------------------

