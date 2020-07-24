//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
elavator *elavator1[10];
int elaNum,floor;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------
elavator::elavator(){
  elafloor=0;
  step=true;

  a=new TTimer(Form1);
  a->OnTimer=UpDown;
  a->Enabled=false;
  a->Interval=600;

  b=new TTimer(Form1);
  b->OnTimer=OpenDoor;
  b->Enabled=false;

  c=new TTimer(Form1);
  c->OnTimer=OpenDoor2;
  c->Enabled=false;

  e=new TPanel(Form1);
  e->Parent=Form1;
  e->Color=clActiveCaption;
  e->Height=600;
  e->Width=200;
  e->Top=50;


  for(int i=0;i<floor;i++){
    TShape *temp;
    temp=new TShape(e);
    temp->Brush->Color=clFuchsia;
    temp->Parent=e;
    temp->Width=e->Width/3;
    temp->Height=e->Height/floor;
    temp->Top=(e->Height/floor)*i;
    ela[i]=temp;

    TEdit *temp1;
    temp1=new TEdit(e);
    temp1->Parent=e;
    temp1->Width=e->Width/3;
    //temp1->Height=e->Height/floor;
    temp1->Top=temp->Top;
    temp1->Left=temp->Width;
    edit[i]=temp1;

    TButton *temp2;
    temp2=new TButton(e);
    temp2->Parent=e;
    temp2->Width=e->Width/3;
    temp2->Height=temp1->Height+20;
    temp2->Top=temp->Top;
    temp2->Left=temp->Width*2;
    temp2->Caption=i+1;
    temp2->OnClick=ButClick;
    but[i]=temp2;
  }
  ela[0]->Brush->Color=clYellow;
}

elavator::~elavator(){
  delete a;
  delete b;
  delete c;

  for(int i=0;i<floor;i++){
    delete ela[i];
    ela[i]=NULL;
    delete edit[i];
    edit[i]=NULL;
    delete but[i];
    but[i]=NULL;
  }
  delete e;
}


void __fastcall elavator::ButClick(TObject *Sender){
  TButton *now=(TButton *)Sender;
  peoplefloor=StrToInt(now->Caption)-1;
  target=StrToInt(edit[StrToInt(now->Caption)-1]->Text)-1;
  a->Enabled=true;
  step=true;

}

void __fastcall elavator::UpDown(TObject *Sender){
  if(step==true){
    if(elafloor==peoplefloor){
      a->Enabled=false;
      b->Enabled=true;
    }else{
      ela[elafloor]->Brush->Color=clFuchsia;
      if(elafloor<peoplefloor){
        ela[++elafloor]->Brush->Color=clYellow;
      }else
        ela[--elafloor]->Brush->Color=clYellow;
    }
  }else{
    if(elafloor==target){
      a->Enabled=false;
      b->Enabled=true;
    }else{
      ela[elafloor]->Brush->Color=clFuchsia;
      if(elafloor<target){
        ela[++elafloor]->Brush->Color=clYellow;
      }else{
        ela[--elafloor]->Brush->Color=clYellow;
      }
    }
  }
}

void __fastcall elavator::OpenDoor(TObject *Sender){
  b->Enabled=false;
  ela[elafloor]->Brush->Color=clRed;
  c->Enabled=true;
}

void __fastcall elavator::OpenDoor2(TObject *Sender){
  c->Enabled=false;
  ela[elafloor]->Brush->Color=clYellow;
  if(step==true){
    step=false;
    a->Enabled=true;
  }
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  elaNum=StrToInt(InputBox("設定","請問您想建造幾座電梯呢?~~~~~","3"));
  for(int i=0;i<elaNum;i++){
    floor=StrToInt(InputBox("設定","請問第"+IntToStr(i+1)+"座電梯您想造幾層樓呢?~~~~","5"));
    elavator1[i]=new elavator;
    elavator1[i]->e->Left=(Form1->Width/elaNum)*i+20;
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormDestroy(TObject *Sender)
{
   for(int i=0;i<elaNum;i++){
    delete elavator1[i];
  }        
}
//---------------------------------------------------------------------------

