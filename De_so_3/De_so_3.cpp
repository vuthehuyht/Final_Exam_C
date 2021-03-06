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
    friend class Bill;
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

class Service{
    friend class Bill;
private:
    static int serviceIDConst;
    int serviceID;
    char serviceName[30];
    int servicePrice;
    char calUnit[30];
public:
    void addService(){
        cout << "Nhap so luong dich vu muon them: ";
        int num; cin >> num;
        for(int i = 0; i < num; i++){
            cout << "Nhap thong tin cho dich vu thu " << i + 1 << ":" << endl;
            Service s;
            fflush(stdin);
            s.serviceID = serviceIDConst++;
            cout << "Nhap ten dich vu: "; cin.getline(s.serviceName, 30);
            cout << "Nhap gia cuoc: "; cin >> s.servicePrice;
            cin.ignore();
            cout << "Nhap don vi tinh: "; cin.getline(s.calUnit, 30);
            writeToFile(s);
        }
    }
    void writeToFile(Service s){
        ofstream ofs("DV.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(&s), sizeof(Service));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Service));
    }

    void displayAllService(){
        cout << "----------Thong tin cua cac dich vu----------" << endl;
        cout << left << setw(10) << "Ma DV" << setw(20) << "Ten DV"<< setw(20) << "Gia DV" <<
            setw(12) << "Don vi tinh" << endl;
        ifstream ifs("DV.DAT");
        while(ifs){
            Service s;
            s.readOneByOne(ifs);
            if(!ifs.eof())
                cout << left << setw(10) << s.serviceID << setw(20) << s.serviceName << setw(20) << s.servicePrice << setw(12) << s.calUnit << endl;
        }
        ifs.close();
    }
};

class Bill{
private:
    Customer customer;
    int serviceTotal;
    int numberOfService[100] = {0};
    Service s[100];
public:
    Bill(){
        serviceTotal = 0;
    }
    void addBill(Customer cus){
        vector<Service> services;
        ifstream ifs("DV.DAT");
        while(!ifs.eof()){
            Service s;
            s.readOneByOne(ifs);
            services.push_back(s);
        }
        cout << "Nhap thong tin hoa don cho " << cus.fullName << ": " << endl;
        customer = cus;
        cout << "Nhap so luong dich vu: "; cin >> serviceTotal;
        for(int i = 0; i < serviceTotal; i++){
            fflush(stdin);
            int serID, mark = 1;
            do{
                cout << "Nhap ma DV: "; cin >> serID;
                for(int j = 0; j < services.size(); j++){
                    if(serID == services[j].serviceID){
                        mark = 0;
                        s[i] = services[j];
                }
            }
                for(int k = 0; k < i; k++){
                    if(serID == services[k].serviceID)
                    mark = 1;
                }
            } while(mark);
            cout << "Nhap so lan da dung: "; cin >> numberOfService[i];
            cout << "Number inputed: " << i << " = " << numberOfService[i] << endl;
        }
        write();
    }
    void write(){
        ofstream ofs("HD.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(this), sizeof(Bill));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Bill));
    }

    void billInfor(){
        cout << "Ho ten KH: " << customer.fullName << endl;
        cout << "Tong so dich vu da dung: " << serviceTotal << endl;
        cout << left << setw(10) << "Ten DV" << setw(15) << "Gia DV" << setw(15) << "Don vi tinh" << setw(15) << "So lan su dung" << endl;
        for(int i = 0; i < serviceTotal; i++)
            cout << left << setw(10) << s[i].serviceName << setw(15) << s[i].servicePrice << setw(15) << s[i].calUnit<< setw(15) << numberOfService[i] << endl;
    }

    void displayAllBill(){
        ifstream ifs("HD.DAT");
        while(!ifs.eof()){
            Bill b;
            b.readOneByOne(ifs);
            b.billInfor();
        }
        ifs.close();
    }
    char* getName(){
        return customer.fullName;
    }
    void sortByName(){
        vector<Bill> bills;
        ifstream ifs("HD.DAT");
        while(!ifs.eof()){
            Bill b;
            b.readOneByOne(ifs);
            bills.push_back(b);
        }
        ifs.close();
        cout << "Size bills: " << bills.size() << endl;
        for(int i = 0; i < bills.size() - 1; i++){
            for(int j = i + 1; j < bills.size(); j++){
                if(strcmp(bills[i].getName(), bills[j].getName()) > 0)
                    swap(bills[i], bills[j]);
            }
        }
        cout << "Thong tin sau khi sap xep" << endl;
        for(int i = 0; i < bills.size(); i++)
            bills[i].billInfor();
    }

    void sortByNum(){
        vector<Bill> bills;
        ifstream ifs("HD.DAT");
        while(!ifs.eof()){
            Bill b;
            b.readOneByOne(ifs);
            bills.push_back(b);
        }
        ifs.close();
        for(int i = 0; i < bills.size(); i++){
            for(int j = 0; j < bills[i].serviceTotal - 1; j++){
                bool swapped = false;
                for(int k = 0; k < bills[i].serviceTotal - j - 1; k++){
                    if(bills[i].numberOfService[k] < bills[i].numberOfService[k + 1]){
                        swap(bills[i].numberOfService[k], bills[i].numberOfService[k + 1]);
                        swapped = true;
                    }
                }
                if (swapped == false)
                    break;
            }
        }
        cout << "Thong tin sau khi sap xep" << endl;
        for(int i = 0; i < bills.size(); i++)
            bills[i].billInfor();
    }

    void thongke(){
        vector<Bill> bills;
        ifstream ifs("HD.DAT");
        while(!ifs.eof()){
            Bill b;
            b.readOneByOne(ifs);
            bills.push_back(b);
        }
        ifs.close();
        cout << "So tien moi khach can tra" << endl;
        cout << left << setw(15) <<  "Ho ten KH" << setw(15) << "So tien can tra" << endl;
        for(int i = 0; i < bills.size(); i++){
            int sum = 0;
            for(int j = 0; j < bills[i].serviceTotal; j++)
                sum += bills[i].numberOfService[j] * bills[i].s[j].servicePrice;
            cout << left << setw(15) << bills[i].getName() << setw(15) << sum << endl;
        }
    }
};

int Customer::custormerIDConst = 10000;
int Service::serviceIDConst = 100;

int main(){
//    Customer c;
//    c.addCustomer();
//    c.displayAllCustomer();
//    Service s;
//    s.addService();
//    s.displayAllService();
//    vector<Customer> cs;
//    ifstream ifs("KH.DAT");
//    while(ifs){
//        Customer c;
//        c.readOneByOne(ifs);
//        if(!ifs.eof())
//            cs.push_back(c);
//    }
//    ifs.close();
//    Bill b[cs.size()];
//    for(int i = 0; i < cs.size(); i++)
//        b[i].addBill(cs[i]);
//    Bill b1;
//    b1.sortByName();
    Bill b;
    b.displayAllBill();
    b.thongke();
    return 0;
}
