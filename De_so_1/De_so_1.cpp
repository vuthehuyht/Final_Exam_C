#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<vector>
using namespace std;

class Nguoi{
	protected:
		string ten, diachi, sodt;
	public:
		Nguoi(){
			ten = diachi = sodt = "";
		}

		friend istream &operator>>( istream &in, Nguoi &n ){
			cout<<"\nTen: " ; getline(cin, n.ten); in>>n.ten;
			cout<<"\nDia chi: " ; getline(cin, n.diachi); in>>n.diachi;
			cout<<"\nSo Dt: "; getline(cin, n.sodt) in>>n.sodt;
		}
		friend ostream &operator<<( ostream &out, Nguoi &n ){
			out<<left<<setw(15)<<n.ten<<setw(15) <<n.diachi <<setw(15)<<n.sodt;
		}

};
class KH: public Nguoi{
	friend class BDS;
	protected:
		int maKH;
		static int makh;
		int loaikh;
	public:
		KH(){
			loaikh = maKH = 0;
		}

		friend istream &operator>>( istream &in, KH &k ){
			k.maKH =makh++;
			Nguoi *n = reinterpret_cast<Nguoi*>(&k);
			in>> *n;
			do{
				cout<<"\nLoai KH: \n1: mua le, \n2: mua Buon. "; in>>k.loaikh;
			} while( k.loaikh < 1 || k.loaikh > 2 );
			cout<<endl;
		}
		friend ostream &operator<<( ostream &out, KH &k ){
				out<<setw(10)<< k.maKH;
				Nguoi *n = reinterpret_cast<Nguoi*>(&k);
				out<<*n;
				if(k.loaikh == 1) out<<"Mua Le";
				if(k.loaikh == 2) out<<"Mua Buon";
				out<<endl;
		}
		void docN( fstream &ifs ){
			ifs.read(reinterpret_cast<char*>(this), sizeof(KH));
		}
		void ghiK(){
			ofstream ofs("KH.DAT",ios::app);
			ofs.write(reinterpret_cast<const char*>(this), sizeof(KH)); ofs.close();
		}
};

class MH{
	friend class BDS;
	protected:
		int maMH, nhom;
		static int mamh;
		string tenmh;
		float giaban;
	public:
		MH(){
			nhom = maMH = 0; tenmh = ""; giaban = 0.0;
		}
		friend istream &operator>>(istream &in, MH &m ){
			m.maMH = mamh++;
			cout<<"Ten MH: "; in>>m.tenmh;
			do{
				cout<<"\nNhom MH: \n1: TT. \n2: TD. \n3: DM. \n4: GD. "; in>>m.nhom;
			} while( m.nhom < 1 || m.nhom > 4);
			cout<<"\nGia ban: "; in>>m.giaban;
		}
		friend ostream &operator<<(ostream &out, MH &m ){
			out<<left<<setw(10)<<m.maMH <<setw(15)<<m.tenmh<<setw(12);
			if( m.nhom == 1 ) out<<"TT.";
			if( m.nhom == 2 ) out<<"TD.";
			if( m.nhom == 3 ) out<<"DM.";
			if( m.nhom == 4 ) out<<"GD.";
			out<<m.giaban<<setw(10);
		}
		void ghiMH(){
			ofstream ofs("MH.DAT",ios::app);
			ofs.write(reinterpret_cast<const char*>(this), sizeof(MH));
		}
		void docMH( fstream &ifs ){
			ifs.read(reinterpret_cast <char*>(this), sizeof(MH));
		}
};
int MH::mamh = 1000;
int KH::makh = 10000;

class BDS{
	protected:
		KH k;
		vector<MH> mh;
		int sl;
		vector<int> sluong;
	public:
		BDS(){
			sl = 0;
		}
		void nhapB( KH k1, MH m[], int n ){
			k = k1;
			cout<<"\nNhap thong tin cho KH "<< k.ten<<" : ";
			do{
				cout<<"\nSo luong MH mua( sl < 10 ): "; cin>>sl;
			} while( sl > 10 );
			for( int i = 0; i < sl; i++ ){
				int ma, ok, kt, s;
				do{
					ok = kt = 0;
					cout<<"\nNhap ma MH: "; cin>> ma;
					if( ma < 1000 || (ma > m[n-1].maMH) ) ok = 1;
					for(int j = 0; j< n; j++ )
						if( ma == m[j].maMH ) mh.push_back( m[j] );
					for(int j = 0; j< i; j++ )
						if( ma == mh[j].maMH ) kt = 1;
				} while( ok || kt );
				cout<<"\nNhap so luong hang mua : "; cin>> s;
				if( s >= 0 ) sluong.push_back( s );
			}
		}
		void xuatB(){
			cout<<left<<setw(10)<<"Ma KH"<<setw(15)<<"Ten KH"<<setw(15)<<"Dia Chi" <<setw(15)
				<<"So DT"<<setw(12)<<"Loai KH"<<endl;
			cout<< k;
			cout<< "\nTong so loai MH mua: " << sl << endl;
			cout<< left << setw(10) <<"Ma MH" << setw(15) << "Ten MH" << setw(12) << "Nhom MH"
				<< setw(10) << "Gia Ban" << setw(10) << "SLuong" << endl;
			for(int i = 0; i< sl; i++ ){
				cout<< mh[i];
				cout<< right << sluong[i] << endl;
			}
			cout<<endl;
		}
		void docB( fstream &ifs ){
			ifs.read(reinterpret_cast<char*>(this),sizeof(BDS));
		}
		void ghiB(){
			ofstream ofs("QLBH.DAT",ios::app);
			ofs.write(reinterpret_cast<const char*>(this),sizeof(BDS));
			ofs.close();
		}
		void sapxep( BDS b[], int n ){
			int lc;
			do{
				cout<<"\n_____Options Sort_____\n";
				cout<<"\n1: Sort by Client Name. \n2: Sort by Product Name. \n0: return main MENU."
					<<"\nEnter your choice ? "; cin>>lc;
				switch( lc ){
					case 1:{
						for( int i = 0; i < n; i++ )
							for( int j = i+1; j < n; j++ )
								if( b[i].k.ten > b[j].k.ten ) swap( b[i], b[j] );
							cout<<"\n___Infomation After Sort___\n";
							for( int i = 0; i < n; i++ )
								b[i].xuatB();
						break;
					}
					case 2:{
						for( int i = 0; i < n; i++ )
							for(int j = 0; j < b[i].sl; j++ )
								for(int k = j+1; k < b[i].sl; k++ )
									if( b[i].mh[j].tenmh > b[i].mh[k].tenmh  )
										swap( b[i].mh[j], b[i].mh[k]  );
							cout<<"\n___Infomation After Sort___\n";
							for(int i = 0; i< n; i++ )
								b[i].xuatB();
						break;
					}
					case 0: break;
				}
			}while ( lc != 0 );
		}
		void hoaDon( BDS b[], int n ){
			cout<<"\n______Recipt Table______\n";
			cout<<left<<setw(10)<<"Ma KH" <<setw(15) <<"Ten KH" <<setw(10) <<"SLM"<< setw(12)
				<<"Tong HD" <<endl;
			for( int i = 0; i< n; i++ ){
				float phi = 0;
				for(int j = 0; j < b[i].sl; j++ )
					phi+= b[i].sluong[j] * b[i].mh[j].giaban;
				cout<<left<<setw(10)<< b[i].k.maKH <<setw(15)<<b[i].k.ten<< setw(10)<< b[i].sl
					<<setw(12)<<phi<<endl;
			}
		}
};

void menu(){
	fstream f("MH.DAT",ios::out); fstream f1("KH.DAT",ios::out); fstream f2("QLBH.DAT",ios::out);
	int somh = 0, sokh = 0, sobds = 0, lc = 0, slkh = 0, slmh = 0, slbds = 0;
	KH kh1[100], kh2[100]; MH mh1[100], mh2[100]; BDS bds1[100], bds2[100], dss;
	do{
		cout<<"\n_____Menu Options____\n1: y 1. \n2: y 2. \n3: y 3. \n4: y 4. \n5; y 5. \n0: Exit."
			<<"\nEnter your choice ? "; cin>> lc;
		switch( lc ){
			case 1:{
				int n; cout<<"\n So luong KH muon them: "; cin>>n;
				for( int i = sokh; i < sokh + n; i++ ){
					cout<<"\nThong tin KH thu "<<i+1 <<" : ";
					cin>>kh1[i]; kh1[i].ghiK();
				} sokh+= n;
				cout<<"\n___THONG TIN CO TRONG FILE___\n";
				cout<<left<<setw(10)<<"Ma KH"<<setw(15)<<"Ten KH"<<setw(15)<<"Dia Chi" <<setw(15)
				<<"So DT"<<setw(12)<<"Loai KH"<<endl;
				fstream ifs("KH.DAT",ios::in);
				if(!ifs) { cout<<"\nFile could not be opened!";  }
				while( ifs ){
					kh2[slkh].docN(ifs);
					if(!ifs.eof()) cout<< kh2[slkh]; slkh++;
				} ifs.close(); slkh--;
				break;
			}
			case 2:{
				int n; cout<<"\n So luong MH muon them: "; cin>>n;
				for( int i = somh; i < somh + n; i++ ){
					cout<<"\nThong tin MH thu "<<i+1 <<" : ";
					cin>> mh1[i]; mh1[i].ghiMH();
				} somh+= n;
				cout<<"\n___THONG TIN CO TRONG FILE___\n";
				cout<<left<<setw(10)<<"Ma MH" <<setw(15)<<"Ten MH" <<setw(12) <<"Nhom MH"
				<<setw(10)<<"Gia Ban" <<endl;
				fstream ifs("MH.DAT",ios::in);
				if(!ifs) { cout<<"\nFile could not be opened!";  }
				while( ifs ){
					mh2[slmh].docMH(ifs);
					if(!ifs.eof()) cout<< mh2[slmh];cout<<endl; slmh++;
				} ifs.close(); slmh--;
				break;
			}
			case 3:{
				for( int i = sobds; i < sokh; i++ ){
					bds1[i].nhapB( kh2[i], mh2, slmh ); bds1[i].ghiB();
				} sobds = sokh;
				cout<<"\n___THONG TIN CO TRONG FILE___\n";
				fstream ifs("QLBH.DAT",ios::in);
				if(!ifs) { cout<<"\nFile could not be opened!";  }
				while( ifs ){
					bds2[slbds].docB(ifs);
					if(!ifs.eof()) bds2[slbds].xuatB(); cout<<endl; slbds++;
				} ifs.close(); slbds--;
				break;
			}
			case 4:  dss.sapxep( bds2, slbds ); break;
			case 5:  dss.hoaDon( bds2, slbds ); break;
			case 0: cout<<"\nThe End.";
		}
	} while( lc != 0 );
}

int main(){
	menu();
	return 0;
}
