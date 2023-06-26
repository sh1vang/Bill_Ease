#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//functions to generate bills
void generatebillheader(char name[50],char date[30]){
printf("\n\n");
printf("\t    ADV.Restaurant");
printf("\n\t   ------------------------");
printf("\ndate:%s",date);
printf("\nInvoice To: %s",name);
printf("\n");
printf("------------------------------------------\n");
printf("Iteam\t\t");
printf("Qty\t\t");
printf("Total\t\t");
printf("\n-----------------------------------------");
printf("\n\n");
}
void generatebillbody(char item[30],int qty,float price){
    printf("%s\t\t",item);
    printf("%d\t\t",qty);
    printf("%.2f\t\t",qty*price);
    printf("\n");
}
 
 struct items
 {
     char item[20];
     float price;
     int qty;
 };

 struct orders{
     char customer[50];
     char date[50];
     int numofitems;
     struct items itm[50];
 };
 


void generatebillfooter(float total){
    printf("\n");
    float dis=0.1*total;
    float nettotal=total-dis;
    float cgst=0.09*nettotal,grandtotal=nettotal + 2*cgst;
    printf("-------------------------------------------\n");
    printf("sub total \t\t\t%.2f",total);
    printf("\ndiscount @10%s\t\t\t.2f","%",dis);
    printf("\n\t\t\t\t--------");
    printf("\n net total \t\t\t%.2f",nettotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
     printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n-------------------------------------------");
    printf("\ngrand total\t\t\t%.2f",grandtotal);
    printf("\n----------------------------------------------\n");
}







int main (){
    int opt;
    int n;
    float total;
    struct orders ord;   // structure ko define kiya
    char savebill='y';
    FILE *fp;
    
    //dashboard
    printf("\t============KDI.RESTAURANT============");
    printf("\n\nplease select your prefered operation:\t ");
    printf("\n1.generate invoice");
    printf("\n2.show all invoice");
    printf("\n3.serch invoice");
    printf("\n4.exit");

    printf("\n\nYour choice:\t ");
    scanf("%d",&opt);
  //  printf("\n you have chosen %d",opt);
    fgetc(stdin);
    switch(opt){
        case 1: 
        printf("\nplease enter the name of the customer: \t");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1]=0;
        strcpy(ord.date,__DATE__);
        printf("\nplease enter the number of items:\t");
        scanf("%d",&n);
        ord.numofitems=n;

        for(int i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("please enter the item %d :\t",i+1);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("please enter the quantity:\t");
            scanf("%d",&ord.itm[i].qty);
            printf("please enter the unit price :\t");
            scanf("%f",&ord.itm[i].price);
            total+=ord.itm[i].qty * ord.itm[i].price;

        }

        generatebillheader(ord.customer,ord.date);
        for(int i=0;i<ord.numofitems;i++){
            generatebillbody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        }
        generatebillfooter(total);

        printf("\ndo you want to save the invoice:\t ");
        scanf("%s",&savebill);

        if(savebill=='y'){
            fp=fopen("restaurantbill.dat","a+");
            fwrite(&ord,sizeof(struct orders),1,fp);
            if(fwrite != 0)
            printf("\nsuccessfully saved ");
            else 
            printf("\nError saving ");
            fclose(fp);
        }
        break;

    }


    printf("\n\n");
    return 0;
}