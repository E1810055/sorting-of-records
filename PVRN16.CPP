#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
class record
{
  private:
  char name[20];
  int n,m_chem,m_phy,m_maths;
  float per;
  public:
  record()
  {
    m_chem=0;
    m_phy=0;
    m_maths=0;
  }
  void get();
  void get_data();
  void sort();
  void copy(record &x, record &y);
  void display();
  void display_data();
  void table();
  void compare();
};
record stud[20];
void record::table()
{
  cout<<"The sorted record is"<<endl;
  cout<<"Sr. "<<"Full Name           "<<"Chem "<<"Maths "<<"Phy "<<"Percentage"<<endl;
}
void record::get()
{
  int i;
  cout<<"Enter the number of students: ";
  cin>>n;
  cout<<"Enter the data of students"<<endl<<"Name and marks(out of 100) of Chemistry,Maths and Physics respectively: "<<endl;
  for(i=0;i<n;i++)
  {
    stud[i].get_data();
  }
}
void record::get_data()
{
  gets(name);
  cin>>m_chem>>m_maths>>m_phy;
  per=(m_chem+m_maths+m_phy)/3.0;
}
void record::copy(record &x, record &y)
{
  strcpy(x.name,y.name);
  x.m_chem=y.m_chem;
  x.m_phy=y.m_phy;
  x.m_maths=y.m_maths;
  x.per=y.per;
}
void record::sort()
{
  int i,j;
  record z;
  for(i=0;i<n;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(strcmpi(stud[i].name,stud[j].name)>0)
      {
	z.copy(z,stud[i]);
	z.copy(stud[i],stud[j]);
	z.copy(stud[j],z);
      }
    }
  }
}
void record::display_data()
{
  int i,x;
  cout<<name;
  x=strlen(name);
  for(i=0;i<=20-x;i++)
  {
    cout<<" ";
  }
  cout<<m_chem<<"    "<<m_phy<<"   "<<m_maths<<"   "<<per;

}
void record::display()
{
  int i;
  for(i=0;i<n;i++)
  {
    cout<<i+1<<".  ";
    stud[i].display_data();
    cout<<endl;
  }
}
void record::compare()
{
  int i,stu,j;
  float max;
  max=stud[0].per;
  for(i=1;i<n;i++)
  {
    if(max<stud[i].per)
    {
      max=stud[i].per;
      stu=i;
    }
  }
  cout<<"the highest percentage obtained is: "<<max;
}
void main()
{
  clrscr();
  record z;
  z.get();
  z.sort();
  z.table();
  z.display();
  z.compare();
  getch();
}

                                  
                                                                                
                                                                                
                                                                                
                                                                                

                                                                                
                                                                                
                                                                                
                                                                                
