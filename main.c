#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
int cities=81;
struct city
{

    int plate;
    char city_name[30];
    char geographical_region[5];
    int neighbor_number;
    struct city *next;
    struct city*next2;
    struct city *prev;

};

struct neighbor
{
    int plate;
    int main_city;
    struct neighbor *next;

};

struct city *first=NULL,*last=NULL;
struct neighbor *n_first=NULL,*n_last=NULL;
struct city *temp;
struct neighbor *n_temp;


void Delete_CityLast()
{


    temp = first;
    if(first->next == NULL)
    {
        free(first);
        first= NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        struct city* delete_c = temp->next;
        free(delete_c);
        temp->next = NULL;
        last=temp;
    }



    cities--;





}


void Delete_CityFirst()
{


    struct city* temp2 = first;
    first= first->next;
    free(temp2);

    cities--;


}


void Delete_CityInter(int p)
{
    if(first->plate == p)
    {
        Delete_CityFirst();
    }
    else
    {
        temp = first;
        while(temp->next->plate != p)
        {
            temp = temp->next;
        }
        struct city *temp1 = temp->next->next;
        struct city *temp2 = temp;
        free(temp->next);
        temp2->next = temp1;
    }

    cities--;
}

void Delete_NeighborFirst()
{


    struct city* temp2 = n_first;
    n_first=n_first->next;
    free(temp2);




}




void Delete_NeighborLast(struct neighbor *delete_n)
{



    n_temp=n_first;

    while(n_temp->next->next!=NULL)
    {


        n_temp=n_temp->next;


    }

    struct neighbor *delete_n2=delete_n;
    free(delete_n2);
    n_temp->next=NULL;











}


void Delete_NeighborInter(struct neighbor *delete_n)
{
    struct neighbor *n1=n_first;


    while(n1->next!=delete_n)
    {

        n1=n1->next;


    }


    struct neighbor *temp1 = n1->next->next;
    struct neighbor *temp2 = n1;
    free(n1->next);
    temp2->next = temp1;





}


void Intercalation(struct city *before_node,int p,char *cn,char *gr,int nn)
{

    struct city* new_node=(struct city*) malloc(sizeof(struct city));

    new_node->plate = p;
    for(int i=0; i<30; i++)
    {
        new_node->city_name[i]=cn[i];

    }


    for(int i=0; i<5; i++)
    {
        new_node->geographical_region[i]=gr[i];

    }
    new_node->neighbor_number=nn;

    new_node->next = before_node->next;
    before_node->next = new_node;


}

void Intercalation_Neighbor(struct neighbor *before_node,int p)
{

    struct neighbor* new_node=(struct neighbor*) malloc(sizeof(struct neighbor));

    new_node->plate = p;

    new_node->next = before_node->next;
    before_node->next = new_node;


}


void Add_MainStart(int plate,int main_city)
{

    struct neighbor *new_node = (struct neighbor*) malloc(sizeof(struct neighbor));

    new_node->plate=plate;
    new_node->main_city=main_city;



    if(n_first==NULL)
    {
        n_first=new_node;
        n_last=new_node;
        n_last->next=NULL;
    }
    else
    {
        new_node->next=n_first;
        n_first=new_node;
    }



}

void Add_MainLast(int plate,int main_city)
{

    struct neighbor *new_node = (struct neighbor*) malloc(sizeof(struct neighbor));


    new_node->plate=plate;
    new_node->main_city=main_city;



    if(n_first==NULL)
    {
        n_first=new_node;
        n_last=new_node;
        n_last->next=NULL;
    }
    else
    {
        n_last->next=new_node;
        n_last=new_node;
        n_last->next=NULL;


    }



}


void Add_NeighborStart(int plate)
{

    struct neighbor *new_node = (struct neighbor*) malloc(sizeof(struct neighbor));

    new_node->plate=plate;



    if(n_first==NULL)
    {
        n_first=new_node;
        n_last=new_node;
        n_last->next=NULL;
    }
    else
    {
        new_node->next=n_first;
        n_first=new_node;
    }





}


void Add_NeighborLast(int plate[10])
{


    struct neighbor *new_node = (struct neighbor*) malloc(sizeof(struct neighbor));


    new_node->plate=plate;



    if(n_first==NULL)
    {
        n_first=new_node;
        n_last=new_node;
        n_last->next=NULL;
    }
    else
    {
        n_last->next=new_node;
        n_last=new_node;
        n_last->next=NULL;


    }




}




void Add_Start(int p,char *cn,char *gr,int nn)
{
    struct city *new_node = (struct city*) malloc(sizeof(struct city));
    new_node->plate=p;




    for(int i=0; i<30; i++)
    {
        new_node->city_name[i]=cn[i];

    }


    for(int i=0; i<5; i++)
    {
        new_node->geographical_region[i]=gr[i];

    }
    new_node->neighbor_number=nn;



    if(first==NULL)
    {
        first=new_node;
        last=new_node;
        last->next=NULL;
    }
    else
    {
        new_node->next=first;
        first=new_node;
    }
}
void Add_Last(int p,char *cn,char *gr,int nn)
{
    struct city *new_node = (struct city*) malloc(sizeof(struct city));

    new_node->plate=p;


    for(int i=0; i<30; i++)
    {
        new_node->city_name[i]=cn[i];

    }




    for(int i=0; i<5; i++)
    {
        new_node->geographical_region[i]=gr[i];


    }
    new_node->neighbor_number=nn;
    if(first==NULL)
    {
        first=new_node;
        last=new_node;
        last->next=NULL;

    }
    else
    {
        last->next=new_node;
        last=new_node;
        last->next=NULL;


    }



}


void List()
{
    struct city *list=first;
    while(list!=NULL)
    {
        printf("%d  %s  %s  %d",list->plate,list->city_name,list->geographical_region,list->neighbor_number);
        list=list->next;
        printf("\n");

    }
    printf("\n");
}

void N_List()
{
    struct neighbor *list=n_first;
    while(list!=NULL)
    {
        printf("%d ",list->plate);
        list=list->next;


    }

}







int main()
{

    FILE * file;
    char buf[100];
    int plate;
    int plate1[10];
    int control=1;
    int control1=1;
    int n_control=1;
    char city_name[30];
    char city_name1[30];
    char city_name2[30];
    char neighbor_name[30];
    char neighbor_name1[30];
    char region_name[5];
    int neighbor=0;
    int neighbor1=0;
    int x=0;


    if ((file = fopen("C:\\Users\\Berkay\\Desktop\\sehirler.txt", "r")) == NULL)
    {
        printf("dosya acilamadi!\n");
        exit(1);
    }






    fgets(buf,100,file);
    char *data = strtok(buf,",,,,,,,");
    plate =atoi(data);
    neighbor++;

    while (data != NULL)
    {

        data= strtok (NULL, " ,.- ");

        if(control==1)
        {
            for(int i=0; i<30; i++)
            {

                city_name[i]=data[i];
                city_name1[i]=city_name[i];


            }



        }



        if(control==2)
        {
            for(int i=0; i<15; i++)
            {

                region_name[i]=data[i];


            }



        }

        control++;
        neighbor++;


    }




    Add_Start(plate,city_name,region_name,(neighbor-4));




    for(int j=0; j<80; j++)
    {

        fgets(buf,100,file);
        char *data = strtok(buf,",,,,,,,");
        plate =atoi(data);
        neighbor1++;


        while (data != NULL)
        {

            data= strtok (NULL, " ,.- ");


            if(control1==1)
            {
                for(int i=0; i<30; i++)
                {

                    city_name[i]=data[i];
                    city_name2[i]=city_name[i];


                }




            }



            if(control1==2)
            {
                for(int i=0; i<15; i++)
                {

                    region_name[i]=data[i];




                }




            }

            control1++;
            neighbor1++;


        }


        Add_Last(plate,city_name,region_name,(neighbor1-4));
        control1=1;
        neighbor1=0;



    }



    //List();

    fclose(file);



    if ((file = fopen("C:\\Users\\Berkay\\Desktop\\sehirler.txt", "r")) == NULL)
    {
        printf("dosya acilamadi!\n");
        exit(1);
    }

    int nb_n;
    int nb_control=0;
    int plate_pl[10];
    for(int j=0; j<81; j++)
    {

        fgets(buf,100,file);
        char *data = strtok(buf,", \n");
        plate =atoi(data);


        if(plate==1)
        {
            Add_MainStart(plate,plate);
        }
        else
        {

            Add_MainLast(plate,plate);


        }

        struct city *nb=first;
        while(nb!=NULL)
        {

            if(nb->plate==plate)
            {

                nb_n=nb->neighbor_number;


            }

            nb=nb->next;

        }

        nb=first;



        while (data !=NULL)
        {

            data = strtok (NULL, ", \n");

            //printf("%d ",n_control);
            if(n_control==3)
            {
                struct city *list=first;

                while(list!=NULL)
                {


                    if(strcmp(data,list->city_name)==0)
                    {

                        // printf("%s",data);
                        Add_NeighborLast(list->plate);
                        //printf("%d\n",list->plate);

                        nb_control++;


                    }

                    list=list->next;

                }




            }





            if(n_control==4)
            {
                struct city *list=first;

                while(list!=NULL)
                {

                    if(strcmp(data,list->city_name)==0)
                    {


                        Add_NeighborLast(list->plate);
                        //printf("%s",data);
                        //printf("%d\n",list->plate);

                        nb_control++;



                    }

                    list=list->next;

                }



            }



            if(n_control==5)
            {
                struct city *list=first;

                while(list!=NULL)
                {

                    if(strcmp(data,list->city_name)==0)
                    {


                        Add_NeighborLast(list->plate);
                        // printf("%s",data);
                        //printf("%d\n",list->plate);

                        nb_control++;

                    }

                    list=list->next;

                }



            }

            if(n_control==6)
            {
                struct city *list=first;
                while(list!=NULL)
                {

                    if(strcmp(data,list->city_name)==0)
                    {


                        Add_NeighborLast(list->plate);
                        //printf("%s",data);
                        //printf("%d\n",list->plate);

                        nb_control++;


                    }

                    list=list->next;

                }



            }

            if(n_control==7)
            {
                struct city *list=first;

                while(list!=NULL)
                {

                    if(strcmp(data,list->city_name)==0)
                    {


                        Add_NeighborLast(list->plate);
                        // printf("%s",data);
                        //printf("%d\n",list->plate);

                        nb_control++;




                    }

                    list=list->next;

                }



            }
            if(n_control==8)
            {

                struct city *list=first;

                while(list!=NULL)
                {




                    if(strcmp(data,list->city_name)==0)
                    {

                        Add_NeighborLast(list->plate);
                        //printf("%s",data);
                        //printf("%d\n",list->plate);

                        nb_control++;



                    }


                    list=list->next;
                }

            }





            if(n_control==9)
            {

                struct city *list=first;
                while(list!=NULL)
                {

                    if(strcmp(data,list->city_name)==0)
                    {


                        Add_NeighborLast(list->plate);
                        //printf("%s",data);
                        //printf("%d\n",list->plate);

                        nb_control++;


                    }

                    list=list->next;

                }



            }


            if(n_control==10)
            {
                struct city *list=first;

                while(list!=NULL)
                {

                    if(strcmp(data,list->city_name)==0)
                    {


                        Add_NeighborLast(list->plate);
                        //printf("%s",data);
                        //printf("%d\n",list->plate);

                        nb_control++;


                    }

                    list=list->next;

                }



            }

            if(n_control==11)
            {
                struct city *list=first;

                while(list!=NULL)
                {

                    if(strcmp(data,list->city_name)==0)
                    {


                        Add_NeighborLast(list->plate);
                        //printf("%s",data);
                        //printf("%d\n",list->plate);

                        nb_control++;


                    }

                    list=list->next;

                }



            }

            if(n_control==12)
            {
                struct city *list=first;

                while(list!=NULL)
                {

                    if(strcmp(data,list->city_name)==0)
                    {


                        Add_NeighborLast(list->plate);
                        //printf("%s",data);
                        //printf("%d\n",list->plate);

                        nb_control++;


                    }

                    list=list->next;

                }



            }



            n_control++;
            //printf("%d\n",nb_n);
            //printf("%d\n",nb_control);
            if(nb_n==nb_control)
            {

                break;

            }


        }




        n_control=1;
        nb_control=0;


    }


    FILE *cikti=fopen("output.txt","w");
    if(cikti==NULL){

        printf("Dosya acilamadi.\n");
        exit(1);

    }









    struct city *diagram=first;
    struct neighbor *diagram1=n_first;
    int diagram_plate[15];

    while(diagram!=NULL)
    {

        if(diagram1->plate==diagram1->main_city)
        {


            for(int w=0; w<diagram->neighbor_number; w++)
            {

                diagram1=diagram1->next;
                diagram_plate[w]=diagram1->plate;
               // printf("%d ",diagram_plate[w]);



            }


        }



        int temp;
        int k, l;

        for (k=1; k<diagram->neighbor_number; k++)
        {
            for (l=0; l<diagram->neighbor_number-k; l++)
            {
                if(diagram_plate[l] > diagram_plate[l+1])
                {
                    temp = diagram_plate[l];
                    diagram_plate [l] = diagram_plate[l+1];
                    diagram_plate[l+1] = temp;
                }
            }
        }


        //printf("%d %s %s %d-> ",diagram->plate,diagram->city_name,diagram->geographical_region,diagram->neighbor_number);
        fprintf(cikti,"%d %s %s %d-> ",diagram->plate,diagram->city_name,diagram->geographical_region,diagram->neighbor_number);




        for(int w=0; w<diagram->neighbor_number; w++)
        {



            if(w==diagram->neighbor_number-1)
            {

                //printf("%d",diagram_plate[w]);
                fprintf(cikti,"%d",diagram_plate[w]);

            }else {//printf("%d-> ",diagram_plate[w]);
                 fprintf(cikti,"%d-> ",diagram_plate[w]);}


        }//printf("\n");
         fprintf(cikti,"\n");
         //printf("|\n");
         fprintf(cikti,"|\n");

         //printf("v\n");
         fprintf(cikti,"v\n");


        diagram=diagram->next;
        diagram1=diagram1->next;


    }

    fclose(cikti);



    // N_List();


    for(int l=0; l<50; l++)
    {

        int secim;
        cikti=fopen("output.txt","a");

        printf("1-Yeni Bir Sehir Veya Yeni Bir Komsuluk Eklemek\n");
        fprintf(cikti,"1-Yeni Bir Sehir Veya Yeni Bir Komsuluk Eklemek\n");
        printf("2-Plaka Kodu Veya Sehir Ismi Ile Sehir Bilgisi Almak\n");
        fprintf(cikti,"2-Plaka Kodu Veya Sehir Ismi Ile Sehir Bilgisi Almak\n");
        printf("3-Sehir Veya Komsuluk Kaydi Silmek\n");
        fprintf(cikti,"3-Sehir Veya Komsuluk Kaydi Silmek\n");
        printf("4-Ayni Bolgede Bulunan Sehilerin Bilgilerini Goruntuleme\n");
        fprintf(cikti,"4-Ayni Bolgede Bulunan Sehilerin Bilgilerini Goruntuleme\n");
        printf("5-Komsu Sayilarina Gore Sehir Bilgileri\n");
        fprintf(cikti,"5-Komsu Sayilarina Gore Sehir Bilgileri\n");
        printf("6-Cikis\n");
        fprintf(cikti,"6-Cikis\n");
        printf("*************************************************************\n");
        fprintf(cikti,"*************************************************************\n");
        printf("Yapmak Istediginiz Islemi Seciniz:");
        fprintf(cikti,"Yapmak Istediginiz Islemi Seciniz:");
        scanf("%d",&secim);
        fprintf(cikti,"%d\n",secim);
        fclose(cikti);

        if(secim==1)
        {
            cikti=fopen("output.txt","a");
            int choose;
            printf("Sehir Eklemek Icin 1'e Basin\n");
            fprintf(cikti,"Sehir Eklemek Icin 1'e Basin\n");
            printf("Komsuluk Eklemek Icin 2'ye Basin\n");
            fprintf(cikti,"Komsuluk Eklemek Icin 2'ye Basin\n");
            printf("Secim:");
            fprintf(cikti,"Secim:");
            scanf("%d",&choose);
            fprintf(cikti,"%d\n",choose);
            if(choose==1)
            {
                struct city *add_first=first;
                struct city *add_last=last;
                int add_plate;
                printf("Eklemek Istediginiz Plakayi Giriniz:");
                fprintf(cikti,"Eklemek Istediginiz Plakayi Giriniz:");
                scanf("%d",&add_plate);
                fprintf(cikti,"%d\n",add_plate);
                if(add_first->plate<add_plate&&add_last->plate>add_plate)
                {

                    printf("Ayni Ozellige Sahip Sehirler Ekleyemezsiniz\n");
                    fprintf(cikti,"Ayni Ozellige Sahip Sehirler Ekleyemezsiniz\n");
                    break;


                }

                if(add_first->plate>add_plate)
                {
                    char add_cityname[30];
                    char add_region[30];
                    int add_neighbor;
                    int n_plate[10];

                    printf("Ekleyeceginiz Sehrin Ismini Giriniz:");
                    fprintf(cikti,"Ekleyeceginiz Sehrin Ismini Giriniz:");
                    scanf("%s",&add_cityname);
                    fprintf(cikti,"%s\n",add_cityname);
                    printf("Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                    fprintf(cikti,"Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:\n");
                    scanf("%s",&add_region);
                    fprintf(cikti,"%s\n",add_region);
                    printf("Kac Adet Komsusu Vardir:");
                    fprintf(cikti,"Kac Adet Komsusu Vardir:\n");
                    scanf("%d",&add_neighbor);
                    fprintf(cikti,"%d\n",add_neighbor);
                    for(int i=0; i<add_neighbor; i++)
                    {

                        printf("Komsu Sehrin Plakasini Giriniz:");
                        fprintf(cikti,"Komsu Sehrin Plakasini Giriniz:");
                        scanf("%d",&n_plate[i]);
                        fprintf(cikti,"%d\n",n_plate[i]);
                        int a=n_plate[i];
                        Add_NeighborStart(a);


                    }

                    Add_Start(add_plate,add_cityname,add_region,add_neighbor);
                    Add_MainStart(add_plate,add_plate);
                    printf("Sehir Listeye Eklenmistir......\n");
                    fprintf(cikti,"Sehir Listeye Eklenmistir......\n");
                    cities++;





                }
                if(add_last->plate<add_plate)
                {

                    char add_cityname[30];
                    char add_region[30];
                    int add_neighbor;
                    int n_plate[10];

                    printf("Ekleyeceginiz Sehrin Ismini Giriniz:");
                    fprintf(cikti,"Ekleyeceginiz Sehrin Ismini Giriniz:");
                    scanf("%s",&add_cityname);
                    fprintf(cikti,"%s\n",add_cityname);
                    printf("Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                    fprintf(cikti,"Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                    scanf("%s",&add_region);
                    fprintf(cikti,"%s\n",add_region);
                    printf("Kac Adet Komsusu Vardir:");
                    fprintf(cikti,"Kac Adet Komsusu Vardir:");
                    scanf("%d",&add_neighbor);
                    fprintf(cikti,"%d\n",add_neighbor);
                    Add_MainLast(add_plate,add_plate);
                    for(int i=0; i<add_neighbor; i++)
                    {

                        printf("Komsu Sehrin Plakasini Giriniz:");
                        fprintf(cikti,"Komsu Sehrin Plakasini Giriniz:");
                        scanf("%d",&n_plate[i]);
                        fprintf(cikti,"%d\n",n_plate[i]);
                        int a=n_plate[i];
                        Add_NeighborLast(a);


                    }



                    Add_Last(add_plate,add_cityname,add_region,add_neighbor);
                    cities++;
                    printf("Sehir Listeye Eklenmistir......\n");
                    fprintf(cikti,"Sehir Listeye Eklenmistir......\n");




                }

                if(add_first->plate<add_plate&&add_last->plate>add_plate)
                {

                    char add_cityname[30];
                    char add_region[30];
                    int add_neighbor;
                    int n_plate[10];
                    struct city *list1=first;

                    printf("Ekleyeceginiz Sehrin Ismini Giriniz:");
                    fprintf(cikti,"Ekleyeceginiz Sehrin Ismini Giriniz:");
                    scanf("%s",&add_cityname);
                    fprintf(cikti,"%s\n",add_cityname);
                    printf("Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                    fprintf(cikti,"Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                    scanf("%s",&add_region);
                    fprintf(cikti,"%s\n",add_region);
                    printf("Kac Adet Komsusu Vardir:");
                    fprintf(cikti,"Kac Adet Komsusu Vardir:");
                    scanf("%d",&add_neighbor);
                    fprintf(cikti,"%d\n",add_neighbor);

                    while(list1!=NULL)
                    {

                        if(list1->plate==add_plate-1)

                        {
                            Intercalation(list1,add_plate,add_cityname,add_region,add_neighbor);
                            cities++;
                            break;


                        }


                        list1=list1->next;


                    }
                    Add_MainLast(add_plate,add_plate);
                    for(int i=0; i<add_neighbor; i++)
                    {

                        printf("Komsu Sehrin Plakasini Giriniz:");
                        fprintf(cikti,"Komsu Sehrin Plakasini Giriniz:");
                        scanf("%d",&n_plate[i]);
                        fprintf(cikti,"%d\n",n_plate[i]);
                        int a=n_plate[i];
                        Add_NeighborLast(a);


                    }

                    printf("Sehir Listeye Eklenmistir......\n");
                    fprintf(cikti,"Sehir Listeye Eklenmistir......\n");




                }



            }

            if(choose==2)
            {

                int add_plate;
                int number;
                int new_plate;
                struct neighbor *add=n_first;
                struct city *plus_n=first;
                printf("Komsu Ekleyeceginiz Ilin Plakasini Giriniz:");
                fprintf(cikti,"Komsu Ekleyeceginiz Ilin Plakasini Giriniz:");
                scanf("%d",&add_plate);
                fprintf(cikti,"%d\n",add_plate);
                printf("Kac Adet Komsu Ekleyeceksiniz:");
                fprintf(cikti,"Kac Adet Komsu Ekleyeceksiniz:");
                scanf("%d",&number);
                fprintf(cikti,"%d\n",number);

                while(add!=NULL)
                {

                    if(add->plate==add_plate&&add->main_city==add_plate)
                    {

                        for(int i=0; i<number; i++)
                        {

                            printf("Eklenecek Komsu Sehrin Plakasini Giriniz:");
                            fprintf(cikti,"Eklenecek Komsu Sehrin Plakasini Giriniz:");
                            scanf("%d",&new_plate);
                            fprintf(cikti,"%d\n",new_plate);

                            Intercalation_Neighbor(add,new_plate);




                        }


                    }

                    add=add->next;

                }
                while(plus_n!=NULL)
                {

                    if(plus_n->plate==add_plate)
                    {


                        plus_n->neighbor_number=plus_n->neighbor_number+number;



                    }

                    plus_n=plus_n->next;



                }

                printf("Yeni Komsular Eklenmistir\n");
                fprintf(cikti,"Yeni Komsular Eklenmistir\n");




            }


           fclose(cikti);

        }

        if(secim==2)
        {
            cikti=fopen("output.txt","a");
            int choose_plate;
            char choose_city[30];
            int choose;
            printf("Plaka Ile Bilgi Almak Icin 1'e Basin\n");
            fprintf(cikti,"Plaka Ile Bilgi Almak Icin 1'e Basin\n");
            printf("Sehir Ismi Ile Bilgi ALmak Icin 2'ye Basin\n");
            fprintf(cikti,"Sehir Ismi Ile Bilgi ALmak Icin 2'ye Basin\n");
            printf("*************************************************************\n");
            fprintf(cikti,"*************************************************************\n");
            printf("Yapmak Istediginiz Islemi Seciniz:");
            fprintf(cikti,"Yapmak Istediginiz Islemi Seciniz:");
            scanf("%d",&choose);
            fprintf(cikti,"%d\n",choose);

            if(choose==1)
            {

                struct city *list=first;
                struct neighbor *n_list=n_first;
                int control_plate=0;
                int neighbor_control;
                int neigborn_control;
                int neighbor_plate[10];

                printf("Bilgi Almak Istediginiz Sehrin Plakasini Giriniz:");
                fprintf(cikti,"Bilgi Almak Istediginiz Sehrin Plakasini Giriniz:");
                scanf("%d",&choose_plate);
                fprintf(cikti,"%d\n",choose_plate);

                while(list!=NULL)
                {

                    if(list->plate==choose_plate)
                    {

                        printf("%s %s %d\n",list->city_name,list->geographical_region,list->neighbor_number);
                        fprintf(cikti,"%s %s %d\n",list->city_name,list->geographical_region,list->neighbor_number);
                        control_plate++;
                        neighbor_control=list->plate;
                        neigborn_control=list->neighbor_number;



                    }


                    list=list->next;

                }

                while(n_list!=NULL)
                {


                    if(n_list->plate==neighbor_control&&n_list->main_city==neighbor_control)
                    {


                        for (int i=0; i<neigborn_control; i++)
                        {



                            n_list=n_list->next;
                            neighbor_plate[i]=n_list->plate;



                        }





                    }

                    n_list=n_list->next;

                }




                if(control_plate==0)
                {
                    int add_choose;

                    printf("Aradiginiz Sehir Bulunamamistir Listeye Eklemek Ister Misiniz?...\n");
                    fprintf(cikti,"Aradiginiz Sehir Bulunamamistir Listeye Eklemek Ister Misiniz?...\n");
                    printf ("1-Evet\n");
                    fprintf (cikti,"1-Evet\n");
                    printf("2-Hayir\n");
                    fprintf(cikti,"2-Hayir\n");
                    printf("Secim:");
                    fprintf(cikti,"Secim:");
                    scanf("%d",&add_choose);
                    fprintf(cikti,"%d\n",add_choose);

                    if(add_choose==1)
                    {
                        struct city *add_first=first;
                        struct city *add_last=last;
                        int add_plate;
                        printf("Eklemek Istediginiz Plakayi Giriniz:");
                        fprintf(cikti,"Eklemek Istediginiz Plakayi Giriniz:");
                        scanf("%d",&add_plate);
                        fprintf(cikti,"%d\n",add_plate);

                        if(add_first->plate>add_plate)
                        {
                            char add_cityname[30];
                            char add_region[30];
                            int add_neighbor;
                            int n_plate[10];

                            printf("Ekleyeceginiz Sehrin Ismini Giriniz:");
                            fprintf(cikti,"Ekleyeceginiz Sehrin Ismini Giriniz:");
                            scanf("%s",&add_cityname);
                            fprintf(cikti,"%s\n",add_cityname);
                            printf("Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            fprintf(cikti,"Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            scanf("%s",&add_region);
                            fprintf(cikti,"%s\n",add_region);
                            printf("Kac Adet Komsusu Vardir:");
                            fprintf(cikti,"Kac Adet Komsusu Vardir:");
                            scanf("%d",&add_neighbor);
                            fprintf(cikti,"%d\n",add_neighbor);
                            for(int i=0; i<add_neighbor; i++)
                            {

                                printf("Komsu Sehrin Plakasini Giriniz:");
                                fprintf(cikti,"Komsu Sehrin Plakasini Giriniz:");
                                scanf("%d",&n_plate[i]);
                                fprintf(cikti,"%d\n",n_plate[i]);
                                int a=n_plate[i];
                                Add_NeighborStart(a);


                            }

                            Add_Start(add_plate,add_cityname,add_region,add_neighbor);
                            Add_MainStart(add_plate,add_plate);
                            printf("Sehir Listeye Eklenmistir......\n");
                            fprintf(cikti,"Sehir Listeye Eklenmistir......\n");
                            cities++;





                        }

                        if(add_last->plate<add_plate)
                        {


                            char add_cityname[30];
                            char add_region[30];
                            int add_neighbor;
                            int n_plate[10];

                            printf("Ekleyeceginiz Sehrin Ismini Giriniz:");
                            fprintf(cikti,"Ekleyeceginiz Sehrin Ismini Giriniz:");
                            scanf("%s",&add_cityname);
                            fprintf(cikti,"%s\n",add_cityname);
                            printf("Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            fprintf(cikti,"Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            scanf("%s",&add_region);
                            fprintf(cikti,"%s\n",add_region);
                            printf("Kac Adet Komsusu Vardir:");
                            fprintf(cikti,"Kac Adet Komsusu Vardir:");
                            scanf("%d",&add_neighbor);
                            fprintf(cikti,"%d\n",add_neighbor);
                            Add_MainLast(add_plate,add_plate);
                            for(int i=0; i<add_neighbor; i++)
                            {

                                printf("Komsu Sehrin Plakasini Giriniz:");
                                fprintf(cikti,"Komsu Sehrin Plakasini Giriniz:");
                                scanf("%d",&n_plate[i]);
                                fprintf(cikti,"%d\n",n_plate[i]);
                                int a=n_plate[i];
                                Add_NeighborLast(a);


                            }



                            Add_Last(add_plate,add_cityname,add_region,add_neighbor);
                            cities++;
                            printf("Sehir Listeye Eklenmistir......\n");
                            fprintf(cikti,"Sehir Listeye Eklenmistir......\n");






                        }
                        if(add_first->plate<add_plate&&add_last->plate>add_plate)
                        {

                            char add_cityname[30];
                            char add_region[30];
                            int add_neighbor;
                            int n_plate[10];
                            struct city *list1=first;

                            printf("Ekleyeceginiz Sehrin Ismini Giriniz:");
                            fprintf(cikti,"Ekleyeceginiz Sehrin Ismini Giriniz:");
                            scanf("%s",&add_cityname);
                            fprintf(cikti,"%s\n",add_cityname);
                            printf("Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            fprintf(cikti,"Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            scanf("%s",&add_region);
                            fprintf(cikti,"%s\n",add_region);
                            printf("Kac Adet Komsusu Vardir:");
                            fprintf(cikti,"Kac Adet Komsusu Vardir:");
                            scanf("%d",&add_neighbor);
                            fprintf(cikti,"%d\n",add_neighbor);
                            while(list1!=NULL)
                            {

                                if(list1->plate==add_plate-1)

                                {
                                    Intercalation(list1,add_plate,add_cityname,add_region,add_neighbor);
                                    cities++;
                                    break;


                                }


                                list1=list1->next;


                            }
                            Add_MainLast(add_plate,add_plate);
                            for(int i=0; i<add_neighbor; i++)
                            {

                                printf("Komsu Sehrin Plakasini Giriniz:");
                                fprintf(cikti,"Komsu Sehrin Plakasini Giriniz:");
                                scanf("%d",&n_plate[i]);
                                fprintf(cikti,"%d\n",n_plate[i]);
                                int a=n_plate[i];
                                Add_NeighborLast(a);


                            }

                            printf("Sehir Listeye Eklenmistir......\n");
                            fprintf(cikti,"Sehir Listeye Eklenmistir......\n");




                        }


                    }



                }
                else
                {


                    int temp;
                    int k, l;

                    for (k=1; k<neigborn_control; k++)
                    {
                        for (l=0; l<neigborn_control-k; l++)
                        {
                            if(neighbor_plate[l] > neighbor_plate[l+1])
                            {
                                temp = neighbor_plate[l];
                                neighbor_plate [l] = neighbor_plate[l+1];
                                neighbor_plate[l+1] = temp;
                            }
                        }
                    }



                    struct city *list1=first;
                    printf("Komsular:\n");
                    fprintf(cikti,"Komsular:\n");

                    while(list1!=NULL)
                    {
                        if(list1->plate==neighbor_plate[0])
                        {
                            printf("%d- %s %s %d\n",list1->plate,list1->city_name,list1->geographical_region,list1->neighbor_number);
                            fprintf(cikti,"%d- %s %s %d\n",list1->plate,list1->city_name,list1->geographical_region,list1->neighbor_number);

                        }
                        for(int q=1; q<cities; q++)
                        {
                            list1=list1->next;
                            for(int w=0; w<neigborn_control; w++)
                            {

                                if(neighbor_plate[w]==list1->plate)
                                {

                                    printf("%d- %s %s %d\n",list1->plate,list1->city_name,list1->geographical_region,list1->neighbor_number);
                                    fprintf(cikti,"%d- %s %s %d\n",list1->plate,list1->city_name,list1->geographical_region,list1->neighbor_number);



                                }




                            }





                        }


                        list1=list1->next;



                    }



                }

            }

            if(choose==2)
            {

                struct city *list=first;
                struct neighbor *n_list=n_first;
                int control_plate=0;
                int neighbor_control;
                int neigborn_control;
                int neighbor_plate[10];

                int control_city=0;

                printf("Bilgi Almak Istediginiz Sehrin Adini Giriniz:");
                fprintf(cikti,"Bilgi Almak Istediginiz Sehrin Adini Giriniz:");
                scanf("%s",&choose_city);
                fprintf(cikti,"%s\n",choose_city);


                while(list!=NULL)
                {

                    if(strcmp(list->city_name,choose_city)==0)
                    {

                        printf("%s %s %d\n",list->city_name,list->geographical_region,list->neighbor_number);
                        fprintf(cikti,"%s %s %d\n",list->city_name,list->geographical_region,list->neighbor_number);
                        control_city++;
                        neighbor_control=list->plate;
                        neigborn_control=list->neighbor_number;


                    }


                    list=list->next;

                }

                while(n_list!=NULL)
                {


                    if(n_list->plate==neighbor_control&&n_list->main_city==neighbor_control)
                    {


                        for (int i=0; i<neigborn_control; i++)
                        {

                            n_list=n_list->next;
                            neighbor_plate[i]=n_list->plate;



                        }





                    }

                    n_list=n_list->next;

                }




                if(control_city==0)
                {


                    int add_choose;

                    printf("Aradiginiz Sehir Bulunamamistir Listeye Eklemek Ister Misiniz?...\n");
                    fprintf(cikti,"Aradiginiz Sehir Bulunamamistir Listeye Eklemek Ister Misiniz?...\n");
                    printf ("1-Evet\n");
                    fprintf (cikti,"1-Evet\n");
                    printf("2-Hayir\n");
                    fprintf(cikti,"2-Hayir\n");
                    printf("Secim:");
                    fprintf(cikti,"Secim:");
                    scanf("%d",&add_choose);
                    fprintf(cikti,"%d\n",add_choose);

                    if(add_choose==1)
                    {
                        struct city *add_first=first;
                        struct city *add_last=last;
                        int add_plate;
                        printf("Eklemek Istediginiz Plakayi Giriniz:");
                        fprintf(cikti,"Eklemek Istediginiz Plakayi Giriniz:");
                        scanf("%d",&add_plate);
                        fprintf(cikti,"%d\n",add_plate);

                        if(add_first->plate>add_plate)
                        {
                            char add_cityname[30];
                            char add_region[30];
                            int add_neighbor;
                            int n_plate[10];

                            printf("Ekleyeceginiz Sehrin Ismini Giriniz:");
                            fprintf(cikti,"Ekleyeceginiz Sehrin Ismini Giriniz:");
                            scanf("%s",&add_cityname);
                            fprintf(cikti,"%s\n",add_cityname);
                            printf("Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            fprintf(cikti,"Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            scanf("%s",&add_region);
                            fprintf(cikti,"%s\n",add_region);
                            printf("Kac Adet Komsusu Vardir:");
                            fprintf(cikti,"Kac Adet Komsusu Vardir:");
                            scanf("%d",&add_neighbor);
                            fprintf(cikti,"%d\n",add_neighbor);
                            for(int i=0; i<add_neighbor; i++)
                            {

                                printf("Komsu Sehrin Plakasini Giriniz:");
                                fprintf(cikti,"Komsu Sehrin Plakasini Giriniz:");
                                scanf("%d",&n_plate[i]);
                                fprintf(cikti,"%d\n",n_plate[i]);

                                int a=n_plate[i];
                                Add_NeighborStart(a);


                            }

                            Add_Start(add_plate,add_cityname,add_region,add_neighbor);
                            Add_MainStart(add_plate,add_plate);
                            printf("Sehir Listeye Eklenmistir......\n");
                            fprintf(cikti,"Sehir Listeye Eklenmistir......\n");
                            cities++;





                        }

                        if(add_last->plate<add_plate)
                        {


                            char add_cityname[30];
                            char add_region[30];
                            int add_neighbor;
                            int n_plate[10];

                            printf("Ekleyeceginiz Sehrin Ismini Giriniz:");
                            fprintf(cikti,"Ekleyeceginiz Sehrin Ismini Giriniz:");
                            scanf("%s",&add_cityname);
                            fprintf(cikti,"%s\n",add_cityname);
                            printf("Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            fprintf(cikti,"Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            scanf("%s",&add_region);
                            fprintf(cikti,"%s\n",add_region);
                            printf("Kac Adet Komsusu Vardir:");
                            fprintf(cikti,"Kac Adet Komsusu Vardir:");
                            scanf("%d",&add_neighbor);
                            fprintf(cikti,"%d\n",add_neighbor);
                            Add_MainLast(add_plate,add_plate);
                            for(int i=0; i<add_neighbor; i++)
                            {

                                printf("Komsu Sehrin Plakasini Giriniz:");
                                fprintf(cikti,"Komsu Sehrin Plakasini Giriniz:");
                                scanf("%d",&n_plate[i]);
                                fprintf(cikti,"%d\n",n_plate[i]);
                                int a=n_plate[i];
                                Add_NeighborLast(a);


                            }



                            Add_Last(add_plate,add_cityname,add_region,add_neighbor);
                            cities++;
                            printf("Sehir Listeye Eklenmistir......\n");
                            fprintf(cikti,"Sehir Listeye Eklenmistir......\n");






                        }
                        if(add_first->plate<add_plate&&add_last->plate>add_plate)
                        {

                            char add_cityname[30];
                            char add_region[30];
                            int add_neighbor;
                            int n_plate[10];
                            struct city *list1=first;

                            printf("Ekleyeceginiz Sehrin Ismini Giriniz:");
                            fprintf(cikti,"Ekleyeceginiz Sehrin Ismini Giriniz:");
                            scanf("%s",&add_cityname);
                            fprintf(cikti,"%s\n",add_cityname);
                            printf("Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            fprintf(cikti,"Ekleyeceginiz Sehir Hangi Bolgede Bulunmaktadir:");
                            scanf("%s",&add_region);
                            fprintf(cikti,"%s\n",add_region);
                            printf("Kac Adet Komsusu Vardir:");
                            fprintf(cikti,"Kac Adet Komsusu Vardir:");
                            scanf("%d",&add_neighbor);
                            fprintf(cikti,"%d\n",add_neighbor);
                            while(list1!=NULL)
                            {

                                if(list1->plate==add_plate-1)

                                {
                                    Intercalation(list1,add_plate,add_cityname,add_region,add_neighbor);
                                    cities++;
                                    break;


                                }


                                list1=list1->next;


                            }
                            Add_MainLast(add_plate,add_plate);
                            for(int i=0; i<add_neighbor; i++)
                            {

                                printf("Komsu Sehrin Plakasini Giriniz:");
                                fprintf(cikti,"Komsu Sehrin Plakasini Giriniz:");

                                scanf("%d",&n_plate[i]);
                                fprintf(cikti,"%d\n",n_plate[i]);
                                int a=n_plate[i];
                                Add_NeighborLast(a);


                            }

                            printf("Sehir Listeye Eklenmistir......\n");
                            fprintf(cikti,"Sehir Listeye Eklenmistir......\n");




                        }


                    }



                }
                else
                {


                    int temp;
                    int k, l;

                    for (k=1; k<neigborn_control; k++)
                    {
                        for (l=0; l<neigborn_control-k; l++)
                        {
                            if(neighbor_plate[l] > neighbor_plate[l+1])
                            {
                                temp = neighbor_plate[l];
                                neighbor_plate [l] = neighbor_plate[l+1];
                                neighbor_plate[l+1] = temp;
                            }
                        }
                    }



                    struct city *list1=first;
                    printf("Komsular:\n");
                    fprintf(cikti,"Komsular:\n");

                    while(list1!=NULL)
                    {

                        for(int q=1; q<cities; q++)
                        {
                            list1=list1->next;
                            for(int w=0; w<neigborn_control; w++)
                            {

                                if(neighbor_plate[w]==list1->plate)
                                {


                                    printf("%d- %s %s %d\n",list1->plate,list1->city_name,list1->geographical_region,list1->neighbor_number);
                                    fprintf(cikti,"%d- %s %s %d\n",list1->plate,list1->city_name,list1->geographical_region,list1->neighbor_number);




                                }




                            }





                        }


                        list1=list1->next;



                    }




                }


            }
         fclose(cikti);

        }

        if(secim==3)
        {
            int delete_choose;
            cikti=fopen("output.txt","a");

            printf("Sehir Kaydi Silmek Icin 1'e Basin\n");
            fprintf(cikti,"Sehir Kaydi Silmek Icin 1'e Basin\n");
            printf("Komsuluk Kaydi Silmek Icin 2'ye Basin\n");
            fprintf(cikti,"Komsuluk Kaydi Silmek Icin 2'ye Basin\n");
            printf("Secim:");
            fprintf(cikti,"Secim:");
            scanf("%d",&delete_choose);
            fprintf(cikti,"%d\n",delete_choose);

            if(delete_choose==1)
            {
                int delete_plate;
                printf("Kaydini Silmek Istediginiz Sehrin Plakasini Giriniz:");
                fprintf(cikti,"Kaydini Silmek Istediginiz Sehrin Plakasini Giriniz:");
                scanf("%d",&delete_plate);
                fprintf(cikti,"%d\n",delete_plate);

                struct city *f_delete=first;
                struct city *l_delete=last;

                if(f_delete->plate==delete_plate)
                {


                    Delete_CityFirst();


                }

                else if(l_delete->plate==delete_plate)
                {

                    Delete_CityLast();


                }

                else
                {


                    Delete_CityInter(delete_plate);


                }




            }
            if(delete_choose==2)
            {

                int delete_plate;
                int delete_neighbor;
                struct neighbor *delete_n=n_first;
                struct city *c1=first;
                int city_n;
                printf("Komsu Sileceginiz Ilin Plakasini Giriniz:");
                fprintf(cikti,"Komsu Sileceginiz Ilin Plakasini Giriniz:");
                scanf("%d",&delete_plate);
                fprintf(cikti,"%d\n",delete_plate);
                printf("Silinecek Komsunun Plakasini Giriniz:");
                fprintf(cikti,"Silinecek Komsunun Plakasini Giriniz:");
                scanf("%d",&delete_neighbor);
                fprintf(cikti,"%d\n",delete_neighbor);

                while(delete_n!=NULL)
                {

                    if(delete_n->plate==delete_plate&&delete_n->main_city==delete_plate)
                    {


                        break;


                    }




                    delete_n=delete_n->next;

                }


                while(c1!=NULL)
                {

                    if(delete_n->plate==c1->plate)
                    {


                        city_n=c1->neighbor_number;
                        break;


                    }


                    c1=c1->next;

                }



                for(int i=0; i<city_n; i++)
                {

                    delete_n=delete_n->next;



                    if(delete_n->plate==delete_neighbor)
                    {

                        if(delete_n->next==NULL)
                        {

                            Delete_NeighborLast(delete_n);
                            c1->neighbor_number--;
                            break;


                        }
                        else
                        {
                            Delete_NeighborInter(delete_n);

                            c1->neighbor_number--;
                            break;



                        }





                    }






                }

                struct neighbor *x=n_first;

                while(x!=NULL)
                {

                    if(x->plate==delete_plate&&x->main_city==delete_plate)
                    {

                        break;

                    }


                    x=x->next;

                }








            }





     fclose(cikti);




        }

        if(secim==4)
        {
            cikti=fopen("output.txt","a");
            struct city *list=first;
            char choose_region[5];
            printf("Bolgenin Kisaltmasini Giriniz:");
            fprintf(cikti,"Bolgenin Kisaltmasini Giriniz:");
            scanf("%s",&choose_region);
            fprintf(cikti,"%s\n",choose_region);

            while(list!=NULL)
            {

                if(strcmp(choose_region,list->geographical_region)==0)
                {

                    printf("%s %s %d\n",list->city_name,list->geographical_region,list->neighbor_number);
                    fprintf(cikti,"%s %s %d\n",list->city_name,list->geographical_region,list->neighbor_number);



                }


                list=list->next;

            }




          fclose(cikti);

        }

        if(secim==5)
        {
            cikti=fopen("output.txt","a");
            struct city *list=first;
            int choose_neigborn;
            printf("Girdiginiz Sayidan Fazla Komsuya Sahip Iller Gosterilecektir:");
            fprintf(cikti,"Girdiginiz Sayidan Fazla Komsuya Sahip Iller Gosterilecektir:");
            scanf("%d",&choose_neigborn);
            fprintf(cikti,"%d\n",choose_neigborn);
            while(list!=NULL)
            {

                if(list->neighbor_number>choose_neigborn)
                {

                    printf("%s %s %d\n",list->city_name,list->geographical_region,list->neighbor_number);
                    fprintf(cikti,"%s %s %d\n",list->city_name,list->geographical_region,list->neighbor_number);



                }


                list=list->next;

            }





         fclose(cikti);


        }


        if(secim==6)
        {

            break;


        }












    }










    return 0;
}
