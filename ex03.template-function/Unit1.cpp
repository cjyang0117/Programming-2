//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int top=0;
template <class T>
  void push(T SNF,T a[]){
    a[top++]=SNF;
  }

template <class T>
  void pop(T a[]){
    if(top!=0) a[--top]=NULL;
  }

template <class T>
  String show(T a[]){
    String s;
    for(int i=top-1;i>-1;i--){
      s=s+a[i]+"\n";
    }
    return s;
  }




  String s,Stack_S[1000];
  int n,Stack_N[1000];
  float f,Stack_F[1000];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  s=Edit1->Text;
  Edit1->Text="";
  push(s,Stack_S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
  Label1->Caption=show(Stack_S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
  pop(Stack_S);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
  n=Edit2->Text.ToInt();
  Edit2->Text="";
  push(n,Stack_N);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
  pop(Stack_N);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
  Label2->Caption=show(Stack_N);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  f=StrToFloat(Edit3->Text);
  Edit3->Text="";
  push(f,Stack_F);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
  pop(Stack_F);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
  Label3->Caption=show(Stack_F);
}
//---------------------------------------------------------------------------
