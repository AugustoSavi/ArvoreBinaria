#include <iostream>
#include <cstdlib>
#include <stack>
//metodos classe no

using namespace std;


class no
{
    private:
        no *esq;
        no *dir;
        int info;
    public:
        no();
        no(int info);
        ~no();
        void lista();
        no *getesq();
        void setesq(no *esq);
        no *getdir();
        void setdir(no *dir);
        int getinfo();
        void setinfo(int info);
};


class tree
{
    private:
        no *arv;

    public:
        tree();
        ~tree();
        no *get();
        void set(no *aux);
        no* consulta(int x);
        void insere(int x);
        void destroe(no *aux);
        void preordem(no *aux);
        void posordem(no *aux);
        void inordem(no *aux);
        void busca_remocao(int x);
        void remove(no *aux,no *pai);
        void imprimearvore();       
        void decrescente( no* aux);
        int soma(no *aux, int x);
        int qtdFolha(no *aux, int x);
        int qtdInfo(no *aux, int x);        
        //*****************************************
        void menu();
        //*****************************************

};


no::no()
{

}

no::no(int info)
{
    dir = NULL;
    esq = NULL;
    this->info = info;

}

no::~no()
{
    cout<<"Valor exclu�do: "<<info;
}

void no::lista()
{
    cout<<info<<"\n";
}

no *no::getesq()
{
    return esq;
}

void no::setesq(no *esq)
{
    this->esq = esq;
}

no *no::getdir()
{
    return dir;
}

void no::setdir(no *dir)
{
    this->dir=dir;
}

int no::getinfo()
{
    return info;
}

void no::setinfo(int info)
{
    this->info = info;
}



//metodos classe tree


tree::tree()
{
    arv=NULL;
}

tree::~tree()
{

}

no *tree::get()
{
    return arv;
}

void tree::set(no *aux)
{
    this->arv=aux;
}


no* tree::consulta(int x)
{
    no *aux;

        aux = arv;
        while(aux!=NULL && aux->getinfo() != x)
        {       
            if (x<aux->getinfo())
            	 aux=aux->getesq();
             else
               aux=aux->getdir();
        }
            
        return aux;
        
}

void tree::destroe(no *aux)
{
}

void tree::insere(int x){
        
     no *aux;
    no *pai;
    if(arv==NULL)
    {
        aux = new no(x);
        arv = aux;
    }
    else
    {
        pai = aux = arv;
        while (aux!=NULL)
        {
            if(x> aux->getinfo())
            {
                pai=aux;
                aux=aux->getdir();
            }
            else
            {
               pai=aux;
               aux=aux->getesq();
            }
        }
        aux = new no(x);
        
            if(x<pai->getinfo())
            {
                pai->setesq(aux);
            }
            else
            {
                pai->setdir(aux);
            }
    }          
}



void tree::preordem(no *aux)
    {
          if(aux!=NULL)
            {aux->lista();
            preordem(aux->getesq());
            preordem(aux->getdir());
            }


}

void tree::posordem(no *aux)
{
     	          if(aux!=NULL)
     	          {
	           	          posordem(aux->getesq());
	           	          posordem(aux->getdir());
	           	          aux->lista();
		          }
}

void tree::inordem(no *aux)
{
     	         if(aux!=NULL)
     	         {
	          	         inordem(aux->getesq());
	          	         aux->lista();
	          	         inordem(aux->getdir());
		         }
}

void tree::busca_remocao(int x)
{
      no *aux, *pai;
      pai=NULL;
      aux = arv;
      while(aux!=NULL && x!=aux->getinfo())
      {
           pai = aux;
           if (x<aux->getinfo())
           	 aux=aux->getesq();
           else
              aux=aux->getdir();
      }
      if(aux!=NULL)
          remove(aux, pai);
      else
         cout<<"Valor n�o encontrado na arvore";

}

void tree::remove(no *aux,no *pai)
{
     no *mm;
     if(aux->getdir()==NULL && aux->getesq()==NULL)
     {
            if (pai==NULL) // Pode ser Pai== ARV;.. pois pai � o primeiro no da arvore
              arv==NULL;
            else
               if(aux->getinfo() < pai->getinfo())
                  pai->setesq(NULL);
               else
                  pai->setdir(NULL);
            delete(aux);
      }
      else
      {
            if(aux->getdir()==NULL)
            {
                 if(pai==NULL)
                     arv=arv->getesq();
                 else
                     if(aux->getinfo() < pai-> getinfo())
                        pai->setesq(aux->getesq());
                     else
                        pai->setdir(aux->getesq());
                 delete(aux);
            }
            else
            if(aux->getesq()==NULL)
            {
                 if(pai == NULL)
	        arv = arv-> getdir();
                 else
                     if(aux->getinfo() < pai-> getinfo())
                        pai->setesq(aux->getdir());
                     else
                        pai->setdir(aux->getdir());
                 delete(aux);
	}
            else
           {
             pai = aux;
	mm = aux->getesq();
	while(mm->getdir()!=NULL)
	{
	    pai = mm;
	    mm = mm->getdir();
             }
             aux->setinfo(mm->getinfo());
             if(mm->getinfo() > pai->getinfo())
                   pai->setdir(mm->getesq());
             else
                  pai->setesq(mm->getesq());

           }
       }


}
//-------------------------------------------------------------
void tree::imprimearvore()
{
      stack<no*> globalStack;
      globalStack.push(arv);
      int EspacoBranco = 32;
      bool LinhaVazia  = false;

      cout <<
      "......................................................";
      cout << endl;
      while(LinhaVazia==false)
         {
         stack<no*> localStack;
         LinhaVazia = true;

         for(int j=0; j<EspacoBranco; j++)
            cout << ' ';

         while(globalStack.empty()==false)
            {
            no* temp = globalStack.top();
            globalStack.pop();
            if(temp != NULL)
               {
               cout << temp->getinfo();
               localStack.push(temp->getesq());
               localStack.push(temp->getdir());

               if(temp->getesq() != NULL ||  temp->getdir() != NULL)
                  LinhaVazia = false;
               }
            else
               {
               cout << "--";
               localStack.push(NULL);
               localStack.push(NULL);
               }
            for(int j=0; j<EspacoBranco*2-2; j++)
               cout << ' ';
            }  //end while globalStack not empty
         cout << endl;
         EspacoBranco /= 2;
         while(localStack.empty()==false)
            {
            globalStack.push( localStack.top() );
            localStack.pop();
            }
         }  //end while LinhaVazia is false
      cout <<
      "......................................................";
      cout << endl;
      }  //end displayTree()

              void tree::decrescente( no* aux){
	      	      if(aux!=NULL)
	      	      {
		       	      decrescente(aux->getdir());
		       	      aux->lista();
		       	      decrescente(aux->getesq());
			      }
}
         int tree::soma(no *aux, int x){

         	        	 if(aux!=NULL){
		  x = soma(aux->getesq(), x);
		  x=x+aux->getinfo();
	            	 x= soma(aux->getdir(), x);



           }
           return x;

}

       int tree::qtdInfo(no *aux, int x){

           	         if(aux!=NULL){
		  x = qtdInfo(aux->getesq(), x);
		  x++;
	            	 x = qtdInfo(aux->getdir(), x);
		 }
return x;
}

int tree::qtdFolha(no *aux, int x)
{
        if(aux!=NULL){
		  x = qtdFolha(aux->getesq(), x);
		 x = qtdFolha(aux->getdir(), x);
		 if(aux->getdir()==NULL && aux->getesq()==NULL)
		 x++;
		 }
return x;
}


void tree::menu()
{
    cout<<"\n\n########################### MENU ####################################";
    cout<<"\n#                                                                   #";
    cout<<"\n#            [ 1 ] Inserir                 [ 1 ]                    #";
    cout<<"\n#            [ 2 ] Remover                 [ 2 ]                    #";
    cout<<"\n#            [ 3 ] Consultar em Pre-Ordem  [ 3 ]                    #";
    cout<<"\n#            [ 4 ] Consultar em Pos-Ordem  [ 4 ]                    #";
    cout<<"\n#            [ 5 ] Consultar em In-Ordem   [ 5 ]                    #";
    cout<<"\n#            [ 6 ] Imprime                 [ 6 ]                    #";
    cout<<"\n#            [ 7 ] Consulta decrescente    [ 7 ]                    #";
    cout<<"\n#            [ 8 ] Somar                   [ 8 ]                    #";
    cout<<"\n#            [ 9 ] Quantidade de elementos [ 9 ]                    #";
    cout<<"\n#            [ 10] Quantidade de folhas    [ 10]                    #";
    cout<<"\n#            [ 11] metodo consulta         [ 11]                    #";
    cout<<"\n#            [ 0 ] Sair                    [ 0 ]                    #";
    cout<<"\n#                                                                   #";
    cout<<"\n#####################################################################";
}


int main()
{

    int x,opcao;
    tree *marv = new tree;
    

        


    do
    {
 

       //system("clear");
       marv->menu();       
       cout<<"\n\n\tInforme a opcao desejada: ";
       cin>>opcao;     

       switch(opcao)
       {
         case 1://insere elementos
         cout<<"Digite o valor a ser inserido: ";
         cin>>x;
         no *raiz;
         raiz = marv->consulta(x);

         if (raiz == NULL)      
                marv->insere(x);

         else
                  cout<<"Elemento j� existe";
         break;
     
         case 2: //Remover
         if(marv!=NULL)
         {
             cout<<"Digite valor a ser removido: ";
             cin>>x;
			marv->busca_remocao(x);
         }
         else
         cout<<"Arvore Vazia";
	                    
         break;
            
         case 3: //Consulta em pre-Ordem
         marv->preordem(marv->get() );
         break;
     
         case 4: //Consulta em pos-Ordem
         marv->posordem(marv->get());
         break;
            
         case 5: //consulta em in-Ordem
         marv->inordem(marv->get());
         break;
         
         case 6: //Imprimir
         marv->imprimearvore();
         break;
         
         case 7: //Imprime decrescente
   	     marv->decrescente(marv->get());
         break;
         
         case 8: // Soma elementos

          x = marv->soma(marv->get(), 0);
          cout<<"Soma dos elementos: "<<x<<"\n";
         break;
         
         case 9:
         	         x = marv->qtdInfo(marv->get(), 0);
         	         cout<<"Quantidade de elementos: "<<x<<"\n";
         break;
         
         case 10:
         	         x= marv->qtdFolha(marv->get(), 0);
         	         cout<<"Quantidade de Folhas: "<<x<<"\n";
       	         break;
   	     
        case 11:
            cout<<"Digite o valor a ser consultado: ";
            cin>>x;
            marv->consulta(x);
        break;
         
         
            
       }
       
       
       getchar();
     } while(opcao!=0);
     

     return 1;
}     
     
