//---------------------------------------------------------------------------

#ifndef PrincipalH
#define PrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Media.hpp>
#include <FMX.Graphics.hpp>
//---------------------------------------------------------------------------
class TfrmPrincipal : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TImageList *ImageList1;
	TGlyph *Glyph1;
	TLabel *Label6;
	TGroupBox *gLetras;
	TButton *btU;
	TButton *btO;
	TButton *btA;
	TButton *btE;
	TButton *btI;
	TEdit *ePalabra;
	TGroupBox *gNivel;
	TButton *btnNivel1;
	TButton *btnNivel2;
	TMediaPlayer *Player;
	TButton *btnNivel3;
	TTimer *Timer;
	TBrushObject *Brush1;
	TLabel *lblAyuda;
	TLabel *lblGanaste;
	void __fastcall btAClick(TObject *Sender);
	void __fastcall btEClick(TObject *Sender);
	void __fastcall btIClick(TObject *Sender);
	void __fastcall btOClick(TObject *Sender);
	void __fastcall btUClick(TObject *Sender);
	void __fastcall btnNivel1Click(TObject *Sender);
	void __fastcall btnNivel2Click(TObject *Sender);
	void __fastcall btnNivel3Click(TObject *Sender);
	void __fastcall TimerTimer(TObject *Sender);
	void __fastcall ePalabraKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, System::WideChar &KeyChar,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmPrincipal(TComponent* Owner);
	void Nuevo (int Nivel) ;
    void buscarVocal ( char v ) ;
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
#endif
