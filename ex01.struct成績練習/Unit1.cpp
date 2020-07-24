//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
struct StdScore{
  int ID;
  int Eco;
  int Pro;
  int Com;
  int Score;
  int Order;
};
StdScore StdA[40],StdB[35];

void generate(StdScore x[],int n){
  for(int i=0;i<n;i++){
    x[i].ID=104001+i;
    x[i].Eco=random(101);
    x[i].Pro=random(101);
    x[i].Com=random(101);
    x[i].Score=x[i].Eco+x[i].Pro+x[i].Com;
    x[i].Order=1;
  }
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(x[i].Score>x[j].Score){
        x[j].Order++;
      }else{
        x[i].Order++;
      }
    }
  }
}

void sortData(StdScore x[],int n,int m){
  for(int i=n-2;i>-1;i--){
    for(int j=0;j<=i;j++){
      switch (m){
        case 1:
          if(x[j].ID>x[j+1].ID){
            StdScore t=x[j];
            x[j]=x[j+1];
            x[j+1]=t;
          }
          break;
        case 6:
          if(x[j].Order>x[j+1].Order){
            StdScore s=x[j];
            x[j]=x[j+1];
            x[j+1]=s;
          }
      }
    }
  }
}

void show(StdScore x[],int n){
  String s="學號\t\t經濟\t\t程設\t\t資素\t\t總分\t\t排名\n";
  for(int i=0;i<n;i++){
    s=s+IntToStr(x[i].ID)+"\t\t"+IntToStr(x[i].Eco)+"\t\t"+IntToStr(x[i].Pro)+"\t\t"
      +IntToStr(x[i].Com)+"\t\t"+IntToStr(x[i].Score)+"\t\t"+IntToStr(x[i].Order)+"\n";
  }
  Form1->Label1->Caption=s;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button3Click(TObject *Sender)
{
  generate(StdA,40);
  show(StdA,40);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  sortData(StdA,40,6);
  show(StdA,40);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  sortData(StdA,40,1);
  show(StdA,40);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  generate(StdB,35);
  show(StdB,35);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  sortData(StdB,35,6);
  show(StdB,35);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
  sortData(StdB,35,1);
  show(StdB,35);
}
//---------------------------------------------------------------------------

