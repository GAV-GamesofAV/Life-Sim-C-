/*
Remaining Work :-
Add Real State
Add Stock Market
Add Multiple Bank Accounts System
Add Multiple Demat Account System
Add Brokers and Brokerage
Add Taxes
Add More Documents
Add Nifty Trading System
*/

// header files
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// function declaration:-
void document();
void bank();
void lottery();
int investment();
void demataccount();
void trading();
void real_estate();
void about();
void job();
void data_entry();
void learn();
int profile();
void achievement();
#define MAX_PROPERTY 5
// Structure
struct property
{
    char name[50];
    int price;
};
struct property pr[MAX_PROPERTY];
// global variable declaration
char name[20], aadhar_name[20];
int aadhar_num;
int dematacnum, dematbal = 0, dematacpin;
int wallet = 1000, bal = 0, ac_num, ac_pin;
int excel_skill = 0, trading_skill = 1;
int achievement_1 = 0, achievement_2 = 0, achievement_3 = 0, achievement_4 = 0, achievement_5 = 0;
int date = 1, month = 1, year = 2024, total_days = 0;
pr[MAX_PROPERTY] = {{"h1", 2300000}, {"h2", 3400000}, {"h3", 5600000}, {"h4", 1900000}, {"h5", 3700000}};
// main function:-
int main()
{
    srand(time(NULL));
    // properties variable

    int max_loan;
    int ch, a, easy_challenge_mode = 0, free_mode = 0;           // variables
    int achievement_1 = 0, achievement_2 = 0, achievement_3 = 0; // variables
    printf("Welcome to Life Simulation Game made by 'ALOK'\n");  // intro
    a = profile();
    if (a == 1)
    {
        easy_challenge_mode = 1;
    }
    else if (a == 2)
    {
        free_mode = 1;
    }
    while (1)
    { // loop

        // achievement
        achievement(&wallet, &achievement_1, &achievement_2, &achievement_3);

        // winning system
        if (easy_challenge_mode == 1)
        {

            if (achievement_3 == 1)
            {
                printf("\n\n\nYou win the game!🎉🎉\n");
                exit(0);
            }
        }

        if (wallet < 0)
        { // lose system
            printf("\nYou lose! You don't have money!");
            exit(0);
        }

        // Date showing system
        if (date > 30)
        {
            month += 1;
            date = 1;
        }
        if (month > 12)
        {
            year += 1;
            month = 1;
        }
        printf("Date : %d/%d/%d\n\n", date, month, year);
        date++;
        total_days++;

        // Real Estate price changer
        float p; // var for price change
        if (total_days % 10 == 0)
        {
            for (int i = 0; i < MAX_PROPERTY; i++)
            {
                p = ((float)rand() / RAND_MAX) * (0.20 - (-0.20)) + (-0.2);
                pr[i].price += pr[i].price * p;
            }
        }

        // ask for choice
        printf("Wallet = $%d\nWhat do you want to do :-\n1. Documents\n2. Bank Account\n3. Lottery\n4. Investment\n5. Learn\n6. Job\n7. About Game\n8. Quit Game\nEnter Choice :", wallet);
        scanf("%d", &ch);
        // choices
        if (ch == 1)
        {
            document();
        }
        else if (ch == 2)
        {
            // bank system
            bank();

            continue;
        }
        else if (ch == 3)
        {
            // lottery system
            lottery();

            continue;
        }
        else if (ch == 8)
        {
            // exit game
            break;
        }
        else if (ch == 7)
        {
            // about
            about();
            continue;
        }
        else if (ch == 5)
        {
            // learn
            learn(&excel_skill, &trading_skill);
        }
        else if (ch == 6)
        {
            // job section
            job();
        }
        else if (ch == 4)
        {
            investment();
        }
        else
        {
            // user becomes oversmart
            printf("Invalid Choice!\n");
            continue;
        }
    }
    return 0;
}

// Document System
void document()
{
    int ch;
    static int aadhar = 0;
    char ename[20];
    while (1)
    {
        printf("Select Document :-\n1. Aadhar Card\n2. Back\nEnter Choice : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            if (aadhar == 1)
            {
                printf("\nYour Aadhar name is %s\nYour Aadhar Number is %d\n\n", aadhar_name, aadhar_num);
            }
            else
            {
                printf("Aadhar Card Making Cost is $200\nType 1 to make else type anything : ");
                scanf("%d", &ch);
                if (ch == 1)
                {
                    printf("Enter Your Name : ");
                    scanf("%s", &aadhar_name);
                    printf("Your Aadhar Card is making. Wait for a Moment!\n");
                    sleep(2);
                    srand(time(NULL));
                    aadhar_num = rand() % 999999 + 111111;
                    printf("\nYour Aadhar Name is %s\nYour Aadhar Number is %d\n\n", aadhar_name, aadhar_num);
                    aadhar = 1;
                    wallet -= 200;
                }
                else
                {
                    break;
                }
            }
        }
        else if (ch == 2)
        {
            break;
        }
        else
        {
            printf("Invalid Choice!\n");
        }
    }
}

// bank function:-
void bank()
{
    // variables declaration
    static int loan = 0, loan_amount, bank_ac = 0;

    int ch, amount, a, epin, eacnum; // entered pin and ac num

    // game loop
    while (1)
    {
        // checks bank account is made or not
        if (bank_ac == 0)
        {
            char ename[20]; // Entered Aadhar Name
            int eanum;      // entered aadhar number
            printf("You Don't have a Bank Account. You need to create a Account. It will cost you $300\nType 1 to create : ");
            scanf("%d", &ch);
            if (ch == 1)
            {
                printf("Enter Your Name(of your Aadhaar Card) : ");
                scanf("%s", &ename);
                printf("Enter Your Aadhar Number : ");
                scanf("%d", &eanum);
                if (eanum != aadhar_num)
                {
                    printf("\nYour Aadhar Name or Aadhar Number isn't found!\n\n");
                    break;
                }
                printf("Creating your Bank Account!\n");
                sleep(2);
                srand(time(NULL));
                ac_num = rand() % 999999 % 111111;
                printf("Your Account Number is : %d\nCreate your pin : ", ac_num);
                scanf("%d", &ac_pin);
                printf("Account Created!\n");
                bank_ac = 1;
                continue;
            }
            else
            {
                break;
            }
        }
        // this IF checks for loan and cut '1%'
        if (loan != 0)
        {
            bal -= loan_amount * 0.01;
        }
        // this IF checks for game loosing set up
        if (bal < 0)
        {
            printf("\nYour balance is in negative\nYou lose!\n");
            exit(0);
        }
        // bank menu
        printf("Bank Balance :$%d\nWhat do you want to do :-\n1. Withdraw money\n2. Deposit money\n3. Loan\n4. Exit\nEnter Your Choice\n", bal);
        scanf("%d", &ch);
        // choice 1 of 'withdraw money'
        if (ch == 1)
        {
            printf("\nEnter Bank your Account Number :");
            scanf("%d", &eacnum);
            printf("\nEnter your pin :");
            scanf("%d", &epin);
            if (eacnum != ac_num || epin != ac_pin)
            {
                printf("Account not Found!\n");
                break;
            }
            printf("\nYou have $%d\nEnter amount to withdraw :$", bal);
            scanf("%d", &amount);
            // checks user have sufficient money
            if (amount <= bal)
            {
                bal -= amount;
                wallet += amount;
                continue;
            }
            // if not then doesn't give him
            else
            {
                printf("Not enough balance!");
                continue;
            }
        }
        // choice 2 to deposit money
        else if (ch == 2)
        {
            printf("\nEnter Your Account Number :");
            scanf("%d", &eacnum);
            if (eacnum != ac_num)
            {
                printf("Account not Found!\n");
                break;
            }
            printf("\nBank Balance = $%d\nEnter amount to deposit :", bal);
            scanf("%d", &amount);
            bal += amount;
            wallet -= amount;
            continue;
        }

        // exit
        else if (ch == 4)
        {
            break;
        }
        // loan setup
        else if (ch == 3)
        {

            // checks user doesn't have running loan
            if (loan == 0)
            {
                // terms and conditions
                printf("Welcome! Here you can get loan of any amount\nHere are some terms and conditions :-\n1. You have to repay your loan with 10%% compound interests\n2. You can't get loan without repaying old loan\n3. 1%% amount of loan(including interest) will be deducted every time you do an activity in bank\n4. You can repay loan anytime you want without paying charges\n\n\nEnter amount :");
                scanf("%d", &loan_amount);
                // payment method and adding money
                printf("Choose payment method :\n1. Cash\n2. Amount in Bank\n");
                scanf("%d", &ch);
                if (ch == 1)
                {
                    printf("$%d added in your wallet\n", loan_amount);
                    wallet += loan_amount;
                }
                else
                {
                    printf("$%d added in your bank account\n", loan_amount);
                    bal += loan_amount;
                }
                // Adding 10% to loan after giving user money
                loan_amount += loan_amount * 0.10;
                // setting loan is running
                loan = 1;
                continue;
            }
            // if user have running loan
            else
            {

                printf("Repay Your Loan!\n Loan amount: %d \nEnter amount to pay :", loan_amount);
                scanf("%d", &amount);
                loan_amount -= amount;
                printf("Select method to pay\n1. Cash\n2. Bank balance\n");
                scanf("%d", &ch);
                if (ch == 1)
                {
                    wallet -= amount;
                    continue;
                }
                else if (ch == 2)
                {
                    printf("Enter Your Account Number : ");
                    scanf("%d", &eacnum);
                    printf("Enter your Pin : ");
                    scanf("%d", &epin);
                    if (eacnum != ac_num || epin != ac_pin)
                    {
                        printf("Account not Found!\n");
                        break;
                    }
                    else
                    {
                        bal -= amount;
                        continue;
                    }
                }
                else
                {
                    printf("Invalid choice!\n");
                    continue;
                }
                // to repay whole loan
                if (loan_amount <= 0)
                {

                    loan = 0;
                    continue;
                }
            }
        }

        else
        {
            printf("\nInvalid Choice!");
            continue;
        }
    }
}

// job function:-
void job()
{
    // variables
    int ch;

    while (1)
    {
        printf("Which job do you want to do :-\n1. Data Entry\n2. Exit\nEnter Choice :");
        scanf("%d", &ch);
        // choice 1 of data_entry
        if (ch == 1)
        {
            // checks user know to use excel
            if (excel_skill == 1)
            {
                data_entry();
                break;
            }
            else
            {
                printf("Learn Excel!\n");
                continue;
            }
        }
        // exit
        else if (ch == 2)
        {
            break;
        }
        else
        {
            printf("\nInvalid Choice!\n");
            continue;
        }
    }
}

// a job function called data_entry:-
void data_entry()
{
    // variables
    int numEntries = rand() % 10 + 1; // Simulate a random number of data entries

    printf("Welcome to the Data Entry Job: Basic Excel Data Entry!\n");
    printf("You need to enter data into an Excel spreadsheet.\n");

    // Simulate Excel-related tasks for each data entry
    for (int i = 1; i <= numEntries; i++)
    {
        // Simulate data entry: Enter a random number in cell A1
        int data = rand() % 100; // Simulate a random data
        int userEntry;

        printf("Data Entry - Enter the number %d in cell A1: ", data);
        scanf("%d", &userEntry);

        if (userEntry == data)
        {
            printf("Correct! Data entered successfully.\n");
            wallet += 20; // Assuming $20 per correctly entered data
        }
        else
        {
            printf("Incorrect. The correct data is %d.\n", data);
        }
    }
}

// learn funtion:-
void learn()
{
    // variables
    int ch, trading_fee, max_trading_level = 4;
    while (1)
    {
        printf("What do you want to do :-\n1. Excel(Data Entry Job)\n2. Learn Trading\n3. Exit\nEnter Choice :");
        scanf("%d", &ch);
        // choice 1 to learn excel
        if (ch == 1)
        {
            // asking to learn
            printf("Pay $700 to learn Excel\nType 1 to pay else anything:");
            scanf("%d", &ch);
            // if iser learns
            if (ch == 1)
            {
                wallet -= 700;
                printf("You Learnt Excel\n");
                excel_skill = 1;
                continue;
            }
            // if user doesn't learn
            else
            {
                continue;
            }
        }
        // exit
        else if (ch == 3)
        {
            break;
        }
        else if (ch == 2)
        {
            // if user haven't fully learnt trading and the max trading level is declared in this function
            if (trading_skill < max_trading_level)
            {
                // setting fee accordingly to their level
                if (trading_skill == 1)
                {
                    trading_fee = 700;
                }
                else if (trading_skill == 2)
                {
                    trading_fee = 1600;
                }
                else if (trading_skill == 3)
                {
                    trading_fee = 4500;
                }
                // printing level and amount
                printf("Your trading level is %d\nYou have to pay $%d to learn\nType 1 to pay else type anything:", trading_skill, trading_fee);
                scanf("%d", &ch);
                // if user learns
                if (ch == 1)
                {
                    trading_skill += 1;
                    wallet -= trading_fee;
                }
                else
                {
                    continue;
                }
            }
            // user mastered trading
            else
            {
                printf("\n\nYou have mastered trading!\n\n\n");
                continue;
            }
        }
        else
        {
            printf("Invalid Choice!");
        }
    }
}

// lottery function:-
void lottery()
{
    // variables
    int lottery, num;
    int ch;
    while (1)
    {
        // menu
        printf("Welcome to lottey centre!\nTicket price is only $500/-\nType '1' to buy else anything :");
        scanf("%d", &ch);
        // user pirchase ticket
        if (ch == 1)
        {
            wallet -= 500;
            lottery = rand() % (50 - 1 + 1) + 1;
            printf("Enter your lucky number between 1 to 50 :");
            scanf("%d", &num);
            if (num == lottery)
            {
                printf("Congratulations! You win first prize🏆🏆\n$10,00,000 added to your wallet\n");
                wallet += 1000000;
                continue;
            }

            else
            {
                printf("You lost!\n");
                continue;
            }
        }
        else
        {
            break;
        }
    }
}

// Investment Menu
int investment()
{
    int ch;
    while (1)
    {
        printf("Select Opttion :-\n1. Demat Account\n2. Trading\n3. Exit\n4. Real Estate\nEnter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            demataccount();
            break;
        case 2:
            trading();
            break;
        case 3:
            return 0;
            break;
        case 4:
            real_estate();
            break;
        default:
            printf("Invalid Choice!\n");
            break;
        }
    }
}

// Demat Account
void demataccount()
{
    static int dematac = 0; // Demat account is made or not variable
    int ch, amount;         // amount to deposit and withdraw
    int eacnum, eacpin;     // Entered pin and accoount number
    char dematname[20];
    if (dematac == 0)
    {
        printf("You Don't have a Demat Account. Creating a Demat Account will cost you $200\nType 1 to make : ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            if (wallet >= 200)
            {
                printf("Enter Your Name : ");
                scanf("%s", &dematname);
                printf("Connect Your Bank Account to start Trading and Investing\n");
                sleep(1);
                printf("Enter Your Bank Account Number : ");
                scanf("%d", &eacnum);
                printf("Enter your Bank Account Pin : ");
                scanf("%d", &eacpin);
                if (eacnum == ac_num || eacpin == ac_pin)
                {
                    printf("Your  Bank Account Number : %d\nYour Bank Account Pin : %d\nYour Name : %s\nYour Name on Aadhar Card : %s\nYour Aadhar Card Number : %d\n\nYour Demat Account is Creating\nPlease wait for a moment\n\n", ac_num, ac_pin, dematname, aadhar_name, aadhar_num);
                    sleep(2);
                    srand(time(NULL));
                    dematacnum = rand() % 9999 + 1111;
                    printf("Your Demat Account Num is %d\nMake a Pin : ", dematacnum);
                    scanf("%d", &dematacpin);
                    printf("\nAccount Created!\n\n");
                    wallet -= 200;
                    dematac = 1;
                }
                else
                {
                    printf("\nAccount Not Found!\n\n");
                }
            }
            else
            {
                printf("\nNot Enough Money!\n");
            }
        }
    }
    else
    {
        while (1)
        {
            printf("Your Demat Account Number is : %d\nYour Demat Account Pin is : %d\nYour Demat Account Balance is : %d\nSelect an Option :-\n1. Deposit Money\n2. Withdraw Money\n3. Exit\nEnter Choice : ", dematacnum, dematacpin, dematbal);
            scanf("%d", &ch);
            if (ch == 1)
            {
                printf("Your Bank Balance : $%d\nEnter amount to deposit : ", bal);
                scanf("%d", &amount);
                if (amount <= bal)
                {
                    dematbal += amount;
                    bal -= amount;
                    printf("\nTransaction Succesfull!\n\n");
                }
                else
                {
                    printf("\nNot Enough Balance!\n\n");
                }
            }
            else if (ch == 2)
            {
                printf("Your Bank Balance : $%d\nEnter Amount to Withdraw : ", bal);
                scanf("%d", &amount);
                if (amount <= dematbal)
                {
                    dematbal -= amount;
                    bal += amount;
                    printf("\nTransaction Succesful!\n\n");
                }
                else
                {
                    printf("\nNot Enough Balance!\n\n");
                }
            }
            else
            {
                break;
            }
        }
    }
}

// trading function:-
void trading()
{
    // variables
    int login = 0;
    static float max_trading_profit = 1.00;
    static float max_trading_loss = -0.99;
    static int bet = 0;
    int c, amount;
    int edacnum, edacpin; // entered demat account number and pin
    float a;
    // setting max profit and loss according to trading level
    if (trading_skill == 1)
    {
        max_trading_profit = 1.00;
        max_trading_loss = -1.00;
    }
    else if (trading_skill == 2)
    {
        max_trading_loss = -0.95;
        max_trading_profit = 1.20;
    }
    else if (trading_skill == 3)
    {
        max_trading_profit = 1.45;
        max_trading_loss = -0.80;
    }
    else if (trading_skill == 4)
    {
        max_trading_profit = 1.60;
        max_trading_loss = -0.75;
    }
    // change price everytime user opens this
    srand(time(0));
    a = ((float)rand() / RAND_MAX) * (max_trading_profit - max_trading_loss) + max_trading_loss;
    bet += bet * a;

    while (1)
    {
        // demat account finding
        if (login == 0)
        {
            printf("Enter Your Demat Account Number : ");
            scanf("%d", &edacnum);
            printf("Enter Your Demat Account Pin : ");
            scanf("%d", &edacpin);
            login = 1;
        }
        if (edacnum == dematacnum || edacpin == dematacpin || login == 1)
        {
            // menu
            printf("\nCurrent Stocks is $%d\n1. Buy\n2. Sell\n3. Wait for price to change\n4. Exit\nEnter Your Choice :", bet);
            scanf("%d", &c);
            // user buy stocks
            if (c == 1)
            {
                a = ((float)rand() / RAND_MAX) * (max_trading_profit - max_trading_loss) + max_trading_loss;
                printf("Enter Amount to Deposit: $");
                scanf("%d", &amount);
                if (dematbal >= amount)
                {
                    dematbal -= amount;
                    bet += amount;
                    bet += (a * bet);
                    sleep(2);
                    printf("Stock price is now $%d", bet);
                }
                else
                {
                    printf("\nNot Enough Balance in Demat Account!\n");
                }
            }
            // user sell
            else if (c == 2)
            {
                printf("Enter Amount to Withdraw : $");
                scanf("%d", &amount);
                if (amount <= bet)
                {
                    dematbal += amount;
                    bet -= amount;
                }
                else
                {
                    printf("\nNot Enough Bet Amount!\n");
                }
            }
            // wait for price
            else if (c == 3)
            {
                a = ((float)rand() / RAND_MAX) * (max_trading_profit - max_trading_loss) + max_trading_loss;
                bet += (a * bet);
                continue;
            }
            else if (c == 4)
            {
                break;
            }
            else
            {
                printf("Invalid Choice!");
                continue;
            }
        }
        else
        {
            printf("\nAccount not Found!\n\n");
            break;
        }
    }
}

// real Estate
void real_estate()
{
    int ch;
    while (1)
    {
        printf("Select an Option :-\n1. Your Property\n2. Buy Property\n3. Sell Property\n4. Back\nEnter Choice : ");
        scanf("%d", &ch);
        if (ch == 2)
        {
            printf("Select Proeperty :-\n");
            for (int i = 0; i < MAX_PROPERTY; i++)
            {
                printf("%d. %s :$%d\n", i + 1, pr[i].name, pr[i].price);
            }
            printf("Enter Choice : ");
            scanf("%d", &ch);
            if (ch == 1)
            {
                printf("Property Name : %s\nProperty Price : %d\n\nType 1 to Buy : ", pr[0].name, pr[0].price);
                scanf("%d", &ch);
                if(ch == 1)
                {
                    wallet -= pr[0].price;
                    
                }
            }
            else if (ch == 2)
            {
            }
            else if (ch == 3)
            {
            }
            else if (ch == 4)
            {
            }
            else if (ch == 5)
            {
            }
            else
            {
                printf("\nInvalid Choice!\n");
            }
        }
        else if (ch == 2)
        {
        }
        else if (ch == 3)
        {
        }
        else if (ch == 4)
        {
            break;
        }
        else
        {
            printf("\nInvalid Choice!\n");
        }
    }
}
// about function:-
void about()
{

    printf("This game is made by Alok.\nThis Money Simulator v1.0.0 beta\nIn this game you have to earn a lot of money by doing many jobs.\nCurrently this only have trading,lottery and Data Entry but after some updates i will add some more ways to earn money\nI will also add ways to spend money\nTo Do Data Entry Job you need to learn it\nYou can increase your profit and reduce your loss in trading by upgrading the skill\nIf your bank balance or wallet get less then 0, You will lose!\n");
    while (getchar() != '\n')
    {
    }
    for (int i = 0; i <= 1; i++)
    {
        printf("\n");
    }
}

// profile
int profile()
{
    int ch;

    printf("Enter Your Name : ");
    scanf("%s", &name);
    printf("note: don't choose invalid mode!\n\n");
    printf("Choose a game mode :-\n1. Challenge mode(complete 3 achievements to win game)\n2. Free mode(Earn as much as you want)\nEnter Choice :");
    scanf("%d", &ch);

    return (ch);
}

// achievement manager
void achievement()
{

    if (wallet >= 10000 && achievement_1 != 1)
    {
        achievement_1 = 1;
        printf("\n\nYou completed an achievement!🏆. You Made your first $10000\n\n");
    }
    if (wallet >= 50000 && achievement_2 != 1)
    {
        achievement_2 = 1;
        printf("\n\nyou completed an achievement!🏆. You made your first $50000\n\n");
    }
    if (wallet >= 100000 && achievement_3 != 1)
    {
        printf("\n\n\n\nYou completed an achievement!🏆. You made your first $100000\n\n");
        achievement_3 = 1;
    }
    if (month == 2 && year == 2024 && achievement_4 != 1)
    {
        achievement_4 = 1;
        printf("You Completed an Achievement!. You made it to 1 month");
    }
    if (year == 2025 && achievement_5 != 1)
    {
        achievement_5 = 1;
        ;
        printf("You Completed an Achievement!. You made it to a Whole year. ");
    }
}