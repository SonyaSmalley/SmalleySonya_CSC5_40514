/*Author: Sonya Smalley
 *Created on March 20, 2020, 18:36
 *Purpose: Menu to be used for Lab Assignment 4 in order to hold Homework 3 */

//System Level Libraries
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    //Variable Declarations
    char choice;    //To be used for the main menu
    
    //Display Menu
    cout<<"Please choose a program to run from Homework Assignment 3, "
        <<"as written by Sonya Smalley:\n";
    cout<<"Type 1 for the Gaddis Books problem.\n";
    cout<<"Type 2 for the Gaddis Bank Charges problem.\n";
    cout<<"Type 3 for the Gaddis Race problem.\n";
    cout<<"Type 4 for the Gaddis ISP problem.\n";
    cout<<"Type 5 for the Gaddis Sort Names problem.\n";
    cout<<"Type 6 for the Savitch Rock Paper Scissors problem.\n";
    cout<<"Type 7 for the Savitch Compatible Signs problem.\n";
    cout<<"Type 8 for the Savitch Roman Conversion problem.\n";
    
    cin>>choice;
    cout<<endl;
    
    //Menu with Homework Problems
    switch(choice)
    {
        case '1': {    //Gaddis Books
            //Declare Variables
            int books,  //variable for # of books purchased
                points; //variable for total points earned

            //Initialize or input i.e. set variable values
            cout<<"Book Worm Points\n"
                <<"Input the number of books purchased this month.\n";
            cin>>books; //Initialize # of books purchased

            //Map inputs -> outputs
            switch (books)
            {
                case 0: points=0;
                        break;
                case 1: points=5;
                        break;
                case 2: points=15;
                        break;
                case 3: points=30;
                        break;
                default: points=60;
            }

            //Display the outputs
            cout<<"Books purchased ="<<setw(3)<<books<<endl;
            cout<<"Points earned   ="<<setw(3)<<points;
            //Exit stage right or left!
            break;}
        
        case '2': {  //Gaddis Bank Charges
            //Declare Variables
            float minfee=10.00;    //the minimum fee for all accounts is $10 per month
            float lowfee=15.00;   //the fee for balances below $400 is $15
            float money,    //starting balance in account
                checks, //number of checks
                cfee,   //check fee: varies according to number of checks
                nbal;   //new balance after applicable fees are accounted for

            //Initialize or input i.e. set variable values
            cout<<"Monthly Bank Fees\n"
                <<"Input Current Bank Balance and Number of Checks\n";
            cin>>money>>checks;

            //Map inputs -> outputs
            //evaluate bank balance and subtract monthly minimum fee
            nbal=money;

            if (money<0)    //if overdrawn...
                nbal=money-minfee-lowfee;
            else if (money<400) //if low balance...
                nbal=money-minfee-lowfee;
            else    //if balance is fine...
                nbal=money-minfee;

            //calculate the check fee
            if (checks<20)
                cfee=checks*0.10;
            else if (checks<40)
                cfee=checks*0.08;
            else if (checks<60)
                cfee=checks*0.06;
            else
                cfee=checks*0.04;

            //calculate the new balance after check fees are subtracted
            nbal=nbal-cfee;

            //Display the outputs
            if (checks<0)
                cout<<"Negative values for checks not allowed. Please restart the program.";
            else
            {
                cout<<setprecision(2)<<fixed<<showpoint;
                cout<<"Balance     $"<<setw(9)<<money<<endl;
                cout<<"Check Fee   $"<<setw(9)<<cfee<<endl;
                cout<<"Monthly Fee $"<<setw(9)<<minfee<<endl;
                cout<<"Low Balance $"<<setw(9)<<lowfee<<endl;
                cout<<"New Balance $"<<setw(9)<<nbal;
                if (money<0)   
                    cout<<"\nAccount Overdrawn!\n";
            }
            //Exit stage right or left!
            break;}
        
        case '3': { //Gaddis Race
            //Declare Variables
            string name1, name2, name3;
            int time1, time2, time3;

            //Initialize or input i.e. set variable values
            cout<<"Race Ranking Program\n"
                <<"Input 3 Runners\n"
                <<"Their names, then their times\n";
            cin>>name1>>time1
                >>name2>>time2
                >>name3>>time3;

            //Map inputs -> outputs
            if (time1<time2&&time1<time3)
                {
                    cout<<name1<<"\t"<<right<<setw(3)<<time1<<endl;
                    if (time2<time3)
                    {    
                        cout<<name2<<"\t"<<right<<setw(3)<<time2<<endl;
                        cout<<name3<<"\t"<<right<<setw(3)<<time3;
                    }
                    else
                    {    
                        cout<<name3<<"\t"<<right<<setw(3)<<time3<<endl;
                        cout<<name2<<"\t"<<right<<setw(3)<<time2;
                    }
                }
            if (time2<time1&&time2<time3)
                {
                    cout<<name2<<"\t"<<right<<setw(3)<<time2<<endl;
                    if (time1<time3)
                    {    
                        cout<<name1<<"\t"<<right<<setw(3)<<time1<<endl;
                        cout<<name3<<"\t"<<right<<setw(3)<<time3;
                    }
                    else
                    {    
                        cout<<name3<<"\t"<<right<<setw(3)<<time3<<endl;
                        cout<<name1<<"\t"<<right<<setw(3)<<time1;
                    }
                }
            if (time3<time1&&time3<time1)
                {
                    cout<<name3<<"\t"<<right<<setw(3)<<time3<<endl;
                    if (time2<time1)
                    {    
                        cout<<name2<<"\t"<<right<<setw(3)<<time2<<endl;
                        cout<<name1<<"\t"<<right<<setw(3)<<time1;
                    }
                    else
                    {    
                        cout<<name1<<"\t"<<right<<setw(3)<<time1<<endl;
                        cout<<name2<<"\t"<<right<<setw(3)<<time2;
                    }
                }
            //Exit stage right or left
            break;}
        
        case '4': { //Gaddis ISP
            //Declare Variables
            char package;   //customer's package
            int hours;  //customer's number of hours used
            float bill; //the amount the customer will be billed, dependent upon package and # of hours used

            //Initialize or input i.e. set variable values
            cout<<"ISP Bill\n"
                <<"Input Package and Hours\n";
            cin>>package>>hours;

            //Map inputs -> outputs
            if (hours>744)  //Input Validation: The number of hours used in a month cannot exceed 744.
                cout<<"Hours used cannot exceed 744\n";
            switch (package)
            {
                case 'A':   //Package A: For $9.95 per month 10 hours of access are provided. Additional hours are $2.00 per hour.
                    if (hours<=10)
                        bill=9.95;
                    else
                        bill=9.95+(hours-10)*2.0;
                    break;
                case 'B':   //Package B: For $14.95 per month 20 hours of access are provided. Additional hours are $1.00 per hour.
                    if (hours<=20)
                        bill=14.95;
                    else
                        bill=14.95+(hours-20)*1.0;
                    break;
                case 'C':   //Package C: For $19.95 per month unlimited access is provided.
                    bill=19.95;
                    break;
                default:    //Input Validation: Be sure the user only selects package A, B, or C.
                    cout<<"Invalid entry";
            }

            //Display the outputs
            cout<<"Bill = $ "<<bill;
                //Exit stage right or left!
            break;}
        
        case '5': { //Gaddis Sort Names
            //Declare Variables
            string name1, name2, name3;
            //Initialize or input i.e. set variable values
            cout<<"Sorting Names\n"<<"Input 3 names\n";
            cin>>name1>>name2>>name3;

            //Map inputs -> outputs
            if (name1<name2 && name1<name3)
            {
                cout<<name1<<endl;
                if (name2<name3)
                    cout<<name2<<endl<<name3;
                else
                    cout<<name3<<endl<<name2;
            }    
            else if (name2<name1 && name2<name3)
            {
                cout<<name2<<endl;
                if (name1<name3)
                    cout<<name1<<endl<<name3;
                else
                    cout<<name3<<endl<<name1;
            }
            else 
            {
                   cout<<name3<<endl;
                if (name1<name2)
                    cout<<name1<<endl<<name2;
                else
                    cout<<name2<<endl<<name1;
            }
            //Exit stage right or left!
            break;}
        
        case '6': { //Savitch Rock Paper Scissors
            //Declare Variables
            char p1, p2;    //variables to hold player 1 (p1) and player 2 (p2) choices

            //Initialize or input i.e. set variable values
            cout<<"Rock Paper Scissors Game\n"
                <<"Input Player 1 and Player 2 Choices\n";
            cin>>p1>>p2;

            //Map inputs -> outputs
            if ((p1=='P'||p2=='P'||p1=='p'||p2=='p')&&(p1=='R'||p2=='R'||p1=='r'||p2=='r'))
                cout<<"Paper covers rock.";
            else if ((p1=='P'||p2=='P'||p1=='p'||p2=='p')&&(p1=='S'||p2=='S'||p1=='s'||p2=='s'))
                cout<<"Scissors cuts paper.";
            else if ((p1=='S'||p2=='S'||p1=='s'||p2=='s')&&(p1=='R'||p2=='R'||p1=='r'||p2=='r'))
                cout<<"Rock breaks scissors.";
            else
                "Nobody wins.";
            //Exit stage right or left!
            break;}
        
        case '7': { //Savitch Compatible Signs
            //Declare Variables
            string sign1, sign2,    //horoscope signs
                elmnt1, elmnt2;  //element belonging to the entered signs
                
            //Initialize or input i.e. set variable values
            cout<<"Horoscope Program which examines compatible signs.\n"
                <<"Input 2 signs.\n";
            cin>>sign1>>sign2;

            //Map inputs -> outputs
            //assign appropriate element to the first sign
            if (sign1=="Aries"||sign1=="Leo"||sign1=="Sagittarius")
                elmnt1="Fire";
            if (sign1=="Taurus"||sign1=="Virgo"||sign1=="Capricorn")
                elmnt1="Earth";
            if (sign1=="Gemini"||sign1=="Libra"||sign1=="Acquarius")
                elmnt1="Air";
            if (sign1=="Cancer"||sign1=="Scorpio"||sign1=="Pisces")
                elmnt1="Water";
            else
                "Invalid entry.";

            //assign appropriate element to the second sign
            if (sign2=="Aries"||sign2=="Leo"||sign2=="Sagittarius")
                elmnt2="Fire";
            if (sign2=="Taurus"||sign2=="Virgo"||sign2=="Capricorn")
                elmnt2="Earth";
            if (sign2=="Gemini"||sign2=="Libra"||sign2=="Acquarius")
                elmnt2="Air";
            if (sign2=="Cancer"||sign2=="Scorpio"||sign2=="Pisces")
                elmnt2="Water";
            else
                "Invalid entry.";

            //Display the outputs
            if (elmnt1==elmnt2)
                cout<<sign1<<" and "<<sign2<<" are compatible "<<elmnt1<<" signs.";
            else
                cout<<sign1<<" and "<<sign2<<" are not compatible signs.";
            //Exit stage right or left!
            break;}
        
        case '8': { //Savitch Roman Conversion
            //Declare Variables
            int num;    //number to be converted
            char n1000s, n100s, n10s, n1s;
            
            //Initialize or input i.e. set variable values
            cout<<"Arabic to Roman numeral conversion.\n"
            <<"Input the integer to convert.\n";
            cin>>num;
            
            //Map inputs -> outputs and Display the outputs
            if (num>1000 && num<3000)
            {    
                cout<<num<<" is equal to ";
                
                //Find the value in each place of the number
                n1s=num%10; //1s place
                n10s=(num/10)%10;   //10s place
                n100s=(num/100)%10; //100s place
                n1000s=(num/1000)%10;   //1000s place
                
                //show the 1000s place arabic value
                cout<<(n1000s==1?"M":
                    n1000s==2?"MM":
                    n1000s==3?"MMM":"");
        
                //show the 100s place arabic value
                cout<<(n100s==1?"C":
                    n100s==2?"CC":
                    n100s==3?"CCC":
                    n100s==4?"CD":
                    n100s==5?"D":
                    n100s==6?"DC":
                    n100s==7?"DCC":
                    n100s==8?"DCCC":
                    n100s==9?"CM":"");
                
                //show the 10s place arabic value
                cout<<(n10s==1?"X":
                    n10s==2?"XX":
                    n10s==3?"XXX":
                    n10s==4?"XL":
                    n10s==5?"L":
                    n10s==6?"LX":
                    n10s==7?"LXX":
                    n10s==8?"LXXX":
                    n10s==9?"XC":"");
                    
                //show the 1s place arabic value
                cout<<(n1s==1?"I":
                    n1s==2?"II":
                    n1s==3?"III":
                    n1s==4?"IV":
                    n1s==5?"V":
                    n1s==6?"VI":
                    n1s==7?"VII":
                    n1s==8?"VIII":
                    n1s==9?"IX":"");
            }
            else
                cout<<num<<" is Out of Range!";
            //Exit stage right or left!
            break;}
        default: cout<<"Not an option. Please choose numbers 1 through 8.\n";
    }
    
    return 0;
}