//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool multiple=false;
int a,s,d,f,g,h,j,k,l;
timeoperation operator *(int z,timeoperation x){
  return timeoperation(z*x.h,z*x.m,z*x.s);
}
timeoperation::timeoperation(int hr=0,int min=0,int sec=0){
  h=hr; m=min; s=sec;
}
timeoperation::timeoperation(float m){
  mult=m;
}

timeoperation timeoperation::operator +(timeoperation t){
  return timeoperation(h+t.h,m+t.m,s+t.s);
}

timeoperation timeoperation::operator -(timeoperation t){
  return timeoperation(h-t.h,m-t.m,s-t.s);
}

timeoperation timeoperation::operator *(int t){
  return timeoperation(h*t,m*t,s*t);
}

timeoperation timeoperation::operator /(float t){
  return timeoperation(h/t,m/t,s/t);
}

timeoperation timeoperation::operator /(timeoperation t){
  float a,b;
  a=h*3600+m*60+s;
  b=t.h*3600+t.m*60+t.s;
  return timeoperation(a/b);
}

String timeoperation::show(){

  int q;
  q=h*3600+m*60+s;
  h=q/3600;
  m=(q-h*3600)/60;
  s=q-(h*3600)-(m*60);
  if(multiple){
    multiple=false;
    return AnsiString(mult);
  }else{
    return IntToStr(h)+":"+IntToStr(m)+":"+IntToStr(s);
  }
}

void vartrans(){
  a=Form1->Edit1->Text.ToInt(); s=Form1->Edit2->Text.ToInt(); d=Form1->Edit3->Text.ToInt();
  f=Form1->Edit4->Text.ToInt(); g=Form1->Edit5->Text.ToInt(); h=Form1->Edit6->Text.ToInt();
  j=Form1->Edit7->Text.ToInt(); k=Form1->Edit8->Text.ToInt(); l=Form1->Edit9->Text.ToInt();
}

timeoperation x,y,z;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button1Click(TObject *Sender)
{
  vartrans();
  x=timeoperation(a,s,d);
  y=timeoperation(f,g,h);
  z=x+y;
  Label1->Caption=z.show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
  vartrans();
  x=timeoperation(a,s,d);
  y=timeoperation(f,g,h);

  if(a<f||a==f&&s<g||a==f&&s==g&&d<h){
    ShowMessage("相減不能為負數");
    return;
  }

  z=x-y;
  Label1->Caption=z.show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
  vartrans();
  x=timeoperation(j,k,l);
  z=x*Edit10->Text.ToInt();
  Label1->Caption=z.show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
  if(Edit10->Text.ToInt()==0){
    ShowMessage("分母不可為零");
    return;
  }

  vartrans();
  x=timeoperation(j,k,l);
  z=x/Edit10->Text.ToInt();
  Label1->Caption=z.show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
  multiple=true;
  vartrans();
  x=timeoperation(a,s,d);
  y=timeoperation(f,g,h);

  if(f==0&&g==0&&h==0){
    ShowMessage("分母不可為零");
    return;
  }

  z=x/y;
  Label1->Caption=z.show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  vartrans();
  x=timeoperation(j,k,l);
  z=Edit11->Text.ToInt()*x;
  Label1->Caption=z.show();
}
//---------------------------------------------------------------------------



