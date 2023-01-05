#include "katering.h"
//Tanggal
bool isTanggalKosong(list_tanggal lt){
	if(first(lt) == NULL){
		return true;
	}
	return false;
}

void createelm_tanggal(adr_tanggal &pt, int info){
	pt = new elm_tanggal;
	info(pt) = info;
	nextMenu(pt) = NULL;
	nextTanggal(pt) = NULL;
}

void createlist_tanggal(list_tanggal &lt){
	first(lt) = NULL;
}

void insert_tanggal(list_tanggal &lt, adr_tanggal pt){
	adr_tanggal curr = first(lt);
	if(curr == NULL){
		first(lt) = pt;
	}else{
		while(nextTanggal(curr) != NULL){
			curr = nextTanggal(curr);
		}
		nextTanggal(curr) = pt;
	}
}

void showlist_tanggal(list_tanggal lt, int tanggal){
	adr_tanggal curr = first(lt);
	if(curr == NULL){
		cout << "List Tanggal Kosong" << endl;
	}else{
		while(curr != NULL){
			if(info(curr) == tanggal){
				if(nextMenu(curr) != NULL){
					cout << "Daftar Menu Pada Tanggal " << info(curr) << " :" << endl;
					showlist_menu(nextMenu(curr));
				}else{
					cout << "Tidak Ada Daftar Menu Pada Tanggal " << info(curr) << endl;
				}
				break;
			}
			curr = nextTanggal(curr);
		}
	}
}

//Menu
bool isMenuExistinTanggal(list_tanggal lt, int tanggal, string menu){
	adr_tanggal curr = first(lt);
	if(curr != NULL){
		while(curr != NULL){
			if(info(curr) == tanggal){
				adr_menu cm = nextMenu(curr);
				while(cm != NULL){
					if(info(cm).compare(menu) == 0){
						return true;
					}
					cm = nextMenu(cm);
				}
				return false;
			}
			curr = nextTanggal(curr);
		}
	}
	return false;
}

void createelm_menu(adr_menu &pm, string info){
	pm = new elm_menu;
	info(pm) = info;
	nextMenu(pm) = NULL;
}

void insert_menu(list_tanggal &lt, int tanggal, adr_menu pm){
	adr_tanggal curr = first(lt);
	if(curr != NULL){
		while(curr != NULL){
			if(info(curr) == tanggal){
				if(nextMenu(curr) == NULL){
					nextMenu(curr) = pm;
				}else{
					adr_menu cm = nextMenu(curr);
					while(nextMenu(cm) != NULL){
						cm = nextMenu(cm);
					}
					nextMenu(cm) = pm;
				}
				
				break;
			}
			curr = nextTanggal(curr);
		}
	}
}

void showlist_menu(adr_menu pm){
	adr_menu cm = pm;
	int count = 0;
	
	if(pm != NULL){
		while(cm != NULL){
			count += 1;
			
			cout << count << ". " << info(cm) << endl;
			
			cm = nextMenu(cm);
		}
	}
}

void delete_menu(list_tanggal &lt, int tanggal, string menu){
	adr_tanggal curr = first(lt);
	bool found = false;
	if(curr != NULL){
		while(curr != NULL){
			if(info(curr) == tanggal){
				adr_menu cm = nextMenu(curr);
				adr_menu pm = NULL;
				adr_menu dm = NULL;
				while(cm != NULL){
					if(info(cm).compare(menu) == 0){
						found = true;
						dm = cm;
						if(pm == NULL){
							nextMenu(curr) = nextMenu(cm);
						}else{
							nextMenu(pm) = nextMenu(cm);
						}
						delete dm;
						
						break;
					}else{
						pm = cm;
						cm = nextMenu(cm);
					}
				}
				
				break;
			}
			curr = nextTanggal(curr);
		}
	}
	
	if(found){
		cout << "Berhasil Menghapus " << menu << " Pada Tanggal " << tanggal << endl;
	}else{
		cout << "Gagal Menghapus " << menu << " Pada Tanggal " << tanggal << " Karena Tidak Ditemukan" << endl;
	}
}
