/*
Autor: Vnícius de Andrade Jordão
Email: Vaj@cesar.school
Commits:
    - Primeira questão: 15:13 - 25/08
    - Segunda questão: 17:11 - 25/08
    - Terceira questão: 17:54 - 25/08
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
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
void twosComplement(int decimal){
 int binary[16];
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

    for (int j = i; j < 16; j++) {
        binary[j] = 0;
    }

    printf ("A forma em binario:");
    for (int j = 15; j >= 0; j--)
    {
        printf ("%d", binary[j]);
    }
    printf("\n");

    printf("Para complemento a 2, mantenha o numero igual ate o primeiro um da direita para a esquerda, e dai em diante inverta todo o resto \n");
    int foundOne=0;
    for (int j = 0; j < 16; j++)
    {
        if (foundOne)
        {
            binary[j]=binary[j]==0?1:0;
            
        }else{
            if (binary[j]==1)
            {
                foundOne=1;
            }
        }
        
    }
    for (int j = 15; j >= 0; j--)
    {
        printf ("%d", binary[j]);
    }
    printf("\n");


};
void decimalToFloat(float decimal){
    unsigned int* bin = (unsigned int*)&decimal; 
    printf("Numero em float (32 bits) no formato IEEE 754:\n");
    int exponent = (*bin >> 23) & 0xFF;

   
    int bias = 127;
    int exponent_with_bias = exponent;
    printf("Vies: %d\n", bias);
    printf("Expoente com vies: %d\n", exponent_with_bias);
    printf("Sinal: %d\n", (*bin >> 31) & 1);
    printf("Parte inteira: ");
    for (int i = 30; i >= 23; i--) {
        printf("%d", (*bin >> i) & 1);
    }
    printf("\n");
    printf("Fraccao: ");
    for (int i = 22; i >= 0; i--) {
        printf("%d", (*bin >> i) & 1);
    }
    printf("\n");
};
void decimalToDouble(double decimal){
    uint64_t* bin = ( uint64_t*)&decimal; 
    printf("Numero em float (32 bits) no formato IEEE 754:\n");
    int exponent = (*bin >> 52) & 0x7FF;

   
    int bias = 1023;
    int exponent_with_bias = exponent;
    printf("Vies: %d\n", bias);
    printf("Expoente com vies: %d\n", exponent_with_bias);
    printf("Sinal: %d\n", (*bin >> 63) & 1);
    printf("Parte inteira: ");
    for (int i = 10; i >= 0; i--) {
        printf("%d", (exponent >> i) & 1);
    }
    printf("\n");
    printf("Fraccao: ");
    for (int i = 51; i >= 0; i--) {
        printf("%d", (*bin >> i) & 1);
    }
    printf("\n");
};
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