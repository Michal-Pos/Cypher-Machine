#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//reversing single word (array of chars)
void odwroc_slowo(char str[], int start, int end)
{
    if (end-start>30){
    	printf("Wczytany tekst zawiera słowo zawierające więcej niż 30 znaków, przerywam pracę \n");
    	exit(2);
    }
    char temp; 
    //start i end wymieniają się wartościami aż się nie spotkają w środku, co skutkuje odwróconą kolejnością liter
    while(start<end){
        temp=str[start];
        str[start]=str[end];
        str[end]=temp;
        start++;
        end--;
    }
}


/*reversing whole text*/
void odwroc_tekst(char str[]){
    int start = 0, end = 0;
    /*reversing whole word if character from (2) group is detected*/
    while(str[end]){   
        for(end=start;str[end]&&str[end]!=' '&& str[end]!=','&& str[end]!='.'&& str[end]!='?' && str[end]!='\n';end++);
        odwroc_slowo(str, start, end-1);
        start=end+1;
    }
}


void koduj_linie(char str[], int k){
	int j, len = strlen(str);
    /*cyphering and decyphering capital letter*/
	for (int i=j=0; i<len; i++){    
            
        if (str[i]>='A' && str[i]<='Z'){
           str[i] +=k;
           if (str[i]>'Z'){
                str[i] -= 26;
           }

           str[j++] = str[i];
        }
	
	/* Checking space, period, coma, question mark and newline characters as end-of-the-word characters */
        else if (str[i]==' ' || str[i]=='.' || str[i]==',' || str[i]=='?' || str[i]=='\n'){
            str[j++] = str[i];
        }

    }
    str[j]='\0';

    // reversing all words in the text and saving them to the output file
    odwroc_tekst(str);
}


void przetwarzanie(FILE* plik_in, FILE* plik_out, int k){
	char* str;
    
    // cyphering whole text line after line and writing them to the output file
    while (fscanf(plik_in, "%[^\n] ", str)!=EOF){
    	koduj_linie(str, k);
    	fprintf(plik_out, "%s\n", str);
    }
}
FILE* wczytaj_input(char* input_file){
	FILE* plik_in;
	printf("Wpisz nazwe pliku wejsciowego, pamiętaj o dodaniu odpowiedniego rozszerzenia: \n");
	scanf("%s", input_file);
    
    if (strlen(input_file)>300){
    	printf("Podana nazwa pliku wejściowego ma więcej niż 300 znaków, kończę pracę");
    	exit(5);
    	}
    
    // opening input file 
    plik_in = fopen(input_file, "r");
    
    // checking if input file does not contain errors
    if (plik_in == NULL){
		printf("Błąd. Nie mogę otworzyć pliku do odczytu %s. Przerywam pracę.\n", input_file);
		exit(3);
	return plik_in;
	}  
}


FILE* wczytaj_output(char* output_file){
	FILE* plik_out;
	printf("Wpisz nazwe pliku wyjsciowego: \n");
    scanf("%s", output_file);
    if (strlen(output_file)>300){
    	printf("Podana nazwa pliku wyjściowego ma więcej niż 300 znaków, kończę pracę");
    	exit(6);
    	}
	// opening output file 
	plik_out = fopen(output_file, "w");
    
    // checking if output file does not contain errors
    if (plik_out == NULL){
		printf("Błąd. Nie mogę otworzyć pliku do zapisu %s. Przerywam pracę.\n", output_file);
		exit(4);
		}
	return plik_out;
    }


int main(void)
{
    char input_file[300], output_file[300];
    int choice, k;
    FILE* plik_in;
    FILE* plik_out;

    // getting input file
    printf("To jest program szyfrujacy i deszyfrujacy tekst.\n");
    plik_in = wczytaj_input(input_file);
    plik_out = wczytaj_output(output_file);
    

    printf("Wybierz odszyfrowanie lub szyfrowanie [1/2]: \n" );
    scanf("%d", &choice);
    
    if (choice!=1 && choice!=2){
    	printf("Nie wybrano zadnej operacji, przerywam prace \n");
            exit(7);
    }
    printf("Podaj klucz jakiego chcesz użyć, musi sie on byc niemniejszy niż od 0 i niewiększy niż 25 \n");
    scanf("%d", &k);
    if ((k<0) || (k>25)){
        printf("Klucz nie mieści sie w wymaganym przedziale, koncze prace \n");
        exit(8);
    }
	
	// cyphering is the came function as cyphering, but he key is equal lenght of the alphabet minus key 
    if (choice == 1){
	przetwarzanie(plik_in, plik_out, 26-k);
        }
    else{
	przetwarzanie(plik_in, plik_out, k);            
        }
    // zamykamy pliki
    fclose(plik_in); 
    fclose(plik_out);
    return 0;
}
