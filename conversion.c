#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>


//Binaire → Décimal

int bintodec(char *val)
{
    int resultat = 0;
    while (*val)
    {
        resultat *= 2;
        resultat += *val == '1' ? 1 : 0;
        ++val;
    }
    printf("La conversion binaire - décimal nous donne : %d\n", resultat);
    return 0;
}

//Hexadécimal → Décimal

int hexatodec(char *val)
{
    int resultat = 0;
    while (isxdigit((char)*val))// "isxdigit" vérifie si le caractère passé est un chiffre hexadécimal
    { 
        int num;
        int caractere = (char)*val++;
        if (isdigit(caractere))//  "isdigit" vérifie si le caractère passé est un caractère décimal
        { 
            num = *val - '0';
        }
        else
        {
            num = tolower(caractere) - 'a' + 10; //"tolower" convertit une lettre donnée en minuscules
        }
        resultat = resultat * 16 + num;
    }
    printf("La conversion hexadécimal - décimal nous donne : %d\n", resultat);
}



//Décimal → Hexadécimal

char *dectohexa(unsigned int val)
{

    int num_decimal, temp, a;
    char hex[32];
    temp = 0;
    while (val > 0)
    {
        switch (val % 16)
        {
        case 10:
            hex[temp] = 'A';
            break;
        case 11:
            hex[temp] = 'B';
            break;
        case 12:
            hex[temp] = 'C';
            break;
        case 13:
            hex[temp] = 'D';
            break;
        case 14:
            hex[temp] = 'E';
            break;
        case 15:
            hex[temp] = 'F';
            break;
        default:
            hex[temp] = (val % 16) + 0x30;
        }
        val = val / 16;
        temp++;
    }
    printf("La conversion décimal - hexadécimal nous donne : ");
    for (a = (temp - 1); a >= 0; a--)
    {
        printf("%c", hex[a]);
    }
    printf("\n");

    return 0;
}




int main() {
   bintodec("1001");
   hexatodec("9A");
   dectohexa(11);
   
}
