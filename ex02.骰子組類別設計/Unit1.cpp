//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
dice Dice;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Dice.amount=Edit1->Text.ToInt();
  Dice.side=Edit2->Text.ToInt();
  Dice.play();
  Label3->Caption=Dice.show();
}
//---------------------------------------------------------------------------
void dice::play(){
  for(int i=0;i<amount;i++){
    point[i]=random(side)+1;
  }
}

String dice::show(){
  String s="";
  for(int i=0;i<amount;i++){
    s=s+IntToStr(point[i])+"\t";
  }
  return s;
}

