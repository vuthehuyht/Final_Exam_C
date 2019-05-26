#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<string.h>
#include<ctime>
using namespace std;

class Person{
protected:
    char fullName[30];
    char address[30];
    char phone[10];
};

class Student:public Person{
    friend class RegisterTable;
private:
    static int studentIDConst;
    int studentID;
    char classes[30];
public:
    void createStudents(){
        int num;
        cout << "Nhap so luong SV: "; cin >> num;
        for(int i = 0; i < num; i++){
            cout << "Nhap thong tin cho SV thu " << i + 1 << endl;
            Student st;
            fflush(stdin);
            cout << "Nhap ho ten: "; cin.getline(st.fullName, 30);
            cout << "Nhap dia chi: "; cin.getline(st.address, 30);
            cout << "Nhap SDT: "; cin.getline(st.phone, 10);
            st.studentID = studentIDConst++;
            cout << "Nhap lop: "; cin.getline(st.classes, 30);
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
        cout << "----------Thong tin cac SV----------" << endl;
        cout << left << setw(15) << "Ma SV" << setw(15) << "Ho ten" << setw(15) << "Dia chi" << setw(15) << "SDT" << setw(15) << "Lop" << endl;
        ifstream ifs("SV.DAT");
        while(!ifs.eof()){
            Student s;
            s.readOneByOne(ifs);
            if(!ifs.eof())
            cout << left << setw(15) << s.studentID << setw(15) << s.fullName << setw(15) << s.address << setw(15) << s.phone << setw(15) << s.classes << endl;
        }
        ifs.close();
    }
};

class Subject{
    friend class RegisterTable;
private:
    static int subjectIDConst;
    int subjectID;
    int lessions;
    char subjectName[30];
    char subjectType[30];
public:
    void createSubjects(){
        int num;
        cout << "Nhap so luong mon: "; cin >> num;
        for(int i = 0; i < num; i++){
            cout << "Nhap thong tin mon thu " << i + 1 << endl;
            Subject sb;
            fflush(stdin);
            cout << "Nhap ten mon: "; cin.getline(sb.subjectName, 30);
            cout << "So tiet hoc: "; cin >> sb.lessions;
            sb.subjectID = subjectIDConst++;
            cout << "1. Dai cuong \n2. Co so nganh \n3. Chuyen nganh ban buoc \n4. Chuyen nganh tu chon \nLoai mon: ";
            int choise; cin >> choise;
            if(choise == 1)
                strcpy(sb.subjectType, "Dai cuong");
            if(choise == 2)
                strcpy(sb.subjectType, "Co so nganh");
            if(choise == 3)
                strcpy(sb.subjectType, "Chuyen nganh ban buoc");
            if(choise == 4)
                strcpy(sb.subjectType, "Chuyen nganh tu chon");
            writeToFile(sb);
        }
    }

    void writeToFile(Subject s){
        ofstream ofs("MH.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(&s), sizeof(Subject));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(Subject));
    }

    void displayAllSubject(){
        cout << "--------Thong tin cac mon hoc--------" << endl;
        cout << left << setw(15) << "Ma MH" << setw(25) << "Ten MH" << setw(15) << "So tiet hoc" << setw(15) << "Loai MH" << endl;
        ifstream ifs("MH.DAT");
        while(!ifs.eof()){
            Subject sb;
            sb.readOneByOne(ifs);
            if(!ifs.eof())
            cout << left << setw(15) << sb.subjectID << setw(25) << sb.subjectName << setw(150) << sb.lessions << setw(15) << sb.subjectType << endl;
        }
        ifs.close();
    }
};

class RegisterTable{
private:
    Student student;
    int sujectTotal;
    int numOfRegister[8];
    Subject subjects[8];
    string registerTime[8];
public:
    void createTable(Student st){
        vector<Subject> sus;
        ifstream ifs("MH.DAT");
        while(!ifs.eof()){
            Subject s;
            s.readOneByOne(ifs);
            if(!ifs.eof())
                sus.push_back(s);
        }
        student = st;
        cout << "Nhap thong tin dang ky cho " << st.fullName << endl;
        do{
            cout << "Nhap so mon dang ky: "; cin >> sujectTotal;
        } while(sujectTotal < 0 || sujectTotal > 8);
        for(int i = 0; i < sujectTotal; i++){
            int subID, mark = 1;
            do {
                cout << "Nhap ma mon: "; cin >> subID;
                for(int j = 0; j < sus.size(); j++){
                    if(subID == sus[j].subjectID){
                        mark = 0;
                        subjects[i] = sus[j];
                    }
                }
                for(int j = 0; j < i; j++)
                    if(subjects[j].subjectID == subID)
                        mark = 1;
            } while(mark);
            registerTime[i] = getTime();
        }
        writeToFile();
    }
    string getTime(){
        time_t t;
        t = time(0);
        struct tm* time_info = localtime(&t);
        char buffer[30];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time_info);
        return string(buffer);
    }

    void writeToFile(){
        ofstream ofs("QLDK.DAT", ios::app);
        ofs.write(reinterpret_cast<const char*>(this), sizeof(RegisterTable));
        ofs.close();
    }

    void readOneByOne(ifstream &ifs){
        ifs.read(reinterpret_cast<char*>(this), sizeof(RegisterTable));
    }

    void detailTable(){
        cout << "Ho ten SV: " << student.fullName << endl;
        cout << "Tong so mon dang ky: " << sujectTotal << endl;
        cout << "Bang dang ky chi tiet" << endl;
        cout << left << setw(15) << "Ma MH" << setw(20) << "Ten MH" << setw(15) << "So tiet" << setw(15) << "Thoi gian DK" << endl;
        for(int i = 0; i < sujectTotal; i++){
            cout << left << setw(15) << subjects[i].subjectID << setw(20) << subjects[i].subjectName << setw(15) << subjects[i].lessions << setw(15) << registerTime[i] << endl;
        }
    }
    void displayAllTable(){
        ifstream ifs("QLDK.DAT");
        while(!ifs.eof()){
            RegisterTable rt;
            rt.readOneByOne(ifs);
            if(!ifs.eof())
                rt.detailTable();
        }
        ifs.close();
    }

};
int Student::studentIDConst = 10000;
int Subject::subjectIDConst = 100;
int main(){
    vector<Student> sts;
    ifstream ifs("SV.DAT");
    while(!ifs.eof()){
        Student s;
        s.readOneByOne(ifs);
        if(!ifs.eof())
            sts.push_back(s);
    }
    ifs.close();
    RegisterTable r[sts.size()];
    for(int i = 0; i < sts.size(); i++)
        r[i].createTable(sts[i]);
    RegisterTable rt;
    rt.displayAllTable();
    return 0;
}
