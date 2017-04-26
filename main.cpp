#include <iostream>
#include <time.h>
#include <fstream>
#include <iomanip>


using namespace std;
class product
{
int code;
string name;
double price;
int quantity;
public:
product()
{
code=price=quantity=0;
name="null";
}
void first_adding();
void adding_product(int code);
void delating_product();
void editing_product();
void displaying_product();
int seaching_product(int cod);
void productadd(int cod,string nam, double prce, int quantite);

};
void product::adding_product(int cod)
{
code=cod;
cout<<"Enter name of product(without space) :"<<endl;
cin>>name;
cout<<"Enter price  per product "<<endl;
cin>>price;
cout<<"Enter product quantity : "<<endl;
cin>>quantity;

}
void product::displaying_product()
{
if(price==0)
{}
else
cout<<code<<setw(12)<<name<<setw(15)<<quantity<<setw(15)<<price<<endl;
}
void product::delating_product()
{
code=0;
quantity=0;
price=0;
}
int product::seaching_product(int cod)
{
int r=0;
if(code==cod)
{
r=1;
}
return r;
}
void product::editing_product()
{
int cd;
cout<<"1:change quantity "<<endl;
cout<<"2:change  price of product"<<endl;
cin>>cd;
switch(cd)
{
case 1:
cout<<"Enter quantity of "<<code<<" no product"<<endl;
cin>>quantity;
break;
case 2:
cout<<"Enter price of "<<code<<" no product"<<endl;
cin>>price;
break;

}


}
void product::productadd(int cod, string nam,double pric,int quantite)
{
	code=cod;
	name=nam;
	price=pric;
	quantity= quantite;
}
	
	
int maximum;
product name[60];
void eaditintng_systemp();
void displaying_stok();
void addin_product();
void delate_product();
void eadit_product();


int main()
{
	fstream input;
	input.open("bill_input.txt",ios::in|ios::app);
	int i=0;
	int cod;
	string nam;
	double price;
	int quntity; 
	while(!input.eof())
	{
		input>>cod;
		input>>nam;
		input>>price;
		input>>quntity;
		name[i].productadd(cod,nam,price,quntity);
		i++;
	}
	input.close();
		
    cout<<"1 : for billing system "<<endl;
    cout<<"2 : for editing system "<<endl;
    cout<<"3 : for displaying stoke "<<endl;
    int number;
    cin>>number;
    switch(number)
    {
case 1:
main();
case 2 :
eaditintng_systemp();
break;
case 3:
 displaying_stok();
 main();

default:
main();
    }


    return 0;
}
void eaditintng_systemp()
{
int look;
cout<<"1: Adding  product"<<endl;
cout<<"2: Delating product"<<endl;
cout<<"3: Editing product "<<endl;
cin>>look;
switch(look)
{
case 1:
addin_product();
break;
case 2:
delate_product();
break;
case 3:
eadit_product();
break;
default:
cout<<"Sorry, you input wrong number, please prass agin"<<endl;
eaditintng_systemp();

}



}

void billing_system()
{








}
void displaying_stok()
{
cout<<"Code "<<"\t"<<"Name"<<"\t\t"<<"Quantity"<<"\t"<<"price"<<endl;
for(int i=0;i<60;i++)
{
name[i].displaying_product();
}
}
void addin_product()
{
int code[60];
cout<<"Please press 0 for goto main manu "<<endl;
for(int i=0;i<50;i++)
{
cout<<"Enter code :"<<endl;
cin>>code[i];
if(code[i]==0)
main();
else
 name[i].adding_product(code[i]);
 }
 }
 void delate_product()
 {
 int cod,p;
 cout<<"Enter what code you want to delate : "<<endl;
 cin>>cod;
 for(int i=0;i<60;i++)
 {
    if(name[i].seaching_product(cod)==1)
    {
     p=i;
    break;
    }
 }
 name[p].delating_product();
}
void eadit_product()
{
int cod,p;
 cout<<"Enter what code you want to Edit : "<<endl;
 cin>>cod;
 for(int i=0;i<60;i++)
 {
    if(name[i].seaching_product(cod)==1)
    {
     p=i;
    break;
    }
 }
 name[p].editing_product();
}
