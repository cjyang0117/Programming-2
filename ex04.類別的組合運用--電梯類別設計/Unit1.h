//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif

class elavator{
  private:
    int peoplefloor;
    int elafloor;
    int target;
    bool step;
    TTimer *a;
    TTimer *b;
    TTimer *c;
    TShape *ela[100];
    TEdit *edit[100];
    TButton *but[100];
    void __fastcall UpDown(TObject *Sender);
    void __fastcall OpenDoor(TObject *Sender);
    void __fastcall OpenDoor2(TObject *Sender);
    void __fastcall ButClick(TObject *Sender);
  public:
    elavator();
    ~elavator();
    TPanel *e;
};