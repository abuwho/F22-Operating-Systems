#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//<WRITE YOUR CODE HERE>


struct Directory;
struct File;


typedef struct Directory Directory;
typedef struct File File;


struct File{
    int id;
    char name[63];
    int size;
    char data[1024];
    
    struct Directory * directory; // The parent directory
};

struct Directory{
    File * files[256];
    Directory * directories[8];
    int nf;
    int nd;
    char path[2048];
};


// Operations on files
void add_to_file(File *file, const char * content);
void append_to_file(File *file, const char * content);
void pwd_file(File * file);


// Operations on directories
void add_file(File* file, Directory *dir);
void add_dir(Directory *dir1, Directory *dir2); // given to you

// Helper functions
void show_dir(Directory *dir);
void show_file(File *file);
void show_file_detailed(File *file);

int main(){
    
    char content1[] = "int printf(const char * format, ...);";
    char content2[] = "int main(){printf('Hello World');}";
    char content3[] = "//This is a comment in C language";
    char content4[] = "Bourne Again Shell!";    
    
    Directory home, bin, root;

    strcpy(home.path, "/home");
    strcpy(bin.path, "/bin");
    strcpy(root.path, "/");
    
    root.nd = 0;
    root.nf = 0;
    home.nf = 0;
    home.nd = 0;
    bin.nf = 0;
    bin.nd = 0;
    
    // Add subdirectories
    add_dir(&home, &root);
    add_dir(&bin, &root);
    
    File bash, ex31, ex32;

    add_file(&bash, &bin);
    add_file(&ex31, &home);
    add_file(&ex32, &home);

    bash.id = 1;
    strcpy(bash.name, "bash");

    ex31.id = 2;
    strcpy(ex31.name, "ex3_1.c");
    strcpy(ex31.data, content1);

    strcpy(ex32.name, "ex3_2.c");
    strcpy(ex32.data, content2);
    
    add_to_file(&bash, content3);
    
    append_to_file(&ex31, content4);

    show_dir(&root);
    show_file_detailed(&bash);
    show_file_detailed(&ex31);
    show_file_detailed(&ex32);

    pwd_file(&bash);
    pwd_file(&ex31);
    pwd_file(&ex32);
   
   return EXIT_SUCCESS;
}

// Helper functions

// Displays the content of the Directory dir
void show_dir(Directory *dir){
    printf("\nDIRECTORY\n");
    printf(" path: %s\n", dir->path);
    printf(" files:\n");
    printf("    [ ");
    for (int i = 0; i < dir->nf; i++){
        show_file(dir->files[i]);
    }
    printf("]\n");
    printf(" directories:\n");
    printf("    { ");
    
    for (int i = 0; i < dir->nd; i++){
        show_dir(dir->directories[i]);
    }
    printf("}\n");
}

// Prints the name of the File file
void show_file(File *file){
    printf("%s ", file->name);
}

// Shows details of the File file
void show_file_detailed(File *file){
    printf("\nFILE\n");
    printf(" id: %d\n", file->id);
    printf(" name: %s\n", file->name);
    printf(" size: %lu\n", file->size);
    printf(" data:\n");
    printf("    [ %s ]\n", file->data);
}



// Implementation: Operations on files

// Adds the content to the File file
void add_to_file(File *file, const char * content) {
    // Update file content
    strcpy(file->data, content);
    // Update file size
    file->size = strlen(file->data);
	
}

// Appends the content to the File file
void append_to_file(File *file, const char * content) {
    // Update file content
    strcat(file->data, content);
    // Update file size
    file->size = strlen(file->data);
}

// Prints the path of the File file
void pwd_file(File * file) {
	// Example: the path for bash file is /bin/bash
    printf("%s/%s\n", file->directory->path, file->name);
}


// Implementation: Operations on directories

// Adds the File file to the Directory dir
void add_file(File* file, Directory *dir) {
    dir->files[dir->nf] = file;
    dir->nf += 1;
    file->directory = dir;
    file->size = 0; // Set size of file
}

// Given to you
// Adds the subdirectory dir1 to the directory dir2
void add_dir(Directory *dir1, Directory *dir2){
	if (dir1 && dir2){
		dir2->directories[dir2->nd] = dir1;
		dir2->nd++;
	}
}
