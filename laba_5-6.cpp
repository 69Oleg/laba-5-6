#include <iostream>
#include <string>
using namespace std;
class Zoo
{
    public:
    string name;
    string strana;
    string korpys1;
    string korpys2;
    string work_time;
    int cena;
    int kolich;
    Zoo():
    name(""),strana(""),korpys1(""),korpys2(""),work_time(""),cena(0),kolich(0)
    {}
    Zoo(string nazvzoo,string nazvstrani, int korpysa, int korpysb, int rabvremya, int bileti, int kolvo)
    :name(nazvzoo), strana(nazvstrani), korpys1(0), korpys2(0), work_time(0), cena(0),kolich(0)
    {}
    Zoo(const Zoo & other):
    name(other.name),strana(other.strana),korpys1(other.korpys1),korpys2(other.korpys2),work_time(other.work_time),cena(NULL),kolich(NULL)
    {}
    ~Zoo(){}
    void print_the_zoo()
{
cout << "nazvanie zooparka " << name << endl;
cout << "nazvanie strani" << strana << endl;
cout << "1 korpys zoo" << korpys1 << endl;
cout << "2 korpys zoo" << korpys2 << endl;
cout << "vremya raboti" << work_time << endl;
cout << "cena bileta" << cena<< endl;
cout << "kolichestvo zhivotnih" << kolich<< endl;
}
void print_nazvzoo(){cout << name << endl;}
void print_nazvstrani(){cout << strana << endl;}
void print_korpysa(){cout << korpys1 << endl;}
void print_korpysb(){cout << korpys2 << endl;}
void print_rabvremya(){cout << work_time << endl;}
void print_bileti(){cout << cena << endl;}
void print_kolvo(){cout << kolich << endl;}

void izm_nazvzoo(string new_name){name = new_name;}
void izm_nazvstrani(string new_strana){strana = new_strana;}
void izm_korpysa(int new_korpys1){korpys1 = new_korpys1;}
void izm_korpysb(int new_korpys2){korpys2 = new_korpys2;}
void izm_rabvremya(int new_work_time){work_time = new_work_time;}
void izm_bileti(int new_cena){cena = new_cena;}
void izm_kolvo(int new_kolich){kolich = new_kolich;}

friend void spisok_kolva_zhiv_za_N(int vse, Zoo* zoo, int vremya, int N);
friend void spisok_of_zoo(int vse, Zoo* zoo,string names);
};

void spisok_of_zoo(int vse, Zoo* zoo,string names)
{
for(int i = 0; i < vse; ++i)
{
if (zoo[i].name == names){zoo[i].print_nazvzoo();}
}
}
void spisok_kolva_zhiv_za_N(int vse, Zoo* zoo, int vremya, int N)
{
    int vsego_animals = 0;
    for(int i = 0; i < vse; ++i)
    {
        int time_per_animal = N * zoo[i].kolich;
        if (time_per_animal <= vremya)
        {
            vsego_animals += zoo[i].kolich;
            vremya -= time_per_animal;
        }
        else
        {
            int animals_to_visit = vremya / N;
            vsego_animals += animals_to_visit;
            break;
        }
    }
}
int main()
{
    Zoo perviy; 
    cout << "do izmeneniy:" <<endl;

    perviy.izm_nazvzoo("Moskovskiy");
    perviy.izm_nazvstrani("Russia");
    perviy.izm_korpysa(10);
    perviy.izm_korpysb(40);
    perviy.izm_rabvremya(14);
    perviy.izm_bileti(800);
    perviy.izm_kolvo(50);
    cout << "posle izmeneniy" <<endl;
    perviy.print_the_zoo();
    
    Zoo zoopark1("Piterskiy","Russia", 20, 50, 12, 500, 70);
    Zoo zoopark2("Rostovskiy","Russia", 40, 60, 13,1000,100);
    Zoo zoo[3] = {perviy,zoopark1,zoopark2};
    cout << "spisok zooparkov" <<endl;
    spisok_of_zoo(3, zoo ,"perviy,zoopark1,zoopark2");

    cout << "kolichestvo zhivotnih za vremya" <<endl;
    spisok_kolva_zhiv_za_N(50, zoo, 14 , 50);
    return 0;
}