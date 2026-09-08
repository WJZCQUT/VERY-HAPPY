#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
int count_letters(char* text);
int count_words(char* text);
int count_sentences(char* text);


int main(void)
{
    char n[100000];
    printf("TEXT: ");
    scanf("%[^\n]",n);
    int letters = count_letters(n);
    int words = count_words(n);
    int sentences = count_sentences(n);
    float L = ((float)letters/words) * 100;
    float S = ((float)sentences/words) * 100;
    float i =0.0588 * L -0.296 * S -15.8;
    int grade = round(i);
    if(grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",grade);
    }
}
int count_letters(char* text)
{
    int count = 0;
    for(int i =0;text[i] != '\0'; i++)
    {
        if(isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}
int count_words(char* text)
{
   int count = 0;
   for(int i = 0; text[i] != '\0'; i++)
   {
    if(text[i] == ' ')
    {
        count++;
    }
   }
   return count +1;
}
int count_sentences(char* text)
{
    int count = 0;
    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i]=='.' || text[i] == '!' || text[i] =='?')
        {
            count++;
        }
    }
return count;
}