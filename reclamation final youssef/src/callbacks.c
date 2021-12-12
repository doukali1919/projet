#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include <string.h>
#include <time.h>
#include "reclamation.h"
int xg;
int tg[4]={0,0,0,0};
int xgg;
int tgg[4]={0,0,0,0};
int xy[]={0,0,0,0},sy;




void
on_ajou_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget*No,*Pr,*Am,*Ac,*ci,*Nt,*windowsup,*se,*jour,*mois,*annee,*labelnom,*labelprenom,*labelresp,*labelcin,*labelnt,*labelobjet;
reclamation o ; 


int i=0, longueurChaine = 0;
char chaine[] = "a1b2c3d4e5f6g7h8i9j0klmnpqrstuvwxyz";
int b=1;
No = lookup_widget (objet,"entry10");
Pr = lookup_widget (objet,"entry11");
ci = lookup_widget (objet,"entry12");
Am = lookup_widget (objet,"entry14");
Nt = lookup_widget (objet,"entry13");
jour = lookup_widget (objet,"spinbutton2");
mois = lookup_widget (objet,"spinbutton3");
annee = lookup_widget (objet,"spinbutton4");
se = lookup_widget (objet,"combobox6");




strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(No)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(Pr)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.objet,gtk_entry_get_text(GTK_ENTRY(Am)));
strcpy(o.messageRecla,gtk_entry_get_text(GTK_ENTRY(Nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.resp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));



 
    longueurChaine = strlen(chaine);
 
    srand(time(NULL));
 
    for(i=0; i < 4; i++)
        {
            o.id[i] = chaine[rand()%longueurChaine];
        }
labelnom=lookup_widget(objet,"label333");
labelprenom=lookup_widget(objet,"label334");
labelresp=lookup_widget(objet,"label335");
labelcin=lookup_widget(objet,"label336");
labelnt=lookup_widget(objet,"label337");
labelobjet=lookup_widget(objet,"label338");




// controle saisie
if(strcmp(o.NOM,"")==0){
		 
          gtk_label_set_text(GTK_LABEL(labelnom),"saisir NOM !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnom),"");
}

if(strcmp(o.Prenom,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"saisir prénom !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelprenom),"");
}


if(strcmp(o.resp,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelresp),"saisir service !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelresp),"");
}

if(strcmp(o.CIN,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"saisir CIN !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelcin),"");
}

if(strcmp(o.messageRecla,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"saisir votre numéro de téléphone !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelnt),"");
}



if(strcmp(o.objet,"")==0){
		  
          gtk_label_set_text(GTK_LABEL(labelobjet),"saisir objet !");
b=0;
}
else {
		  
          gtk_label_set_text(GTK_LABEL(labelobjet),"");
}
if(b==1){
Ajouter_ch( o);

}

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet,"treeview5");
affi_ch(p,"reclamation.txt");



}


void
on_supp_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *dd,*lb;

char idd[20];
FILE *F;
int x=-1;
char NOM[20];
char resp[20];
char Prenom[20];
char CIN[20];
char id[20];
char jour[20];
char mois[20];
char annee[20];
char messageRecla[20];
char objet1[20];
lb = lookup_widget (objet,"label332");
dd = lookup_widget (objet,"entry15");
strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("reclamation.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s \n",id,NOM,Prenom,resp,CIN,messageRecla,jour,mois,annee,objet1) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
}else
{
    supp_ch(idd);
    gtk_label_set_text(GTK_LABEL(lb),"supprimer avec succes");/* code */
}

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet,"treeview5");
affi_ch(p,"reclamation.txt");
}


void
on_rech_ch_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{


GtkWidget *dd,*Nm,*Pnom,*cin,*resp1,*Jour,*Mois,*Num,*Annee,*objet1,*lb;

char id[20];
char NOM[20];
char Prenom[20];
char resp[20];
char CIN[20];
char messageRecla[20];
char jour[20];
char mois[20];
char annee[20];
char objet[20];
char idd[20];
reclamation o ;
int x=-1;
FILE *F;

dd = lookup_widget (button,"entry16");
Nm = lookup_widget(button, "entry17");
Pnom = lookup_widget(button, "entry18");
resp1 = lookup_widget(button, "label355");
cin = lookup_widget (button,"entry19");
Num = lookup_widget(button, "entry20");
Jour = lookup_widget(button, "spinbutton6");
Mois = lookup_widget(button, "spinbutton6");
Annee = lookup_widget(button, "spinbutton7");
objet1 = lookup_widget(button, "entry21");
lb = lookup_widget(button, "label354");

strcpy(idd,gtk_entry_get_text(GTK_ENTRY(dd)));

F = fopen ("reclamation.txt", "r");


  if (F!=NULL)
 {
  while (fscanf (F,"%s %s %s %s %s %s %s %s %s %s\n",id,NOM,Prenom,resp,CIN,messageRecla,jour,mois,annee,objet) != EOF)
  {
  
    if (strcmp (idd,id) == 0)
      {
      x=1;
      } 
     } 
    
     fclose (F);
  }

if(x==-1)
{
gtk_label_set_text(GTK_LABEL(lb),"l'id n'existe pas ");
gtk_entry_set_text(GTK_LABEL(Nm),"");
gtk_entry_set_text(GTK_LABEL(Pnom),"");
gtk_label_set_text(GTK_LABEL(resp1),"");
gtk_entry_set_text(GTK_LABEL(cin),"");
gtk_entry_set_text(GTK_LABEL(Num),"");
gtk_entry_set_text(GTK_LABEL(objet1),"");
}else
{
    reclamation o = rechercher_reclamation(idd);
    gtk_label_set_text(GTK_LABEL(lb),"avec succées");/* code */


gtk_entry_set_text(GTK_LABEL(Nm),o.NOM);
gtk_entry_set_text(GTK_LABEL(Pnom),o.Prenom);
gtk_label_set_text(GTK_LABEL(resp1),o.resp);
gtk_entry_set_text(GTK_LABEL(cin),o.CIN);
gtk_entry_set_text(GTK_LABEL(Num),o.messageRecla);
gtk_entry_set_text(GTK_LABEL(objet1),o.objet);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Jour),jour);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Mois),mois);
//gtk_spin_button_set_value(GTK_SPIN_BUTTON(Annee),annee);

}

}


void
on_modi_ch_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *no,*pr,*ci,*nt,*am,*se,*jour,*mois,*annee,*dd;
reclamation o;
char id[20];


dd = lookup_widget (objet_graphique,"entry16");
no = lookup_widget (objet_graphique,"entry17");
pr = lookup_widget (objet_graphique,"entry18");
se = lookup_widget (objet_graphique,"combobox7");
ci = lookup_widget (objet_graphique,"entry19");
nt = lookup_widget (objet_graphique,"entry20");
jour = lookup_widget (objet_graphique,"spinbutton5");
mois = lookup_widget (objet_graphique,"spinbutton6");
annee = lookup_widget (objet_graphique,"spinbutton7");
am = lookup_widget (objet_graphique,"entry21");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(dd)));

strcpy(o.NOM,gtk_entry_get_text(GTK_ENTRY(no)));
strcpy(o.Prenom,gtk_entry_get_text(GTK_ENTRY(pr)));
strcpy(o.resp,gtk_combo_box_get_active_text(GTK_COMBO_BOX(se)));
strcpy(o.CIN,gtk_entry_get_text(GTK_ENTRY(ci)));
strcpy(o.messageRecla,gtk_entry_get_text(GTK_ENTRY(nt)));
o.dt_ns.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
o.dt_ns.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
o.dt_ns.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(o.objet,gtk_entry_get_text(GTK_ENTRY(am)));
modi_ch(id,o);

//mise a jour treeview
 GtkWidget* p=lookup_widget(objet_graphique,"treeview5");
affi_ch(p,"reclamation.txt");
}


void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_actua_ch_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{ 

GtkTreeModel     *model,*labe;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet_graphique,"treeview5");
	gchar *CIN;
        gchar *NOM;
        gchar *Prenom;
        gchar *objet;
        gchar *messageRecla;
        gchar *jour;
	gchar *mois;
	gchar *annee;
	gchar *resp;


        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,1,&NOM,2,&Prenom,3,&resp,4,&CIN,5,&messageRecla,6,&jour,7,&mois,8,&annee,9,&objet,-1);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry16")),id);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry17")),NOM);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry18")),Prenom);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry19")),CIN);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry20")),messageRecla);
 gtk_entry_set_text(GTK_ENTRY(lookup_widget(objet_graphique,"entry21")),objet);

		//gtk_widget_show(lookup_widget(objet,"modifier_ch"));//afficher le bouton modifier
                gtk_notebook_prev_page(GTK_NOTEBOOK(lookup_widget(objet_graphique,"notebook3")));//redirection vers la page precedente



labe = lookup_widget(objet_graphique, "label355");
gtk_label_set_text(GTK_LABEL(labe),resp);




         
}
//mise a jour treeview

affi_ch(p,"reclamation.txt");
}







void
on_supp_tree_ch_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{  GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p=lookup_widget(objet,"treeview5");;
        
        gchar *id;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

            supp_ch( id);// supprimer la ligne du fichier
}

}
int x;
int t[2]={0,0};

void
on_radiobutton11_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
 {x=1;} 

}


void
on_radiobutton12_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
{x=2;} 


}


void
on_checkbutton14_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


 if (gtk_toggle_button_get_active(togglebutton)) 

   {t[1]=1;}    

}


void
on_checkbutton15_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

 if (gtk_toggle_button_get_active(togglebutton)) 
  {t[0]=1;}  

}


void
on_button5_ok__clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *output;
char ch1[200]=" travaille en ";
char ch2[200]=" ";
char ch3[200]=" ";
if (x==1) 
strcpy(ch2," Mode jour ");
 else  
strcpy(ch2," Mode nuit ");
 if (t[0]==1)
 strcat(ch3," Groupe B "); 
if(t[1]==1)
 strcat (ch3,"  Groupe A");
strcat(ch3,ch1);
strcat(ch3,ch2);
output = lookup_widget(objet, "label356");

gtk_label_set_text(GTK_LABEL(output),ch3);





}


/*void
on_button7_quiter_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
 GtkWidget *fenetre_ouvrier,*fenetre_auth ;
fenetre_ouvrier=lookup_widget(button,"Gestion_ouvrier");
gtk_widget_destroy(fenetre_ouvrier);


}*/





void
on_facebook_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.facebook.com/doukali.youcef");
}


void
on_instagram_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
system("firefox https://www.instagram.com/doukali.youssef");
}


void
on_button56_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *eresp;

char id[20];
char NOM[20];
char Prenom[20];
char resp[20];
char CIN[20];
char messageRecla[20];
char jour[20];
char mois[20];
char annee[20];
char objet[20];
int nb1=0;
int nb2=0;

      
  FILE* F;

F=fopen("reclamation.txt","r");
if(F!=NULL)
{
    
    while(fscanf(F,"%s %s %s %s %s %s %s %s %s %s\n",id,NOM,Prenom,resp,CIN,messageRecla,jour,mois,annee,objet)!=EOF)
    {
        if((strcmp(resp,"Restauration")==0)){
        nb1++;
           }                                  
else
{
      nb2++;
 }
}

if(nb1>nb2){
    strcpy(resp,"Restauration");
}
else
{
    strcpy(resp,"Hebergement");
}

fclose(F);
eresp = lookup_widget(button, "label373");
gtk_label_set_text(GTK_LABEL(eresp),resp);


}

}


void
on_button7_quiter_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre;
fenetre = lookup_widget(button, "Gestion_reclam");
gtk_widget_destroy (fenetre);


}
