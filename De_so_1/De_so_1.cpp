#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<vector>
#include<sstream>
#include<iomanip>
using namespace std;

class Nguoi{
protected:
    string hoTen;
    string diaChi;
    string soDT;


};

class KhachHang : public Nguoi{
    friend class HoaDon;
private:
    int maKH;
    string nhomKH;
    vector<KhachHang> customers;

public:
    void readCustomerFile(){
        fstream f;
        f.open("KH.DAT", ios::in);

        if(f.fail()){
            cout << "Opening file failed!" << endl;
            return;
        }
        else {
            string data;
            int indexTemp = 1;
            KhachHang cus;
            while(!f.eof()){
                getline(f, data);
                if(indexTemp == 1){
                    cus.hoTen = data;
                    indexTemp++;
                    continue;
                }
                if(indexTemp == 2){
                    cus.diaChi = data;
                    indexTemp++;
                    continue;
                }
                if(indexTemp == 3){
                    cus.soDT = data;
                    indexTemp++;
                    continue;
                }
                if(indexTemp == 4){
                    stringstream ss(data);
                    ss >> cus.maKH;
                    indexTemp++;
                    continue;
                }
                if(indexTemp == 5){
                    cus.nhomKH = data;
                    customers.push_back(cus);
                    indexTemp = 1;
                    continue;
                }
            }
            f.close();
        }
    }

    void displayCustomers(){
        for(int i = 0;i < customers.size(); i++){
            cout << customers[i].hoTen << endl;
            cout << customers[i].diaChi << endl;
            cout << customers[i].soDT << endl;
            cout << customers[i].maKH << endl;
            cout << customers[i].nhomKH << endl;
        }
    }

    void enterCustomer(){
        KhachHang cus;
        fflush(stdin);
        cout << "Nhap ten KH: "; getline(cin, cus.hoTen);
        cout << "Nhap dia chi KH: "; getline(cin, cus.diaChi);
        cout << "Nhap so DT KH: "; getline(cin, cus.soDT);
        cout << "Nhap ma KH: "; cin >> cus.maKH;
        cin.ignore();
        cout << "Nhap nhom KH: "; getline(cin, cus.nhomKH);
        writeCustomer(cus);
    }

    void writeCustomer(KhachHang cus){
        fstream f;
        f.open("KH.DAT", ios::app);
        if(f.fail()){
            cout << "Opening file fail" <<endl;
            return;
        }
        else{
            f << cus.hoTen << endl;
            f << cus.diaChi << endl;
            f << cus.soDT << endl;
            f << cus.maKH << endl;
            f << cus.nhomKH << endl;
        }
        f.close();
    }

};

class MatHang{
    friend class HoaDon;
private:
    int maHang;
    string tenHang;
    int donGia;
    vector<MatHang> products;

public:
    void enterProduct(){
        MatHang pro;
        fflush(stdin);
        cout << "Nhap ma mat hang: "; cin >> pro.maHang;
        cin.ignore();
        cout << "Nhap ten hang: "; getline(cin, pro.tenHang);
        cout << "Nhap don gia: "; cin >> pro.donGia;
        writeProduct(pro);
    }

    void writeProduct(MatHang pro){
        fstream f;
        f.open("MATHANG.DAT", ios::app);
        if(f.fail()){
            cout << "Opening file fail" <<endl;
            return;
        }
        else{
            f << pro.maHang << endl;
            f << pro.tenHang << endl;
            f << pro.donGia << endl;
        }
        f.close();
    }

    void readProductFile(){
        fstream f;
        f.open("MATHANG.DAT", ios::in);
        if(f.fail()){
            cout << "Opening file fail" <<endl;
            return;
        } else {
            string data;
            int index = 1;
            MatHang p;
            while(!f.eof()){
                getline(f, data);
                if(index == 1){
                    stringstream ss(data);
                    ss >> p.maHang;
                    index++;
                    continue;
                }
                if(index == 2){
                    p.tenHang = data;
                    index++;
                    continue;
                }
                if(index == 3){
                    stringstream ss(data);
                    ss >> p.donGia;
                    products.push_back(p);
                    index = 1;
                }
            }
            f.close();
        }
    }

    void displayProduct(){
        for(int i = 0; i < products.size(); i++){
            cout << products[i].maHang << endl;
            cout << products[i].tenHang << endl;
            cout << products[i].donGia << endl;
        }
    }
};

class HoaDon{
private:
    map<int, map<int, int> > billLists;
    map<int, int> productsList;
    KhachHang kh; MatHang m;
    vector<KhachHang> customerList;
    vector<MatHang> products;

public:
    void enterBill(){
        kh.readCustomerFile();
        m.readProductFile();
        customerList = kh.customers;
        products = m.products;
        cout << customerList.size() << " " << products.size() << endl;
        for(int i = 0; i < customerList.size(); i++){
            cout << "Nhap danh sach hang da mua cho " << customerList[i].hoTen << ":" << endl;
            int productID = 0;
            int number;
            bool check = true;
            while(productID != -1){
                cin >> productID;

                for(map<int, int>::iterator k = productsList.begin(); k != productsList.end(); k++){
                    if(k->first == productID){
                        check = false;
                        cout << "Ma mat hang trung." << endl;
                    }
                }
               /* if(check && productID != -1){
                    do{
                        cin >> productID;
                        for(int j = 0;j < products.size(); j++){
                            if(productID == products[j].maHang){
                                productsList.insert(make_pair(productID, number));
                            }
                            else {
                                check = false;
                                cout << "Ma mat hang khong dung." << endl;
                                cout << products[j].maHang << endl;
                                break;
                            }
                        }
                    } while(check == false);
                }*/
                cin >> number;
            }
            billLists.insert(make_pair(customerList[i].maKH, productsList));
        }
    }

    void printBills(){
        for(map<int, map<int, int> >::iterator i = billLists.begin(); i != billLists.end(); i++){
           /*I cout << "Danh sach hang hoa cua khach co ID " << i->first << " la: " << endl;
            cout << left << setw(20) << "Product ID" << setw(10) << "Number" << endl;
            for(map<int, int>::iterator j = i->second.begin(); j != i->second.end(); j++){
                cout << left << setw(20) << j->first << setw(10) << j->second << endl;
            } */
            cout << i->second.size() << endl;
        }
    }

};

int main(){
    HoaDon bill;
    bill.enterBill();
    bill.printBills();
    return 0;
}
