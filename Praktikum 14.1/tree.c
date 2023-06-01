#include <stdio.h>
#include <stdlib.h>

typedef struct node tree;
typedef char dataType;

struct node
{
    tree *kiri;
    tree *kanan;
    dataType data;
};

void bentuk();
void sisip();
int menu_kunjungan();
void preorder(tree *);
void inorder(tree *);
void postorder(tree *);
tree *cari(tree *, dataType);

tree *root = NULL, *new_node, *p, *q;

int main()
{
    char opsi, opsi1, opsi2, kar;
    int kunjungan;
    puts("MEMBENTUK SEBUAH TREE");
    bentuk();
    fflush(stdin);
    do
    {
        kunjungan = menu_kunjungan();

        printf("Hasil Penelusuran menggunakan ");
        switch (kunjungan)
        {
        case 1:
            printf("preorder : ");
            preorder(root);
            break;
        case 2:
            printf("inorder : ");
            inorder(root);
            break;
        case 3:
            printf("postorder : ");
            postorder(root);
            break;
        default:
            exit(0);
        }
        fflush(stdin);
        printf("\nMau mode yang lain [y/t] ? ");
        opsi1 = getchar();
    } while (opsi1 == 'y' || opsi1 == 'Y');

    puts("\n\nMencari data dalam tree..");
    do
    {
        fflush(stdin);
        printf("Masukkan data yang dicari : ");
        kar = getchar();

        if (cari(root, kar) == NULL)
            printf("%c tidak ada dalam tree\n", kar);
        else
            printf("%c ada dalam tree\n", kar);
        fflush(stdin);
        printf("Mau mencari lagi ? ");
        opsi2 = getchar();
    } while (opsi2 == 'y' || opsi2 == 'Y');
}

void bentuk()
{
    dataType data[10];
    int i = 0;

    printf("Masukkan data TREE : ");
    gets(data);
    while (data[i] != '\0')
    {
        new_node = (tree *)malloc(sizeof(tree));
        if (new_node == NULL)
        {
            puts("Memory gagal dialokasikan");
            exit(0);
        }
        else
        {
            new_node->data = data[i];
            new_node->kanan = NULL;
            new_node->kiri = NULL;
        }
        i++;
        sisip();
    }
}

void sisip()
{
    if (root == NULL)
        root = new_node;
    else
    {
        p = root;
        q = root;
        while (q != NULL && new_node->data != p->data)
        {
            p = q;
            if (new_node->data < p->data)
                q = p->kiri;
            else
                q = p->kanan;
        }
        if (new_node->data != p->data)
        {
            if (new_node->data < p->data)
                p->kiri = new_node;
            else
                p->kanan = new_node;
        }
    }
}

int menu_kunjungan()
{
    int pilihan;
    puts("\nPilih Penelusuran Tree");
    puts("1. Preorder");
    puts("2. Inorder");
    puts("3. Postorder");
    printf("Pilihan anda : ");
    scanf("%d", &pilihan);
    return pilihan;
}

void preorder(tree *root)
{
    if (root != NULL)
    {
        printf("%c", root->data);
        preorder(root->kiri);
        preorder(root->kanan);
    }
}

void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->kiri);
        printf("%c", root->data);
        inorder(root->kanan);
    }
}

void postorder(tree *root)
{
    if (root != NULL)
    {
        postorder(root->kiri);
        postorder(root->kanan);
        printf("%c", root->data);
    }
}

tree *cari(tree *root, dataType data)
{
    if (root == NULL)
        return NULL;
    else if (data < root->data)
        return (cari(root->kiri, data));
    else if (data > root->data)
        return (cari(root->kanan, data));
    else if (data == root->data)
        return root;
}