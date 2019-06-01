#include<iostream>
#include<iomanip>
#include<fstream>
#include<vector>
#include<sstream>
#include<string.h>
#include<string>
using namespace std;

class Nguoi{
    protected:
    char fullName[30];
    char address[30];
    char phone[10];
};

class NhanVien:public Nguoi{
    friend class Bill;
private:
    static int maNVConst;
    int maNV;
    char time[10];
public:
    void addInfor(){
        fflush(stdin);
        NhanVien nv;
        cout << "Nhap ho ten: "; cin.getline(nv.fullName, 30);
        cout << "Nhap dia chi: "; cin.getline(nv.address, 30);
        cout << "Nhap SDT: "; cin.getline(nv.phone, 10);
        cout << "Nhap thoi gian ky hop dong: "; cin.getline(nv.time, 10);
        nv.maNV = maNVConst++;
        writeToFile(nv);
    }

    void writeToFile(NhanVien nv){
        ofstream ofs("NV.DAT", ios::app);
        ofs << nv.maNV << endl;
        ofs << nv.fullName << endl;
        ofs << nv.address << endl;
        ofs << nv.phone << endl;
        ofs << nv.time << endl;
    }

    vector<NhanVien> getAllNhanVien(){
        ifstream ifs("NV.DAT");
        vector<NhanVien> nvs;
        string line;
        while(!ifs.eof()){
            NhanVien nv;
            getline(ifs, line);
            stringstream ss(line);
            ss >> nv.maNV;
            getline(ifs, line);
            strcpy(nv.fullName, line.c_str());
            getline(ifs, line);
            strcpy(nv.address, line.c_str());
            getline(ifs, line);
            strcpy(nv.phone, line.c_str());
            getline(ifs, line);
            strcpy(nv.time, line.c_str());
            if (!ifs.eof())
                nvs.push_back(nv);
        }
        ifs.close();
        return nvs;
    }

    void displayAllNV(){
        vector<NhanVien> nvs = getAllNhanVien();
        cout << "Danh sach cac nhan vien" << endl;
        cout << left << setw(15) << "Ma NV" << setw(20) << "Ho ten" << setw(20) << "Dia chi" << setw(15) << "SDT" << setw(15) << "Ngay ky HD" << endl;
        for(int i = 0; i < nvs.size(); i++)
            cout << left << setw(15) << nvs[i].maNV << setw(20) << nvs[i].fullName << setw(20) << nvs[i].address << setw(15) << nvs[i].phone << setw(15) << nvs[i].time << endl;
    }
};

class MatHang{
    friend class Bill;
private:
    static int MHIDConst;
    int MHID;
    char tenMH[30];
    char nhomMH[30];
    int giaban;
    int soluong;
public:
    void addInfor(){
        MatHang mh;
        cout << "Nhap ten MH: "; cin.getline(mh.tenMH, 30);
        cout << "1.Dien tu \n2.Dien lanh \n3.May tinh \n4.Thiet bi van phong \nLoai MH:";
        int choise; cin >> choise;
        if(choise == 1)
            strcpy(mh.nhomMH, "Dien tu");
        if(choise == 2)
            strcpy(mh.nhomMH, "Dien lanh");
        if(choise == 3)
            strcpy(mh.nhomMH, "May tinh");
        if(choise == 4)
            strcpy(mh.nhomMH, "Thiet bi van phong");
        cout << "Nhap gia ban: "; cin >> mh.giaban;
        cout << "Nhap so luong: "; cin >> mh.soluong;
        mh.MHID = MHIDConst++;
        writeToFile(mh);
    }

    void writeToFile(MatHang mh){
        ofstream ofs("MH.DAT", ios::app);
        ofs << mh.MHID << endl;
        ofs << mh.tenMH << endl;
        ofs << mh.nhomMH << endl;
        ofs << mh.giaban << endl;
        ofs << mh.soluong << endl;
        ofs.close();
    }

    vector<MatHang> getAllMH(){
        vector<MatHang> mhs;
        ifstream ifs("MH.DAT");
        string line;
        while(!ifs.eof()){
                MatHang mh;
            getline(ifs, line);
            stringstream ss(line);
            ss >> mh.MHID;
            getline(ifs, line);
            strcpy(mh.tenMH, line.c_str());
            getline(ifs, line);
            strcpy(mh.nhomMH, line.c_str());
            getline(ifs, line);
            stringstream s(line);
            s >> mh.giaban;
            getline(ifs, line);
            stringstream s1(line);
            s1 >> mh.soluong;
            if(!ifs.eof())
                mhs.push_back(mh);
        }
        ifs.close();
        return mhs;
    }

    void displayAllMH(){
        vector<MatHang> mhs = getAllMH();
        cout << "Danh sach mat hang" << endl;
        cout << left << setw(15) << "Ma MH" << setw(10) << "Ten MH" << setw(25) <<"Nhom MH" << setw(15) << "Gia ban" << setw(15) << "So luong" << endl;
        for(int i = 0;i < mhs.size(); i++){
            cout << left << setw(15) << mhs[i].MHID << setw(10) << mhs[i].tenMH << setw(25) << mhs[i].nhomMH << setw(15) << mhs[i].giaban << setw(15) << mhs[i].soluong << endl;
        }
     }
};
class Bill{
private:
    NhanVien nv;
    int total;
    int nums[100];
    MatHang mhs[100];
public:
    void createBill(NhanVien n){
        total = 0;
        nv = n;
        cout << "Nhap thong tin cho bang DS ban hang cua " << n.fullName << endl;
        MatHang m;
        vector<MatHang> mathang = m.getAllMH();
        char cont = 'y';
        while(cont == 'y'){
            int mhiD, mark = 1;
            do {
                cout << "Nhap ma MH: "; cin >> mhiD;
                for(int i = 0; i < mathang.size(); i++){
                    if(mhiD == mathang[i].MHID){
                        mark = 0;
                        mhs[total] = mathang[i];
                    }
                }
                for(int i = 0; i < total; i++){
                    if(mhiD == mhs[i].MHID)
                        mark = 1;
                }
            }while(mark);
            cout << "So luong: "; cin >> nums[total];
            total++;
            cout << "Continue?(y/n)"; cin >> cont;
        }
        writeToFile();
    }
    void writeToFile(){
        ofstream ofs("QLBH.DAT",ios::app);
        ofs.write((const char*)this, sizeof(Bill));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read((char*)this, sizeof(Bill));
    }

    void detail(){
        cout << "Ho ten: " << nv.fullName << endl;
        cout << "Tong so mat hang da ban: " << total << endl;
        cout << "Bang danh sach" << endl;
        cout << left << setw(15) << "Ma MH" << setw(15) << "Ten MH" << setw(15) << "So luong" << endl;
        for(int i = 0;i < total; i++)
            cout << left << setw(15) << mhs[i].MHID << setw(15) << mhs[i].tenMH << setw(15) << nums[i] << endl;

    }

    void displayAllBill(){
        ifstream ifs("QLBH.DAT");
        while(!ifs.eof()){
            Bill b;
             b.readOneByOne(ifs);
             if(!ifs.eof())
                b.detail();
        }
        ifs.close();
    }

    void sortByName(){
        ifstream ifs("QLBH.DAT");
        vector<Bill> bills;
        while(!ifs.eof()){
            Bill b;
             b.readOneByOne(ifs);
             if(!ifs.eof())
                bills.push_back(b);
        }
        ifs.close();
        for(int i = 0; i < bills.size() - 1; i++){
            for(int j = i + 1; j < bills.size(); j++){
                if(strcmp(bills[j].nv.fullName, bills[i].nv.fullName) < 0)
                    swap(bills[j], bills[i]);
            }
        }
        cout << "Danh sach sau khi sap xep la: " << endl;
        for(int i = 0; i < bills.size(); i++)
            bills[i].detail();
    }

    void thongke(){
        ifstream ifs("QLBH.DAT");
        vector<Bill> bills;
        while(!ifs.eof()){
            Bill b;
             b.readOneByOne(ifs);
             if(!ifs.eof())
                bills.push_back(b);
        }
        ifs.close();
        cout << "Thong ke doanh thu cua nhan vien" << endl;
        cout << left << setw(25) << "Ho ten" << setw(15) << "Doanh thu" << endl;
        for(int i = 0; i < bills.size(); i++){
            int sum = 0;
            for(int j = 0; j < bills[i].total; j++)
                sum += bills[i].mhs[j].giaban * bills[i].nums[j];
            cout << left << setw(25) << bills[i].nv.fullName << setw(15) << sum << endl;
        }
    }
};
int NhanVien::maNVConst = 1000;
int MatHang::MHIDConst = 1000;
int main(){
//    int n = 1;
//    for(int i = 0; i < n; i++){
//        MatHang nv;
//        nv.addInfor();
//    }
//    MatHang m;
//    m.displayAllMH();
//    NhanVien n;
//    vector<NhanVien> nvs = n.getAllNhanVien();
//    for(int i = 0; i < nvs.size(); i++){
//        Bill b;
//        b.createBill(nvs[i]);
//    }
    Bill b;
    b.thongke();
    return 0;
}
