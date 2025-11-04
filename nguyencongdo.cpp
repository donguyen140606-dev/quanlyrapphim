#include<iostream> 
#include<string> 
using namespace std;
 
 class NhanVien{
 	public:
 		string hoTen, gioiTinh, vitriWork;
 		string timeChamCong;
		 int caLam,ID;
		 void nhap();
		 void Xuat(); 
 		
 };
 void NhanVien::nhap(){
 	cin.ignore() ;
 	cout<<"\nNhap Ho Ten: " ;
 	getline(cin,hoTen) ;
 	cout<<"\nNhap gioi tinh: " ;
 	getline(cin,gioiTinh);
 	cout<<"\nVi Tri Lam Viec: " ;
	getline(cin,vitriWork) ;
	cout<<"\nSo ID: " ;
	cin>> ID; 	
	cout<<"\nCa lam viec: " ;
	cin>> caLam;	
	cout<<"\nThoi gian lam viec: " ;
	cin>> timeChamCong; 
 }
 void NhanVien::Xuat(){
 	cout<<"========================================"<<endl;
 	cout<<"\nHo Ten: "<<hoTen ;
 	cout<<"\nGioi Tinh: " <<gioiTinh;
	cout<<"\nVi tri lam viec: " <<vitriWork;
	cout<<"\nID: " <<ID; 
	cout<<"\nCa lam: " <<caLam;
	cout<<"\nThoi gian lam viec: " <<timeChamCong<<endl;
	cout<<"========================================"<<endl;
	 }
 
 typedef struct Node{
 	NhanVien data;
 	struct Node *next;
 }node;
 class list{
 	public:
 		node *head,*tail;
 		list();
 		node *createNode(NhanVien v);
 		void addNV(NhanVien v); // them nhan vien
 		void Show();
 		void deleteNV(int id) ; // xoa nhan vien
 		void editNV(int id);
 		
 }; 	
 
 // Sua thong tin nhan vien  
 void list::editNV(int id){
 	if(head==NULL)
 	  cout<<"Khong co nhan vien nao!"<<endl;
 	else{
 		int flag=0;
 		for(node *i=head;i!=NULL;i=i->next){
 			if(i->data.ID==id){
 				cout<<"Da tim thay nhan vien"<<endl;
 				cout<<"Thong tin nhan vien:"<<endl;
 				i->data.Xuat();
 				cout<<"----Nhap lai thong tin can sua----:"<<endl;
 				i->data.nhap();
 				flag=1;
 				break;
			 }
		  	}
	 if(flag==0){
	  cout<<"Khong co nhan vien nao hop le!"<<endl;
	  cout<<"Xin nhap lai ID: ";
	  int b;
	  cin>>b;
	  editNV(b);
}
 }
}
 
 
 list::list(){ // Ham khoi tao
 	head=tail=NULL;
 }
 void list::deleteNV(int id) {   // xoa nhan vien
 	if(head==NULL) 
 	  cout<<"\nKhong Co Nhan Vien Nao" ;
 	else if(head->data.ID==id) {
 		node *p=head;
		head=head->next; 
		delete p;
		cout<<"\nDa xoa nhan vien thanh cong" ;
	 }
	else {
		int flag=0; 
		node *j=head;
		node *i=head->next ;
		for(i=head->next;i!=NULL;i=i->next) {
			if(i->data.ID==id) {
				j->next = i->next;
				delete i;
				cout<<"\nDa xoa nhan vien thanh cong"<<endl ;
				flag=1; 
				break; 
			}
			else {
				j=i; 
			}				 					 			
		}
		if(flag==0)	{
	     cout<<"\nKhong tim thay ID "<<endl;
		 cout<<"Xin nhap lai ID: ";
		 int newid;
		 cin>>newid;
		 deleteNV(newid);			
	}
}
}
 // xuat danh sach		 
 void list::Show(){
 	cout<<"========= DANH SACH NHAN VIEN ========="<<endl; 
 	for(node *i=head;i!=NULL;i=i->next) {
       i->data.Xuat();	 
	   }
 	  
 }
 // tao node nhan vien 
 node* list::createNode(NhanVien v){
 	node *p= new node();
 	p->data=v;
 	p->next=NULL;
 	return p;
 	
 }
 // them nhan vien 
 void list::addNV(NhanVien v){
 	node *p=createNode(v);
 	if(p==NULL)
 	   cout<<"\nCap nhat p loi" ;
 	else if(head==NULL){
 		head=tail=p;
	 }
	else{
		tail->next=p;
		tail=p;
	}
 }
 
  
 int main(){
 	NhanVien a;
 	list b; 
 	int menu;
 	do{ 
 	  cout<<"=========== MENU QUAN LY NHAN VIEN ===========" << endl;
 	  cout<<"1.Them nhan vien"<<endl;
 	  cout<<"2.Hien thi danh sach sinh vien"<<endl;
 	  cout<<"3.Sua thong tin nhan vien"<<endl;
 	  cout<<"4.Xoa nhan vien"<<endl;
 	 
 	  cout<<"0.Thoat chuong trinh"<<endl;
 	  cout<<"-----------------------"<<endl;
 	  cout<<"Xin moi chon phuong thuc:";
 	  cin>>menu;
 	  
 	  switch(menu){
 	  	case 1:{
 	  		int n; 
 	        cout<<"\nNhap so nhan vien: " ;
 	        cin>>n;
	        for(int i=0;i<n;i++) {
	 	      a.nhap() ;
	 	      b.addNV(a) ;
	 }
			break;
		   }
		case 2:{
			b.Show();
			break;
		}
		case 3:{
			int d;
	        cout<<"\nNhap ID NV can sua thong tin:"<<endl;
	        cin>>d;
 	        b.editNV(d);
			break;
		}
		case 4:{
			int c; 
 	        cout<<"\nNhap ID can xoa: " ;
 	        cin>>c; 
 	        b.deleteNV(c);
			break;
		}
		case 0:{
			cout<<"Thoat chuong trinh"<<endl;
			break;
		}
		default:
			cout<<"Lua chon khong hop le. Vui long nhap lai"<<endl;
	   }
	 }while (menu !=0);
// 	int n; 
// 	cout<<"\nNhap so nhan vien: " ;
// 	cin>>n;
//	 for(int i=0;i<n;i++) {
//	 	a.nhap() ;
//	 	b.addNV(a) ;
//	 }
// 	
// 	b.Show();
// 	int c; 
// 	cout<<"\nNhap ID can xoa: " ;
// 	cin>>c; 
// 	b.deleteNV(c);
//	b.Show(); 
//	int d;
//	cout<<"\nNhap ID NV can sua thong tin:"<<endl;
//	cin>>d;
//	b.editNV(d);
//	b.Show();
//	  
 } 
