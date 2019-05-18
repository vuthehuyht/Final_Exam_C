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
            if(d.levelDriver < 'a' && d.levelDriver <= 'z')
                d.levelDriver -= 32;
            while(d.levelDriver < 'A' || d.levelDriver > 'F'){
                cout << "Nhap trinh lai do: "; cin >> d.levelDriver;
            }
            drivers.push_back(d);
        }
        //writeToFile();
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
};

class AssignTable {
private:
    Driver d;
    vector<Buses> busesList;
    int number;
    vector<int> numberOfTurnList;
};
int Driver::driverIDConst = 10000;
int Buses::busIDConst = 100;
int main(){
    Driver d;
    d.addDriver();
    return 0;
}
