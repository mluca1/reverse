
/*Matt L, Lab 08 (Reverse)
* April 3, 2019
* Last Edit: April 3, 2019 @ 1:35am
*/

#include<stdio.h>
#include<string.h>

#define MAXCHAR 1000

//-----------------------------------------------
//Reverses the string
void stringrev(char s[], int len)
{

int i=0;
int j = len-1;
char temp;

    while(i < j) 
    {
        temp = s[i];
        s[i++] = s[j];
        s[j--] = temp;
    }
}

//-----------------------------------------------
int main (int argc, char** argv)
{
  
int line = 0;
int count = 0;
int k;
   
   FILE *f1,*f2;
   char str [MAXCHAR];
   

//checks for the arguments
    if(argc!=3)
    {
        printf("You have not given enough arguments. \n");
    
    return -1;
    }

   // open file for reading
    f1 = fopen (argv[1], "r");
    
    //open file for writing
    f2 = fopen (argv[2], "w");
    
    //if input file exists
    if (f1 != NULL ) 
    {
        printf("File opened successfully! \n\n");
    
    while (fgets(str, MAXCHAR, f1) != NULL)
    {
        printf("%s", str);
        k = strlen(str);
   
    //count character
        count = count + k;
   
    //reverse string
        stringrev(str,k);
   
    //write to file
       fputs (str, f2);
       line++;    
    }
        printf("lines are: %d\ntotal character are: %d\n",line,count);
  
    }
        else {
            printf("ERROR:File not found.\n");
    
    return -1;
    }


    // close connection
    fclose(f1);
    fclose(f2);
  
    return 0;
}