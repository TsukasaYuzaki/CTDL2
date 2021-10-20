#include <iostream>

using namespace std;
//Cay nhi phan, voi node(left) < node < node(right)


typedef struct Node{
    int data;
    Node* left;
    Node* right;
}tree;


////Ham dieu huong cay
int LeftT(int value, tree* root){
    return value < root->data;
}
int RightT(int value, tree* root){
    return value > root->data;
}




/*Ham insert them gia tr
-Neu Node == NULL thi them gia tri vao do
-Gia tri < root => them vao root trai
-Gia tri > root => them vao root phai
*/
tree* add(tree* root, int value){
    //Kiem tra goc da co gia tri chua
    if(root == NULL){
        tree* node = new tree;
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if(LeftT(value, root)){
        root->left = add(root->left, value);
    }
    else{
        root->right = add(root->right, value);
    }
    return root;
}

//Duyet cay nhi phan:

//Tien tu: NLR
void NLRDeQuy(tree* root){
    if(root != NULL){
        cout << root->data << " ";
        NLRDeQuy(root->left);
        NLRDeQuy(root->right);
    }
}

void NLR(tree* root){
	tree *p;
	while( root!=NULL ){
		if( root->left == NULL ){
			cout<< root->data << " ";
			root = root->right;
		}
		else{
			p = root->left;
			while(p->right && p->right != root ){
				p = p->right;
			}
			if( p->right == NULL ){
				p->right = root;
				cout<< root->data << " ";
				root = root->left;
			}
			else{
				p->right = NULL;
			//	cout<< root->data << " ";
				root = root->right;
			}
		}
	}
}





//Trung tu: LNR
void LNRDeQuy(tree *root){
   if(root != NULL){
        LNRDeQuy(root->left);
        cout << root->data << " ";
        LNRDeQuy(root->right);
    }
}

void LNR(tree* root){
	tree *p;
	while( root!=NULL ){
		if( root->left == NULL ){
			cout<< root->data << " ";
			root = root->right;
		}
		else{
			p = root->left;
			while(p->right && p->right != root ){
				p = p->right;
			}
			if( p->right == NULL ){
				p->right = root;
				//cout<< root->data << " ";
				root = root->left;
			}
			else{
				p->right = NULL;
				cout<< root->data << " ";
				root = root->right;
			}
		}
	}
}


//Hau tu: LRN
void LRNDeQuy(tree *root){
    if(root != NULL){
        LRNDeQuy(root->left);
        LRNDeQuy(root->right);
        cout << root->data << " ";
    }
}

int main(){
    /* tree:
             50
		    /  \
		  30    70
		  /\	 /\
		20  40  60 90
		/
      10

	*/
    int n;
    tree* root = NULL;
    cout << "Nhap vao so phan tu cua cay: ";
    cin >> n;
    for(int i = 1; i<=n; i++){
        int a;
        cout << "\nNhap vao phan tu thu " << i << " :";
        cin >> a;
        root = add(root, a);
    }


    cout << "\n";
    cout << root->data;
    cout << "\n";



    cout << "\nDuyet tien tu(NLR): ";
    NLR(root);
    cout << "\nDuyet trung tu(LNR): ";
    LNR(root);
    cout << "\nDuyet hau tu(LRN): ";
    LRNDeQuy(root);
    return 0;
}
