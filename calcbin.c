/*
Autor: Vnícius de Andrade Jordão
Email: Vaj@cesar.school
Commits:
    - Primeira questão: 15:13 - 25/08
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
void decimalToBinary(int decimal){
    int binary[32];
    int i=0;
    printf("Convertendo %d para binario \n", decimal);
    while (decimal>0)
    {
        printf("Resto: %d \n", (decimal%2));
        binary[i]= decimal%2;
        i++;
        printf("Quociente: %d \n", (decimal/2));
        decimal=decimal/2;


    }
    printf ("A forma em binario:");
    for (int j = i-1; j >= 0; j--)
    {
        printf ("%d", binary[j]);
    }
    printf("\n");
    
    
    
};
void decimalToOctal(int decimal){
    int octal[32];
    int i=0;
    printf("Convertendo %d para octal \n", decimal);
    while (decimal>0)
    {
        printf("Resto: %d \n", (decimal%8));
        octal[i]= decimal%8;
        i++;
        printf("Quociente: %d \n", (decimal/8));
        decimal=decimal/8;


    }
    printf ("A forma em octal:");
    for (int j = i-1; j >= 0; j--)
    {
        printf ("%d", octal[j]);
    }
    printf("\n");
};
void decimalToHex(int decimal){
    char hex[32];
    int i=0;
    printf("Convertendo %d para hexadecimal \n", decimal);
    while (decimal>0)
    {
        printf("Resto: %d \n", (decimal%16));
        if ((decimal%16)<10)
        {
        hex[i]=48 + (decimal%16);
            
        }else{
            hex[i]=55+(decimal%16);
        }
        
        i++;
        printf("Quociente: %d \n", (decimal/16));
        decimal=decimal/16;


    }
    printf ("A forma em hexadecimal:");
    for (int j = i-1; j >= 0; j--)
    {
        printf ("%c", hex[j]);
    }
    printf("\n");
};
void decimalToBCD(int decimal){
    char bcd[64]="";
    printf("Convertendo %d para BCD \n", decimal);
    while (decimal>0)
    {
        int digito= decimal%10;
        printf("Digito: %d, BCD: ", digito);
        char tempbcd[5]="";
        for(int i = 3; i >= 0; i--) {
            printf("%d", (digito >> i) & 1);
            char bit = ((digito >> i) & 1)+'0';
            strncat(tempbcd,&bit,1);
        }
        char temp[64];
        strcpy(temp, bcd);
        strcpy(bcd,tempbcd);
        strcat(bcd,temp);
        
        
        printf("\n");
        decimal=decimal/10;
       


    }
    printf("Juntando as partes: %s\n", bcd);
  
};
void twosComplement(int decimal){};
void decimalToFloat(double decimal){};
void decimalToDouble(double decimal){};
int main(){
    int opcao, num;
    double realNum;

    printf("Calculadora Didatica\n");
    while (opcao!=10)
    {
    printf("Escolha uma operacao:\n");
    printf("1. Decimal para Binario\n");
    printf("2. Decimal para Octal\n");
    printf("3. Decimal para Hexadecimal\n");
    printf("4. Decimal para BCD\n");
    printf("5. Decimal para Complemento a 2\n");
    printf("6. Real para Float\n");
    printf("7. Real para Double\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Digite um numero decimal: ");
            scanf("%d", &num);
            decimalToBinary(num);
            break;
        case 2:
            printf("Digite um numero decimal: ");
            scanf("%d", &num);
            decimalToOctal(num);
            break;
        case 3:
            printf("Digite um numero decimal: ");
            scanf("%d", &num);
            decimalToHex(num);
            break;
        case 4:
            printf("Digite um numero decimal: ");
            scanf("%d", &num);
            decimalToBCD(num);
            break;
        case 5:
            printf("Digite um numero decimal: ");
            scanf("%d", &num);
            twosComplement(num);
            break;
        case 6:
            printf("Digite um numero real: ");
            scanf("%lf", &realNum);
            decimalToFloat(realNum);
            break;
        case 7:
            printf("Digite um numero real: ");
            scanf("%lf", &realNum);
            decimalToDouble(realNum);
            break;
    }
       
    }
    
    
}