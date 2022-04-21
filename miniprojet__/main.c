#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 FILE *file=NULL ,*copie=NULL;
 int choix,v,id;


typedef struct Voiture{
     int idVoiture;
     char marque[15];
     char nomVoiture[15];
     char couleur[7];
     int nbplaces ;
     int prixjour;
     char EnLocation[4];
}voiture;



typedef struct date{
     int jour;
     int mois;
     int annee;
}date;

 typedef struct contratLocation{
     float numContrat;
     int idVoiture;
     int idClient;
     date debut;
     date fin ;
     int cout;
}contratLocation;

typedef struct Client{
   int idclient;
   char nom[20];
   char prenom[20];
   int cin;
   char adresse[15];
   int telephone;
}client;



/************************menu de location*********************************/
void locationVoiture(void){
    contratLocation *contrat;
    contrat=(contratLocation*)malloc(sizeof(contratLocation));
    float num;
    int exist=0;
    voiture *car=(voiture*)malloc(sizeof(voiture));
    voiture *car1=(voiture*)malloc(sizeof(voiture));
    client *pers=(client*)malloc(sizeof(client));

      do{

    printf("\n                          \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n                          \xba  LOCATION D'UNE VOITURE  \xba");
    printf("\n                          \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xba    Visualiser contrat.....................1      \xba");
	printf("\n               \xba    Louer voiture..........................2      \xba");
	printf("\n               \xba    retourner voiture .....................3      \xba");
	printf("\n               \xba    Modifier contrat.......................4      \xba");
	printf("\n               \xba    Supprimer contrat......................5      \xba");
	printf("\n               \xba    retour.................................6      \xba");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	scanf("%d",&choix);
	getchar();
	system("CLS");

	switch(choix){
	    /********************pour visualiser un contrat*****************************************/
        case 1:{
            exist=0;
	        file=fopen("location.txt","r");
	        if(file){
                    fseek(file,0,SEEK_END);//pour traiter le cas si le fichier existe mais il est vide.
                    v=ftell(file);
                    if(v){
                       fseek(file,0,SEEK_SET);
                       printf("entrer le numero du contrat");
                       scanf("%f",&num);
                       while(!feof(file)){
                       fscanf(file,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",&contrat->numContrat,&contrat->idVoiture,&contrat->idClient,&contrat->debut.jour,&contrat->debut.mois,&contrat->debut.annee,&contrat->fin.jour,&contrat->fin.mois,&contrat->fin.annee,&contrat->cout);
                       if(num==contrat->numContrat){
                         exist=1;
                         printf("%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",contrat->numContrat,contrat->idVoiture,contrat->idClient,contrat->debut.jour,contrat->debut.mois,contrat->debut.annee,contrat->fin.jour,contrat->fin.mois,contrat->fin.annee,contrat->cout);
                         break;}
	                   }
	                   if(exist==0){
	                      printf("\n\n                     +_+ce numero de contrat n'existe pas+_+                    ");}

                    }
	                else
                       printf("\n\n                    +_+aucun contrat enregistre a ce moment+_+                          \n\n");}
            else
                    printf("\n\n               +_+ERREUR(FICHIER N'EXISTE PAS-> aucun contrat a ce moment)+_+                \n\n");

            fclose(file);
        break;}

        /***********************pour louer une voiture*********************************/
	    case 2:{
	        char nom[20];
	        char prenom[20]  ;
	        FILE *file1=NULL,*file2=NULL ;
	        int existv=0,existc=0;
	        char loc[4]="oui";

	        printf(" \n\n    votre information:     \n\n");
	        printf("       entrer votre nom : ");
	        scanf("%s",nom);
	        printf("\n     entrer votre prenom : ");
	        scanf("%s",prenom);
	        printf(" \n\n  information sur la voiture que vous souhaiter louer:          ");
	        printf("\n     la marque : ");
	        scanf("%s",car1->marque);
	        printf("       nom du voiture : ");
	        scanf("%s",car1->nomVoiture);
	        printf("\n     la couleur : ");
	        scanf("%s",car1->couleur);
	        printf("\n     nombre de places : ");
	        scanf("%d",&car1->nbplaces);
	        getchar();
	        file1=fopen("Voitures.txt","r");
	        if(file1){
                while(!feof(file1)){
                    fscanf(file1,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",&car->idVoiture,car->marque,car->nomVoiture,car->couleur,&car->nbplaces,&car->prixjour,car->EnLocation);
                    if(strcmp(car->marque,car1->marque)==0 && strcmp(car->nomVoiture,car1->nomVoiture)==0 && strcmp(car->couleur,car1->couleur)==0 && car->nbplaces==car1->nbplaces){
                        existv=1;
                        id=car->idVoiture;
                        break;
                    }
                }
	        }
	        else
                printf("\n\n          +_+ERREUR(Voitures.txt!!!)+_+             \n\n");

	        fclose(file1);
	        file2=fopen("clients.txt","r");
	        if(file2){
                while(!feof(file2)){
                    fscanf(file2,"%d\t%s\t%s\t%d\t%s\t%d \n",&pers->idclient,pers->nom,pers->prenom,&pers->cin,pers->adresse,&pers->telephone);
                    if(strcmp(nom,pers->nom)==0 && strcmp(prenom,pers->prenom)==0){
                        existc=1;

                        break;
                    }
                }
	        }else
	        printf("              +_+ERREUR(clients.txt!!!!)+_+             ");
	        fclose(file2);
	        if(existv){
                if(existc){
                        if( strcmp(car->EnLocation,loc) ==0){
                            printf("\n\n    +_+cette voiture n'est pas disponible a ce moment+_+        \n\n");
                        }
                        else{
                           FILE *copie1=NULL;
                           copie1=fopen("copie1.txt","a");
                            file1=fopen("Voitures.txt","r");
                        do{
                      fscanf(file1,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",&car->idVoiture,car->marque,car->nomVoiture,car->couleur,&car->nbplaces,&car->prixjour,car->EnLocation);
                      if(id==car->idVoiture){
                        fprintf(copie1,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",car->idVoiture,car->marque,car->nomVoiture,car->couleur,car->nbplaces,car->prixjour,loc);
                        }
                      else
                        fprintf(copie1,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",car->idVoiture,car->marque,car->nomVoiture,car->couleur,car->nbplaces,car->prixjour,car->EnLocation);
                        }while(!feof(file1));
                        fclose(file1);
                        fclose(copie1);
                        remove("Voitures.txt");
                        rename("copie1.txt","Voitures.txt");
                        file2=fopen("location.txt","a");
                        if(file2){
                        printf("\n entrer le numero du contrat : \n");
                        scanf("%f",&contrat->numContrat);
                        printf("\n entrer l'id du voiture : \n");
                        scanf("%d",&contrat->idVoiture);
                        printf("\n entrer l'id du client : \n");
                        scanf("%d",&contrat->idClient);
                        printf("\n entrer la date de debut de location (jour/mois/annee) : \n");
                        scanf("%d/%d/%d",&contrat->debut.jour,&contrat->debut.mois,&contrat->debut.annee);
                        printf(" entrer la date de fin de location (jour/mois/annee) : \n");
                        scanf("%d/%d/%d",&contrat->fin.jour,&contrat->fin.mois,&contrat->fin.annee);
                        printf("\n entrer le cout : \n");
                        scanf("%d",&contrat->cout);
                        fprintf(file2,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",contrat->numContrat,contrat->idVoiture,contrat->idClient,contrat->debut.jour,contrat->debut.mois,contrat->debut.annee,contrat->fin.jour,contrat->fin.mois,contrat->fin.annee,contrat->cout);
                        fclose(file2);}
                        else
                            printf("\n\n              +_+ERREUR(location.txt!!!)+_+             \n\n");




                }}
                else
                    printf(" \n\n              +_+ce client n'existe pas+_+               \n Veuillez vous rendre dans le menu de gestion des clients pour l'ajouter\n\n");
	        }
	        else
                printf("\n\n              +_+cette voiture n'existe pas+_+            \n\n");







	        break;}
/***************************** pour retourner une voiture ***************************************** */

	    case 3:{
	        FILE *file1=NULL;
	        FILE *copie1=NULL;
	        printf("entrer l'id du voiture a retourner : \n\n");
	        scanf("%d",&id);
	        copie=fopen("copie.txt","a");
            file=fopen("Voitures.txt","r");
            if(file){
                char loc[4]="non";
                do{
                      fscanf(file,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",&car->idVoiture,car->marque,car->nomVoiture,car->couleur,&car->nbplaces,&car->prixjour,car->EnLocation);
                      if(id==car->idVoiture){
                         fprintf(copie,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",car->idVoiture,car->marque,car->nomVoiture,car->couleur,car->nbplaces,car->prixjour,loc);
                        }
                      else{
                         fprintf(copie,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",car->idVoiture,car->marque,car->nomVoiture,car->couleur,car->nbplaces,car->prixjour,car->EnLocation);}
                }while(!feof(file));
                fclose(file);
                fclose(copie);
                        remove("Voitures.txt");
                        rename("copie.txt","Voitures.txt");
	         }
            else
                printf("          +_+ERREUR(Voitures.txt!!!)+_+             ");

            contratLocation contrat;
            exist=0;

            file1=fopen("location.txt","r");
            if(file1){
	            while(!feof(file1)){
                   fscanf(file1,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",&contrat.numContrat,&contrat.idVoiture,&contrat.idClient,&contrat.debut.jour,&contrat.debut.mois,&contrat.debut.annee,&contrat.fin.jour,&contrat.fin.mois,&contrat.fin.annee,&contrat.cout);
                   if(contrat.idVoiture==id){
                        exist=1;
                        break;}}
                   fclose(file1);
	               if(exist==1){
                        file1=fopen("location.txt","r");
                        copie1=fopen("copie1.txt","a");
                        while(!feof(file1)){
                            fscanf(file1,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",&contrat.numContrat,&contrat.idVoiture,&contrat.idClient,&contrat.debut.jour,&contrat.debut.mois,&contrat.debut.annee,&contrat.fin.jour,&contrat.fin.mois,&contrat.fin.annee,&contrat.cout);
                            if(contrat.idVoiture!=id){
                               fprintf(copie1,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",contrat.numContrat,contrat.idVoiture,contrat.idClient,contrat.debut.jour,contrat.debut.mois,contrat.debut.annee,contrat.fin.jour,contrat.fin.mois,contrat.fin.annee,contrat.cout);
                          }}
            } }
            else
                printf("\n\n             +_+ce id n'existe pas+_+       \n\n");


            fclose(copie1);
            fclose(file1);
            remove("location.txt");
            rename("copie1.txt","location.txt");
            free(pers);
            free(car);
            free(car1);

	        ;break;}

/*************************pour modifier une contrat*********************************************/
       case 4:{
	        contratLocation nvcontrat;
	        exist=0;
	        printf("\n\n             entrer le numero du contrat a modifier :       \n\n");
	        scanf("%f",&nvcontrat.numContrat);

	        file=fopen("location.txt","r");
            if(file){
	           while(!feof(file)){
                   fscanf(file,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",&contrat->numContrat,&contrat->idVoiture,&contrat->idClient,&contrat->debut.jour,&contrat->debut.mois,&contrat->debut.annee,&contrat->fin.jour,&contrat->fin.mois,&contrat->fin.annee,&contrat->cout);
                   if(nvcontrat.numContrat==contrat->numContrat){
                        exist=1;
                        break;}}
               fclose(file);

               if(exist){
                  printf("\n    entrer la nouvelle date de rouer(jour/mois/annee) :");
                  scanf("%d/%d/%d",&nvcontrat.fin.jour,&nvcontrat.fin.mois,&nvcontrat.fin.annee);
                  printf("\n    enrer le nouveau cout :");
                  scanf("%d",&nvcontrat.cout);
                  copie=fopen("copie.txt","a");
                  file=fopen("location.txt","r");
                  while(!feof(file)){
                      fscanf(file,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",&contrat->numContrat,&contrat->idVoiture,&contrat->idClient,&contrat->debut.jour,&contrat->debut.mois,&contrat->debut.annee,&contrat->fin.jour,&contrat->fin.mois,&contrat->fin.annee,&contrat->cout);
                      if(contrat->numContrat==nvcontrat.numContrat){
                           fprintf(copie,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",contrat->numContrat,contrat->idVoiture,contrat->idClient,contrat->debut.jour,contrat->debut.mois,contrat->debut.annee,nvcontrat.fin.jour,nvcontrat.fin.mois,nvcontrat.fin.annee,nvcontrat.cout);

                      }
                      else
                           fprintf(copie,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",contrat->numContrat,contrat->idVoiture,contrat->idClient,contrat->debut.jour,contrat->debut.mois,contrat->debut.annee,contrat->fin.jour,contrat->fin.mois,contrat->fin.annee,contrat->cout);

                  }
	           }else
	              printf("\n\n             +_+ce numero de contrat n'existe pas+_+       \n\n");
	        }
	        else
               printf("\n\n             +_+ERREUR(location.txt!!!)+_+                     \n\n");
            fclose(file);
            fclose(copie);
            remove("location.txt");
            rename("copie.txt","location.txt");

	        ;break;}

/*******************************+pour supprimer une contrat*********************************+++++*/
        case 5:{
          printf("entrer l'id du voiture rendue : ");
          scanf("%d",&id);
          int existv=0,r=0;
          char loc[4]="oui";
          voiture car;
          file=fopen("Voitures.txt","r");
          if(file){
             while(!feof(file)){
                fscanf(file,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",&car.idVoiture,car.marque,car.nomVoiture,car.couleur,&car.nbplaces,&car.prixjour,car.EnLocation);
                if(id==car.idVoiture){
                    existv=1;
                    if(strcmp(loc,car.EnLocation)==0)
                       r=1;
                    break;
                }
            }
          }
          else
             printf("          +_+ERREUR(Voitures.txt!!!)+_+             ");

          fclose(file);
          if(existv){
            if(r)
                printf("\n\n           +_+impossible de supprimer ce contrat ,la voiture n'est pas encore rendue+_+                 \n\n");

            else{
                    contratLocation contrat;
                    exist=0;
                    file=fopen("location.txt","r");
                    if(file){
	                   while(!feof(file)){
                           fscanf(file,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",&contrat.numContrat,&contrat.idVoiture,&contrat.idClient,&contrat.debut.jour,&contrat.debut.mois,&contrat.debut.annee,&contrat.fin.jour,&contrat.fin.mois,&contrat.fin.annee,&contrat.cout);
                           if(contrat.idVoiture==id){
                           exist=1;
                           break;}}
                       rewind(file);

	                   if(exist){
                         copie=fopen("copie.txt","a");
                         while(!feof(file)){
                          fscanf(file,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",&contrat.numContrat,&contrat.idVoiture,&contrat.idClient,&contrat.debut.jour,&contrat.debut.mois,&contrat.debut.annee,&contrat.fin.jour,&contrat.fin.mois,&contrat.fin.annee,&contrat.cout);
                          if(contrat.idVoiture!=id){
                             fprintf(copie,"%f\t%d\t%d\t%d/%d/%d\t%d/%d/%d\t%d \n",contrat.numContrat,contrat.idVoiture,contrat.idClient,contrat.debut.jour,contrat.debut.mois,contrat.debut.annee,contrat.fin.jour,contrat.fin.mois,contrat.fin.annee,contrat.cout);
                          }}
                   }}
                   else
	                   printf("\n\n             +_+ce numero de contrat n'existe pas+_+       \n\n");
                       fclose(file);
                       fclose(copie);
                       remove("location.txt");
                       rename("copie.txt","location.txt");}

          }
          else
            printf("\n\n          +_+ce id n'existe pas+_+              \n\n");

        break;}

	    case 6:{;break;}

	    default:
	         printf("                     +_+ce choix n'existe pas+_+                 ");

	}

        }while(choix!=6);
}


/*****************************menu de gestion des voitures**********************************/
void GestionDesVoitures(void){
     voiture *car=(voiture*)malloc(sizeof(voiture));

     do{

    printf("\n                          \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n                          \xba  GESTION DES VOITURES  \xba");
    printf("\n                          \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xba    Liste des voitures.....................1      \xba");
	printf("\n               \xba    Ajouter voiture........................2      \xba");
	printf("\n               \xba    Modifier voiture.......................3      \xba");
	printf("\n               \xba    Supprimer voiture......................4      \xba");
	printf("\n               \xba    Retour.................................5      \xba");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	scanf("%d",&choix);
	getchar();
	system("CLS");

	switch(choix){

/*****************************pour lister les voitures************************************/
      case 1:{
          file=fopen("Voitures.txt","r");
          if(file){
             fseek(file,0,SEEK_END);
             v=ftell(file);
             if(v){
               fseek(file,0,SEEK_SET);
               while(!feof(file)){
                    fscanf(file,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",&car->idVoiture,car->marque,car->nomVoiture,car->couleur,&car->nbplaces,&car->prixjour,car->EnLocation);
                    printf("%d\t%s\t%s\t%s\t%d\t%d\t%s \n",car->idVoiture,car->marque,car->nomVoiture,car->couleur,car->nbplaces,car->prixjour,car->EnLocation);}
              }
               else
                        printf("\n\n                  +_+AUCUN VOITURE A CE MOMENT(le fichier est vide)+_+          \n\n");

          }
          else
             printf("\n\n                    +_+aucun Voitures enregistrees a ce moment+_+            \n\n");
          fclose(file);

          break;}

/***************************************pour ajouter une voiture***********************************+*/
      case 2:{

          printf("\n\n     -----------entrer les informations de la voiture----------       \n");
          printf("\n  entrer l'id de voiture : ");
          scanf("%d",&car->idVoiture);
          printf("\n  entrer la marque de la voiture : ");
          scanf("%s",car->marque);
          printf("\n  entrer le nom  de la voiture : ");
          scanf("%s",car->nomVoiture);
          printf("\n  entrer la couleur de la voiture : ");
          scanf("%s",car->couleur);
          printf("\n  entrer le nombre de places de la voiture : ");
          scanf("%d",&car->nbplaces);
          printf("\n  entrer le prix par jour de la voiture : ");
          scanf("%d",&car->prixjour);
          printf("\n  en location ou pas ?(oui|non) : ");
          scanf("%s",car->EnLocation);

          file=fopen("Voitures.txt","a");
          fprintf(file,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",car->idVoiture,car->marque,car->nomVoiture,car->couleur,car->nbplaces,car->prixjour,car->EnLocation);
          fclose(file);

          break;}

/******************************************pour modifier les information d'une voiture************************************/
          case 3:{
              voiture car1;
              printf("entrer l'id de voiture que vous vouler modifier : ");
              scanf("%d",&id);
              file=fopen("voitures.txt","r");
              do{
                  fscanf(file,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",&car->idVoiture,car->marque,car->nomVoiture,car->couleur,&car->nbplaces,&car->prixjour,car->EnLocation);
                  if(id==car->idVoiture){
                     v=1;
                     break;
                  }
              }while(!feof(file));
              fclose(file);
              if(v){
                  printf("\n\n             entrer les nouveau informations du voiture :      \n\n");
                  printf("\n     entrer la marque de la voiture : ");
                  scanf("%s",car1.marque);
                  printf("\n     entrer le nom  de la voiture : ");
                  scanf("%s",car1.nomVoiture);
                  printf("\n     entrer la couleur de la voiture : ");
                  scanf("%s",car1.couleur);
                  printf("\n     entrer le nombre de places de la voiture : ");
                  scanf("%d",&car1.nbplaces);
                  printf("\n     entrer le prix par jour de la voiture : ");
                  scanf("%d",&car1.prixjour);
                  printf("\n     en location ou pas ?(oui|non) : ");
                  scanf("%s",car1.EnLocation);
                  file=fopen("voitures.txt","r");
                  copie=fopen("copie.txt","a");
                  do{
                      fscanf(file,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",&car->idVoiture,car->marque,car->nomVoiture,car->couleur,&car->nbplaces,&car->prixjour,car->EnLocation);
                      if(id==car->idVoiture){
                        fprintf(copie,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",car->idVoiture,car1.marque,car1.nomVoiture,car1.couleur,car1.nbplaces,car1.prixjour,car1.EnLocation);
                        }
                      else
                        fprintf(copie,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",car->idVoiture,car->marque,car->nomVoiture,car->couleur,car->nbplaces,car->prixjour,car->EnLocation);
                  }while(!feof(file));
                  fclose(file);
                  fclose(copie);
                  remove("voitures.txt");
                  rename("copie.txt","voitures.txt");

              }
              else
                  printf("\n\n                     +_+ce id n'existe pas+_+                   \n\n");

           break;}

/**************************************pour supprimer une contrat*****************************/
           case 4 :{
                file=fopen("voitures.txt","r");
                copie=fopen("copie.txt","a");
                fseek(file,0,SEEK_END),
                v=ftell(file);
                if(v){
                   printf("entrer l'id du voiture a supprimee : ");
                   scanf("%d",&id);
                   fseek(file,0,SEEK_SET);
                   while(!feof(file)){
                     fscanf(file,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",&car->idVoiture,car->marque,car->nomVoiture,car->couleur,&car->nbplaces,&car->prixjour,car->EnLocation);
                     if(id!=car->idVoiture){
                         fprintf(copie,"%d\t%s\t%s\t%s\t%d\t%d\t%s \n",car->idVoiture,car->marque,car->nomVoiture,car->couleur,car->nbplaces,car->prixjour,car->EnLocation);
                     }
                }}
                else
                printf("                 +_+aucun voitures enregistrer a ce moment.+_+              ");
                fclose(file);
                fclose(copie);
                remove("voitures.txt");
                rename("copie.txt","voitures.txt");

           break;}


           case 5:{
                break;}

           default:
            printf("                 +_+ce choix n'existe pas.+_+                     ");


   }}while(choix!=5);
   free(car);
}



void GestionDesClients(void){
   client *pers=(client*)malloc(sizeof(client));

     do{

    printf("\n                              \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n                              \xba GESTION DES CLIENTS \xba");
    printf("\n                              \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xba    Liste des clients......................1      \xba");
	printf("\n               \xba    Ajouter client.........................2      \xba");
	printf("\n               \xba    Modifier client........................3      \xba");
	printf("\n               \xba    Supprimer client.......................4      \xba");
	printf("\n               \xba    Retour.................................5      \xba");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	scanf("%d",&choix);
	getchar();
	system("CLS");

	switch(choix){

/************************************pour lister les clients *****************************************/
      case 1:{
          file=fopen("clients.txt","r");
          if(file){
            fseek(file,0,SEEK_END);
            v=ftell(file);
            if(v){
               fseek(file,0,SEEK_SET);
               while(!feof(file)){
                    fscanf(file,"%d\t%s\t%s\t%d\t%s\t%d \n",&pers->idclient,pers->nom,pers->prenom,&pers->cin,pers->adresse,&pers->telephone);
                    printf("%d\t%s\t%s\t%d\t%s\t%d \n",pers->idclient,pers->nom,pers->prenom,pers->cin,pers->adresse,pers->telephone);}}

          }
          else
            printf("\n\n                    +_+aucun Client enregistrees a ce moment+_+            \n\n");

          fclose(file);

      break;}

/*********************************pour ajouter un clients ******************************/
      case 2:{

          printf("\n\n-----------entrer les informations du client----------\n\n");
          printf("\n  entrer l'id de client : ");
          scanf("%d",&pers->idclient);
          printf("\n  entrer le nom du client : ");
          scanf("%s",pers->nom);
          printf("\n  entrer le prenom du client  : ");
          scanf("%s",pers->prenom);
          printf("\n  entrer le CIN du client : ");
          scanf("%d",&pers->cin);
          printf("\n  entrer l'adresse du client : ");
          scanf("%s",pers->adresse);
          printf("\n  entrer le telephone du client : ");
          scanf("%d",&pers->telephone);

          file=fopen("clients.txt","a");
          fprintf(file,"%d\t%s\t%s\t%d\t%s\t%d \n",pers->idclient,pers->nom,pers->prenom,pers->cin,pers->adresse,pers->telephone);
          fclose(file);

      break;}

/************************************pour modifier un client ************************************************/
      case 3:{
              client pers1;
              printf("\n\n          entrer l'id du client que vous vouler modifier ces informations :      \n\n");
              scanf("%d",&id);
              file=fopen("clients.txt","r");
              do{
                 fscanf(file,"%d\t%s\t%s\t%d\t%s\t%d \n",&pers->idclient,pers->nom,pers->prenom,&pers->cin,pers->adresse,&pers->telephone);
                 if(id==pers->idclient){
                    v=1;
                    break;
                 }
              }while(!feof(file));
              fclose(file);
              if(v){
                  printf("\n\n          entrer les nouveau informations du client : \n\n");
                  printf("\n  entrer le nom du client : ");
                  scanf("%s",pers1.nom);
                  printf("\n  entrer le prenom du client  : ");
                  scanf("%s",pers1.prenom);
                  printf("\n  entrer le CIN du client : ");
                  scanf("%d",&pers1.cin);
                  printf("\n  entrer l'adresse du client : ");
                  scanf("%s",pers1.adresse);
                  printf("\n  entrer le telephone du client : ");
                  scanf("%d",&pers1.telephone);/**/

                  file=fopen("clients.txt","r");
                  copie=fopen("copie.txt","a");
                  if(file && copie){
                    do{
                      fscanf(file,"%d\t%s\t%s\t%d\t%s\t%d \n",&pers->idclient,pers->nom,pers->prenom,&pers->cin,pers->adresse,&pers->telephone);
                      if(id==pers->idclient){
                        fprintf(copie,"%d\t%s\t%s\t%d\t%s\t%d \n",pers->idclient,pers1.nom,pers1.prenom,pers1.cin,pers1.adresse,pers1.telephone);
                      }
                      else
                        fprintf(copie,"%d\t%s\t%s\t%d\t%s\t%d \n",pers->idclient,pers->nom,pers->prenom,pers->cin,pers->adresse,pers->telephone);
                    }while(!feof(file));}
                  else
                    printf("\n\n\n            ERREUR           \n\n\n");

                  fclose(file);
                  fclose(copie);
                  remove("clients.txt");
                  rename("copie.txt","clients.txt");

              }
               else
                {printf("                     +_+ce id n'existe pas.+_+                          ");}

           break;}

/**********************************pour supprimer un client************************************/
           case 4 :{
                file=fopen("Clients.txt","r");
                copie=fopen("copie.txt","a");
                fseek(file,0,SEEK_END),
                v=ftell(file);
                if(v){
                   printf("entrer l'id du client a supprimee : ");
                   scanf("%d",&id);
                   fseek(file,0,SEEK_SET);
                   while(!feof(file)){
                     fscanf(file,"%d\t%s\t%s\t%d\t%s\t%d \n",&pers->idclient,pers->nom,pers->prenom,&pers->cin,pers->adresse,&pers->telephone);
                     if(id!=pers->idclient){
                        fprintf(copie,"%d\t%s\t%s\t%d\t%s\t%d \n",pers->idclient,pers->nom,pers->prenom,pers->cin,pers->adresse,pers->telephone);
                     }
                }}
                else
                   printf("                 +_+aucun client enregistrer a ce moment.+_+              ");
                fclose(file);
                fclose(copie);
                remove("Clients.txt");
                rename("copie.txt","Clients.txt");

           break;
           case 5:{
            break;}

           default:
              printf("                 +_+ce choix n'existe pas.+_+                     ");

	}
     }}while(choix!=5);

}

int main()
{

/*********************************menu principal **************************************/
    do{

    printf("\n                              \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
    printf("\n                              \xba   MENU PRINCIPAL  \xba");
    printf("\n                              \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
    printf("\n               \xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xba    location...............................1      \xba");
	printf("\n               \xba    gestion voitures.......................2      \xba");
	printf("\n               \xba    gestion clients........................3      \xba");
	printf("\n               \xba    quitter................................4      \xba");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xba                                                  \xba");
	printf("\n               \xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc");
	printf("\n\n                                Votre choix  :  ");
	scanf("%d",&choix);
	getchar();
	system("CLS");


	switch(choix){
      case 1:{ locationVoiture();break;}
      case 2:{ GestionDesVoitures();break;}
      case 3:{ GestionDesClients();break;}
      case 4:{printf(" \n\n\n\n\n\n                -_-FIN DU PROGRAMME-_-            \n\n\n\n\n\n");break;}
      default:{
        printf("\n\n                 +_+choix invalide+_+                        \n\n");
        getchar();
        break;
      }
	}

    }while(choix!=4);
    return 0;
}
