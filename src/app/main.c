#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	char word[50], sort[50], latters[26], nothing[2] = " ", t, cherta[2] = "_";
	char latters_for_answer[27] = "abcdefghijklmnopqrstuvwxyz";
	int latters_count[26] = { 0 }, i = 0, j, count = 0, p = 0, misstakes = 0;
	for (i = 0; i < 26; i++)
	{
		latters_count[i] = 0;
	}
	cout << "Set the word: ";
	cin >> word;
	//cout << word << endl;
	i = 0;
	while (word[i] != nothing[1])
	{
		count++;
		i++;
	}
	//cout << count << endl;
	for (i = 0; i < count; i++)
	{
		word[i] = tolower(word[i]);
	}
	int raw[26][50] = { 0 };
	for (i = 0; i < count; i++)
	{
		sort[i] = word[i];
	}
	for (i = 1; i < count; i++) 
	{
		t = sort[i];
		j = i - 1;
		while (j >= 0 and t < sort[j]) {
			sort[j + 1] = sort[j];
			j -= 1;
		}
		sort[j + 1] = t;
	}
	for (i = 0; i < count; i++)
	{
		//printf("%c", sort[i]);
	}
	//printf("\n");
	latters[0] = sort[0];
	j = 1;
	for (i = 0; i < count - 1; i++)
	{
		if (sort[i] != sort[i + 1]) 
		{
			latters[j] = sort[i + 1];
			j++;
		}
	}
	latters[j] = '0';
	for (i = 0; i < j + 1; i++)
	{
		//printf("%2c", latters[i]);
	}
	//printf("\n\n");
	j = 0;
	while (latters[j] != '0') 
	{
		for (i = 0; i < count; i++)
		{
			if (latters[j] == word[i])
			{
				latters_count[j]++;
				raw[j][p] = i;
				p++;
			}
		}
		j++;
		p = 0;
	}
	for (i = 0; latters[i] != '0'; i++)
	{
		//printf("| %c | %i |\n",latters[i], latters_count[i]);
	}
	for (i = 0; latters[i] != '0'; i++)
	{
		for (j = 0; j < latters_count[i]; j++)
		{
			//printf("%2i", raw[i][j]);
		}
		//printf("\n");
	}
	char answer[50] = "_________________________________________________";
	int count_of_close = count;
	while ((count_of_close > 0) and (misstakes != 7))
	{
		for (i = 0; i < count; i++)
		{
			printf("%2c", answer[i]);
		}
		printf("\n");
		for (p = 0; p < 26; p++)
		{
			printf("%2c", latters_for_answer[p]);
		}
		printf("\nPlease, chose the latter: ");
		cin >> t;
		for (p = 0; p < 26; p++)
		{
			if (latters_for_answer[p] == t) latters_for_answer[p] = cherta[0];
		}
		for (i = 0; latters[i] != '0'; i++)
		{
			if (latters[i] == t)
			{
				misstakes--;
				count_of_close -= latters_count[i];
				for (j = 0; j < latters_count[i]; j++)
				{
					answer[raw[i][j]] = t;
				}
			}
		}
		misstakes++;
	}
	for (i = 0; i < count; i++)
	{
		printf("%2c", answer[i]);
	}
	if (misstakes < 7) printf("\n\nWell done!\n\n");
	else printf("\n\nVi mertvi!\n\n");
}
