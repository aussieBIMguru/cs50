#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get the text
    string book = get_string("Text: ");
    // Get the metrics
    int book_letters = count_letters(book);
    int book_words = count_words(book);
    int book_sentences = count_sentences(book);
    // Calculate L and S
    float L = ((float) book_letters / (float) book_words) * (float) 100;
    float S = ((float) book_sentences / (float) book_words) * (float) 100;
    // Calculate the index
    int grade = round((float) 0.0588 * L - (float) 0.296 * S - (float) 15.8);
    // Return grade level
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Function for counting letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

// Function for counting words
int count_words(string text)
{
    // By default we have a word
    int words = 1;
    // Scan for words
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isblank(text[i]))
        {
            words++;
        }
    }
    return words;
}

// Function for counting sentences
int count_sentences(string text)
{
    int sentences = 0;
    // Scan for punctuation
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char testchar = text[i];
        if (testchar == '.' || testchar == '!' || testchar == '?')
        {
            sentences++;
        }
    }
    return sentences;
}