#define _CRT_SECURE_NO_WARNINGS
#include "ListOfSentences.h"
#include "PrepText.h"
#include "Plagiat.h"
#include "windows.h"

typedef char8_t path[256];

static SentList orig, plagiat;
static StolenList stolen;
static String origText, plagiatText;
static path origPath = "C:\\CourseTest\\esseOrig.txt";
static path plagPath = "C:\\CourseTest\\essePlag.txt";

static TCode code = ANSI;
static BitSet set;

HashTable StopWords; \

FILE* outputFile, * percentage;

void printNChars(char* str, char* end) {
	for (; str < end && *str != '\0'; str++) {
		putchar(*str);
	}
	putchar('\n'); // ƒл€ перехода на новую строкe
}

void printfNChars(char* str, char* end) {
	for (; str < end && *str != '\0'; str++) {
		fputc(*str, outputFile);
	}
	fputc('\n', outputFile);
}

void printStemWords(const HashTable table) {
	size_t i = 0;
	for (; i < table.capacity; i++) {
		table.listWords[i].curr = table.listWords[i].head;
		while (table.listWords[i].curr->next != NULL) {
			table.listWords[i].curr = table.listWords[i].curr->next;
			printNChars(table.listWords[i].curr->word.arr, table.listWords[i].curr->word.end);
		}
	}
}

const path output = "C:\\Course3sem\\FileRead.txt";
const path percent = "C:\\Course3sem\\Percentage.txt";


int main(int argc, char* argv[]) {
	StopWords = HashFill();
	SetConsoleOutputCP(1251);
	origText = ReadFromFile(argv[1], code);
	plagiatText = ReadFromFile(argv[2], code);

	//BitSet_PutChar(&set, 23, ба, ва, га, да, жа, за, йа, ка, ла, ма, на, па, ра, са, та, фа, ха, ца, ча, ша, ща, ъа, ьа);
	//for (size_t i = аа; i < €а; i++) {
	//	if (BitSet_In(SoglasnyeLetters[0], i) == true) {
	//		printf("%zx ", i);
	//	}
	//}


	puts("Orig text is:");
	puts(origText.arr);
	puts("PLagiat text is");
	puts(plagiatText.arr);
	orig = SentList_Create();
	plagiat = SentList_Create();
	Run(origText.end,origText.arr,code, &orig, StopWords);
	Run(plagiatText.end, plagiatText.arr, code, &plagiat, StopWords);
	orig.curr = orig.head;
	while (orig.curr->next != NULL) {
		orig.curr = orig.curr->next;
		puts("Sentence is");
		printNChars(orig.curr->start, orig.curr->end);
		printStemWords(orig.curr->sent);

	}
	plagiat.curr = plagiat.head;
	while (plagiat.curr->next != NULL) {
		plagiat.curr = plagiat.curr->next;
		puts("Sentence is");
		printNChars(plagiat.curr->start, plagiat.curr->end);
		printStemWords(plagiat.curr->sent);

	}

	stolen = FindPlagiat(&orig,&plagiat,code);
	stolen.curr = stolen.head;
	outputFile = fopen(output, "w");
	percentage = fopen(percent,"w");
	while (stolen.curr->next != NULL) {
		stolen.curr = stolen.curr->next;
		fputs("ќригинальное предложение: \n", outputFile);
		printfNChars(stolen.curr->orig.start, stolen.curr->orig.end);
		fputs("”краденное предложение:\n", outputFile);
		printfNChars(stolen.curr->plagiat.start, stolen.curr->plagiat.end);
		fputs("\n", outputFile);
		printf("\n");
	}
	fprintf(percentage,"%2f", stolen.Percentage * 100);
	fclose(outputFile);
	fclose(percentage);
	return 0;

}