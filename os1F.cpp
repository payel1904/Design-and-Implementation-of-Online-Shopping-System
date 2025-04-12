#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<vector>
using namespace std;
class User {
    public:
        string username;
        string password;
    
        User(string username, string password) {
            this->username = username;
            this->password = password;
        }
    };
class Bill{
    private:
   string item;
   int rate;
   int quantity;
   public:
   Bill():item(""),rate(0),quantity(0){};

  void  Setitem(string it)
   {
    item=it;
   }
   void setRate(int r)
   {
    rate=r;
   }
   void setQuantity(int quant)
   {
    quantity=quant;
   }
   string getitem()
   {
    return item;
   }
   int getrate()
   {
    return rate;
   }
   int getquantity()
   {
    return quantity;
   }
};
class ShoppingSystem {
    private:
        vector<User> users;        
    public:
        ShoppingSystem() {
            loadUsers();
        }
    
        // Register a new user
        void registerUser() {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
    
            User newUser(username, password);
            users.push_back(newUser);
            saveUserToFile(newUser);
            cout << "Registration successful!" << endl;
        }
    
        // Login existing user
        bool loginUser() {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
    
            for (auto& user : users) {
                if (user.username == username && user.password == password) {
                    cout << "Login successful!" << endl;
                    return true;
                }
            }
            cout << "Invalid username or password!" << endl;
            return false;
        }
    
        // Load users from a file
        void loadUsers() {
            ifstream file("users.dat");
            string username, password;
            while (file >> username >> password) {
                users.push_back(User(username, password));
            }
            file.close();
        }
    
        // Save new user to a file
        void saveUserToFile(User& user) {
            ofstream file("users.dat", ios::app);
            file << user.username << " " << user.password << endl;
            file.close();
        }
    };

void addData(Bill b)
{
   bool close=false;
   while(!close)
   {
    int choice;
    cout<<"\t1.add item"<<endl;
    cout<<"\t2.exit"<<endl;
    cout<<"\tenter choice"<<endl;
    cin>>choice;
    if(choice==1)
    {  system("cls");
        string item;
        int rate;
        int quantity;
        cout<<"enter item name"<<endl;
        cin>>item;
        b.Setitem(item);
        cout<<"enter rate"<<endl;
        cin>>rate;
        b.setRate(rate);
        cout<<"enter quantity"<<endl;
        cin>>quantity;
        b.setQuantity(quantity);
        ofstream out("bill1.txt",ios::app);//for not be overriden
        if(!out)
        {
            cout<<"Error: file can't open "<<endl;
        }else{
            out<<"\t"<<b.getitem()<<" : "<<b.getrate()<<":"<<b.getquantity()<<endl<<endl;
        }
        out.close();
        cout<<"items added successfuly"<<endl;
        Sleep(3000);
    }else if(choice==2)
    {  system("cls");
        close=true;
        cout<<"back to main menu!"<<endl;
        Sleep(3000);
    }
   }
}
void printBill()
{
  system("cls");
  int count=0;
  bool close=false;
  while(!close)
  {
    system("cls");
    int choice;
    cout<<"\t1.add Bill"<<endl;
    cout<<"\t2.close session"<<endl;
    cout<<"\tenter your choice"<<endl;
    cin>>choice;
    if(choice==1)
    {
        string item;
        int quant;
        cout<<"\tEnter item"<<endl;
        cin>>item;
        cout<<"\tenter quantity"<<endl;
        cin>>quant;
        ifstream in("bill1.txt");
        ofstream out("temp1.txt");
        string line;
        bool found=false;
        while(getline(in,line))
        {
            stringstream ss;
            ss<<line;
            string itemName;
            int itemRate,itemQuant;
            char delimiter;//for separation
            ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;
            if(item==itemName)
            {
                found=true;
                if(quant<=itemQuant)
                { int amount=quant*itemRate;
                  cout<<"\t Item | Rate | quantity | amount |"<<endl;
                  cout<<"\t"<<item<<"\t"<<itemRate<<"\t"<<quant<<"\t"<<amount<<endl;
                  int newQuant=itemQuant-quant;
                  itemQuant=newQuant;
                  count+=amount;
                  out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl<<endl;

                }else{
                  cout<<"\tsorry!"<<item<<"ended"<<endl;
                    
                }
            }else{
                //item not found
                out<<line<<endl;//so that deletion of  other  items available in the file not occur


            }

        }
        if(found==false)
        {
          cout<<"\t Item not available!"<<endl;
        }
        out.close();
        in.close();
        remove("bill1.txt");
        rename("temp1.txt","bill1.txt");//copy from temp to bill
    }else if(choice==2)
    {
      close=true;
      cout<<"\tCounting is closed"<<endl;
    }
    Sleep(3000);

  }
  system("cls");
  cout<<endl<<endl;
  cout<<"\t Total Bill--------------------------"<<count<<endl<<endl<<endl;
  cout<<"\tThanks for shopping"<<endl;
  Sleep(3000);
}

int main()
{    ShoppingSystem s;
    Bill b;
    bool exit=false;

    while(!exit)
    {
      system("cls");//clear the previous output and output the current
      int val;
      cout<<"\tWelcome to online shopping system"<<endl;
      cout<<"\tAvailable items:"<<endl;
     // ifstream inputFile("bill1.txt");
      string line;
    ifstream inputFile("bill1.txt");
if (inputFile.is_open()) {
    cout << "\tFile opened successfully!" << endl;
    while (getline(inputFile, line)) {
        cout << line << endl;
    }
    inputFile.close();
} else {
    cerr << "\tUnable to open file." << endl;
}     
      cout<<"\t1.owner"<<endl;
      cout<<"\t2.customer"<<endl;
      cout<<"\t3.want to exit"<<endl;
      int usertype;
      cout<<"\tSelect userType:"<<endl;
      cin>>usertype;
      if(usertype==1)
      { system("cls");
        cout<<"\t1.addItem"<<endl;
       cout<<"\t3.exit"<<endl;
       cout<<"\tenter choice"<<endl;
        cin>>val;
        if(val==1)
      {  system("cls");//previous output will be hide
        addData(b);
        Sleep(2000);
      }else if(val==3)
      {
        system("cls");
        exit=true;
        cout<<"\t Good Luck!"<<endl;
        Sleep(3000);
      }

      } else if(usertype==2){
        int choice;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                system("cls");
                s.registerUser();
                break;
            case 2:
            system("cls");
                if (s.loginUser()) {
                    cout<<"\t2.Add to Cart"<<endl;
                    cout<<"\t3.exit"<<endl;
                    cout<<"\tenter choice"<<endl;
                    cin>>val;
                     if(val==2)
                    {
                      printBill();
                    }else if(val==3)
                    {
                      system("cls");
                      exit=true;
                      cout<<"\t Good Luck!"<<endl;
                      Sleep(3000);
                    }
                    
                }
                break;
            case 3:
            system("cls");
                cout << "Exiting system!" << endl;
                system("cls");
                exit=true;
                cout<<"\t Good Luck!"<<endl;
                Sleep(3000);

                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }else if(usertype==3)
    {
        system("cls");
        exit=true;
        cout<<"\t Good Luck!"<<endl;
        Sleep(3000);
    }
} 
  return 0;
}
