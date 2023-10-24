#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char *grade_scale = "\
Grades    Grade Points    Numerical Scale of Grades\n\
A         4.0             85 – 100%\n\
A-        3.7             80 –  84%\n\
B+        3.3             75 –  79%\n\
B         3.0             70 –  74%\n\
B-        2.7             65 –  69%\n\
C+        2.3             60 –  64%\n\
C         2.0             55 –  59%\n\
D         1.0             50 –  54%\n\
F         0               0  –  49%\
";

void die(char *s)
{
	fprintf(stderr, "%s\n", s);
	exit(2);
}

int is_frac = 0;
double nume = -1.0;
double denom = -1.0;

int main(int argc, char **argv)
{
	if(argc == 1) {
		//if no arg given, print the scale
		printf("%s\n", grade_scale);
		exit(0);
	}
	else if(argc != 2)
	{
		fprintf(stderr, "Usage: %s [percentage | fraction]\n       %s (with no arguments)\n", argv[0], argv[0]);
		exit(1);
	}
	char *raw_grade = argv[1];
	while(*raw_grade)
	{
		if(*raw_grade != '/' && *raw_grade != '.' && !isdigit(*raw_grade)) {die("Error: grade is not percentage or fraction");}
		if(*raw_grade == '/')
		{
			is_frac = 1;
			char *delim="/";
			char *tok = strtok(argv[1], delim);
			nume = atof(tok);
			tok = strtok(NULL, delim);
			if(tok != NULL)
			{
				denom = atoi(tok);
			}
			else
			{
				die("Error: fraction has no denominator");
			}
			//printf("%d/%d\n", nume, denom);
		}
		raw_grade++;
	}
	
	double grade = atof(argv[1]);
	if(is_frac)
	{
		grade = (nume/denom)*100;
	}

	//NOTE: this code will interpret 79.01 as an A- because its greater than 79 - FIX?
	if(grade <= 49) {printf("F\n");}
	else if(grade <= 54) {printf("D\n");}
	else if(grade <= 59) {printf("C\n");}
	else if(grade <= 64) {printf("C+\n");}
	else if(grade <= 69) {printf("B-\n");}
	else if(grade <= 74) {printf("B\n");}
	else if(grade <= 79) {printf("B+\n");}
	else if(grade <= 84) {printf("A-\n");}
	else if(grade <= 100) {printf("A\n");}

	return 0;
}
