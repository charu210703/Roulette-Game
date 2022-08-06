#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int spinning(int uprlimit);

int main(){
    int you = 0;
    int computer = 0;
    int i,op,result,res,jk,jkcomp,bety,betc,ch;
    char con,betop;
    char pos[10], winner[12], loser[12];
    printf("⁜-⁜-⁜                                ⁜-⁜-⁜\n");
    printf("⁜-⁜-⁜ Welcome To Our Roulette Game!!!⁜-⁜-⁜\n");
    printf("⁜-⁜-⁜                                ⁜-⁜-⁜\n");
    srand(i);
    do {
        printf("\nEnter the your bet amount:");
        scanf("%d",&bety);
        printf("Do you want computer to make random bet?(y/n)\n");
        scanf(" %c",&betop);
        if (betop == 'y'){
            do {
                betc =( rand() % 35) * 100;
            }while (betc == 0);
            printf("The computer has betted %d.\n", betc);
        }
        else{
            betc = bety;
        }
        printf("1. Jackpot\n2. Red or Black\n3. Odd or Even\n4. Low or High\nEnter the option:");
        scanf("%d",&op);
        if (op == 1){
            printf("Kindly Enter 100 for 00\n");
            printf("Enter the bet number:");
            scanf("%d",&jk);
            if (jk == 0){
                jk = 37;
            }
            if (jk == 100){
                jk == 38;
            }
            do{
                jkcomp = spinning(38);
            }while (jkcomp == jk);
            result = spinning(38);
            printf("The ball has landed on %d.\n",result);
            if (result == jk){
                you += 3500 + betc;
                computer -= betc;
            }
            else if (result == jkcomp){
                computer += 3500 + bety;
                you -= bety;
            }
            else{
                computer -= betc;
                you -= bety;
            }
            printf("Current amount of Computer:%d \nCurrent amount of player %d\n",computer,you);

        }
        if (op == 2){
            printf("1. Red\n2. Black\nEnter the option:");
            scanf("%d",&ch);
            result = spinning(2);
            if (result == 1){
                strcpy(pos,"Red");
            }
            else{
                strcpy(pos,"Black");
            }
            printf("The ball has landed on %s.\n",pos);

            if (result == ch){
                you += betc;
                computer -= betc;
            }
            else {
                computer += bety;
                you -= bety;
            }
            printf("Current amount of Computer:%d \nCurrent amount of player %d\n",computer,you);

        }
        if (op == 3){
            printf("1. Odd\n2. Even\nEnter the option:");
            scanf("%d",&ch);
            result = spinning(36);
            if (result % 2 == 0){
                res = 2;
            }
            else{
                res = 1;
            }
            if (res == 1){
                strcpy(pos,"Odd");
            }
            else{
                strcpy(pos,"Even");
            }
            printf("The ball has landed on %d which is a %s.\n",result,pos);

            if (res == ch){
                you += betc;
                computer -= betc;
            }
            else {
                computer += bety;
                you -= bety;
            }
            printf("Current amount of Computer:%d \nCurrent amount of player %d\n",computer,you);

        }
        if (op == 4){
            printf("1. Low\n2. High\nEnter the option:");
            scanf("%d",&ch);
            result = spinning(36);
            if (result <= 18){
                res = 1;
            }
            else{
                res = 2;
            }
            if (res == 1){
                strcpy(pos,"Low");
            }
            else{
                strcpy(pos,"High");
            }
            printf("The ball has landed on %d which is a %s.\n",result,pos);
            
            if (res == ch){
                you += betc;
                computer -= betc;
            }
            else {
                computer += bety;
                you -= bety;
            }
            printf("Current amount of Computer:%d \nCurrent amount of player %d\n",computer,you);
        }
        printf("Do you want to play again?(y/n)\n");
        scanf(" %c",&con);
        i++; 
    }while (con != 'n');
    if( computer == you){
        printf("(\\_/)\n");
        printf("(-.-)\n");
        printf("/> It's a tie!\n"); 
    }
    else{
        if (computer > you){
            strcpy(winner,"Computer");                
            strcpy(loser,"Player");
        }
        if (computer < you){
            strcpy(loser,"Computer");                
            strcpy(winner," Player ");
        }
        printf("  ⁜   (\\_/)                       ⁜\n");
        printf("⁜-⁜-⁜ (-.-)  Congratulations!!! ⁜-⁜-⁜\n");
        printf("  ⁜   /> The winner is %s!  ⁜\n",winner);
        printf("\n( -_-) Sorry, %s has lost. Better luck next time.\n",loser);
    }
    return 0;
}

int spinning(int uprlimit){
    int rand_num = rand() % uprlimit;
    return rand_num;
}