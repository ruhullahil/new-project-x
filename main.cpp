#include <iostream>
#include <fstream>
#include<conio.h>
#include<bits/stdc++.h>


using namespace std;
class product
{
int code;
string name;
double price;
int quantity;
public:
product()///CONSTRUCTOR
{
code=price=quantity=0;
name="null";
}
void adding_product(int code);
void delating_product();
void editing_product();
void displaying_product();///display all product price
int seaching_product(int cod);///comparing function
double display_product_price(int);///Display billing
void first_adding(int ,string, double,int);/// when programe run
int _return();
string * changing(double []);///file handeling function
};
 string * product::changing(double arr[])/// function file
{
    arr[0]=code;
    arr[1]=price;
    arr[2]=quantity;
    return &name;
}
int product::_return()
{
    return code;
}
void product::first_adding(int code,string name, double price, int quantity)///first adding function extension
{
    this->code=code;
    this->name=name;
    this->price=price;
    this->quantity=quantity;
}
double product::display_product_price(int product_quantity)
{
    if(code==0)
    {

    }
    else
    {
    cout<<code<<setw(10)<<name<<setw(12)<<product_quantity<<setw(8)<<price*product_quantity<<endl;///set width of every printed variable

    }
    quantity=quantity-product_quantity;
    return price*product_quantity;
}

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
void product::displaying_product()///display main display function
{
if(price==0)
{}
else
cout<<setw(5)<<code<<setw(20)<<name<<setw(6)<<quantity<<setw(10)<<price<<endl;
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
int maximum;
product name[60];
void billing_system();
void eaditintng_systemp();
void displaying_stok();
void addin_product();
void delate_product();
void eadit_product();
void file_firstadd();
void display_billing_system(int [],int []);
double VAT(double);
double discount(double);
void firstaddingproduct();
void update();





int main()
{
    firstaddingproduct();///first file adding
    cout<<"1 : for billing system "<<endl;
    cout<<"2 : for editing system "<<endl;
    cout<<"3 : for displaying stoke "<<endl;
    int number;
    cin>>number;
    switch(number)///use switch case
    {
case 1:
    system("cls");///clearing function
    billing_system();///calling billing function
break;
case 2 :
    system("cls");
eaditintng_systemp();///calling editing system function
break;
case 3:
    system("cls");
 displaying_stok();///calling displaying  function
 getch();///holding screen
 system("cls");
 main();///go to main function

default:/// for other value
main();///go to main function
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
system("cls");
addin_product();///calling adding sub- ordinate function
break;
case 2:
    system("cls");
delate_product();/// calling deleting sub-ordinate function
break;
case 3:
    system("cls");
eadit_product();///calling editing sub-ordinate function
break;
default:
cout<<"Sorry, you input wrong number, please prass agin"<<endl;
eaditintng_systemp();///recurse function
}
}

void billing_system()
{
cout<<"Enter code which is buying () press 0 for show memo" <<endl;
int product_id[50];
int product_quantity[50];
for(int i=0;i<50;i++)
{
    cout<<"product_id "<<i+1<<" :";
    cin>>product_id[i];
     if(product_id[i]==0)
        break;
    cout<<"Quantiy :";
    cin>>product_quantity[i];

}
display_billing_system( product_id,product_quantity);///calling billing sub-ordinate function
}
void displaying_stok()
{
cout<<setw(6)<<"Code "<<setw(20)<<"Name"<<setw(10)<<"Quantity"<<setw(6)<<"price"<<endl;
for(int i=0;i<60;i++)
{
name[i].displaying_product();///calling display class function for showing cash memo
}
}
void addin_product()
{
int code;
cout<<"Please press 0 for goto main manu "<<endl;
for(int i=maximum;i<50;i++)
{
cout<<"Enter code :"<<endl;
cin>>code;
if(code==0){
system("cls");
 update();///update file
main();}
else
 name[i].adding_product(code);///calling class function for adding product in class object
 maximum++;/// increasing maximum for show this in stock
 }

 }
 void delate_product()
 {
 int cod,p;
 cout<<"Enter what code you want to delate : "<<endl;
 cin>>cod;
 for(int i=0;i<60;i++)
 {
    if(name[i].seaching_product(cod)==1)///comparing product from object;
    {
     p=i;
    break;
    }
 }
 name[p].delating_product();/// deleting product from object;
 maximum--;///decreasing
 update();///updating file
 getch();
 system("cls");
 main();///go to main menu
}
void eadit_product()
{
int cod,p;
 cout<<"Enter what code you want to Edit : "<<endl;
 cin>>cod;
 for(int i=0;i<60;i++)
 {
    if(name[i].seaching_product(cod)==1)///comparing from object
    {
     p=i;
    break;
    }
 }
 name[p].editing_product();///calling editing function from product function
 update();///updating file
 getch();
 main();/// go to main function
}
void display_billing_system(int product_id[],int quantity [])
{
    system("cls");
    double sum=0;
   for(int i=0; i<50;i++)
    for(int j=0;j<60;j++)
   {
       if(name[j].seaching_product(product_id[i])==1)/// comparing from class object
       {
           sum+=name[j].display_product_price(quantity[i]);/// display from class privet value
       }
   }
   cout<<"____________________________________________________"<<endl;
   cout<<"                          sum="<<sum<<endl;
   cout<< "                    discount ="<<discount(sum)<<endl;///calling display function
   cout<<"                      VAT    ="<<VAT(sum)<<endl;      /// calling VAT function
   cout<<"___________________________________________________________"<<endl;
   cout<<"                  total price="<<sum-discount(sum)+VAT(sum)<<endl;///displaying grand total
   update();///updating file
   getch();
   system("cls");
   main();/// go to main menu

}
double discount(double sum)/// discount functions definition
{
    if(sum>2000)
        return .12*sum;
    else if(sum>1500)
        return .10*sum;
    else
        return 0.0;
}
double VAT(double sum)
{
    return .15*sum;
}
void firstaddingproduct()/// file function definition
{
    fstream st_input;
    st_input.open("product.txt",ios::in);
    int t_code;
    string t_name;
    double t_price;
    int t_quantity;

    maximum=0;
    while(!st_input.eof())///calling end of file function
    {
        st_input>>t_code;
        st_input>>t_name;
        st_input>>t_price;
        st_input>>t_quantity;
        name[maximum].first_adding(t_code,t_name,t_price,t_quantity);
        maximum++;

    }



}
void update()/// defination of updating file function
{
    fstream update;
    update.open("product.txt",ios::out);///opening file

    double arr[3];
    string *nam;///declaring pointer variable
    for(int i=0; i<maximum;i++)
    {
       nam=name[i].changing(arr);
       update<<arr[0]<<" ";
       update<<*nam<<" ";/// inserting pointer value s
       update<<arr[1]<<" ";
       update<<arr[2];
       update<<endl;
    }
}


