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

class TicketBuyer:public Person{
    friend class Bill;
private:
    static int ticketBuyerIDConst;
    int ticketBuyerID;
    char buyerType[100];
public:
    void addBuyer(){
        int number;
        cout << "Nhap so luong nguoi mua: "; cin >> number;
        for(int i = 0; i < number; i++){
            TicketBuyer tb;
            fflush(stdin);
            cout << "Nhap ho ten: "; cin.getline(tb.fullName, 30);
            cout << "Nhap dia chi: "; cin.getline(tb.address, 30);
            cout << "Nhap so DT: "; cin.getline(tb.phoneNumber, 11);
            tb.ticketBuyerID = ticketBuyerIDConst++;
            cout << "1. Mua le \n2. Mua tap the \n3. Mua qua mang \nLoai nguoi mua: ";
            int choise; cin >> choise;
            if(choise == 1)
                strcpy(tb.buyerType, "Mua le");
            if(choise == 2)
                strcpy(tb.buyerType, "Mua tap the");
            if(choise == 3)
                strcpy(tb.buyerType, "Mua qua mang");
            writeToFile(tb);
        }
    }

    void writeToFile(TicketBuyer tb){
        ofstream ofs("NGUOIMUA.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(&tb), sizeof(TicketBuyer));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(TicketBuyer));
    }

    void displayAllBuyer(){
        cout << "----------Thong tin cua cac nguoi mua----------" << endl;
        cout << left << setw(10) << "Ma NM" << setw(15) << "Ho ten NM" << setw(15) << "Dia chi" << setw(15) << "So DT" << setw(15) << "Loai NM" << endl;
        ifstream ifs("NGUOIMUA.DAT");
        while(!ifs.eof()){
            TicketBuyer tb;
            tb.readOneByOne(ifs);
            if(!ifs.eof())
                cout << left << setw(10) << tb.ticketBuyerID << setw(15) << tb.fullName << setw(15) << tb.address << setw(15) << tb.phoneNumber << setw(15) << tb.buyerType << endl;
        }
        ifs.close();
    }
};

class Ticket{
    friend class Bill;
private:
    static int ticketIDConst;
    int ticketID;
    int price;
    char seatType[10];
public:
    void addTicket(){
        int number;
        cout << "Nhap so luong ve: "; cin >> number;
        for(int i = 0; i < number; i++){
                cout << "Nhap thong tin ve thu " << i + 1 << ": " << endl;
            Ticket t;
            fflush(stdin);
            cout << "Nhap gia: "; cin >> t.price;
            cout << "1. Thuong \n2. VIP \nLoai ghe: ";
            int choise; cin >> choise;
            if(choise == 1)
                strcpy(t.seatType, "Thuong");
            if(choise == 2)
                strcpy(t.seatType, "VIP");
            t.ticketID = ticketIDConst++;
            writeToFile(t);
        }
    }

    void writeToFile(Ticket t){
        ofstream ofs("VE.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(&t), sizeof(Ticket));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Ticket));
    }

    void displayAllTicket(){
        cout << "----------Thong tin cua ve----------" << endl;
        cout << left << setw(10) << "Ma ve" << setw(15) << "Gia ve" << setw(15) << "Loai ghe" << endl;
        ifstream ifs("VE.DAT");
        while(ifs){
            Ticket t;
            t.readOneByOne(ifs);
            if(!ifs.eof())
                cout << left << setw(10) << t.ticketID << setw(15) << t.price << setw(15) << t.seatType << endl;
        }
    }
};

class Bill{
private:
    TicketBuyer tb;
    int ticketTotal;
    int numOfTicket[100]= {0};\
    Ticket t[100];
public:
    Bill(){
        ticketTotal = 0;
    }
    void addBill(TicketBuyer _tb){
        vector<Ticket> ts;
        ifstream ifs("VE.DAT");
        while(ifs){
            Ticket t;
            t.readOneByOne(ifs);
            if(!ifs.eof())
                ts.push_back(t);
        }
        ifs.close();
        cout << "Nhap thong tin hoa cho " << _tb.fullName << ": " << endl;
        tb = _tb;
        cout << "Nhap so luong ve da mua: "; cin >> ticketTotal;
        for(int i = 0; i < ticketTotal; i++){
            fflush(stdin);
            int tickID, mark = 1;
            do{
                cout << "Nhap ma ve: "; cin >> tickID;
                for(int j = 0; j < ts.size(); j++){
                    if(tickID == ts[j].ticketID){
                        mark = 0;
                        t[i] = ts[j];
                    }
                }
                for(int j = 0; j < i; j++){
                    if(tickID == t[j].ticketID)
                        mark = 1;
                }
            } while(mark);
            do{
                cout << "Nhap so luong: "; cin >> numOfTicket[i];
            }while(numOfTicket[i] < 1 || numOfTicket[i] > 20);
        }
        writeToFile();
    }
    void writeToFile(){
        ofstream ofs("HOADON.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(this), sizeof(Bill));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Bill));
    }
    void detailBill(){
        cout << "Ho ten: " << tb.fullName << endl;
        cout << "Tong luong ve da mua: " << ticketTotal <<endl;
        cout << left << setw(10) << "Ma ve" << setw(15) << "Gia ve" << setw(15) << "Loai ghe" << setw(15) << "So luong" << endl;
        for(int i = 0; i < ticketTotal; i++){
            cout << left << setw(10) << t[i].ticketID << setw(15) << t[i].price << setw(15) << t[i].seatType << setw(15) << numOfTicket[i] << endl;
        }
    }
    void displayAllBill(){
        ifstream ifs("HOADON.DAT");
        while(!ifs.eof()){
            Bill b;
            b.readOneByOne(ifs);
            if(!ifs.eof())
                b.detailBill();
        }
        ifs.close();
    }

    char* getName(){
        return tb.fullName;
    }

    vector<Bill> getBillVector(){
        vector<Bill> bills;
        ifstream ifs("HOADON.DAT");
        while(!ifs.eof()){
            Bill b;
            b.readOneByOne(ifs);
            if(!ifs.eof())
                bills.push_back(b);
        }
        ifs.close();
        return bills;
    }

    void sortByName(){
        vector<Bill> temp = getBillVector();
        for(int i = 0; i < temp.size() - 1; i++){
            for(int j = i + 1; j < temp.size(); j++)
                if(strcmp(temp[i].getName(), temp[j].getName()) > 0)
                    swap(temp[i], temp[j]);
        }
        cout << "Danh sach sau khi sap xep la:" << endl;
        for(int i = 0; i < temp.size(); i++)
            temp[i].detailBill();
    }

    void sortByTurn(){
        vector<Bill> temp = getBillVector();
        for(int i = 0; i < temp.size(); i++){
            for(int j = 0; j < temp[i].ticketTotal - 1; j++){
                bool swapped = false;
                for(int k = 0;k < temp[i].ticketTotal - j - 1; k++){
                    if(temp[i].numOfTicket[k] < temp[i].numOfTicket[k + 1]){
                        swapped = true;
                        swap(temp[i].numOfTicket[k], temp[i].numOfTicket[k + 1]);
                    }
                }
                if(swapped == false)
                    break;
            }
        }
        cout << "Danh sach sau khi sap xep la:" << endl;
        for(int i = 0; i < temp.size(); i++)
            temp[i].detailBill();
    }

    void thongke(){
        cout << left << setw(15) << "Họ ten NM" << setw(15) << "Thanh tien" << endl;
        vector<Bill> temp = getBillVector();
        for(int i = 0; i < temp.size(); i++){
            int sum = 0;
            for(int j = 0; j < temp[i].ticketTotal; j++)
                sum += temp[i].numOfTicket[j] * temp[i].t[j].price;
            cout << left << setw(15) << temp[i].getName() << setw(15) << sum << endl;
        }
    }
};
int TicketBuyer::ticketBuyerIDConst = 10000;
int Ticket::ticketIDConst = 100;
int main(){
//    vector<TicketBuyer> tbs;
//    ifstream ifs("NGUOIMUA.DAT");
//    while(!ifs.eof()){
//        TicketBuyer tb;
//        tb.readOneByOne(ifs);
//        if(!ifs.eof())
//            tbs.push_back(tb);
//    }
//    ifs.close();
    Bill b;
//    for(int i = 0; i < tbs.size(); i++)
//        b.addBill(tbs[i]);
    b.displayAllBill();
    b.thongke();
    return 0;
}
