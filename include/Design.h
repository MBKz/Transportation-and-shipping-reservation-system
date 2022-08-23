#ifndef DESIGN_H
#define DESIGN_H
#include<stdio.h>
#include<string.h>
string s1 = "\tDamascus university _ ITE Department .";
string s2 = "\tEng.Manar Al-Kaseem .";
string s3 = "\tMhd Bker kazmoz && Bishr Al-Khoja && Humam Al-Bazzal .";
void sleep(long int interval)
{
for(int i=0;i<interval*1000;i++);
}
void design1(){
      printf("                                            %c",201);//print left top corner
    for(int i=0;i<34;i++)
    {
  printf("%c",205);sleep(10000);
    }
  printf("%c\n",187);//print top right corner
  printf("                                            %c WELCOME TO Programming 3 Project ",186);//print vertical borders
  printf("%c\n",186);
  printf("                                            %c",200);//print bottom left corner
    for(int i=0;i<34;i++)
    {
      printf("%c",205);sleep(10000);
    }

  printf("%c\n",188);//print bottom right corner
  printf("\n");
for(int i =0 ;i<s1.length();i++){
    cout<<s1[i];
          sleep(10000);
}cout<<endl;

for(int i =0 ;i<s2.length();i++){
    cout<<s2[i];
          sleep(10000);
}
cout<<endl;

for(int i =0 ;i<s3.length();i++){
    cout<<s3[i];
          sleep(10000);
}
cout<<endl;
}
void design2(){
      printf("                                                %c",201);//print left top corner
    for(int i=0;i<20;i++)
    {
  printf("%c",205);
    }
  printf("%c\n",187);//print top right corner
  printf("                                                %cWELCOME TO MUSISCORE",186);//print vertical borders
  printf("%c\n",186);
  printf("                                                %c",200);//print bottom left corner
    for(int i=0;i<20;i++)
    {
      printf("%c",205);
    }
  printf("%c\n",188);//print bottom right corner
  printf("\n");
}

void finalPrint(){

}
#endif // DESIGN_H
