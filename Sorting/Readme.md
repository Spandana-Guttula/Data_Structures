# Sorting Algorithm 
qsort() function is pre-defined function in C library

## void qsort(void* base, size_t num, size_t size, int (*compare)(const void*, const void*))
      
       compare: Function pointer to a comparison function that compares two elements. and const void* means read only to the data of any datatype 
        
        returnType comparatorName(const void* a, const void* b);
                    if   <0 means a is before b --> Asecnding order
                        >0 means b is before a --> descending order

       
## Description
<p align="left">C String is stored as an array of characters.
<p align="left">The difference between a character array and a C string is that the string in C is terminated with a unique character ‘\0’.
<p align="left">C strings Declaration types 
<p align="left"> i. CHARACTER ARRAYS 
<p align="left"> String Literal without size( char str[] = " Geeksfor geeks" )
 <p align="mid">                      - String Literal with size (char str[50] = "GeeksforGeeks" )
 <p align="mid">                     - String character  by character with Size ( char str[14] = { 'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'} )
 <p align="mid">                     - String character  by character without  Size (char str[] = { 'G','e','e','k','s','f','o','r','G','e','e','k','s','\0'})
 <p align="left">ii. Character Pointers
 <p align="left">- Directly assigned to pointer ( char *str  =  "GfG") ---> Stores in READ ONLY BLOCK 
 <p align="mid">                     -  dynamically alloacted ( char *str) ---> gets stored in heap 


## Important difference


| Strings as Character ARRAYS | Strings as POINTERS |
|----------|----------|
|Auto variable are stored in stack segment | Allocated in heap segment |
| Get stored as Global variable in data segment  | Stroed in READ ONLY MEMORY of data Segment | 



## AMD Interview


