#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;

class Person{
protected:
    char fullName[30];
    char address[30];
    char phone[10];
};

class Reader:public Person{
    friend class QLMS;
private:
    static int readerIDConst;
    int readerID;
    char readerType[30];
public:
    void createReaders(){
        int num;
        cout << "Nhap so luong ban doc: "; cin >> num;
        for(int i = 0; i < num; i++){
            cout << "Nhap thong tin ban doc thu " << i + 1 << endl;
            Reader reader;
            fflush(stdin);
            cout << "Nhap ho ten: "; cin.getline(reader.fullName, 30);
            cout << "Nhap dia chi: "; cin.getline(reader.address, 30);
            cout << "Nhap so DT: "; cin.getline(reader.phone, 10);
            reader.readerID = readerIDConst++;
            int choise;
            cout << "1. Sinh vien \n2. Hoc vien cao hoc \n3. Giao vien \n Loai ban doc: ";
            cin >> choise;
            if(choise == 1)
                strcpy(reader.readerType, "Sinh vien");
            if(choise == 2)
                strcpy(reader.readerType, "Hoc vien cao hoc");
            if(choise == 1)
                strcpy(reader.readerType, "Giao vien");
            writeToFile(reader);
        }
    }

    void writeToFile(Reader r){
        ofstream ofs("SACH.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(&r), sizeof(Reader));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Reader));
    }

    void displayAllReaders(){
        cout << "--------Thong tin cac ban doc--------" << endl;
        cout << left << setw(15) << "Ma BD"  << setw(15) << "Ho ten" << setw(15) << "Dia chi" << setw(15) << "So DT" << setw(15) << "Loai BD" << endl;
        ifstream ifs("SACH.DAT");
        while(!ifs.eof()){
            Reader r;
            r.readOneByOne(ifs);
            if(!ifs.eof())
                cout << left << setw(15) << r.readerID << setw(15) << r.fullName << setw(15) << r.address << setw(15) << r.phone << setw(15) << r.readerType << endl;
        }
        ifs.close();
    }
};

class Book{
    friend class QLMS;
private:
    static int bookIDConst;
    int bookID;
    int publishingYear;
    char author[30];
    char bookType[50];
    char bookName[50];
public:
    void creareBooks(){
        int num;
        cout << "Nhap so luong sach: "; cin >> num;
        for(int i = 0;i < num; i++){
            cout << "Nhap thong tin sach thu " << i + 1 << endl;
            Book book;
            fflush(stdin);
            cout << "Nhap ten sach: "; cin.getline(book.bookName, 50);
            cout << "Nhap tac gia sach: "; cin.getline(book.author, 30);
            cout << "Nam xuat ban: "; cin >> book.publishingYear;
            book.bookID = bookIDConst++;
            int choise;
            cout << "1. Khoa hoc tu nhien \n2. Van hoc-Nghe thuat \n3. Dien tu vien thong \n4. Cong nghe thong tin \nLoai sach: ";
            cin >> choise;
            if(choise == 1)
                strcpy(book.bookType, "Khoa hoc tu nhien");
            if(choise == 2)
                strcpy(book.bookType, "Van hoc-Nghe thuat");
            if(choise == 3)
                strcpy(book.bookType, "Dien tu vien thong");
            if(choise == 4)
                strcpy(book.bookType, "Cong nghe thong tin");
            writeToFile(book);
        }
    }

    void writeToFile(Book b){
        ofstream ofs("BD.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(&b), sizeof(Book));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Book));
    }

    void displayAllBooks(){
        cout << "-------Thong tin sach-------" << endl;
        cout << left << setw(15) << "Ma sach" << setw(15) << "Ten sach" << setw(15) << "Tac gia" << setw(15) << "Nam xuat ban" << setw(15) << "Loai sach" << endl;
        ifstream ifs("BD.DAT");
        while(!ifs.eof()){
            Book b;
            b.readOneByOne(ifs);
            if(!ifs.eof())
                cout << left << setw(15) << b.bookID << setw(15) << b.bookName << setw(15) << b.author << setw(15) << b.publishingYear << setw(15) << b.bookType << endl;
        }
        ifs.close();
    }
};

class QLMS{
private:
    Reader r;
    int booksTotal;
    int numOfBook[5];
    Book books[5];
    char tinhtrang[5][10];
public:
    void createQLMS(Reader reader){
        vector<Book> bs;
        ifstream ifs("BD.DAT");
        while(!ifs.eof()){
            Book b;
            b.readOneByOne(ifs);
            if(!ifs.eof())
                bs.push_back(b);
        }
        ifs.close();
        cout << "Nhap thong tin muon sach cho " << reader.fullName << endl;
        r = reader;
        do{
            cout << "Nhap so dau sach muon: ";
            cin >> booksTotal;
        } while (booksTotal < 0 || booksTotal > 5);
        for(int i = 0;i < booksTotal; i++){
            int bookIDTemp, mark = 1;
            do {
                cout << "Nhap ma sach: "; cin >> bookIDTemp;
                for(int j = 0; j < bs.size(); j++){
                    if(bookIDTemp == bs[j].bookID){
                        mark = 0;
                        books[i] = bs[j];
                    }
                }
                for(int j = 0; j < i; j++)
                    if(books[j].bookID == bookIDTemp)
                        mark = 1;
            } while(mark);
            do{
                cout << "So luong: "; cin >> numOfBook[i];
            } while(numOfBook[i] < 0 || numOfBook[i] > 3);
            fflush(stdin);
            cout << "Tinh trang: "; cin.getline(tinhtrang[i], 10);
        }
        writeToFile();
    }
    void writeToFile(){
        ofstream ofs("QLMS.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(this), sizeof(QLMS));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(QLMS));
    }

    void QLMSInfor(){
        cout << "Ho ten: " << r.fullName << endl;
        cout << "Tong so dau sach muon: " << booksTotal << endl;
        cout << "Thong tin nhung sach muon" << endl;
        cout << left << setw(15) << "Ma sach" << setw(15) << "Ten sach" << setw(15) << "So luong" << setw(15) << "Tinh trang" << endl;
        for(int i = 0; i < booksTotal; i++){
            cout << left << setw(15) << books[i].bookID << setw(15) << books[i].bookName << setw(15) << numOfBook[i] << setw(15) << tinhtrang[i] << endl;
        }
     }

     void displayAllQLMS(){
         cout << "\n--------Quan ly muon sach-------\n";
         ifstream ifs("QLMS.DAT");
         while(!ifs.eof()){
            QLMS q;
            q.readOneByOne(ifs);
            q.QLMSInfor();
         }
         ifs.close();
     }

     vector<QLMS> getList(){
         vector<QLMS> t;
         ifstream ifs("QLMS.DAT");
         while(!ifs.eof()){
            QLMS q;
            q.readOneByOne(ifs);
            t.push_back(q);
         }
         ifs.close();
         return t;
     }
     char* getName(){
         return r.fullName;
     }
     int getSum(){
         int sum = 0;
         for(int i = 0; i < booksTotal; i++)
            sum += numOfBook[i];
         return sum;
     }
     void sortByName(){
         vector<QLMS> qs = getList();
         for(int i = 0; i < qs.size() - 1; i++){
            for(int j = i + 1; j < qs.size(); j++)
                if(strcmp(qs[i].getName(), qs[j].getName()) < 0)
                    swap(qs[i], qs[j]);
         }
         cout << "Danh sach sau khi sap xep la: " << endl;
         for(int i = 0; i < qs.size(); i++)
            qs[i].QLMSInfor();
     }

     void sortBySum(){
         vector<QLMS> qs = getList();
         for(int i = 0; i < qs.size() - 1; i++){
            for(int j = i + 1; j < qs.size(); j++)
                if(qs[i].getSum() < qs[j].getSum())
                    swap(qs[i], qs[j]);
         }
         cout << "Danh sach sau khi sap xep la: " << endl;
         for(int i = 0; i < qs.size(); i++)
            qs[i].QLMSInfor();
     }

    void timkiem(char* name){
        vector<QLMS> qs = getList();
        int mark = 1;
        for(int i = 0; i < qs.size(); i++){
            if(strcmp(qs[i].getName(), name) == 0){
                mark = 0;
                cout << "Thong tin tim kiem" << endl;
                qs[i].QLMSInfor();
            }
        }
        if (mark == 1)
            cout << "Khong tim thay ket qua" << endl;
    }
};
int Reader::readerIDConst = 10000;
int Book::bookIDConst = 100;
int main(){
//    vector<Reader> rs;
//    ifstream ifs("SACH.DAT");
//    while(!ifs.eof()){
//        Reader r;
//        r.readOneByOne(ifs);
//        if(!ifs.eof())
//            rs.push_back(r);
//    }
//    ifs.close();
//    QLMS qlms[rs.size()];
//    for(int i = 0; i < rs.size(); i++)
//        qlms[i].createQLMS(rs[i]);
    QLMS q;
    //q.displayAllQLMS();
    char name[30];
    cout << "Nhap ten can tim:"; cin.getline(name, 30);
    q.timkiem(name);
    return 0;
}
