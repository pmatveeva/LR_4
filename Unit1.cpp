//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
typedef struct
 {int x[10];
  int s;} Tos;
Tos o[20];
Tos newo[20];
Tos newosel[20];
int min,count,avr=0,countnew;
int weigth[10][10];
int begin=0;
int end=9;
//---------------------------------------------------------------------------
void Selection()
{int i,j,max;
min=0;
max=0;
for (i=0;i<20;i++)
  {o[i].s=0;
   for (j=0;j<9;j++)
       o[i].s=o[i].s+weigth[o[i].x[j]][o[i].x[j+1]];
   if (o[i].s<o[min].s) min=i;
   if (o[i].s>max) max=o[i].s;
   }
for (i=0;i<10;i++)
   Form1->StringGrid4->Cells[i][0]=o[min].x[i]+1;
Form1->Edit1->Text=o[min].s;
newo[0]=o[min];
avr=(max+o[min].s)/2;
count=1;
for (i=0;i<20;i++)
        if ((o[i].s<=avr)&&(i!=min))
                newo[count++]=o[i];
if (count<=1)
        {avr=max;
         for (i=0;i<20;i++)
                if (i!=min) newo[count++]=o[i];
         }

}
//---------------------------------------------------------------------------
void Crossing()
{int point,i,j,k,m,n;
 Tos o1,o2;
 point=2+rand()%6;
 //if (point==8) point==7;
 countnew=count;
 for (i=0;i<count;i++)
       {o1=newo[i];
        m=n=1;
        j=i;
        while((j<=i)&&(i!=count-1))
                j=rand()%count;
        o2=newo[j];
        for (k=1;k<9;k++)
                for (int l=1;l<=point;l++)
                  if (newo[j].x[k]==newo[i].x[l] && m<9 && n<9)
                        {o1.x[m++]=newo[j].x[k];
                         o2.x[k]=newo[i].x[n++];
                         }
        o1.s=o2.s=0;
        for (k=0;k<9;k++)
          {o1.s=o1.s+weigth[o1.x[k]][o1.x[k+1]];
           o2.s=o2.s+weigth[o2.x[k]][o2.x[k+1]];}

        if (countnew<20)
        {
        if (o1.s<o2.s) newo[countnew++]=o1;
        else newo[countnew++]=o2;
        }
        else
        {if (o1.s<newo[i].s) newo[i]=o1;
        if (o2.s<newo[j].s) newo[j]=o2;}


        }
for (i=0;i<countnew;i++)
   {Form1->StringGrid2->Cells[0][i]=i+1;
    for (j=0;j<10;j++)
       Form1->StringGrid2->Cells[j+1][i]=newo[i].x[j]+1;
    }
 
}
//---------------------------------------------------------------------------
void Mutation()
{Tos om;
 int i;
 for (i=1;i<countnew;)
  {
   i=i+rand()%4;
   om=newo[i];
   if (i<countnew)
   {
   int k;
   k=1+rand()%8;
   //if (k==9) k=8;
   om.x[k]=1+rand()%9;
   //if (om.x[k]==10) om.x[k]=9;
   if (om.x[k]==end)
        for (int j=k;j<9;j++)
             om.x[j]=end;
   om.s=0;
   for (k=0;k<9;k++)
          om.s=om.s+weigth[om.x[k]][om.x[k+1]];
   newo[i]=om;
   i++;
   }
   }
for (i=0;i<20;i++)
  if (o[i].s>avr)
  {om=o[i];
   int k;
   k=1+rand()%8;
   //if (k==9) k=8;
   om.x[k]=1+rand()%9;
   //if (om.x[k]==10) om.x[k]=9;
   if (om.x[k]==end)
        for (int j=k;j<9;j++)
             om.x[j]=end;
   om.s=0;
   for (k=0;k<9;k++)
          om.s=om.s+weigth[om.x[k]][om.x[k+1]];
   newo[countnew++]=om;
   }
for (i=0;i<countnew;i++)
   {Form1->StringGrid3->Cells[0][i]=i+1;
    for (int j=0;j<10;j++)
       Form1->StringGrid3->Cells[j+1][i]=newo[i].x[j]+1;
    }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{int i,j;
randomize();
for (i=0;i<10;i++)
  {weigth[i][i]=0;
   for (j=i+1;j<10;j++)
        {weigth[i][j]=1+rand()%20;
         weigth[j][i]=weigth[i][j];}
   }
Form1->Edit12->Text=weigth[0][1];
Form1->Edit13->Text=weigth[0][2];
Form1->Edit14->Text=weigth[0][3];
Form1->Edit15->Text=weigth[0][4];
Form1->Edit16->Text=weigth[0][5];
Form1->Edit17->Text=weigth[0][6];
Form1->Edit18->Text=weigth[0][7];
Form1->Edit19->Text=weigth[0][8];
Form1->Edit110->Text=weigth[0][9];
Form1->Edit23->Text=weigth[1][2];
Form1->Edit24->Text=weigth[1][3];
Form1->Edit25->Text=weigth[1][4];
Form1->Edit26->Text=weigth[1][5];
Form1->Edit27->Text=weigth[1][6];
Form1->Edit28->Text=weigth[1][7];
Form1->Edit29->Text=weigth[1][8];
Form1->Edit210->Text=weigth[1][9];
Form1->Edit34->Text=weigth[2][3];
Form1->Edit35->Text=weigth[2][4];
Form1->Edit36->Text=weigth[2][5];
Form1->Edit37->Text=weigth[2][6];
Form1->Edit38->Text=weigth[2][7];
Form1->Edit39->Text=weigth[2][8];
Form1->Edit310->Text=weigth[2][9];
Form1->Edit45->Text=weigth[3][4];
Form1->Edit46->Text=weigth[3][5];
Form1->Edit47->Text=weigth[3][6];
Form1->Edit48->Text=weigth[3][7];
Form1->Edit49->Text=weigth[3][8];
Form1->Edit410->Text=weigth[3][9];
Form1->Edit56->Text=weigth[4][5];
Form1->Edit57->Text=weigth[4][6];
Form1->Edit58->Text=weigth[4][7];
Form1->Edit59->Text=weigth[4][8];
Form1->Edit510->Text=weigth[4][9];
Form1->Edit67->Text=weigth[5][6];
Form1->Edit68->Text=weigth[5][7];
Form1->Edit69->Text=weigth[5][8];
Form1->Edit610->Text=weigth[5][9];
Form1->Edit78->Text=weigth[6][7];
Form1->Edit79->Text=weigth[6][8];
Form1->Edit710->Text=weigth[6][9];
Form1->Edit89->Text=weigth[7][8];
Form1->Edit810->Text=weigth[7][9];
Form1->Edit910->Text=weigth[8][9];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{int i,j,k;
for (i=0;i<20;i++)
        {for (j=0; j<11;j++)
                {
                Form1->StringGrid1->Cells[j][i]="";
                Form1->StringGrid2->Cells[j][i]="";
                Form1->StringGrid3->Cells[j][i]="";
                Form1->StringGrid4->Cells[j][i]="";
                }
        }

begin=atoi(Form1->Edit2->Text.c_str())-1;
end=atoi(Form1->Edit3->Text.c_str())-1;
for (i=0;i<20;i++)
  {o[i].x[0]=begin;
   o[i].x[9]=end;
   for (j=1;j<9;j++)
       {o[i].x[j]=rand()%10;
        bool ok=false;
        while (!ok)
         {ok=true;
          for (k=0; k<j; k++)
                if (o[i].x[j]==o[i].x[k] || o[i].x[j]==end)
                 {ok=false;
                  o[i].x[j]=rand()%10;
                  exit;}
          }
        }

   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
weigth[0][1]=atoi(Form1->Edit12->Text.c_str());
weigth[0][2]=atoi(Form1->Edit13->Text.c_str());
weigth[0][3]=atoi(Form1->Edit14->Text.c_str());
weigth[0][4]=atoi(Form1->Edit15->Text.c_str());
weigth[0][5]=atoi(Form1->Edit16->Text.c_str());
weigth[0][6]=atoi(Form1->Edit17->Text.c_str());
weigth[0][7]=atoi(Form1->Edit18->Text.c_str());
weigth[0][8]=atoi(Form1->Edit19->Text.c_str());
weigth[0][9]=atoi(Form1->Edit110->Text.c_str());
weigth[1][2]=atoi(Form1->Edit23->Text.c_str());
weigth[1][3]=atoi(Form1->Edit24->Text.c_str());
weigth[1][4]=atoi(Form1->Edit25->Text.c_str());
weigth[1][5]=atoi(Form1->Edit26->Text.c_str());
weigth[1][6]=atoi(Form1->Edit27->Text.c_str());
weigth[1][7]=atoi(Form1->Edit28->Text.c_str());
weigth[1][8]=atoi(Form1->Edit29->Text.c_str());
weigth[1][9]=atoi(Form1->Edit210->Text.c_str());
weigth[2][3]=atoi(Form1->Edit34->Text.c_str());
weigth[2][4]=atoi(Form1->Edit35->Text.c_str());
weigth[2][5]=atoi(Form1->Edit36->Text.c_str());
weigth[2][6]=atoi(Form1->Edit37->Text.c_str());
weigth[2][7]=atoi(Form1->Edit38->Text.c_str());
weigth[2][8]=atoi(Form1->Edit39->Text.c_str());
weigth[2][9]=atoi(Form1->Edit310->Text.c_str());
weigth[3][4]=atoi(Form1->Edit45->Text.c_str());
weigth[3][5]=atoi(Form1->Edit46->Text.c_str());
weigth[3][6]=atoi(Form1->Edit47->Text.c_str());
weigth[3][7]=atoi(Form1->Edit48->Text.c_str());
weigth[3][8]=atoi(Form1->Edit49->Text.c_str());
weigth[3][9]=atoi(Form1->Edit410->Text.c_str());
weigth[4][5]=atoi(Form1->Edit56->Text.c_str());
weigth[4][6]=atoi(Form1->Edit57->Text.c_str());
weigth[4][7]=atoi(Form1->Edit58->Text.c_str());
weigth[4][8]=atoi(Form1->Edit59->Text.c_str());
weigth[4][9]=atoi(Form1->Edit510->Text.c_str());
weigth[5][6]=atoi(Form1->Edit67->Text.c_str());
weigth[5][7]=atoi(Form1->Edit68->Text.c_str());
weigth[5][8]=atoi(Form1->Edit69->Text.c_str());
weigth[5][9]=atoi(Form1->Edit610->Text.c_str());
weigth[6][7]=atoi(Form1->Edit78->Text.c_str());
weigth[6][8]=atoi(Form1->Edit79->Text.c_str());
weigth[6][9]=atoi(Form1->Edit710->Text.c_str());
weigth[7][8]=atoi(Form1->Edit89->Text.c_str());
weigth[7][9]=atoi(Form1->Edit810->Text.c_str());
weigth[8][9]=atoi(Form1->Edit910->Text.c_str());
int i,j;
for (i=0;i<10;i++)
  {weigth[i][i]=0;
   for (j=0;j<i;j++)
        {weigth[i][j]=weigth[j][i];}
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{int i,j;
for (i=0;i<20;i++)
        {
        for (j=0;j<11;j++)
        {
        Form1->StringGrid2->Cells[j][i]="";
        Form1->StringGrid1->Cells[j][i]="";
        Form1->StringGrid3->Cells[j][i]="";
        }
        }
for (i=0;i<20;i++)
   {Form1->StringGrid1->Cells[0][i]=i+1;
    for (j=0;j<10;j++)
       Form1->StringGrid1->Cells[j+1][i]=o[i].x[j]+1;
    }
Selection();
Crossing();
Mutation();
for (i=0;i<20;i++)
   o[i]=newo[i];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
int i,j,k;
for (k=0;k<50;k++)
{
for (i=0;i<20;i++)
        {
        for (j=0;j<11;j++)
        {
        Form1->StringGrid2->Cells[j][i]="";
        Form1->StringGrid1->Cells[j][i]="";
        Form1->StringGrid3->Cells[j][i]="";
        }
        }
for (i=0;i<20;i++)
   {Form1->StringGrid1->Cells[0][i]=i+1;
    for (j=0;j<10;j++)
       Form1->StringGrid1->Cells[j+1][i]=o[i].x[j]+1;
    }
Selection();
Crossing();
Mutation();
for (i=0;i<20;i++)
   o[i]=newo[i];

}
}
//---------------------------------------------------------------------------

