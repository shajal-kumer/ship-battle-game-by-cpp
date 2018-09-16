#include<iostream>
#include<ctime>
#include<windows.h>
using namespace std;

const int rows = 10;
const int cols = 10;
const int Maxship = 10;
int Matrix[rows][cols];

void Clear() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            Matrix[i][j] = 0;
        }
    }
}

void SetShip() {
    int i = 0;
    while(i < Maxship) {
        int x = rand() % 10;
        int y = rand() % 10;

        if(Matrix[x][y] != 1) {
            i++;
            Matrix[x][y] = 1;
        };
    }
}
void Show() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout<<Matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}

bool Attack(int x, int y) {
    if(Matrix[x][y] == 1){
        Matrix[x][y] = 2;
        return true;
    }
    return false;
}

int NumberOfShips() {
    int c = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(Matrix[i][j] == 1){
                c++;
            }
        }
    }
    return c;
}

int main() {
    srand(time(NULL));
    Clear();
    SetShip();
    int pos1, pos2;
    char prompt;
    while(1) {
        cout<<"Please Input Ship Location For Attacking (1 2) : ";cin>>pos1>>pos2;
        if(Attack(pos1, pos2)) {
            cout<<"You got me :)"<<endl;
        } else {
            cout<<"Sorry no ship at that position!"<<endl;
        }
        cout<<"Number of ship left: "<<NumberOfShips()<<endl<<endl;
        cout<<"Do you want to surrender (y/n): ";cin>>prompt;
        if(prompt == 'y' || prompt == 'Y')
            break;
    }
    cout<<"Game Over!"<<endl;
    Show();



//    Show();
//    cout<<"=============================="<<endl;
//    SetShip();
//    Show();
//    cout<<"=============================="<<endl;
//    Attack(1,1);
//    Show();
//    cout<<"=============================="<<endl;
//    cout<<"Number of left ships is: " << NumberOfShips() << endl;

return 0;
}
