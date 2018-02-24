#include "player.h"
#include <ctime>

int randomInt(int  max_int) {
    srand(time(NULL));
    return (rand() % max_int) + 1;
}

void printInfo(List L) {
    /**
    * PR : menampilkan informasi ID, nama, dan lokasi file
    */

    address Q = first(L);
    do {
        cout<<"name    : "<<info(Q).name<<endl
            <<"ID      : "<<info(Q).ID<<endl
            <<"location: "<<info(Q).location<<endl;
        Q = next(Q);
    } while(Q!=first(L));
    cout<<"==============================================="<<endl;
}


void playMusic(address P) {
    /**
    * PR : memainkan lagu yang ditunjuk oleh pointer P
    */

    string filename = info(P).location+"/"+info(P).name;
    cout<<"playing "<<filename<<endl;
    PlaySound(TEXT(filename.c_str()), NULL, SND_FILENAME);
    _sleep(500); //delay 0.5 second
}


void shuffleList(List &L) {
    /**
    * PR : mengacak isi (elemen) dari list L
    * FS : isi (elemen) dari list teracak
    */
    //-------------your code here-------------

    List L2;
    createList(L2);
    address M,P;
    int MAX = 0;
    int i = 0;
    int num;
    infotype x;
    if(first(L)!=NULL){
        address Q = first(L);
        while(Q != first(L)){
            MAX = MAX + 1;
            Q = next(Q);
        };

        for(i=1;i<=MAX;i++){
            while(M == NULL && first(L)!= NULL){
                x.ID = randomInt(MAX);
                M = findElmByID(L,x);
            }
            if(M==first(L)){
                deleteFirst(L,P);
                insertFirst(L2,P);
            }else if(M==last(L)){
                deleteLast(L,P);
                insertLast(L2,P);
            }else{
                deleteAfter(L,prev(M),P);
                insertFirst(L2,P);
            }
        }
        L = L2;
    }
    //----------------------------------------
}

void sortListByID(List &L) {
    /**
    * PR : mengurutkan isi (elemen) dari list L berdasarkan ID
    * FS : isi (elemen) dari list L terurut
    */
    //-------------your code here-------------
    List L2;
    createList(L2);
    address P;
    if(first(L)!=NULL){
        while(first(L) != NULL){
            deleteFirst(L,P);
            insertAndSort(L2,P);
        }
    }
    L=L2;

    //----------------------------------------

}

void playRepeat(List &L, int n) {
    /**
    * PR : memainkan seluruh lagu di dalam list
    *      dari lagu pertama hingga terakhir sebanyak n kali
    */
    //-------------your code here-------------

    for(int i=0; i<n;i++){
        address Q = first(L);
        while(Q != last(L)){
            playMusic(Q);
            Q=next(Q);
        }
    }
    //----------------------------------------
}

void deleteMusicByID(List &L, infotype x) {
    /**
    * IS : list L mungkin kosong
    * PR : menerima input user untuk ID lagu yang ingin dihapus
    *      jika ID lagu ditemukan, hapus (deallocate) lagu dari list
    * FS : elemen dengan ID yang dicari dideallocate
    */
    //-------------your code here-------------
    address P;
    address Q = findElmByID(L,x);
    if(first(L)!=NULL){
        if(Q!=NULL){
            if(Q==first(L)){
                deleteFirst(L,P);
            }else if (Q==last(L)){
                deleteLast(L,P);
            } else{
                deleteAfter(L,prev(Q),P);
            }
        }else{
            cout<<"ID not Found"<<endl;
        }
    }else{
        cout<<"Empty List"<<endl;
    }

    //----------------------------------------

}

void insertAndSort(List &L, address P) {
    /**
    * IS : List may be empty
    * PR : insert an element pointed by P into an already sorted-by-ID List L
    *      so that the elements inside List L is still sorted by ID
    *      procedure must also check if such ID is already exists (No Duplicate ID)
    * FS : elements in List L sorted by ID, P is inside List L
    */

    //-------------your code here-------------
    //address Fo = findElm(L,info(P));
    //if(Fo==NULL){
        if(first(L)==NULL){
            insertFirst(L,P);
        }else if(L.first->info.ID >= P->info.ID){
            insertFirst(L,P);
        }else if(L.first->info.ID <= P->info.ID){
            address Q = first(L);
            address F = Q;
            if(first(L)==last(L)){
                insertLast(L,P);
            }else{
                do{
                    if(Q->info.ID <= P->info.ID){
                        F = Q;
                    }
                    Q = next(Q);

                }while (Q!=first(L));
                insertAfter(L,F,P);

            }
        }
    //----------------------------------------
}
