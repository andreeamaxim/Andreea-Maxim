/*

Consideram ca suntem  alocare dinamica a memoriei
1.
.
.
. => Lucru cu siruri de caractere
Consideram incheiat acest capitol

Facem o legatura cu alta zona de materie
folosind metode de alocare mecanica si practic in  cap in care am intrat
este vorba despre arbori binari alocati dinamic

1. Arbori binari alocare dinamica
Aplicatie: Un algoritm de compresie folosind algoritmul codului Huffman
Pasi:
1. Text -> frecventele de aparitie ale caracterelor
2. sortare vectorului de frecventa
3. constructia arborului de compresie
4. verificare RSD SRD SDR
5. afisare
*/

#include <iostream>
using namespace std;
int mystrlen(char *str)
{
    int len = 0;
    int i;
    for (i=0; str[i] != 0 ; i++)
    {
        len++;
    }
    return(len);
}

struct litera {
                int frecventa;
                string caracter;
              }
              litere[100];

struct nod    {
               int sus;
               nod *stanga=NULL,*dreapta=NULL;
              }
            A[100];
int count=1;
int dictionar(char *str)
{
    int max=-1;
    int V[176];
    for (int i=1;i<=176;i++)
        V[i]=0;
    for(int i=0;i<=mystrlen(str);i++)
    {
        V[str[i]]++;
        if(V[str[i]]>max) max=V[str[i]];
    }
    while(max!=0)
    {
        for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if(V[ch]==max)
                {
                    litere[count].caracter=ch;
                    litere[count].frecventa=V[ch];
                    count++;
                }
            }
        max--;
    }
    /*for(int x=1;x<count;x++)
    {
        cout<<litere[x].caracter<<" "<<litere[x].frecventa<<endl;
    }*/


}
void inorder(nod* node)
{
    if (!node) // end the recursion if node == nullptr
       return;
    inorder(node->stanga);            // display the left subtree
    std::cout << node->sus << " "; // display the current node
    inorder(node->dreapta);           // display the right subtree
}

   char *a=new char;
    int main (){
   char temp;
   cout<<"Introduceti cuvantul: ";
   cin.get(a,100);
   dictionar(a);
   struct nod arbore[count];
   for (int i=1;i<=count;i++)
    arbore[i].sus=litere[i].frecventa;
struct nod arbore2[count-1];
arbore2[count-1].sus=arbore[count].sus+arbore[count].sus;
arbore2[count-1].stanga=&arbore[count-1];
arbore2[count-1].dreapta=&arbore[count];
for(int i=count-2;i>=1;i--)
{
    arbore2[i].sus=arbore2[i].sus+arbore[i-1].sus;
    arbore2[i].stanga=&arbore[i-1];
    arbore2[i].dreapta=&arbore2[i];
}
inorder(arbore2);




return 0;
}

