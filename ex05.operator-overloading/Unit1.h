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
        TEdit *Edit1;
        TEdit *Edit2;
        TEdit *Edit3;
        TButton *Button1;
        TEdit *Edit4;
        TEdit *Edit5;
        TEdit *Edit6;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit7;
        TEdit *Edit8;
        TEdit *Edit9;
        TEdit *Edit10;
        TShape *Shape1;
        TLabel *Label3;
        TButton *Button2;
        TEdit *Edit11;
        TButton *Button3;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
class timeoperation{
  friend timeoperation operator *(int,timeoperation);
  private:
    int h,m,s;
    float mult;
  public:
    timeoperation(int hr,int min,int sec);
    timeoperation(float mult);
    timeoperation operator +(timeoperation);
    timeoperation operator *(int);
    timeoperation operator -(timeoperation);
    timeoperation operator /(float);
    timeoperation operator /(timeoperation);
    String show();
};