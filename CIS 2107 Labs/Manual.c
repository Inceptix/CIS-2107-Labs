/*
 * Name:	Marinos Rrapaj
 * Section:	02
 * Date:	03/11/2019
 * Lab:  	CIS2107_Lab07_Manual
 * Goal: 	To design and implement functions to process characters and strings.
 */


#include <stdio.h>
#include <memory.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//functions
void * upperLower(const char * s);
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4);
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4);
void compareStr(const char *s1, const char *s2);
void comparePartialStr(const char *s1, const char *s2, int n);
void randomize(void);
int tokenizeTelNum(char *num);
void reverse(char *text);
int countSubstr (char * line, char * sub);
int countChar (char * line, char c);
int countWords(char *string);
void countAlpha(char *string);
void startsWithB(char *string[], int size);
void endsWithed(char *string[], int size);

int main() {

    //random generator
    srand(time(NULL));

    //test for upperLower
    const char test[] = "This iS A Test";
    upperLower(test);

    //test for convertStrtoInt
    printf("\n\nThe sum of 4 strings is: %d", convertStrtoInt("3", "4", "5", "6"));

    //test for convertStrtoFloat
    printf("\n\nThe sum of 4 strings is: %.2f\n\n", convertStrtoFloat("3.5", "4.5", "5.5", "6.5"));

    //test for compareStr
    compareStr("Test1", "Test2");

    //test for comparePartialStr
    comparePartialStr("Test1", "Test2", 4);

    //test for randomize
    randomize();

    //test for tokenize number
    char str[] = "(267) 436-6281";
    tokenizeTelNum(str);

    //test for reverse
    char line[] = "Hello world";
    reverse(line);

    //test for countSubstr
    char *line1 = "helloworldworld";
    char *substring = "world";
    printf("\n\nNumber of Substrings %s inside %s: %d\n", substring, line1, countSubstr(line1, substring));

    //test for countChar
    char w = 'w';
    printf("\nNumber of character %c inside %s: %d\n", w, line1, countChar(line1, w));

    //test for countAlpha
    char str1[] = "Hello it's me.";
    countAlpha(str1);

    //test for countWords
    char countstring[] = "hello world!";
    printf("\n\nNumber of words in string is: %d\n", countWords(countstring));

    //test for startsWithB
    char *series[] = {"bored", "hello", "Brother", "manual", "bothered"};
    int size = sizeof(series) / sizeof(series[0]);
    startsWithB(series, size);

    //test for endsWithed
    endsWithed(series, size);
    return 0;

}

// 1.(Displaying Strings in Uppercase and Lowercase)
void * upperLower (const char * s)
{
    // to print in uppercase
    for(int i=0;i<strlen(s);i++)
    {
        printf("%c ",toupper(s[i]));
    }

    printf("\n");

// to print in lowercase
    for(int i=0;i<strlen(s);i++)
    {
        printf("%c ",tolower(s[i]));
    }

}

// 2.(Converting Strings to Integers for Calculations)
int convertStrtoInt(const char *s1, const char *s2, const char *s3, const char *s4)
{
    int i1=atoi(s1);
    int i2=atoi(s2);
    int i3=atoi(s3);
    int i4=atoi(s4);
    return i1+i2+i3+i4;

}

//3.(Converting Strings to Floating Point for Calculations)
float convertStrtoFloat(const char *s1, const char *s2, const char *s3, const char *s4)
{
    float f1 = strtof(s1, NULL);
    float f2 = strtof(s2, NULL);
    float f3 = strtof(s3, NULL);
    float f4 = strtof(s4, NULL);

    return f1+f2+f3+f4;

}

//4.(Comparing Strings)
void compareStr(const char *s1, const char *s2)
{
    int result;
    result = strcmp(s1, s2);

    if (result > 0)
    {
        printf("The first string is greater than the second string.\n\n");
    }
    else if (result < 0)
    {
        printf("The first string is less than the second string.\n\n");
    }
    else
    {
        printf("Both strings are equal.\n\n");
    }

}

//5.(Comparing Portions of Strings)
void comparePartialStr(const char *s1, const char *s2, int n)
{
    int result;
    result = strncmp(s1, s2, n);

    if (result > 0)
    {
        printf("The first string is greater than the second string.\n\n");
    }
    else if (result < 0)
    {
        printf("The first string is less than the second string.\n\n");
    }
    else
    {
        printf("Both strings are equal.\n\n");
    }

}

//6.(Random Sentences)
void randomize(void)
{
    //create the size of array
   int size = 5;

   //create first array of article
   char* article[size];
   article[0] = "a";
   article[1] = "one";
   article[2] = "the";
   article[3] = "some";
   article[4] = "any";


   //create second array of noun
   char* noun[size];
   noun[0] = "cat";
   noun[1] = "dog";
   noun[2] = "truck";
   noun[3] = "plane";
   noun[4] = "skateboard";


   //create third array of verb
   char* verb[size];
   verb[0] = "drove";
   verb[1] = "jumped";
   verb[2] = "ran";
   verb[3] = "walked";
   verb[4] = "flew";


   //create fourth array of preposition
   char* preposition[size];
   preposition[0] = "to";
   preposition[1] = "from";
   preposition[2] = "over";
   preposition[3] = "under";
   preposition[4] = "on";

   //sentance index to keep track of sentance current character
   int sentenceIndex=0;

   //keep track of current index that is current array
   int currentIndex=0;

   //store the variable to keep track of current random number
   int randPosition=0;

   //keep the current sentence generated
   char sentance[100];

   //loop for twenty sentences
   int k,i;
   for(k=0;k<20;k++){

       //reset the sentence
       for(i=0;i<100;i++){
           sentance[i]='\0';
       }

       //reset current index
       currentIndex =0;

       //get random number
       randPosition = rand()%5;
       //copy data to sentence until null came
       while(article[randPosition][currentIndex]!='\0'){
           sentance[sentenceIndex]=article[randPosition][currentIndex];
           sentenceIndex++;
           currentIndex++;
       }
       //put space in between
       sentance[sentenceIndex]=' ';
       sentenceIndex++;

       currentIndex =0;
       randPosition = rand()%5;
       while(noun[randPosition][currentIndex]!='\0'){
           sentance[sentenceIndex]=noun[randPosition][currentIndex];
           sentenceIndex++;
           currentIndex++;
       }

       sentance[sentenceIndex]=' ';
       sentenceIndex++;

       currentIndex =0;
       randPosition = rand()%5;
       while(verb[randPosition][currentIndex]!='\0'){
           sentance[sentenceIndex]=verb[randPosition][currentIndex];
           sentenceIndex++;
           currentIndex++;
       }


       sentance[sentenceIndex]=' ';
       sentenceIndex++;

       currentIndex =0;
       randPosition = rand()%5;
       while(preposition[randPosition][currentIndex]!='\0'){
           sentance[sentenceIndex]=preposition[randPosition][currentIndex];
           sentenceIndex++;
           currentIndex++;
       }
       sentance[sentenceIndex]=' ';
       sentenceIndex++;

       currentIndex =0;
       randPosition = rand()%5;
       while(article[randPosition][currentIndex]!='\0'){
           sentance[sentenceIndex]=article[randPosition][currentIndex];
           sentenceIndex++;
           currentIndex++;
       }
       sentance[sentenceIndex]=' ';
       sentenceIndex++;

       currentIndex =0;
       randPosition = rand()%5;
       while(noun[randPosition][currentIndex]!='\0'){
           sentance[sentenceIndex]=noun[randPosition][currentIndex];
           sentenceIndex++;
           currentIndex++;
       }
       //change first character to upper case
       sentance[0]=sentance[0]-32;
       //put dot at the end
       sentance[sentenceIndex]='.';
       printf("%s",sentance);
       sentenceIndex=0;
       currentIndex=0;
       printf("\n");

    }
}

//7.(Tokenizing Telephone Numbers)
int tokenizeTelNum(char *num)
{
    int area;
    long phone;
    char phonestr[50];
    char numcopy[50];

    /* copy the string because num may point to a constant array */
    strcpy(numcopy, num);

    char *tok = strtok(numcopy, "()");
    if(tok == NULL) return -1; /* error*/
    area = atoi(tok);

    tok = strtok(NULL, "-");
    if(tok == NULL) return -1; /* error*/
    strcpy(phonestr, tok);

    tok = strtok(NULL, "");
    if(tok == NULL) return -1; /* error*/
    strcat(phonestr, tok);
    phone = atol(phonestr);

    printf("\nArea: %d Phone: %ld\n", area, phone);
    return 0; /*success*/

}

//8.(Displaying a Sentence with Its Words Reversed)
void reverse(char *text)
{
    char *pointers[ 50 ];
    char *temp;
     int count = 0, i;

     temp = strtok( text, " " );

     while ( temp ) {
        pointers[ count++ ] = temp;
        temp = strtok( NULL, " " );
     }

     printf( "The tokens in reverse order are:\n" );

     for ( i = count - 1; i >= 0; i-- )
        printf( "%s ", pointers[ i ] );

}

//9.(Counting the Occurrences of a Substring)
int countSubstr (char * line, char * sub)
{
    //store the line to find in find
   char *find = line;
   //find the length of substring to find
   int len = strlen(sub);
   //initial count
   int count = 0;
   //continue if len of substring is not 0
   if(len )
   {
       //use strstr() function to find the sub string
       //if it is found find will contains the string starting from the sub
       //ex: find = "abc dbc abc dbc", sub = "dbc"
       //find = strstr(find,sub) sets the "dbc abc dbc" string into find
       //if not found sets ""
       //which means null
       while( (find = strstr(find, sub)))
       {
           //forward by sub string length
           find += len;
           //increment count
           count++;
       }
   }
   return count;

}

//10.(Counting the Occurrences of a Character)
int countChar (char *line, char c)
{
    char* temp = line;
    int count = 0;

    while(temp != NULL)
    {
    temp = strchr(temp, c);
       if( temp )
        {
           temp++;
           count++;
        }
    }
    return count;

}


//11.(Counting the Letters of the Alphabet in a String)
void countAlpha(char *string)
{


}

//12.(Counting the Number of Words in a String)
int countWords(char *string)
{
    char *token = strtok(string, " \n");
    int count = 0;
    while(token != NULL) {
        count++;
        token = strtok(NULL, " \n");
    }
    return count;

}

//13.(Strings Starting with "b")
void startsWithB(char *string[], int size)
{
    puts("");
    puts("Words that start with b");

    int i;
    for(i=0;i<size;i++)
    {

        if(string[i][0]=='B' || string[i][0]=='b')
        printf("%s\n",string[i]);
    }

    puts("");
}

//14.(Strings Ending with "ed")
void endsWithed(char *string[], int size)
{

    puts("Words that end with ed");
    int i;
    for (i=0; i < size; i++)
    {
        int len = strlen(string[i]);
        if (string[i][len-1] == 'd' && string[i][len-2] == 'e')
        printf("%s\n", string[i]);
    }

    puts("");
}
