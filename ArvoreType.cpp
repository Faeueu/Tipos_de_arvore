#include <iostream>
using namespace std;

struct NoArvore{
    int data;
    NoArvore *left;
    NoArvore *right;
};

NoArvore* inserirNo(int value) {
    NoArvore* newNo = new NoArvore;
    newNo->data = value;
    newNo->left = NULL;
    newNo->right = NULL;
    return newNo;
}

int altura(NoArvore *raiz){
    if(raiz == NULL){
        return 0;
    }
    return 1+max(altura(raiz->left), altura(raiz->right));
}

int contarNo(NoArvore *raiz){
    if (raiz==NULL) {
        return 0;
    }
    return 1 + contarNo(raiz->left) + contarNo(raiz->right);
}

bool arvoreCheia(NoArvore *raiz){
    if(raiz == NULL){
        return true;
    }

    if(raiz->left == NULL && raiz->right == NULL){
        return true;
    }

    if((raiz->left == NULL && raiz->right != NULL) || (raiz->left != NULL && raiz->right == NULL)){
        return false;
    }

    return (arvoreCheia(raiz->left) && arvoreCheia(raiz->right));
}

bool arvorePerfeita(NoArvore *raiz){
    if(raiz == NULL){
        return true;
    }

    int alturaEsquerda = altura(raiz->left);
    int alturaDireita = altura(raiz->right);

    if(alturaEsquerda == alturaDireita){
        return arvorePerfeita(raiz->left) && arvorePerfeita(raiz->right);
    }
    return false;
}

bool arvoreCompleta(NoArvore *raiz, int indice, int NumNo){
    if(raiz == NULL){
        return true;
    }

    if(indice >= NumNo){
        return false;
    }

    return arvoreCompleta(raiz->left, 2*indice+1, NumNo) &&
            arvoreCompleta(raiz->right, 2*indice+2, NumNo);

}

bool ArvoreCompleta(NoArvore *raiz){
    int alturaArvore = altura(raiz);
    int totalNo = contarNo(raiz);

    return arvoreCompleta(raiz, 0, totalNo) && (totalNo == (1 <<alturaArvore)-1);
}

bool arvoreBalanceada(NoArvore *raiz){
    if(raiz == NULL){
        return true;
    }

    int alturaEsquerda = altura(raiz->left);
    int alturaDireita = altura(raiz->right);

    if(alturaEsquerda - alturaDireita <= 1 && alturaDireita - alturaEsquerda <= 1){
        return arvoreBalanceada(raiz->left) && arvoreBalanceada(raiz->right);
    }
    return false;
}

bool arvoreDegenerada(NoArvore *raiz){
    if(raiz == NULL || (raiz->left == NULL && raiz->right == NULL)){
        return true;
    }
    
    if((raiz->left == NULL && raiz->right != NULL) || (raiz->left != NULL && raiz->right == NULL)){
        return arvoreDegenerada(raiz->left) && arvoreDegenerada(raiz->right);
    }
    return false;
}

bool arvoreDistorcida(NoArvore *raiz){
    if(raiz == NULL || (raiz->left == NULL && raiz->right == NULL)){
        return true;
    }

    if((raiz->left == NULL && raiz->right != NULL) || (raiz->left != NULL && raiz->right == NULL)){
        return arvoreDistorcida(raiz->left) || arvoreDistorcida(raiz->right);
    }
    return false;
}


int main(){
    NoArvore *raiz = inserirNo(1);
    raiz->left = inserirNo(2);
    raiz->right = inserirNo(3);
    raiz->left->left = inserirNo(4);
    raiz->left->right = inserirNo(5);
    raiz->right->left = inserirNo(6);
    raiz->right->right = inserirNo(7);
    raiz->left->left->left = inserirNo(8);
    raiz->left->left->right = inserirNo(9);
    raiz->left->right->left = inserirNo(10);
    raiz->left->right->right = inserirNo(11);

    cout << "A arvore e cheia? " << endl;
    if(arvoreCheia(raiz)){
        cout << "Sim";
    }else{
        cout << "Nao";
    }
    cout << endl;

    cout << "Arvore perfeita?" << endl;
    if(arvorePerfeita(raiz)){
        cout << "Sim";
    }else{
        cout << "Nao";
    }
    cout << endl;

    cout << "Arvore completa?" << endl;
    if(ArvoreCompleta(raiz)){
        cout << "Sim";
    }else{
        cout << "Nao";
    }
    cout << endl;

    cout << "Arvore balanceada?" << endl;
    if(arvoreBalanceada(raiz)){
        cout << "Sim";
    }else{
        cout << "Nao";
    }
    cout << endl;

    cout << "Arvore degenerada?" << endl;
    if(arvoreDegenerada(raiz)){
        cout << "Sim";
    }else{
        cout << "Nao";
    }
    cout << endl;

    cout << "Arvore distorcida?" << endl;
    if(arvoreDistorcida(raiz)){
        cout << "Sim";
    }else{
        cout << "Nao";
    }


    
    delete raiz;
    return 0;
}
