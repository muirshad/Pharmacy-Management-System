

#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#define max 10

using namespace std;
//the header file

class medicineType	//base class
{
public:

    void take_order();//to  take_order
    void delete_order(); //to delete the order
    void modify(); //to modify the order
	void order_list(); //to display the order_list
	void daily_summary(); //to display daily_summary
	void exit();  //function to exit system
	medicineType();//constuctor

};

 medicineType::medicineType ()
{

}		//constructor for class CarType


struct node //constract node
{
	int reciept_number;
	string customerName;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Probiotics","Vitamin C(500mg)","Acid Free C(500mg)","Women'S Multivate","Marino Tablet","Maxi Cal Tablet",
	"Amino Zinc Tablet","Burnex","Fabuloss 5","Royal Propollen"};
	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double total;

	node *prev;
	node *next;
	node *link; 

}*q, *temp;				//pointer declaration 


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;

int main()	// Main function
{

	system("COLOR 4e");		//Color to change background
	medicineType medicine;
	int menu;
	do
	{
		system("cls");
		cout<<"\n\n\t\t\t\t\t\t\t**************************************************\n";
		cout<<"\t\t\t\t\t\t\t||         PHARMACY MANAGEMENT SYSTEM           ||\n";
		cout<<"\t\t\t\t\t\t\t**************************************************\n\n";
		cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n\n";
		cout<<"\t\t\t\t\t\t\t||\t1. Take new Medicine order \t\t ||\n\n";
		cout<<"\t\t\t\t\t\t\t||\t2. Delete latest Medicine order\t\t ||\n\n";
		cout<<"\t\t\t\t\t\t\t||\t3. Modify Order List \t\t\t ||\n\n";
		cout<<"\t\t\t\t\t\t\t||\t4. Print the Reciept and Make Payment \t ||\n\n";
		cout<<"\t\t\t\t\t\t\t||\t5. Daily Summary of total Sale \t\t ||\n\n";
		cout<<"\t\t\t\t\t\t\t||\t6. Exit\t\t\t\t\t ||\n\n";
		cout<<"\t\t\t\t\t\t\t--------------------------------------------------\n\n";
		cout<<"\t\t\t\t\t\t\tEnter choice: ";

		cin>>menu;

		switch (menu)
		{
		case 1:
			{
				medicine.take_order();	//function add
				break;
			}	//end case 1
		
		
		case 2:
			{
				medicine.delete_order();	//function delete
				cout<<"\t\t\t\t\t\t\t";system("PAUSE");
				break;
			}	//end case 2
			
		case 3:
			{
				medicine.modify();	//function modify
				cout<<"\t\t\t\t\t\t\t";system("PAUSE");
				break;
			}	//end case 3

		case 4:
			{
				medicine.order_list();	//function order
				cout<<"\t\t\t\t\t\t\t";system("PAUSE");
				break;
			}	//end case 4
		case 5:
			{
				medicine.daily_summary();	//function daily_summary
				cout<<"\t\t\t\t\t\t\t";system("PAUSE");
				break;
			}	//end case 5
        case 6:
			{
				medicine.exit();	//function exit
				goto a;
				break;
			}	//end case 6

		
		default:
			{
				cout<<"\t\t\t\t\t\t\tYou enter invalid input\nre-enter the input\n"<<endl;
				break;
			}//end defeault
		}//end Switch
	}while(menu!=6);//end do
	a://goto
	cout<<"\t\t\t\t\t\t\tthank you"<<endl;
	cout<<"\t\t\t\t\t\t\t";system ("PAUSE");
	return 0;
}//end  main function


void medicineType::take_order()		//function to take_order
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	            cout <<"\n\t\t\t\t\t\t\t\t                       Add Order Details\n";
            	cout <<"\t\t\t\t\t\t\t___________________________________________________________________________ \n\n";

	node *temp;
	temp=new node;

				cout <<"\t\t\t\t\t\t\t***************************************************************************\n";
				cout<<"\t\t\t\t\t\t\tDRUGS ID"<<"\tDRUGS TYPE"<<"   \t\tDRUGS NAME"<<"           DRUGS PRICE($)"<<endl;
				cout <<"\t\t\t\t\t\t\t***************************************************************************\n";
                cout<<"\t\t\t\t\t\t\t01"<<"\t"<<"\tOTC"<<"\t\t"<<"      Probiotics"<<"  	        $ 2.00"<<endl;
                cout<<"\t\t\t\t\t\t\t02"<<"\t"<<"\tOTC"<<"\t\t"<<"      Vitamin C(500mg)"<<"		$ 3.00"<<endl;
                cout<<"\t\t\t\t\t\t\t03"<<"\t"<<"\tOTC"<<"\t\t"<<"      Acid Free C(500mg)"<<"	$ 1.00"<<endl;
                cout<<"\t\t\t\t\t\t\t04"<<"\t"<<"\tOTC"<<"\t\t"<<"      Women'S Multivate"<<"		$ 4.00"<<endl;
                cout<<"\t\t\t\t\t\t\t05"<<"\t"<<"\tOTC"<<"\t\t"<<"      Marino Tablet"<<"	    	$ 1.00"<<endl;
                cout<<"\t\t\t\t\t\t\t06"<<"\t"<<"\tOTC"<<"\t\t"<<"      Maxi Cal Tablet"<<" 		$ 5.00"<<endl;
                cout<<"\t\t\t\t\t\t\t07"<<"\t"<<"\tOTC"<<"\t\t"<<"      Amino Zinc Tablet"<<"		$ 7.00"<<endl;
                cout<<"\t\t\t\t\t\t\t08"<<"\t"<<"\tOTC"<<"\t\t"<<"      Burnex"<<"		        $ 4.00"<<endl;//1353fn
                cout<<"\t\t\t\t\t\t\t09"<<"\t"<<"\tOTC"<<"\t\t"<<"      Fabuloss 5"<<"	  	$ 3.00"<<endl;
                cout<<"\t\t\t\t\t\t\t10"<<"\t"<<"\tOTC"<<"\t\t"<<"      Royal Propollen"<<"	    	$ 5.00"<<endl;
                cout<<" "<<endl;
    
	temp = new node;
	cout <<"\t\t\t\t\t\t\t**************************************************************************\n";
	cout << "\t\t\t\t\t\t\tType Order no: ";
    cin >> temp->reciept_number;
	cout<< "\t\t\t\t\t\t\tEnter Customer Name: ";
	cin>> temp->customerName;
	cout<<"\t\t\t\t\t\t\tEnter Date : ";
	cin>>temp->date;
	cout << "\t\t\t\t\t\t\tHow many Medicine would you like to order:"<< endl;
	cout<<"\t\t\t\t\t\t\t( Maximum is 10 order for each transaction ) : ";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "\t\t\t\t\t\t\tThe Medicine you order is exceed the maximum amount of order !";
		system("\t\t\t\t\t\t\tpause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "\t\t\t\t\t\t\tPlease enter your selection : ";
		cin>> temp->menu2[i];
        cout<< "\t\t\t\t\t\t\tMedicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "\t\t\t\t\t\t\tHow many medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "\t\t\t\t\t\t\tThe amount You need to pay is: " << temp->amount[i]<<" $"<<endl;
        cout<<"\t\t\t\t\t\t\t";system("PAUSE");
                      
	}
	cout<<"\t\t\t\t\t\t\t==========================================================================="<<endl;
    cout << "\t\t\t\t\t\t\t                        Order Taken Successfully"<<endl;
    cout<<"\t\t\t\t\t\t\t==========================================================================="<<endl;
    cout << "\t\t\t\t\t\t\t                    Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"\t\t\t\t\t\t\t==========================================================================="<<endl;
	cout<<"\t\t\t\t\t\t\t";system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
}
}//End function take_order


void medicineType::order_list()		//Function to display receipt
{
	int i, num, num2;	
	bool found;			//variable to search 
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;
	
	cout<<"\t\t\t\t\t\t\tEnter the Reciept Number To Print The Reciept\n";
	cout<<"\t\t\t\t\t\t\t";cin>>num2;
	cout<<"\n";
	cout<<"\t\t\t\t\t\t\t==========================================================================="<<endl;
	cout <<"\t\t\t\t\t\t\tHere is the Order list\n"; 
	cout<<"\t\t\t\t\t\t\t==========================================================================="<<endl;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\t\t\t\t\t\t\tThere is no Order to show\n\t\t\t\t\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
		cout <<"\t\t\t\t\t\t\tReciept Number : "<<temp->reciept_number;
		cout <<"\n";
		cout<<"\t\t\t\t\t\t\tCustomer Name: "<<temp->customerName<<endl;
				
		cout<<"\t\t\t\t\t\t\tOrder Date : "<<temp->date<<endl;
				
		cout<<"\t\t\t\t\t\t\t_____________________________________________________________________________"<<endl;
			
		cout << "\t\t\t\t\t\t\t===============================================================================" << endl;
		cout << "\t\t\t\t\t\t\t|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
		cout << "\t\t\t\t\t\t\t=======++==================++================++===============++===============" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout <<"\t\t\t\t\t\t\t" <<temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" $"<<endl;
			cout<<"\t\t\t\t\t\t\t_________________________________________________________________________________"<<endl;
		}
		
		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"\t\t\t\t\t\t\tTotal Bill is : "<<temp->total;
		cout<<"\n";
		cout << "\t\t\t\t\t\t\tType the exact amount You need to pay: ";
        cin >> num;

		cout <<"\n";
		cout <<"\n";
		cout<<"\t\t\t\t\t\t\tPayment Done\n\t\t\t\t\t\t\tThank You\n";
		cout <<"\n\t\t\t\t\t\t\t_______________________________________________________________________________\n";
		}


}
}	//End function order_list


void medicineType::delete_order()	//function to delete_order
{
	system("cls");
	int i, num, count;
    cout<<"\t\t\t\t\t\t\tEnter the data you want to delete \n";
    cout<<"\t\t\t\t\t\t\t";cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"\t\t\t\t\t\t\tCan not delete from an empty list.\n";
	else
	{
		if(start_ptr->reciept_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"\t\t\t\t\t\t\tThe Reciept is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;
	
		while((!found) && (q != NULL))
		{
  			if(q->reciept_number != num) 
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q) 
				last = temp;
				delete q;
				cout<<"\t\t\t\t\t\t\tThe Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"\t\t\t\t\t\t\tItem to be deleted is not in the list."<<endl;
			}
		} 
}	//End function delete_order



void medicineType::modify()		//function to modify order
{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start_ptr;
 cout<<"\t\t\t\t\t\t\tEnter Receipt Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"\t\t\t\t\t\t\tNO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "\t\t\t\t\t\t\tChange  Order Number: ";
    cin >> temp->reciept_number;
	cout<< "\t\t\t\t\t\t\tChange Customer Name: ";
	cin>> temp->customerName;
	cout<<"\t\t\t\t\t\t\tChange Date : ";
	cin>>temp->date;
	cout << "\t\t\t\t\t\t\tHow many New Medicine would you like to Change:"<< endl;
	cout<<"\t\t\t\t\t\t\t( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "\t\t\t\t\t\t\tThe Medicine you order is exceed the maximum amount of order !";
		cout<<"\t\t\t\t\t\t\t";system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{
		
		cout << "\t\t\t\t\t\t\tPlease enter your selection to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "\t\t\t\t\t\t\tChange Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "\t\t\t\t\t\t\tHow many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "\t\t\t\t\t\t\tThe amount You need to pay After Modify  is: " << temp->amount[i]<<" RM"<<endl;
        cout<<"\t\t\t\t\t\t\t";system("PAUSE");
	}
	temp = temp->next;
	system("cls");
	
	}

 cout<<"\t\t\t\t\t\t\tRECORD MODIFIED....!"<<endl;
 }
 else 
 {
 	if(temp != NULL && temp->reciept_number != sid)
 	{
 	cout<<"\t\t\t\t\t\t\tInvalid Reciept Number...!"<<endl;
    }
 }
}
}
}		//End modify function



void medicineType::daily_summary()		//Function to display Daily Summary
{
	int i,num;
	system("cls");
	node *temp ;

	temp=start_ptr;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\t\t\t\t\t\t\tThere is no Order to show\n\t\t\t\t\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"\t\t\t\t\t\t\t==========================================================================="<<endl;
		cout <<"\t\t\t\t\t\t\t \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"\t\t\t\t\t\t\t==========================================================================="<<endl;

		while(temp!=NULL)
		{
		
				cout <<"\t\t\t\t\t\t\tReciept Number : "<<temp->reciept_number;
				cout <<"\n";
				cout<<"\t\t\t\t\t\t\tCustomer Name: "<<temp->customerName<<endl;
				
				cout<<"\t\t\t\t\t\t\tOrder Date : "<<temp->date<<endl;
				
				cout<<"\t\t\t\t\t\t\t____________________________________________________________________________"<<endl;
			
				cout << "\t\t\t\t\t\t\t==========================================================================" << endl;
				cout << "\t\t\t\t\t\t\t|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "\t\t\t\t\t\t\t=======++==================++================++===============++==========" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout <<"\t\t\t\t\t\t\t"<< temp->type <<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" RM"<<endl;
				cout<<"\t\t\t\t\t\t\t_____________________________________________________________________________"<<endl;
			}
			
			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"\t\t\t\t\t\t\tTotal Bill is : "<<temp->total;
		
			cout <<"\n";
			cout <<"\n";
			cout <<"\n\t\t\t\t\t\t\t_______________________________________________________________________________\n";
				
			temp=temp->next;
		}
	}
}		//End daily summary
void medicineType::exit() //Function to exit
{
	cout<<"\n\t\t\t\t\t\t\tYou choose to exit.\n"<<endl;
}	//end function exit


////////////////////////////THE END OF PROGRAM//////////////////////////////////////////
