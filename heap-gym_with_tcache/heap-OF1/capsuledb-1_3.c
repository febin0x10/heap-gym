#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void* allocate_str(){
int size;
int ch;
printf("Size: ");
fflush(stdout);
scanf("%d", &size);
if (size < 1){
printf("\nSize too low, initializing Minimum 16 bytes!\n");
fflush(stdout);
size = 16;
}
char string[size];


if (size <= 5000){
  void* allocated = (void*)malloc(size);
  //memcpy(allocated,string,size);
  printf("\nSupply the String Data: ");
  //scanf("%s", allocated);
  printf("\n");
  fflush(stdout);
  read(0,allocated, size-1);
  //memcpy(allocated, string, sizeof(string));
  printf("\n");
  fflush(stdout);
  printf(" [Hit Enter again to finish] \n\n");
  fflush(stdout);
  //memcpy(allocated,string,(size_t)size);
  //scanf("%s", eof);
  while ((ch = getchar()) != '\n' && ch != EOF){
    printf("\0");
  }
  return allocated;
} else {
  return NULL;
}
}


void* allocate_int(){
int integer;
int* int_ptr = (int*)malloc(8);

printf("\nValue: ");
fflush(stdout);
scanf("%d",int_ptr);

return int_ptr;

}


void* data_add(){
void* retval;
int choose;

printf("\nChoose datatype [1 -> Int ,2 - Str ]: ");
fflush(stdout);
scanf("%d",&choose);

if (choose == 2){
  retval = allocate_str();
} else {
  retval = allocate_int();
}
return retval;
}

int edit_data(void* edit_ptr){
int type;
int esize;
int value = 0;
char* editstring = "";
int ch;

printf("Data type? [1-> Int, 2 -> Str]: ");
fflush(stdout);
scanf("%d",&type);

if (type == 1){
  int* integer_ptr = (int*)edit_ptr;
  printf("\nValue: ");
  fflush(stdout);
  //scanf("%d",&value);
  scanf("%d",integer_ptr);
  //memcpy(integer_ptr, &value, 8);
  return 0;
} else if (type == 2) {
  //printf("\nSize: ");
  //scanf("%d",&esize);
  printf("\nData: ");
  fflush(stdout);
  printf("\n");
  fflush(stdout);
  //printf("%p\n", edit_ptr);
  //read(0,edit_ptr, sizeof(edit_ptr));
  scanf("%s", edit_ptr);
  printf("\n");
  fflush(stdout);
  printf(" [Hit Enter again to finish] \n\n");
  fflush(stdout);
  while ((ch = getchar()) != '\n' && ch != EOF){
    printf("\0");
  }
  return 0;
} else {
  printf("Invalid Choice / Operation!\n");
  fflush(stdout);
  return 1;
}


}


int view_data(void* view_ptr){
int vtype;
printf("\nType? [1 => Int, 2 => Str]: ");
fflush(stdout);
scanf("%d",&vtype);

if (vtype == 2){
  char* str = (char*)view_ptr;
  printf("\n *********\n");
  fflush(stdout);
  printf(str);
  fflush(stdout);
  printf("\n ---------\n");
  fflush(stdout);
} else if (vtype == 1) {
  int* integer = (int*)view_ptr;
  printf("\n *********\n");
  printf(" %d", *integer);
  printf("\n --------- \n");
  fflush(stdout);
} else  {
  int* integer = (int*)view_ptr;
  printf("\n --------- \n");
  fflush(stdout);
  printf(" %d", *integer);
  printf("\n --------- \n");
  fflush(stdout);
}


  return 0;
}



int main(){

void* storage_pointers[16];
//int limit[10];
int counter;
int choice;
int dtype;
int editindex;
int choose;
int del_index;
int view_index;
int total_capacity = sizeof(storage_pointers)/sizeof(storage_pointers[0]); // uaf fix
void* freed_list[100]; // DF and UAF fix
int noedit = 0;
int freecounter; // DF and UAF fix
int nofree = 0; // Double Free fix


printf("--------------------\n");
printf("|    CapsuleDB     |\n");
printf("|       v1.3       |\n");
printf("--------------------\n\n");
fflush(stdout);


counter = 0;
freecounter = 0;
while (1){

  printf("[+] Temporary Data Storage Engine\n");
  fflush(stdout);
  printf("(1) Create Data Capsule\n");
  fflush(stdout);
  printf("(2) Edit Data Capsule\n");
  fflush(stdout);
  printf("(3) Delete Capsule\n");
  fflush(stdout);
  printf("(4) View Capsule Data\n");
  fflush(stdout);
  printf(" [*] Total Capsules filled %d/%d\n", counter, sizeof(storage_pointers)/sizeof(storage_pointers[0]));
  fflush(stdout);


  printf("> ");
  fflush(stdout);
  scanf("%d",&choice);

if (choice == 1){
  printf("\nChoose datatype [1 -> Int ,2 - Str ]: ");
  fflush(stdout);
  scanf("%d",&choose);

  if (choose == 2){
    storage_pointers[counter] = allocate_str();
    for (int j=0; j <= total_capacity; j++){
      if (freed_list[j] == storage_pointers[counter]);
      freed_list[j] = NULL;
    }
    counter++;

  } else if (choose == 1) {
    storage_pointers[counter] = allocate_int();
    for (int j=0; j <= total_capacity; j++){
      if (freed_list[j] == storage_pointers[counter]);
      freed_list[j] = NULL;
    }
    counter++;

  } else {
    printf(" [-] Invalid Choice!\n");
  }
} else if (choice == 2){
  printf("Index: ");
  scanf("%d", &editindex);
  //printf("%p\n",storage_pointers[editindex]);
  noedit = 0;
  for (int i=0; i <= total_capacity; i++){
    if (storage_pointers[editindex] == freed_list[i]){
      noedit = 1;
    }
  }

  if (noedit == 0){
  edit_data(storage_pointers[editindex]);
} else {
    printf("\n\n [x] Use-After-Free Attempt: Can't Edit Freed Chunk! \n\n");
    fflush(stdout);
}


} else if (choice == 3){
  printf("Index?: ");
  fflush(stdout);
  scanf("%d", &del_index);
  nofree = 0;
  for (int i=0; i <= total_capacity; i++){
    if (storage_pointers[del_index] == freed_list[i]){
      printf(" \n\n [x] Double-Free Attempt: Freed Already! Can't free already free chunk! \n\n");
      fflush(stdout);
      nofree = 1;
    }
  }

  if (nofree != 1){
    free(storage_pointers[del_index]);
    freed_list[freecounter] = storage_pointers[del_index];
    freecounter++;
    }

} else if (choice == 4){
  printf("Index?: ");
  fflush(stdout);
  scanf("%d", &view_index);
  view_data(storage_pointers[view_index]);
}




} // While End

} // Main End
