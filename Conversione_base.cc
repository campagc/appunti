
// ------------
// char BN->B10 
// ------------

//----ITERATTIVO char BN -> B10---

int converti_decimale(char * numero, int base); // char Bn -> B10
int lenght(char * V);
int power(int base, int esponente);

//iterattivo: usa lenght() e power()
int converti_decimale(char * numero, int base){ // base B -> decimale

    int len = lenght(numero);
    int ris = 0;
    int aux;
    for(int i=0; i<len; i++){

        aux = numero[i] - '0'; // cast
        if(aux >= base){
            cout << "errore: cifra maggiore o uguale della base";
            exit(0);
        }
        ris += aux * power(base, len-i-1);

    }
    return ris;
}

int lenght(char * V){
    int i=0;
    for(; V[i]!='\0'; i++){
    }
    return i;
}

int power(int base, int esponente){
    int ris = 1;
    if(esponente == 0){
        return 1;
    }

    for(int i=0; i<esponente; i++){
        ris *= base;
    }

    return ris;
}

//FINE

//----RICORSIVO char BN -> B10---

int converti_decimale_ricorsivo(char * numero, int base);
int converti_decimale_ricorsivo_aux(char * numero, int base, int len);
int lenght_ricorsivo(char * V);
int power_ricorsivo(int base, int esponente);

int converti_decimale_ricorsivo(char * numero, int base){

    int len = lenght_ricorsivo(numero);
    return converti_decimale_ricorsivo_aux(numero, base, len);
}

int converti_decimale_ricorsivo_aux(char * numero, int base, int len){
    if(numero == '\0' || len == 0){
        return 0;
    }
    int aux = numero[0] - '0';

    if(aux >= base){
        cout << "errore: cifra maggiore o uguale della base";
        exit(0);
    }

    return aux * power_ricorsivo(base, len-1) + converti_decimale_ricorsivo_aux(numero+1, base, len-1);
}

int power_ricorsivo(int base, int esponente){
    if(esponente == 0){
        return 1;
    }

    return power_ricorsivo(base, esponente-1) * base;
}


int lenght_ricorsivo(char * V){
    if(V[0] == '\0'){
        return 0;
    }

    return 1 + lenght_ricorsivo(V+1);
}




// ------------
// B10-> char Bn
// ------------

// Iterattivo B10->char * Bn

void converti_base(int n, int base, char * vettore_dove_salvare);

void converti_base(int n, int base, char * vettore_dove_salvare){
    char V_aux[100];
    int i;
    for(i=0; n>=base; i++){
        int cifra = n%base;
        V_aux[i]= '0' + cifra;
        n = (n-cifra)/base;
    }
    V_aux[i]='0' + n;
    V_aux[i+1]='\0';

    //al contrario mi serve però
    int len = i+1;
    for(int j=0; j<len; j++){
        vettore_dove_salvare[j]=V_aux[i];
        i--;
    }
    return;
}

// Ricorsivo B10->char * Bn

void converti_base_ricorsivo(int n, int base, char * vettore_dove_salvare);
void converti_base_ricorsivo_aux(int n, int base, char * vettore_dove_salvare, int & i);

void converti_base_ricorsivo(int n, int base, char * vettore_dove_salvare){
    int i=0;
    return converti_base_ricorsivo_aux(n, base, vettore_dove_salvare, i);
}

void converti_base_ricorsivo_aux(int n, int base, char * vettore_dove_salvare, int & i){
    if(n < base){
        vettore_dove_salvare[i] = '0' + n;
        i++;
        return;
    }
    int cifra = n%base;
    converti_base_ricorsivo_aux((n-cifra)/base, base, vettore_dove_salvare, i);
    vettore_dove_salvare[i] = '0' + cifra;
    i++;
    return;
}






/// last
//recursive to base ten ex. rtobaseten("4AD", 17, strlen("4AD") - 1)
int rtobaseten(char* number, int base, int index) {
    //base case: if we end up at the start of the string we just return 0
    if (index < 0) return 0;
    //we get the character at the given position
    char n = number[index];
    int value = 0;
    //convert if the value is between 0 and 9
    if ('0' <= n && n <= '9')
        value = (n - '0');
    //convert if the value is between A and Z
    else if ('A' <= n && n <= 'Z')
        value = (n - 'A' + 10);
    //the formula is a sum of the value * base ^ index(0->1->2...) + the same one with the previous number and index + 1 (here we decrese the index since we're going from right to left and the rightmost number will be at the highest index)
    return value * pow(base, strlen(number) - index - 1) + rtobaseten(number, base, index - 1);
}

