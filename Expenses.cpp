// A Program to store your daily expenses

#include <iostream>
#include <fstream>
#include <cstring>
#include <time.h>


// variables
std::string idate , iday;
std::string date,day;
std :: string comment;
int amount;
int numOfExpense;
int totalAmount = 0;


  //declaring time and string to get day
  time_t ct = time(0);
  std :: string currentTime = ctime(&ct);
  std:: string expenseName;

//input function
void input()
{
std::cout<<"WELCOME TO EXPENSE COUNTER";
std :: cout << "\n\nThe Expenses are stored in 'Expenses' folder in home directory";
  std::cout<<"\n\nEnter the date (or) press c to enter today's date: ";
  std::cin>>idate;
  std::cout<<"\nEnter the day (or) press d to enter today's date: ";
  std::cin>>iday;

   
}

//Getting date and day and processing it
 void dateAndDay(std::string da,std::string de)
  {
    if (da == "c")
      date = __DATE__;  
    else 
    {
      date = da;
    }
    if (de == "d")
      day = currentTime.substr(0,3);
    else
      day = de;
  }

int main()
{
  //creating myfile object

  std::fstream myfile;
  
  myfile.open("Expenses.txt", std::ios::app);
 
  //calling the functions
  
   input(); // gets input 
   dateAndDay(idate,iday); //process it
 

  
 if (myfile.is_open())
    {
      myfile << "\n\n  ~~~~~~~~~~~~~~~~~~"; 
      myfile << "\n Date  -  " << date;
      myfile << "\n Day  -  " << day;


      std :: cout <<"\n Enter the expenses and if you wanna quit enter 'quit' in the name of the expense\n ";

      for (int i = 1; i <= 30; i++)
      {
        
        std::cout<<"\n Name of the expense: ";
        std::getline(std::cin >> std::ws,expenseName);
        //std::ws since we get an input from cin
        //in the before line it automatically 
        //inserts a newline character
        //and that \n is given as inout for 
        //the getline function
        
        if(expenseName == "quit")
          break;

        std::cout<<"\nEnter the amount: ";
        std::cin>>amount;
        totalAmount += amount;
        //writing the details in the file
        myfile << "\n\n " << i <<"."<< expenseName << "\t  -    " << amount;

      }
      myfile << "\n\n Total Amount   -    " << totalAmount; 
      std :: cout << "\nWrite a comment for the expenses if you like or enter 'quit' to quit:  ";
      std :: getline(std::cin >> std::ws,comment);
      if (comment == "quit")
      {
        ;
      }
      else
        myfile <<"\n\n"<<"Comment: " << comment;

    }
  myfile.close();
  std :: cout <<"\n" << "Total Amount:  " << totalAmount << "\n\n";

}
