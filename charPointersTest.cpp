//some c testing data stuff using casting, shows how a string is stored as ascii hex in main mem.
#include <cstring>
#include <iostream>

typedef unsigned char *byte_pointer;

using namespace std;

//show bytes in hex, use with poitners to see values stored at addresses
void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i<len; i++) {
    printf(" %.2x", start[i]);
  }
  printf("\n");
}

int main(){
  short x = 12345;
  short mx = -x; 

  show_bytes((byte_pointer) &x, sizeof(short));
  show_bytes((byte_pointer) &mx, sizeof(short));




}