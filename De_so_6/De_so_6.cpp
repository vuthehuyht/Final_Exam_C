#include<iostream>
#include<vector>
#include<fstream>
#include<iomanip>
#include<string.h>
using namespace std;

class Person{
protected:
    char fullName[30];
    char address[30];
    char phone[10];
};

class Student:public Person{
    friend class Mark;
private:
    static int studentIDConst;
    int studentID;
    char classes[30];
public:
    void createStudent(){
        int num;
        cout << "Nhap so luong SV: "; cin >> num;
        for(int i = 0; i < num; i++){
            cout << "Nhap thong tin cho SV thu " << i + 1 << endl;
            fflush(stdin);
            Student st;
            cout << "Nhap ho ten: "; cin.getline(st.fullName, 30);
            cout << "Nhap dia chi: "; cin.getline(st.address, 30);
            cout << "Nhap so DT: "; cin.getline(st.phone, 30);
            st.studentID = studentIDConst++;
            int choise;
            cout << "1. Toan hoc \n2. Toan tin Ung dung \n3. May tinh & Khoa hoc thong tin \nLop: ";
            cin >> choise;
            if(choise == 1)
                strcpy(st.classes, "Toan hoc");
            if(choise == 2)
                strcpy(st.classes, "Toan tin Ung dung");
            if(choise == 3)
                strcpy(st.classes, "May tinh & Khoa hoc thong tin");
            writeToFile(st);
        }
    }

    void writeToFile(Student s){
        ofstream ofs("SV.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(&s), sizeof(Student));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Student));
    }

    void displayAllStudents(){
        cout << "--------Thong tin cac sinh vien--------" << endl;
        cout << left << setw(15) << "Ma SV" << setw(15) << "Ho ten SV" << setw(15) << "Dia chi" << setw(15) << "So DT" << setw(15) << "Lop" << endl;
        ifstream ifs("SV.DAT");
        while(!ifs.eof()){
            Student stu;
            stu.readOneByOne(ifs);
            if(!ifs.eof())
            cout << left << setw(15) << stu.studentID << setw(15) << stu.fullName << setw(15) << stu.address << setw(15) << stu.phone << setw(15) << stu.classes << endl;
        }
        ifs.close();
    }
};

class Subject{
    friend class Mark;
private:
    static int subjectIDConst;
    int subjectID;
    int dvht;
    char subjectName[50];
    char subjectType[50];
public:
    void createSuject(){
        int num;
        cout << "Nhap so luong MH: "; cin >> num;
        for(int i = 0; i < num; i++){
            cout << "Nhap thong tin cho MH thu " << i + 1 << endl;
            Subject sb;
            fflush(stdin);
            cout << "Nhap ten MH: "; cin.getline(sb.subjectName, 50);
            cout << "Nhap so DVHT: "; cin >> sb.dvht;
            sb.subjectID = subjectIDConst++;
            int choise;
            cout << "1. Dai cuong \n2.Co so nganh \n3. Chuyen nganh \nLoai MH: "; cin >> choise;
            if(choise == 1)
                strcpy(sb.subjectType, "Dai cuong");
            if(choise == 2)
                strcpy(sb.subjectType, "Co so nganh");
            if(choise == 3)
                strcpy(sb.subjectType, "Chuyen nganh");
            writeToFile(sb);
        }
    }

    void writeToFile(Subject s){
        ofstream ofs("MONHOC.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(&s), sizeof(Subject));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Subject));
    }

    void displayAllSubject(){
        cout << "-------Thong tin cac mon hoc-------" << endl;
        cout << left << setw(15) << "Ma MH" << setw(15) << "Ten MH" << setw(15) << "SO DVHT" << setw(15) << "Loai MH" << endl;
        ifstream ifs("MONHOC.DAT");
        while(!ifs.eof()){
            Subject sb;
            sb.readOneByOne(ifs);
            if(!ifs.eof())
                cout << left << setw(15) << sb.subjectID << setw(15) << sb.subjectName << setw(15) << sb.dvht << setw(15) << sb.subjectType << endl;
        }
        ifs.close();
    }
};

class Mark{
private:
    Student st;
    int subjectTotal;
    int scores[100];
    Subject sb[100];
public:
    void creatMarkTable(Student _st){
        vector<Subject> sbs;
        ifstream ifs("MONHOC.DAT");
        while(!ifs.eof()){
            Subject s;
            s.readOneByOne(ifs);
            if(!ifs.eof())
            sbs.push_back(s);
        }
        ifs.close();
        Mark ms;
        fflush(stdin);
        ms.st = _st;
        cout << "Nhap diem cho SV " << _st.fullName << endl;
        cout << "Nhap tong so MH: "; cin >> ms.subjectTotal;
        for(int i = 0; i < ms.subjectTotal; i++){
            int subIDTemp, mark = 1;
            do{cout << "Nhap ma MH: "; cin >> subIDTemp;
                for(int j = 0; j < sbs.size(); j++){
                    if(subIDTemp == sbs[j].subjectID){
                        mark = 0;
                        ms.sb[i] = sbs[j];
                    }
                }
                for(int k = 0; k < i; k++)
                    if(subIDTemp == ms.sb[k].subjectID)
                        mark = 1;
            } while(mark);
            do {
            cout << "Nhap diem: "; cin >> ms.scores[i];
            } while(ms.scores[i] < 0 || ms.scores[i] > 10);
        }
        writeToFile(ms);
    }
    void writeToFile(Mark m){
        ofstream ofs("BANGDIEM.DAT",ios::app);
        ofs.write(reinterpret_cast<const char*>(&m), sizeof(Mark));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Mark));
    }

    void markTable(){
        cout << "------Bang diem-------" << endl;
        cout << "Ho ten SV: " << st.fullName << endl;
        cout << "Tong so MH: " << subjectTotal << endl;
        cout << "\nThong tin diem cac mon hoc" << endl;
        cout << left << setw(15) << "Ma MH" << setw(15) << "Ten MH" << setw(15) << "So DVHT" << setw(15) << "Diem" << endl;
        for(int i = 0; i < subjectTotal; i++){
            cout << left << setw(15) << sb[i].subjectID << setw(15) << sb[i].subjectName << setw(15) << sb[i].dvht << setw(15) << scores[i] << endl;
        }
    }

    void displayAllMarkTable(){
        ifstream ifs("BANGDIEM.DAT");
        while(!ifs.eof()){
            Mark m;
            m.readOneByOne(ifs);
            if(!ifs.eof())
                m.markTable();
        }
        ifs.close();
    }

    vector<Mark> getMark(){
        vector<Mark> marks;
        ifstream ifs("BANGDIEM.DAT");
        while(!ifs.eof()){
            Mark m;
            m.readOneByOne(ifs);
            if(!ifs.eof())
                marks.push_back(m);
        }
        ifs.close();
        return marks;
    }

    char* getName(){
        return st.fullName;
    }

    void sortByName(){
        vector<Mark> marks = getMark();
        for(int i = 0; i < marks.size() - 1; i++){
            for(int j= i + 1; j < marks.size();j++)
                if(strcmp(marks[i].getName(), marks[j].getName()) < 0)
                swap(marks[i], marks[j]);
        }
        cout << "Danh sach sau khi sap xep la:" << endl;
        for(int i = 0; i < marks.size(); i++)
            marks[i].markTable();
    }

    void thongke(){
        vector<Mark> marks = getMark();
        cout << left << setw(15) << "Ho ten" << setw(15) << "Diem TB" << endl;
        for(int i = 0; i < marks.size(); i++){
            int sum = 0, sumOfDVHT = 0;
            for(int j = 0; j < marks[i].subjectTotal; j++){
                sum += marks[i].scores[j] * marks[i].sb[j].dvht;
                sumOfDVHT += marks[i].sb[j].dvht;
            }
            cout << left << setw(15) << marks[i].st.fullName <<  setw(15) << sum / sumOfDVHT << endl;
        }
    }
};
int Student::studentIDConst = 10000;
int Subject::subjectIDConst = 100;
int main(){
//    ifstream ifs("SV.DAT");
//    vector<Student> sts;
//    while(!ifs.eof()){
//        Student st;
//        st.readOneByOne(ifs);
//        if(!ifs.eof())
//            sts.push_back(st);
//    }
//    Mark m[sts.size()];
//    for(int i = 0; i < sts.size(); i++)
//        m[i].creatMarkTable(sts[i]);
    Mark ma;
    ma.displayAllMarkTable();
    ma.thongke();
    return 0;
}
