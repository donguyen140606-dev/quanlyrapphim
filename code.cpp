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
 	cout<<"\n"<<hoTen ;
 	cout<<"\nGioi Tinh: " <<gioiTinh;
	cout<<"\nVi tri lam viec: " <<vitriWork;
	cout<<"\nID: " <<ID; 
	cout<<"\nCa lam: " <<caLam;
	cout<<"\nThoi gian lam viec: \n" <<timeChamCong; 
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
 		void deleteNV(int id) ;
 };
 
 
 list::list(){ // Ham khoi tao
 	head=tail=NULL;
 }
 void list::deleteNV(int id) {
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
				cout<<"\nDa xoa nhan vien thanh cong" ;
				flag=1; 
				break; 
			}
			else {
				j=i; 
			}				 					 			
		}
		if(flag==0)	cout<<"\nKhong tim thay ID " ;
	}
}
 		 
				 
			 
		 
	 
 
 void list::Show(){
 	cout<<"\nBang Quan Ly Nhan Vien: " ;
 	for(node *i=head;i!=NULL;i=i->next) {
       i->data.Xuat();	 
	   }
 	  
 }
 node* list::createNode(NhanVien v){
 	node *p= new node();
 	p->data=v;
 	p->next=NULL;
 	return p;
 	
 }
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
 	int n; 
 	cout<<"\nNhap so nhan vien: " ;
 	cin>>n;
	 for(int i=0;i<n;i++) {
	 	a.nhap() ;
	 	b.addNV(a) ;
	 }
 	
 
 	b.Show();
 	int c; 
 	cout<<"\nNhap ID can xoa: " ;
 	cin>>c; 
 	b.deleteNV(c);
	b.Show(); 
	 return 0; 
 } 
