#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;

class Person{
    friend class AssignTable;
protected:
    char fullName[30];
    char address[30];
    char phoneNumber[11];
};

class Customer:public Person{
private:
    static int custormerIDConst;
    int customerID;
    char customerType[100];
public:
    void addCustomer(){
        int number;
        cout << "Nhap so luong khach muon them: "; cin >> number;
        for(int i = 0; i < number; i++){
            cout << "Nhap thong tin khach thu " << i + 1 << ": " << endl;
            fflush(stdin);
            Customer c;
            cout << "Nhap ho ten: "; cin.getline(c.fullName, 30);
            cout << "Nhap dia chi: "; cin.getline(c.address, 30);
            cout << "Nhap so DT: "; cin.getline(c.phoneNumber, 11);
            c.customerID = custormerIDConst++;
            cout << "1. Ca nhan \n2. Dai dien don vi hanh chinh \n3. Dai dien don vi kinh doanh \nLoai khach hang: ";
            int choice; cin >> choice;
            if(choice == 1){
                string s = "Ca nhan";
                strcpy(c.customerType, "Ca nhan");
            }
            if(choice == 2){
                string s = "Dai dien don vi hanh chinh";
                strcpy(c.customerType, s.c_str());
            }
            if(choice == 3){
                string s = "Dai dien don vi hanh chinh";
                strcpy(c.customerType, s.c_str());
            }

            writeToFile(c);
        }
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Customer));
    }

    void writeToFile(Customer c){
        ofstream ofs("KH.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(&c), sizeof(Customer));
        ofs.close();
    }

    void displayAllCustomer(){
        ifstream ifs("KH.DAT");
        cout << "----------Thong tin cua cac khach hang----------" << endl;
        cout << left << setw(10) << "Ma KH" << setw(20) << "Ho ten" << setw(20) << "Dia chi" <<
            setw(12) << "So DT" << setw(10) << "Loai KH" << endl;
        while(ifs){
            Customer c;
            c.readOneByOne(ifs);
            if(!ifs.eof())
                cout << left << setw(10) << c.customerID << setw(20) << c.fullName << setw(20) << c.address <<
                setw(12) << c.phoneNumber << setw(10) << c.customerType << endl;
        }
    }
};

int Customer::custormerIDConst = 10000;

int main(){
    Customer c;
    c.addCustomer();
    c.displayAllCustomer();
    return 0;
}
