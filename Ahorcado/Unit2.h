//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TfrmInicio : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TRadioButton *Nivel1;
	TRadioButton *Nivel2;
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmInicio(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmInicio *frmInicio;
//---------------------------------------------------------------------------
#endif
