#include <iostream>
#include <fstream>
#include "add.hpp"
using namespace std;

void search(Boi * Ring, int k)
{
int i;
string s1;
string s2;
string sw;
cout<<"Выберите параметр поиска\n";
cout<<"1.Фамилия первого бойца\n2.Фамилия второго бойца\n3.Фамилия победителя/ничья";
int c;
cin>>c;
switch(c){
	case 1: cin>>s1; break;
	case 2: cin>>s2; break;
	case 3: cin>>sw; break;
	}
if (c==1){
	i=0;
	while(i<k){
		if(Ring[i].p1==s1){
			cout<<"№|";
			cout<<"Боец №1| ";
			cout<<"Боец №2| ";
			cout<<"Результат| ";
			cout<<"Вид победы \n";
			cout<<Ring[i].p1<<" "<<Ring[i].p2<<" "<<Ring[i].Res<<" "<<Ring[i].type<<"\n";

			}
		i++;}
	}
if (c==2){
        i=0;
        while(i<k){
                if(Ring[i].p2==s2){
                        cout<<"№|";
                        cout<<"Боец №1| ";
                        cout<<"Боец №2| ";
                        cout<<"Результат| ";
                        cout<<"Вид победы \n";
			cout<<Ring[i].p1<<" "<<Ring[i].p2<<" "<<Ring[i].Res<<" "<<Ring[i].type<<"\n";
                        }
                i++;}
        }
if (c==3){
        i=0;
        while(i<k){
                if(Ring[i].Res==sw){
                        cout<<"№|";
                        cout<<"Боец №1| ";
                        cout<<"Боец №2| ";
                        cout<<"Результат| ";
                        cout<<"Вид победы \n";
			cout<<Ring[i].p1<<" "<<Ring[i].p2<<" "<<Ring[i].Res<<" "<<Ring[i].type<<"\n";
                        }
                i++;}
        }

}

void del(Boi * Ring, int k)
{
int i=0;
int j;
cout<<"выберите номер боя";
cin>>j;
while (i<k)
{
	if(i==j){
	cout<<i<<" "<<Ring[i].p1<<" "<<Ring[i].p2<<" "<<Ring[i].Res<<" "<<Ring[i].type<<"\n";
	}
i++;
}
ofstream file("spisok.txt");
i=0;
while(i<k)
{
	if(i==j){i++;}
	else{file<<i<<" "<<Ring[i].p1<<" "<<Ring[i].p2<<" "<<Ring[i].Res<<" "<<Ring[i].type<<"\n",i++;}
}
//goto Menu;
}

void results(int Menu)
{
int k=0;
int i=0;
string str;
ifstream file("spisok.txt");

cout<<"№|";
cout<<"Боец №1| ";
cout<<"Боец №2| ";
cout<<"Результат| ";
cout<<"Вид победы \n";
while(getline(file,str)){k++;}
//Boi* Ring=new Boi[k];
file.clear();
file.seekg(0,ios_base::beg);
Boi* Ring=new Boi[k-1];
while (i<k-1)
{
	file>>Ring[i].p1;
	file>>Ring[i].p2;
	file>>Ring[i].Res;
	file>>Ring[i].type;
	i++;
}
i=0;
while (i<k-1)
{
	cout<<i<<"| "<<Ring[i].p1<<" "<<Ring[i].p2<<" "<<Ring[i].Res<<" "<<Ring[i].type<<"\n";
i++;
}
file.close();
if(Menu==3)del(Ring, k);
if(Menu==4)search(Ring, k);
delete [] Ring;
}
void add()
{
Boi fight;
cout<<"введите фамилию первого бойца ";
cin>>fight.p1;
cout<<"введите фамилию второго бойца ";
cin>>fight.p2;
cout<<"введите фамилию победителя (введите 0 если ничья) ";
cin>>fight.Res;
if (fight.Res!="0")
{
	cout<<"введите вид победы ";
	cin>>fight.type;
}
else
{
	fight.type="-";
}
ofstream file1("spisok.txt",std::ios::app);
file1<<fight.p1<<" "<<fight.p2<<" "<<fight.Res<<" "<<fight.type<<" \n ";
file1.close();
}
int main(){
Menu:
//выводим меню
cout<<"Выберите пункт меню\n";
cout<<"1. Вывод\n2. Добавить бой\n3. Удалить бой\n4. Поиск\n5. Выход\n";
int Menu=0;
cin>>Menu;
switch(Menu)
{
	case 1: results(Menu); break;
	case 2: add(); break;
	case 3: results(Menu); break;
	case 4: results(Menu); break;
	case 5: return 0;
	default: break;
}
goto Menu;}

