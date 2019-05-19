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
public:

};

class Driver:public Person{
private:
    static int driverIDConst;
    int driverID;
    char levelDriver;
    vector<Driver> drivers;
public:
    void addDriver(){
        int numberOfDriver;
        cout << "So luong lai xe muon them: "; cin >> numberOfDriver;
        for(int i = 0; i < numberOfDriver; i++){
            cout << "Nhap lai xe thu " << i + 1 << ": " << endl;
            fflush(stdin);
            Driver d;
            cout << "Nhap ho ten: "; cin.getline(d.fullName, 30);
            cout << "Nhap dia chi: "; cin.getline(d.address, 30);
            cout << "Nhap so DT: "; cin.getline(d.phoneNumber, 11);
            d.driverID = driverIDConst++;
            cout << "Nhap trinh do: "; cin >> d.levelDriver;
            if(d.levelDriver >= 'a' && d.levelDriver <= 'z')
                d.levelDriver = d.levelDriver - 32;
            while(d.levelDriver < 'A' || d.levelDriver > 'F'){
                cout << "Nhap trinh lai do: "; cin >> d.levelDriver;
            }
            drivers.push_back(d);
        }
        writeToFile();
    }

    void writeToFile(){
        ofstream ofs("LX.DAT", ios::app);
        if(ofs.fail()){
            cout << "Error!" << endl;
            return;
        }else {
            for(int i = 0; i < drivers.size(); i++)
                ofs.write(reinterpret_cast<const char*>(&drivers[i]), sizeof(Driver));
            ofs.close();
        }
        readDriverFile();
    }

    void readDriverFile(){
        ifstream ifs("LX.DAT");
        if(ifs.fail()){
            cout << "Error!" << endl;
            return;
        } else {
            cout << "----------Thong tin cua cac lai xe----------" << endl;
            cout << left << setw(10) << "Ma LX" << setw(20) << "Ho ten" << setw(20) << "Dia chi" <<
            setw(12) << "So DT" << setw(10) << "Trinh do" << endl;
            while(!ifs.eof()){
                ifs.read(reinterpret_cast<char*>(this), sizeof(Driver));
                if(!ifs.eof())
                    cout << left << setw(10) << driverID << setw(20) << fullName << setw(20) << address <<
                    setw(12) << phoneNumber << setw(10) << levelDriver << endl;
            }
        }
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Driver));
    }

};

class Buses{
    friend class AssignTable;
private:
    static int busIDConst;
    int busID;
    int range;
    int numberOfStops;
    vector<Buses> buses;
public:
    Buses(){
        range = numberOfStops = 0;
    }
    void addBus(){
        int number;
        cout << "So luong tuyen muon them: "; cin >> number;
        for(int i = 0; i < number; i++){
            cout << "Nhap thong tin cho tuyen thu " << i + 1 << endl;
            Buses bus;
            bus.busID = busIDConst++;
            cout << "Nhap khoang cach: "; cin >> bus.range;
            cout << "Nhap so diem dung: "; cin >> bus.numberOfStops;
            buses.push_back(bus);
        }
        writeToFile();
    }

    void writeToFile(){
        ofstream ofs("TUYEN.DAT", ios::app);
        if(ofs.fail()){
            cout << "Error" << endl;
            return;
        } else {
            for(int i = 0; i < buses.size(); i++)
                ofs.write(reinterpret_cast<const char*>(&buses[i]), sizeof(Buses));
            ofs.close();
        }
        readBusesFile();
    }

    void readBusesFile(){
        ifstream ifs("TUYEN.DAT");
        if(ifs.fail()){
            cout << "Error" << endl;
            return;
        } else {
            cout << "----------Thong tin cua cac tuyen xe----------" << endl;
            cout << left << setw(10) << "Ma tuyen" << setw(15) << "Khoang cach" << setw(15) << "So diem dung" << endl;
            while(!ifs.eof()){
                ifs.read(reinterpret_cast<char*>(this), sizeof(Buses));
                if(!ifs.eof())
                    cout << left << setw(10) << busID << setw(15) << range << setw(15) << numberOfStops << endl;
            }
            ifs.close();
        }
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Buses));
    }
};

class AssignTable {
private:
    int busesTotal;
    Driver d;
    Buses busesList[100];
    int numberOfTurnList[100] = {0};
public:
    void addWord(Driver driver){
        vector<Buses> buses;
        ifstream ifs("TUYEN.DAT");

        while(ifs){
            Buses b;
            b.readOneByOne(ifs);
            if(!ifs.eof())
                buses.push_back(b);
        }
        cout << "Size vector buses: " << buses.size() << endl;
       cout << "Nhap thong tin phan cong cho " << driver.fullName << ": " << endl;
       d = driver;
       do{
        cout << "Nhap so luong tuyen muon chay: "; cin >> busesTotal;
       } while(busesTotal < 0 || busesTotal > 16);

       for(int i = 0; i < busesTotal; i++){
            int busIDTemp, mark = 1, counter = 0;
            do{
                cout << "Nhap ma tuyen: "; cin >> busIDTemp;
                for(int j = 0; j < buses.size(); j++){
                    if(busIDTemp == buses[j].busID){
                        mark = 0;
                        busesList[i] = buses[j];
                    }
                }

                for(int k = 0; k < i; k++){
                    if(busesList[k].busID == busIDTemp)
                        mark = 1;
                }
            } while(mark);
            int number;
            do{
                cout << "Nhap so luot chay: "; cin >> number;
                numberOfTurnList[i] = number;
            } while(number< 0 || number > 16);
       }
       write();
    }

    void write(){
        ofstream ofs("PHANCONG.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(this), sizeof(AssignTable));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(AssignTable));
    }

    void workInfor(){
        cout << "Ho ten LX: " << d.fullName << endl;
        cout << "Tong so chuyen chay: " << busesTotal << endl;
        cout << "Thong tin cac chuyen chay:" << endl;
        cout << left << setw(10) << "Ma chuyen" << setw(15) << "Khoang cach" << setw(15) << "So chuyen" << endl;
        for(int i = 0; i < busesTotal; i++)
            cout << left << setw(10) << busesList[i].busID << setw(15) << busesList[i].range << setw(15)<< numberOfTurnList[i] << endl;
    }

    char* getName(){
        return d.fullName;
    }

    void sortByName(){
        vector<AssignTable> temp;
        ifstream ifs("PHANCONG.DAT");
        while(!ifs.eof()){
            AssignTable a;
            a.readOneByOne(ifs);
            if(!ifs.eof()){
                temp.push_back(a);
            }
        }
        ifs.close();
        //cout << "Size temp: " << temp.size() << endl;
        for(int i = 0; i < temp.size() - 1; i++){
            for(int j = i + 1; j < temp.size(); j++){
                if(strcmp(temp[i].getName(), temp[j].getName()) > 0)
                    swap(temp[i], temp[j]);
            }
        }
        cout << "Thong tin sau khi sap xep la:" << endl;
        for(int i = 0; i < temp.size(); i++)
            temp[i].workInfor();
    }

    void sortByTurn(){
        vector<AssignTable> temp;
        ifstream ifs("PHANCONG.DAT");
        while(!ifs.eof()){
            AssignTable a;
            a.readOneByOne(ifs);
            if(!ifs.eof()){
                temp.push_back(a);
            }
        }
        ifs.close();
        //cout << "Size temp: " << temp.size() << endl;
        for(int i = 0; i < temp.size() - 1; i++){
            for(int j = i + 1; j < temp.size(); j++){
                if(temp[i].busesTotal < temp[j].busesTotal)
                    swap(temp[i], temp[j]);
            }
        }
        cout << "Thong tin sau khi sap xep la:" << endl;
        for(int i = 0; i < temp.size(); i++)
            temp[i].workInfor();
    }

    void thongke(){
        vector<AssignTable> temp;
        ifstream ifs("PHANCONG.DAT");
        while(!ifs.eof()){
            AssignTable a;
            a.readOneByOne(ifs);
            if(!ifs.eof()){
                temp.push_back(a);
            }
        }
        ifs.close();
        cout << left << setw(15) << "Ho ten LX" << setw(10) << "Quang duong" << endl;
        for(int i = 0; i < temp.size(); i++){
            int sum = 0;
            for(int j = 0; j < temp[i].busesTotal; j++){
                sum += (temp[i].busesList[j].range * temp[i].busesList[j].numberOfStops);
            }
            cout << left << setw(15) << temp[i].getName() << setw(10) << sum / 2<< endl;
        }
    }
};
int Driver::driverIDConst = 10000;
int Buses::busIDConst = 100;
int main(){
    /*Driver d;
    d.addDriver();
    Buses b;
    b.addBus();
    AssignTable a;
    ifstream ifs("LX.DAT");
    vector<Driver> drs;
    while(ifs){
        Driver d;
        d.readOneByOne(ifs);
        if(!ifs.eof())
            drs.push_back(d);
    }
    for(int i = 0;i < drs.size(); i++)
        a.addWord(drs[i]);
    */
    AssignTable a;
    a.sortByTurn();
    a.thongke();
    return 0;
}
