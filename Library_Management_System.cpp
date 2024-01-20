/* Library Management System */
/* BY VANSHIT AGGARWAL*/
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

fstream myfile;
string s[100];
struct books{
	string name,author,type;
	books*link;
	books(){
		link=NULL;
	}
};

class records{
	books *start,*cur,*temp;
	public:
		records(){
			start=NULL;
		}
		void create_file(string n,string a, string t){
			if(start==NULL){
				start=new books;
				start->link=NULL;
				start->name=n;
				start->author=a;
				start->type=t;
				myfile.open("books library.txt",ios::out | ios::app);
				
				myfile<<"Name_:_"<<start->name<<"__|__Author:_"<<start->author<<"__|__Type_:_"<<start->type<<endl;
				myfile.close();
			}
			else{
				cur=start;
				while(cur->link!=NULL){
					cur=cur->link;
				}
				temp= new books;
				temp->name=n;
				temp->author=a;
				temp->type=t;
				temp->link=NULL;
				cur->link=temp;
				
				myfile.open("books library.txt",ios::out | ios::app);
				myfile<<"Name_:_"<<temp->name<<"__|__Author:_"<<temp->author<<"__|__Type_:_"<<temp->type<<endl;
				myfile.close();
			}
		}
		void print_now(){
			cur=start;
			int c;
			cout<<"Book #"<<"--->Name\tAuthor\tType"<<endl;
			for(c=1;cur->link!=NULL;c++){
				cout<<"  "<<c<<" ---> "<<cur->name<<"\t"<<cur->author<<"\t"<<cur->type<<endl;
				cur=cur->link;
			}
			cout<<"  "<<c<<" ---> "<<cur->name<<"\t"<<cur->author<<"\t"<<cur->type<<endl;
		}
		void search(string n){
			int i,k=0;
			string ss;
			myfile.open("books library.txt",ios::in);
			while(!myfile.eof()){
				myfile>>s[k];
				k++;
			}
			k--;
			myfile.close();
			for(i=0;i<k;i++){
				if(s[i].find(n)>0 && s[i].find(n)<s[i].length()){
					break;
				}
			}
			if(i!=k){
				char mod;
				cout<<"\n Want to modify Book data ..?? (y/n) ";
				cin>>mod;
				if(mod=='y' || mod=='Y'){
					string n,an,tp;
					cout<<"Enter Book Name : ";
					cin>>n;
					cout<<"Enter Author Name : ";
					cin>>an;
					cout<<"Enter book type : ";
					cin>>tp;
					
					s[i]="Name_:_"+n+"__|__Author:_"+an+"__Type_:_"+tp;
					myfile.open("books library.txt",ios::out);
					for(int j=0;j<k;j++){
						myfile<<s[j]<<endl;
						myfile.close();
					}
				}
			}
				else{
					cout<<"\n Record Not Found "<<endl;
				}
			}
			void printer(){
				myfile.open("books library.txt",ios::in);
				int i=0;
				while(!(myfile.eof())){
					myfile>>s[i];
					cout<<s[i]<<endl;
					i++;
				}
			myfile.close();
		}
};

int main(){
	records l1;
	int nooffiles,i,p,ch,k,j;
	string n,an,t;
	cout<<"\n\t=====================================================================\n\n";
	cout<<"\t\t\t BOOKS LIBRARY\n";
	cout<<"\n\t=====================================================================\n\n";
	cout<<"\n\t=====================================================================\n\n";
	cout<<"\n\t 1- CAN ENTER NEW BOOK\n";
	cout<<"\n\t 2-CAN SEARCH AND UPDATE THE BOOKS DATA\n";
	cout<<"\n\t 3- WHEN A BOOK IS BROUGHT, YOU CAN DELETEIT FROM YOUR LIBRARY\n ";
	cout<<"\n\t 4- CAN SEE ALL THE  LIST ANY TIME \n ";
	cout<<"\n\t 5- YOU CAN SEARCH ANY BOOK ONLINE \n ";
	
	cout<<"\n\t=====================================================================\n\n";
	cout<<"\n\t========================= SAVE BOOKS ================================\n"<<endl;
	
	cout<<"How many book's data you want to save "<<endl;
	cin>>nooffiles;
	
	for(int i=0;i<nooffiles;i++){
		cout<<"\n\t Enter Name \t";
		cin>>n;
		cout<<"\n\t Enter Author Name \t";
		cin>>an;
		cout<<"\n\t Enter TYPE(bio,cs,maths,novels,poetry,history,etc) \t";
		cin>>t;
		l1.create_file(n,an,t);
	}
	system("CLS");
	do{
		cout<<"\n\n What you want to do with your books now"<<endl;
		cout<<"\n 1-Save new book\n";
		cout<<"2-Delelte any book"<<endl;
		cout<<"3-Search and Modify"<<endl;
		cout<<"4-Read all list"<<endl;
		cout<<"5-Read online books "<<endl;
		cout<<"6-Exit\n"<<endl;
		cin>>ch;
		system("CLS");
		switch(ch){
			case 1:
				cout<<"\n\t=============== ADD NEW BOOK ===================\n\n";
				cout<<"Enter book data to insert in your library"<<endl;
				
				cout<<"\n Enter Name \t";
				cin>>n;
				cout<<"\n Enter Author name \t";
				cin>>an;
				cout<<"Enter type \t";
				cin>>t;
				l1.create_file(n,an,t);
				cout<<"Book "<<n<<" has been saved in your library"<<endl;
				break;
				
			case 2:
			cout<<"\n\t==================== DELETE BOOK=====================\n\n";
			myfile.open("books library.txt",ios::in);
			k=0;
			int del;
			while(myfile.good()){
				myfile>>s[k];
				cout<<k+1<<"-"<<s[k]<<endl;
				k++;
			}	
			myfile.close();
			cout<<"Which book data you want to delete ..?";
			cin>>del;
			s[del-1]="";
			
			cout<<"\n Book record has been deleted "<<endl;
			myfile.open("books library.txt",ios::out);
			for(j=0;j<k;j++)
			myfile<<s[j]<<endl;
			myfile<<endl;
			myfile.close();
			break;
			
			case 3: 
			cout<<"\n\t=========================SEARCH AND UPDATE BOOK DATA ================\n\n";
			cout<<"Enter book name to search it from the library\t";
			cin>>n;
			l1.search(n);
			break;
			
			case 4:
			cout<<"\n\t================== PRINTING ALL LIST =====================\n\n";
			l1.printer();
			break;
			
			case 5:
				cout<<" ======================SEARCH BOOK ONLINE ====================\n\n";
				system("cmd/c start https://books.google.com/");
				break;
				
			case 6:
			cout<<"\n\t=======================LIST OF BOOKS ADDED NOW ================== \n\n";
			l1.print_now();
			break;
			
			default:
			cout<<"\t----------------------InValid--------------------------"<<endl;	
		}
	}
	while(ch>0 && ch<6);
	cout<<"\n THANK YOU"<<endl;
	getch();
}