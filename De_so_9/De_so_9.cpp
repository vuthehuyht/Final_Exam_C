#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>
#include<sstream>
#include<map>
#include <cstdlib>
#include<string>
using namespace std;
class Person{
    protected:
    string fullName;
    string address;
    string phone;
};

class Customer:public Person{
    friend class Bill;
private:
    static int customerIDConst;
    int customerID;
    string customerType;
public:
    void addCustomer(){
        fflush(stdin);
        cout << "Them khach hang moi" << endl;
        Customer customer;
        cout << "Nhap ho ten: "; getline(cin, customer.fullName);
        cout << "Nhap dia chi: "; getline(cin, customer.address);
        cout << "Nhap SDT: "; getline(cin, customer.phone);
        customer.customerID = customerIDConst++;
        cout << "1. Mua le \n2. Mua buon \nLoai KH: ";
        int choise; cin >> choise;
        if(choise == 1)
            customer.customerType = "Mua le";
        if(choise == 2)
            customer.customerType = "Mua buon";
        //writeToFile(customer);
    }

    void writeToFile(Customer c){
        ofstream ofs("KH.DAT", ios::app);
        if(ofs.is_open()){
            ofs << c.fullName << endl;
            ofs << c.address << endl;
            ofs << c.phone << endl;
            ofs << c.customerID << endl;
            ofs << c.customerType << endl;
            ofs.close();
        }else
            cout << "Unable to open file" << endl;
    }

    void displayAllCustomer(){
        cout << left << setw(15) << "Ma KH" << setw(15) << "Ho ten" << setw(15) << "Dia chi" << setw(15) << "SDT" << setw(15) << "Loai KH" << endl;
        vector<Customer> cus = getCus();
        for(int i = 0; i < cus.size(); i++)
            cus[i].toString();
    }

    vector<Customer> getCus(){
        vector<Customer> cus;
        ifstream ifs("KH.DAT");
        string line;
        if(ifs.is_open()){
            while(!ifs.eof()){
                Customer customer;
                getline(ifs, line);
                customer.fullName = line;
                getline(ifs, line);
                customer.address = line;
                getline(ifs, line);
                customer.phone = line;
                getline(ifs, line);
                stringstream ss(line);
                ss >> customer.customerID;
                getline(ifs, line);
                customer.customerType = line;
                if(!ifs.eof())
                cus.push_back(customer);
            }
            ifs.close();
        }
        return cus;
    }

    void toString(){
        cout << left << setw(15) << this->customerID << setw(15) << this->customerID << setw(15) << this->address << setw(15) << this->phone
         << setw(15) << this->customerType << endl;
    }
};

class Item{
    friend class Bill;
private:
    static int itemIDConst;
    int itemID;
    int price;
    string itemName;
    string itemType;
public:
    void addItem(){
        cout << "Them mat hang moi" << endl;
        fflush(stdin);
        Item newItem;
        cout << "Nhap ten: "; getline(cin, newItem.itemName);
        cout << "1.Hang thoi trang \n2.Hang tieu dung \n3.Hang dien may \n4.Hang gia dung \nloai MH: "; int choise; cin >> choise;
        if(choise == 1)
            newItem.itemType = "Hang thoi trang";
        if(choise == 2)
            newItem.itemType = "Hang tieu dung";
        if(choise == 3)
            newItem.itemType = "Hang dien may";
        if(choise == 4)
            newItem.itemType = "Hang gia dung";
        cout << "Nhap gia MH: ";  cin >> newItem.price;
        newItem.itemID = itemIDConst++;
        writeToFile(newItem);
    }

    void writeToFile(Item item){
        ofstream ofs("MH.DAT", ios::app);
        if(ofs.is_open()){
            ofs << item.itemID << endl;
            ofs << item.itemName << endl;
            ofs << item.itemType << endl;
            ofs << item.price << endl;
            ofs.close();
        } else
            cout << "Unable to open file" << endl;
    }

    vector<Item> getItems(){
        vector<Item> items;
        ifstream ifs("MH.DAT");
        string data;
        if(ifs.is_open()){
            while(!ifs.eof()){
                Item i;
                getline(ifs, data);
                stringstream ss(data);
                ss >> i.itemID;
                getline(ifs, data);
                i.itemName = data;
                getline(ifs, data);
                i.itemType = data;
                getline(ifs, data);
                stringstream s(data);
                s >> i.price;
                if(!ifs.eof())
                    items.push_back(i);
            }
            ifs.close();
        }
        return items;
    }

    void toString(){
        cout << left << setw(15) << this->itemID << setw(20) << this->itemName << setw(20) << this->itemType << setw(15) << this->price << endl;
    }

    void displayAllItems(){
        cout << left << setw(15) << "Ma MH" << setw(20) << "Ten MH" << setw(20) << "Loai MH" << setw(15) << "Gia" << endl;
        vector<Item> items = getItems();
        for(int i = 0; i < items.size(); i++){
            items[i].toString();
        }
    }
};
class Bill{
private:
    Customer customer;
    Item item;
    map<int, int> lists;
public:
    void createBill(Customer c){
        customer = c;
        Item it;
        vector<Item> its = it.getItems();
        cout << "Nhap hoa don cho KH " << c.fullName << endl;
        char cont = 'y';
        while(cont == 'y'){
            int itemID, mark = 1;
            do{
                cout << "Nhap ma hang: "; cin >> itemID;
                for(int i = 0; i < its.size(); i++){
                    if(itemID == its[i].itemID)
                        mark = 0;
                }
                for(map<int, int>::iterator i = lists.begin(); i != lists.end(); i++){
                    if(i->first == itemID)
                        mark = 1;
                }
            } while(mark);
            cout << "So luong"; int num; cin >> num;
            lists.insert(make_pair(itemID, num));
            cout << "Continue?(y/n)"; cin >> cont;
        }
        writeToFile();
    }

    void writeToFile(){
        ofstream ofs("QLBH.DAT", ios::app);
        ofs << customer.customerID << endl;
        ofs << lists.size() << endl;
        for(map<int, int>::iterator i = lists.begin(); i != lists.end(); i++)
            ofs << i->first << " " << i->second << endl;
        ofs.close();
    }

    void readFile(map<Customer, vector<pair<Item, int> > > &l){
        vector<Customer> cus = customer.getCus();
        ifstream ifs("QLBH.DAT");
        string line;
        while(!ifs.eof()){
            getline(ifs, line);
            for(vector<Customer>::size_type i = 0; i < cus.size(); i++){
                Customer c = cus[i];
                if (atoi(line) == c.customerID){
                    vector<pair<Item, int> > items;
                    getline(ifs, line);
                    for(int j = 0; j < atoi(line); j++){
                        getline(ifs, line);
                        Item itemTemp;
                        int numTemp;
                        splitString(line, ' ', itemTemp, numTemp);
                        items.push_back(make_pair(itemTemp, numTemp));
                    }
                    l.insert(make_pair(c, items));
                }
            }
        }
        ifs.close();
    }

    void splitString(const string &str, const char ch, Item &i, int &num){
        vector<Item> its = item.getItems();
        vector<string> v_str;
        string sub;
        string::size_type pos = 0;
        string::size_type old_pos = 0;
        bool flag = true;

        while(flag){
            pos = str.find_first_of(ch,pos);
            if(pos == string::npos)
            {
                flag = false;
                pos = str.size();
            }
            sub = str.substr(old_pos,pos - old_pos);
            v_str.push_back(sub);
            old_pos = ++pos;
        }
        for(vector<string>::iterator iter = v_str.begin(); iter != v_str.end(); iter++){
            if(iter == v_str.begin()){
                for(vector<Item>::size_type i = 0; i < its.size(); i++){
                    if(atoi(iter->data()) == its[i].itemID)
                        i = its[i];
                }
            } else {
                stringstream ss(iter->data());
                ss >> num;
            }
        }
    }

};

int Customer::customerIDConst = 10000;
int Item::itemIDConst = 1000;
int main(){
    Customer c;
    vector<Customer> cus = c.getCus();
    for(int i = 0; i < cus.size(); i++){
        Bill b;
        b.createBill(cus[i]);
    }
    Bill bill;
    map<Customer, vector<pair<Item, int> > > ds;
    bill.readFile(ds);
    cout << ds.size() << endl;
    return 0;
}
