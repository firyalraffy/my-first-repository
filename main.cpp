#include "katering.cpp"

int main(){
	//Variables
	list_tanggal lt;
	adr_tanggal pt;
	adr_menu pm;
	string menu;
	int i, tanggal, pilihan;
	
	//Algorithm
	createlist_tanggal(lt);
	do{
		cout << "=== MENU PROGRAM KATERING ===" << endl;
		cout << "[1] Membuat List Tanggal" << endl;
		cout << "[2] Tambahkan Menu Di List Tanggal" << endl;
		cout << "[3] Tampilkan Semua Menu Berdasarkan Tanggal" << endl;
		cout << "[4] Hapus Menu Berdasarkan Tanggal" << endl;
		cout << "[0] Keluar" << endl << endl;
		cout << "Pilih : "; cin >> pilihan;
		
		cout << endl;
		switch(pilihan){
			case 0:{
				cout << "Keluar dari program..." << endl;
				
				break;
			}
			
			case 1:{
				if(isTanggalKosong(lt)){
					do{
						cout << "Masukkan Jumlah Tanggal [29/30/31] : ";
						cin >> tanggal;
						
						cout << endl;
						if(tanggal < 29 || tanggal > 31){
							cout << "Tanggal Tidak Valid" << endl << endl;
						}
					}while(tanggal < 29 || tanggal > 31);
					
					for(i=1; i<=tanggal; i++){
						createelm_tanggal(pt, i);
						insert_tanggal(lt, pt);
					}
					
					cout << "Berhasil Membuat List Tanggal Sebanyak " << tanggal << endl; 
				}else{
					cout << "List Tanggal Sudah Dibuat" << endl;
				}
				
				break;
			}
			
			case 2:{
				cin.ignore();
				cout << "Masukkan Nama Menu : ";
				getline(cin >> ws, menu);
				
				cout << "Masukkan Tanggal   : ";
				cin >> tanggal;
				
				if(!isMenuExistinTanggal(lt, tanggal, menu)){
					createelm_menu(pm, menu);
					insert_menu(lt, tanggal, pm);
					cout << "Berhasil Menambahkan Menu " << menu << " Pada Tanggal " << tanggal << endl;
				}else{
					cout << "Gagal Menambahkan Menu " << menu << " Pada Tanggal " << tanggal << " Karena Sudah Terdaftar" << endl;
				}
				
				break;
			}
			
			case 3:{
				cout << "Masukkan Tanggal : ";
				cin >> tanggal;
				
				showlist_tanggal(lt, tanggal);
				
				break;
			}
			
			case 4:{
				cin.ignore();
				cout << "Masukkan Nama Menu : ";
				getline(cin >> ws, menu);
				
				cout << "Masukkan Tanggal   : ";
				cin >> tanggal;
				
				delete_menu(lt, tanggal, menu);
				
				break;
			}
			
			default:{
				cout << "Pilihan Tidak Valid" << endl;
				
				break;
			}
		}
		
		if(pilihan != 0){
			cout << endl;
			system("pause");
			system("cls");
		}
	}while(pilihan != 0);
	
	return 0;
}
