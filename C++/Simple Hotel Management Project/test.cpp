#include <iostream>
using namespace std;

int main(){
    int quantity;
    int choice;
    // Quantity
    int quantRooms = 0, quantPasta = 0, quantBurger = 0, quantNoodles = 0, quantShake = 0, quantChicken = 0;
    // Sold foods
    int soldRooms = 0, soldPasta = 0, soldBurger = 0, soldNoodles = 0, soldShake = 0, soldChicken = 0;
    // Total price 
    int totalRooms = 0, totalPasta = 0, totalBurger = 0, totalNoodles = 0, totalShake = 0, totalChicken = 0;

    cout << "\n\t Quantity of items we have: ";
    cout << "\n Rooms available: ";
    cin >> quantRooms;
    cout << "\n Quantity of Pasta: ";
    cin >> quantPasta;
    cout << "\n Quantity of Burger: ";
    cin >> quantBurger;
    cout << "\n Quantity of Noodles: ";
    cin >> quantNoodles;
    cout << "\n Quantity of Shake: ";
    cin >> quantShake;
    cout << "\n Quantity of Chicken: ";
    cin >> quantChicken;

    m:
    cout <<"\n\t\t\t Please select from the menu options: ";
    cout <<"\n\n1) Rooms";
    cout <<"\n\n2) Pasta";
    cout <<"\n\n3) Burger";
    cout <<"\n\n4) Noodles";
    cout <<"\n\n5) Shake";
    cout <<"\n\n6) Chicken";
    cout <<"\n\n7) Information regarding sales and collection";
    cout <<"\n\n8) Exit";

    cout <<"\n\n Please Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
        /* code */
        cout << "\n\n Enter the number of rooms you want: ";
        cin >> quantity;
        if(
            quantRooms - soldRooms >= quantity
        ) {
            soldRooms = soldRooms + quantity;
            totalRooms = totalRooms + (quantity*1000);
            cout << "\n\n\t\t" << quantity << "room/rooms have been alloted to you!";
        } else 
            cout << "\n\t Only "<< quantRooms - soldRooms << "Rooms remaining in hotel";
            break;
        
        case 2:
        /* code */
        cout << "\n\n Enter Pasta Quantity: ";
        cin >> quantity;
        if(
            quantPasta - soldPasta >= quantity
        ) {
            soldPasta = soldPasta + quantity;
            totalPasta = totalPasta + (quantity*200);
            cout << "\n\n\t\t" << quantity << "pasta have been order to you!";
        } else 
            cout << "\n\t Only "<< quantPasta - soldPasta << "Pasta remaining.";
            break;
        
        case 3:
        /* code */
        cout << "\n\n Enter Burger Quantity: ";
        cin >> quantity;
        if(
            quantBurger - soldBurger >= quantity
        ) {
            soldBurger = soldBurger + quantity;
            totalBurger = totalBurger + (quantity*200);
            cout << "\n\n\t\t" << quantity << "burger have been order to you!";
        } else 
            cout << "\n\t Only "<< quantBurger - soldBurger << "Burger remaining.";
            break;
        
        case 4:
        /* code */
        cout << "\n\n Enter Noodles Quantity: ";
        cin >> quantity;
        if(
            quantNoodles - soldNoodles >= quantity
        ) {
            soldNoodles = soldNoodles + quantity;
            totalNoodles = totalNoodles + (quantity*200);
            cout << "\n\n\t\t" << quantity << "noodles have been order to you!";
        } else 
            cout << "\n\t Only "<< quantNoodles - soldNoodles << "Noodles remaining.";
            break;
        
        case 5:
        /* code */
        cout << "\n\n Enter Shake Quantity: ";
        cin >> quantity;
        if(
            quantShake - soldShake >= quantity
        ) {
            soldShake = soldShake + quantity;
            totalShake = totalShake + (quantity*200);
            cout << "\n\n\t\t" << quantity << "Shake have been order to you!";
        } else 
            cout << "\n\t Only "<< quantShake - soldShake << "Shake remaining.";
            break;
        
        case 6:
        /* code */
        cout << "\n\n Enter Chicken Quantity: ";
        cin >> quantity;
        if(
            quantChicken - soldChicken >= quantity
        ) {
            soldChicken = soldChicken + quantity;
            totalChicken = totalChicken + (quantity*200);
            cout << "\n\n\t\t" << quantity << "Chicken have been order to you!";
        } else 
            cout << "\n\t Only "<< quantChicken - soldChicken << "Chicken remaining.";
            break;
        
        case 7:
        cout << "\n\t\t Details of sales and collection ";
        cout << "\n\n Number of rooms we had: "<< quantRooms;
        cout << "\n\n Number of rooms we sold for rent " << soldRooms;
        cout << "\n\n Remaining rooms: " << quantRooms - soldRooms;
        cout << "\n\n Total rooms collection for the day: " << totalRooms;

        cout << "\n\n Number of Pasta we had: " << quantPasta;
        cout << "\n\n Number of Pasta we sold " << soldPasta;
        cout << "\n\n Remaining Pasta: " << quantPasta - soldPasta;
        cout << "\n\n Total Pasta collection for the day: " << totalPasta;

        cout << "\n\n Number of Burger we had: " << quantBurger;
        cout << "\n\n Number of Burger we sold " << soldBurger;
        cout << "\n\n Remaining Burger: " << quantBurger - soldBurger;
        cout << "\n\n Total Burger collection for the day: " << totalBurger;

        cout << "\n\n Number of Noodles we had: " << quantNoodles;
        cout << "\n\n Number of Noodles we sold " << soldNoodles;
        cout << "\n\n Remaining Noodles: " << quantNoodles - soldNoodles;
        cout << "\n\n Total Noodles collection for the day: " << totalNoodles;

        cout << "\n\n Number of Shake we had: " << quantShake;
        cout << "\n\n Number of Shake we sold " << soldShake;
        cout << "\n\n Remaining Shake: " << quantShake - soldShake;
        cout << "\n\n Total Shake collection for the day: " << totalShake;

        cout << "\n\n Number of Chicken we had: " << quantChicken;
        cout << "\n\n Number of Chicken we sold " << soldChicken;
        cout << "\n\n Remaining Chicken: " << quantChicken - soldChicken;
        cout << "\n\n Total Chicken collection for the day: " << totalChicken;

        cout << "\n\n\n Total collection for the day: " << totalRooms + totalPasta + totalBurger + totalNoodles + totalShake + totalChicken;
        break;

        case 8:
            exit(0);
            default:
                cout << "\n Please select the numbers mentioned above!";
    }
    goto m;
}