#include <iostream> //to include the input , output operations
#include <fstream> //to performing file input , output operations
#include <string> //to deal with a sequence of characters

using namespace std;

ofstream out ;

#define CUSTOMOR_COUNT 100 // array declaration
#define SHOP_COUNT 100 // array declaration
#define DeliveryOrder_COUNT 100 // array declaration

struct NameType // declare struct for name informations
{
	string first;
	string middle;
	string last;
	string fullname;
};

struct AddressType // declare struct for address informations
{
	string address;
	string city;
	string state;
	string zip;
};

struct ContactType // declare struct for contact informations
{
	string phone;
	string cellphone;
	string fax;
	string email;
};

struct CustomerType // declare struct for customer informations
{
	NameType name;
	AddressType address;
	ContactType contact;
}customerlist[CUSTOMOR_COUNT]; //customer array declaration

struct ShopType // declare struct for shop informations
{
	NameType name;
	AddressType address;
	ContactType contact;
	string website;
}shoplist[SHOP_COUNT]; //shop array declaration

struct ItemType // declare struct for item informations
{
    string order;
    string item;
    string qty;
    string value;
};

struct DeliveryOrder // declare struct for delivery order informations
{
    ItemType item;
    NameType name;
    AddressType address;
	ContactType contact;
	ShopType website;
}delivery[DeliveryOrder_COUNT]; //delivery order array declaration

void AddCustomer(int count) // function to read customer informations
{
	
	cout<<"\n- Enter Customer Details -\n";
    cout<<"First Name: ";
    cin>>customerlist[count].name.first;
    cout<<"Middle Name: ";
    cin>>customerlist[count].name.middle;
    cout<<"Last Name: ";
    cin>>customerlist[count].name.last;

    cout<<"\n- Customer Address Details -\n";
    cout<<"Address: ";
    cin>>customerlist[count].address.address;
    cout<<"City: ";
    cin>>customerlist[count].address.city;
    cout<<"State: ";
    cin>>customerlist[count].address.state;
    cout<<"ZIP: ";
    cin>>customerlist[count].address.zip;

   cout<<"\n- Customer Contact Details -\n";
    cout<<"Phone number: ";
    cin>>customerlist[count].contact.phone;
    cout<<"Cellphone number: ";
    cin>>customerlist[count].contact.cellphone;
    cout<<"Fax number: ";
    cin>>customerlist[count].contact.fax;
    cout<<"Email address: ";
    cin>>customerlist[count].contact.email;
    cout<<endl;
	
}


void AddShop(int count) // function to read shop informations
{
	
	
    cout<<"\n- Enter Shop Details -\n";
    cout<<"Shop Name: ";
    cin>>shoplist[count].name.fullname;

    cout<<"\n- Shop Address Details -\n";
    cout<<"Address: ";
    cin>>shoplist[count].address.address;
    cout<<"City: ";
    cin>>shoplist[count].address.city;
    cout<<"State: ";
    cin>>shoplist[count].address.state;
    cout<<"ZIP: ";
    cin>>shoplist[count].address.zip;

    cout<<"\n- Shop Contact Details -\n";
    cout<<"Phone number: ";
    cin>>shoplist[count].contact.phone;
    cout<<"Cellphone number: ";
    cin>>shoplist[count].contact.cellphone;
    cout<<"Fax number: ";
    cin>>shoplist[count].contact.fax;
    cout<<"Email address: ";
    cin>>shoplist[count].contact.email;
    cout<<"Website Name: ";
    cin>>shoplist[count].website;
    cout<<endl;
    
}


void AddDeliveryOrder(int count) // function to read delivery order informations
{
	
    cout<<"\n- Enter Delivery Order Details -\n";
    cout<<"Order: ";
    cin>>delivery[count].item.order;
    cout<<"Item: ";
    cin>>delivery[count].item.item;
    cout<<"Quantity: ";
    cin>>delivery[count].item.qty;
    cout<<"Value: ";
    cin>>delivery[count].item.value;
    
    cout<<"\n- Enter Customer Details -\n";
    cout<<"Customer Name: ";
    cin>>delivery[count].name.first;
    cout<<"Phone number: ";
    cin>>delivery[count].contact.phone;
    cout<<"Address: ";
    cin>>delivery[count].address.address;
    
    cout<<"\n- Enter Shop Details -\n";
    cout<<"Shop Name: ";
    cin>>delivery[count].name.fullname;
    cout<<"Phone number: ";
    cin>>delivery[count].contact.phone;
    cout<<"Website Name: ";
    cin>>delivery[count].website.website;
    cout<<"Address: ";
    cin>>delivery[count].address.address;
    cout<<endl;
    
}


void Canceldeliver(string order, int counter) // function to cancel specific delivery order informations
{                                             // it cancel a correct record by order number 
    for(int ctr = 0; ctr < counter ; ctr++)   // this loop to check all records from first record to last record
    {
         if(delivery[ctr].item.order.compare(order)==0) // to check if the correct record 
         {
           for(int i=ctr ;i<100; i++)
           {
           delivery[i].item.order=delivery[i+1].item.order; 
           delivery[i].item.item=delivery[i+1].item.item;
           delivery[i].item.qty=delivery[i+1].item.qty;
           delivery[i].item.value=delivery[i+1].item.value;
           delivery[i].name.first=delivery[i+1].name.first;
           delivery[i].contact.phone=delivery[i+1].contact.phone;
           delivery[i].address.address=delivery[i+1].address.address;
           delivery[i].name.fullname=delivery[i+1].name.fullname;
           delivery[i].website.website=delivery[i+1].website.website;
           }
         }
         cout<<endl;
    }
    cout<<"This Delivery Order has deleted"<<endl; // this message to tell to the user that deletion succeeded
}


void displayALLcustomer(int ctr) // function to display all customers informations
{
	 out.open("display customer.txt") ; 
	 
    for(int count = 0; count < ctr; count++) // loop to repet statments to all customor
	{
    	out << "-----------Customer " << count + 1   <<" Details -----------\n";
		out << "First Name: " << customerlist[count].name.first << "\n";
		out << "Middle Name: " << customerlist[count].name.middle << "\n";
		out << "Last Name: " << customerlist[count].name.last << "\n";
	    
	    out << "\n - Address Details - \n";
		out << "Address: " << customerlist[count].address.address << "\n";
		out << "City: " << customerlist[count].address.city<< "\n";
	    out << "State: " << customerlist[count].address.state<< "\n";
	    out << "ZIP: " << customerlist[count].address.zip<< "\n";
	    
		out << "\n- Contact Details - \n";
    	out << "Phone number: " << customerlist[count].contact.phone<< "\n";
    	out << "Cellphone number: " << customerlist[count].contact.cellphone<< "\n";
	    out << "Fax number: " << customerlist[count].contact.fax<< "\n";
	    out << "Email address: " << customerlist[count].contact.email<< "\n";	
	
		out << "-------------------End of Record----------------------\n";
		
		
	}
	out.close() ; 
}

void displaycustomer(int count) // function to display only one customer informations
{                               // it is a part of (searchcustomer function)

    	cout << "-----------Customer " << count + 1   <<" Details -----------\n";
		cout << "First Name: " << customerlist[count].name.first << "\n";
		cout << "Middle Name: " << customerlist[count].name.middle << "\n";
		cout << "Last Name: " << customerlist[count].name.last << "\n";
	    
	    cout << "\n - Address Details - \n";
		cout << "Address: " << customerlist[count].address.address << "\n";
		cout << "City: " << customerlist[count].address.city<< "\n";
	    cout << "State: " << customerlist[count].address.state<< "\n";
	    cout << "ZIP: " << customerlist[count].address.zip<< "\n";
	    
		cout << "\n- Contact Details - \n";
    	cout << "Phone number: " << customerlist[count].contact.phone<< "\n";
    	cout << "Cellphone number: " << customerlist[count].contact.cellphone<< "\n";
	    cout << "Fax number: " << customerlist[count].contact.fax<< "\n";
	    cout << "Email address: " << customerlist[count].contact.email<< "\n";	
	
		cout << "-------------------End of Record----------------------\n";
		
}


void displayALLshop(int ctr) // function to display all shop informations
{
		
	    for(int count = 0; count < ctr; count++) // loop to repet statments to all shop
	{
        cout << "-----------Shop " << count + 1  <<" Details -----------\n";
		cout << "Name: " << shoplist[count].name.fullname << "\n";
	    
	    cout << "\n - Address Details - \n";
		cout << "Address: " << shoplist[count].address.address << "\n";
		cout << "City: " << shoplist[count].address.city<< "\n";
	    cout << "State: " << shoplist[count].address.state<< "\n";
	    cout << "ZIP: " << shoplist[count].address.zip<< "\n";
	    
		cout << "\n- Contact Details - \n";
    	cout << "Phone number: " << shoplist[count].contact.phone<< "\n";
    	cout << "Cellphone number: " << shoplist[count].contact.cellphone<< "\n";
	    cout << "Fax number: " << shoplist[count].contact.fax<< "\n";
	    cout << "Email address: " << shoplist[count].contact.email<< "\n";	
	    cout << "Website Name: " << shoplist[count].website<< "\n";	
	
		cout << "-------------------End of Record----------------------\n";
		
	
	 }
}

void displayshop(int count) // function to display only one shop informations
{                           // it is a part of (searchshop function)
          
        cout << "-----------Shop " << count + 1  <<" Details -----------\n";
		cout << "Name: " << shoplist[count].name.fullname << "\n";
	    
	    cout << "\n - Address Details - \n";
		cout << "Address: " << shoplist[count].address.address << "\n";
		cout << "City: " << shoplist[count].address.city<< "\n";
	    cout << "State: " << shoplist[count].address.state<< "\n";
	    cout << "ZIP: " << shoplist[count].address.zip<< "\n";
	    
		cout << "\n- Contact Details - \n";
    	cout << "Phone number: " << shoplist[count].contact.phone<< "\n";
    	cout << "Cellphone number: " << shoplist[count].contact.cellphone<< "\n";
	    cout << "Fax number: " << shoplist[count].contact.fax<< "\n";
	    cout << "Email address: " << shoplist[count].contact.email<< "\n";	
	    cout << "Website Name: " << shoplist[count].website<< "\n";	
	
		cout << "-------------------End of Record----------------------\n";
		
}


void Updatecustomer(string phone, int counter) // function to update one customer informations
{
    
    for(int ctr=0; ctr<counter ; ctr++ ) // this loop to check all records from first record to last record 
    {
        if(customerlist[ctr].contact.phone.compare(phone)==0) // to check if the correct record
        {
            cout<<"\n--------------Update Customer Details--------------\n";
            
            cout<<"New first name: ";
            cin>> customerlist[ctr].name.first;
            cout<<"New middle name: ";
            cin>>customerlist[ctr].name.middle;
            cout<<"New last name: ";
            cin>>customerlist[ctr].name.last;
            cout<<endl;
            
            cout<<"New address: ";
            cin>> customerlist[ctr].address.address;
            cout<<"New city: ";
            cin>>customerlist[ctr].address.city;
            cout<<"New state: ";
            cin>>customerlist[ctr].address.state;
            cout<<"New ZIP: ";
            cin>>customerlist[ctr].address.zip;
            cout<<endl;
            
            cout<<"New phone number: ";
            cin>>customerlist[ctr].contact.phone;
            cout<<"New cellphone number: ";
            cin>> customerlist[ctr].contact.cellphone;
            cout<<"New fax number: ";
            cin>> customerlist[ctr].contact.fax;
            cout<<"New email address: ";
            cin>>customerlist[ctr].contact.email;
            cout<<endl;
            
        }
    }
}


void Updateshop(string phone, int counter) // function to update one shop informations
{
    
    for(int ctr=0; ctr<counter ; ctr++ ) // this loop to check all records from first record to last record
    {
        if(shoplist[ctr].contact.phone.compare(phone)==0) // to check if the correct record
        {
            cout<<"\n--------------Update Shop Details--------------\n";
            
            cout<<"New name: ";
            cin>>shoplist[ctr].name.fullname;
            cout<<endl;
            
            cout<<"New address: ";
            cin>>shoplist[ctr].address.address;
            cout<<"New city: ";
            cin>>shoplist[ctr].address.city;
            cout<<"New state: ";
            cin>> shoplist[ctr].address.state;
            cout<<"New ZIP: ";
            cin>>shoplist[ctr].address.zip;
            cout<<endl;
            
            cout<<"New phone number: ";
            cin>> shoplist[ctr].contact.phone;
            cout<<"New cellphone number: ";
            cin>>shoplist[ctr].contact.cellphone;
            cout<<"New fax number: ";
            cin>>shoplist[ctr].contact.fax;
            cout<<"New email address: ";
            cin>>shoplist[ctr].contact.email;
            cout<<"New website name: ";
            cin>>shoplist[ctr].website;
            cout<<endl;
            
        }
    }
}


void Deletecustomer(string phone, int counter) // function to delet one customer informations
{
    for(int ctr = 0; ctr < counter ; ctr++) // this loop to check all records from first record to last record
    {
         if(customerlist[ctr].contact.phone.compare(phone)==0) // to check if the correct record
         {
            for(int i=ctr ;i<100; i++)
            {
            customerlist[i].name.first=customerlist[i+1].name.first; 
            customerlist[i].name.middle=customerlist[i+1].name.middle;
            customerlist[i].name.last=customerlist[i+1].name.last;
            customerlist[i].address.address=customerlist[i+1].address.address;
            customerlist[i].address.city=customerlist[i+1].address.city;
            customerlist[i].address.state=customerlist[i+1].address.state;
            customerlist[i].address.zip=customerlist[i+1].address.zip;
            customerlist[i].contact.phone=customerlist[i+1].contact.phone;
            customerlist[i].contact.cellphone=customerlist[i+1].contact.cellphone;
            customerlist[i].contact.fax=customerlist[i+1].contact.fax;
            customerlist[i].contact.email=customerlist[i+1].contact.email;
            }
         }
    }
    cout<<"This customerlist has deleted"<<endl; // this message to tell to the user that deletion succeeded
}


void Deleteshop(string phone, int counter) // function to delet one shop informations
{
    for(int ctr = 0; ctr < counter ; ctr++) // this loop to check all records from first record to last record
    {
         if(shoplist[ctr].contact.phone.compare(phone)==0) // to check if the correct record
         {
             for(int i=ctr ;i<100; i++)
             {
                
            shoplist[i].name.fullname=shoplist[i+1].name.fullname; 
            shoplist[i].address.address=shoplist[i+1].address.address;
            shoplist[i].address.city=shoplist[i+1].address.city;
            shoplist[i].address.state=shoplist[i+1].address.state;
            shoplist[i].address.zip=shoplist[i+1].address.zip;
            shoplist[i].contact.phone=shoplist[i+1].contact.phone;
            shoplist[i].contact.cellphone=shoplist[i+1].contact.cellphone;
            shoplist[i].contact.fax=shoplist[i+1].contact.fax;
            shoplist[i].contact.email=shoplist[i+1].contact.email;
            shoplist[i].website=shoplist[i+1].website;
             }
         }
         
    }
    cout<<"This shoplist has deleted"<<endl; // this message to tell to the user that deletion succeeded
}

void searchcustomer(string phone, int counter) // function to search for one customer informations
{
	int phonN = -1; //Initial assumption that there is no phone number
	
	for(int ctr = 0; ctr < counter; ctr++) // this loop to check all records from first record to last record
	{
		if(phone == customerlist[ctr].contact.phone) // to check if the correct record
		{
			phonN = ctr; //add the number of index to this valuable
			break; //exit condition
		}
		
	}
	
	if(phonN != -1) //if there any value to this valuable
		displaycustomer(phonN);	// call the function
	else // if there is no vale
		cout << "customer not found!\n\n"; //display this message
}

void searchshop(string phone, int counter) // function to search for one shop informations
{
	int phonN = -1; //Initial assumption that there is no phone number
	
	for(int ctr = 0; ctr < counter; ctr++) // this loop to check all records from first record to last record
	{
		if(phone == shoplist[ctr].contact.phone) // to check if the correct record
		{
			phonN = ctr; //add the number of index to this valuable
			break; //exit condition
		}
		
	}
	
	if(phonN != -1) //if there any value to this valuable
		displayshop(phonN);	// call the function
	else  // if there is no vale
		cout << "shop not found!\n\n"; //display this message
}



int main() // here the program will start
{
	//declare valiable
	int choice; 
	int counter = 0; //add Initial value
	string phone;
	string order;

	do //use Do...while loop to display the list at least one
	{ 
		cout << "1.Add new customer\n";
		cout << "2.Add new shop\n";
		cout << "3.Add new delivery order\n";
		cout << "4.Cancel delivery order\n";
		cout << "5.Update customer details\n";
		cout << "6.Update shop details\n";
		cout << "7.Delete customer records\n";
		cout << "8.Delete shop records\n";
		cout << "9.Show customer lists\n";
		cout << "10.Show shop lists\n";
		cout << "11.Search for a specific customer details\n";
		cout << "12.Search for a specific shop details\n";
		cout << "13.Quit\n";

		cout << "Enter your choice: "; 
		cin >> choice;

		switch (choice) 
		{
		//each case will call a specific function
		case 1:
		    AddCustomer(counter);
		    counter++; //to go to next index in array
		    
		    break; //to stop this case

		case 2:
		    AddShop(counter);
		    counter++; //to go to next index in array
		    
			break; //to stop this case
			
		case 3:
		    AddDeliveryOrder(counter);
		    counter++; //to go to next index in array
		    
			break; //to stop this case

		case 4:
            cout<<"Enter order: ";
		    cin>>order;
		    cout<<endl;
		    Canceldeliver( order, counter);
		    counter--;
			break; //to stop this case

		case 5:
		     cout<<"Enter customer phone: ";
		     cin>>phone;
		     cout<<endl;
		     Updatecustomer( phone, counter);
			 break; //to stop this case

		case 6:
             cout<<"Enter shop phone: ";
		     cin>>phone;
		     cout<<endl;
		     Updateshop( phone, counter);
			 break; //to stop this case

		case 7:
		     cout<<"Enter customer phone: ";
		     cin>>phone;
		     cout<<endl;
		     Deletecustomer ( phone, counter);
             counter--;
			 break; //to stop this case

		case 8:
             cout<<"Enter shop phone: ";
		     cin>>phone;
		     cout<<endl;
		     Deleteshop( phone, counter);
		     counter--;
			 break; //to stop this case

		case 9:
		     
		    displayALLcustomer(counter);
		    cout<< "open the file\n\n";
	        
			break; //to stop this case

		case 10:
		  
	        displayALLshop(counter);
	        break; //to stop this case
	        
		case 11:
		    cout << "Enter customer phone number: ";
			cin >> phone;
		    searchcustomer( phone, counter);
			break; //to stop this case

		case 12:
		    cout << "Enter shop phone number: ";
			cin >> phone;
		    searchshop( phone, counter);
			break; //to stop this case

		case 13:
			cout << "Program Terminated";
			break; //to stop this case

		default:
			cout << "Input error, try again!\n\n";
		}
	} while (choice != 13); //in number 13 , the loop will stop disply the list
	return 0; //end of program
}

