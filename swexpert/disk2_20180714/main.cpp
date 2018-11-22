#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
using namespace std;
char disk[16][1024][1024];
char filename[100][16];
int filesize[100];
char data[4096];
int diskId;

void change_disk(int id) {
    assert(0<=id && id<=15);
    diskId = id;
}

void read_disk(int sector, char *data) {
    assert(0<=sector && sector<1024);
    memcpy(data, disk[diskId][sector], 1024);
}

void write_disk(int sector, char *data) {
    assert(0<=sector && sector<1024);
    memcpy(disk[diskId][sector], data, 1024);
}

extern void read_file(char *filename, char *data, int size);
extern void insert_file(char *filename, int offset, char *data, int size);
extern void delete_file(char *filename, int offset, int size);

unsigned int hash(char *data, int size) {
    unsigned int h=0;
    for(int i=0; i<size; i++) {
        h = (h<<5)+h+(data[i]-'A');
    }
    return h;
}

void read_data() {

}

int insert_data() {
    int fileId = rand()%100;
    int size = rand()%4096+1;
    for(int i=0; i<size; i++) {
        data[i]='A'+rand()%26;
    }
    int offset = rand() % (filesize[fileId]+1);
    insert_file(filename[fileId], offset, data, size);
    return fileId;
}
int delete_data() {
    int fileId = rand()%100;
    int offset = rand() % filesize[fileId];
    int size = rand() % (filesize[fileId]-offset)+1;
    delete_file(filename[fileId], offset, size);
    return fileId;
}

bool verify_data() {
}


void init() {
    srand(3);
    for(int i=0; i<100; i++) {
        for(int j=0; j<16; j++) {
            filename[i][j] = 'A' + rand()%26;
        }
        filesize[i]=0;
    }
}

int main() {
    int start = clock();
    init();
    int fileId=0;
    for(int i=0; i<10*1024*1024; i++) {
        switch(rand()%10) {
            case 0: case 1: case 2: case 3: case 4: case 5:
                fileId = insert_data();
                break;
            case 6: case 7: case 8: case 9:
                fileId = delete_data();
                break;
        }
        verify_data();
    }
    int time = start - clock();
}
