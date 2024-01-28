#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
float calculate_cli(int letter, int word, int sentence);

int main(void)
{
    string text = get_string("Text: ");
    int letter = count_letters(text);
    int word = count_words(text);
    int sentence = count_sentences(text);
    float cli = calculate_cli(letter, word, sentence);

    if (cli < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (cli >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", cli);
    }
}

int count_letters(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]) && (i == 0 || !isspace(text[i - 1])))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}

float calculate_cli(int letter, int word, int sentence)
{
    float L = (float) letter / word * 100;
    float S = (float) sentence / word * 100;
    return 0.0588 * L - 0.296 * S - 15.8;
}
