#include<stdio.h>
#include<stdlib.h>

#define NUM_OF_CHARACTERS 511
#define COMBINED_NODE -1
#define DELETED_NODE_WEIGHT -1
#define NOT_FOUND -1
#define NO_WEIGHT 0
#define FILE_MAX_NUM_OF_CHARACTERS 1024*1024
#define MAX_HUFFMAN_CODE_BITS 8

typedef struct node {
    char character;
    long long weight;
    struct node* left;
    struct node* right;
}*Node, * Tree, node;

//malloc������
void handleAllocError(void* pointer) {
    if (NULL == pointer) {
        printf("Failed to alloc memory.");
        exit(1);
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

//�ҳ����ڵ�������Ȩ����С���������ڵ���±�
//�Ҳ�����ΪNOT_FOUND
void findSmallWeight(Tree* treeArray, int* first, int* second) {
    int i = 0;
    for (i = 0; treeArray[i] == NULL && i < NUM_OF_CHARACTERS; i++);
    if (i == NUM_OF_CHARACTERS) {
        *first = NOT_FOUND;
        *second = NOT_FOUND;
        return;
    }
    *first = i;
    *second = i;
    for (int j = i; j < NUM_OF_CHARACTERS; j++) {
        if (treeArray[j] = NULL) {
            continue;
        }
        if (treeArray[j]->weight < treeArray[*first]->weight) {
            *second = *first;
            *first = j;
        }
        else if (treeArray[j]->weight > treeArray[*second]->weight) {
            *second = j;
        }
    }
}

//����Ȩ�����飬���ع�������
Tree buildHaffmanTree(int* weights) {
    //��ʼ����
    Node treeArray[NUM_OF_CHARACTERS];
    for (int i = 0; i < NUM_OF_CHARACTERS; i++) {
        if (weights[i] == 0) {
            treeArray[i] = NULL;
            continue;
        }
        treeArray[i] = (Node)malloc(sizeof(node));
        handleAllocError(treeArray[i]);
        treeArray[i]->character = (char)i;
        treeArray[i]->weight = weights[i];
        treeArray[i]->left = NULL;
        treeArray[i]->right = NULL;
    }

    //�������ڵ�
    int firstWeight;
    int secondWeight;
    Tree root = NULL;

    //������
    while (1) {
        //�����½ڵ㣬���ӽڵ�
        findSmallWeight(treeArray, &firstWeight, &secondWeight);
        if (firstWeight == secondWeight) {
            break;
        }
        root = (Tree)malloc(sizeof(node));
        handleAllocError(root);
        root->right = treeArray[firstWeight];
        root->left = treeArray[secondWeight];
        root->character = COMBINED_NODE;
        root->weight = treeArray[firstWeight]->weight + treeArray[secondWeight]->weight;

        //��β
        treeArray[firstWeight] = root;
        treeArray[secondWeight] = NULL;
    }
    return root;
}

//��ȡ��������ļ�
char* readFromFile(const char* fileName) {
    FILE* filePointer = fopen(fileName, "r");
    if (NULL == filePointer) {
        printf("Failed to open the file.");
        exit(1);
    }
    char* fileContent = (char*)malloc(sizeof(char) * FILE_MAX_NUM_OF_CHARACTERS);
    for (int i = 0; i < NUM_OF_CHARACTERS; i++) {
        fileContent[i] = 0;
    }
    handleAllocError(fileContent);
    if (fclose(filePointer) == -1) {
        printf("Failed to close the file.");
        exit(1);
    };
    int character_count = 0;
    while (fileContent[character_count] = fgetc(filePointer) && fileContent[character_count] != EOF);
    return fileContent;
}


char* readFromHuffmanFileAndDecode(const char* fileName) {

}

//ʹ�ñ������ļ�����Ϣ����Ȩֵ
void generateFileStatistics(int* weights, char* fileContent) {
    for (int i = 0; i < NUM_OF_CHARACTERS; i++) {
        weights[i] = 0;
    }
    for (long long i = 0; fileContent[i] != EOF; i++) {
        weights[fileContent[i]]++;
    }
    return;
}

//Ѱ��ĳ���ַ��Ĺ���������,Ԥ��Ϊchar�������MAX_HUFFMAN_CODE_BITS,Ԥ��ȫ����ա�
//����ֵ1��ʾ�ҵ���
//������������0��1
int findHuffmanCodingOfACharacter(Tree huffmanTree, char character, char* codeBits, int* bitsPosition) {
    if (huffmanTree == NULL) {
        return 0;
    }
    if (huffmanTree->character = character) {
        return 1;
    }
    else if (findHuffmanCodingOfACharacter(huffmanTree->left, character, codeBits, bitsPosition)) {
        codeBits[*bitsPosition] = 0;
        (* bitsPosition)++;
        return 1;
    }
    else if (findHuffmanCodingOfACharacter(huffmanTree->right, character, codeBits, bitsPosition)) {
        codeBits[*bitsPosition] = 1;
        (* bitsPosition)++;
        return 1;
    }
    else {
        return 0;
    }
}


//ʹ�ù����������б���,���ر������λλ��
long long HuffmanCoding(Tree huffmanTree, char* fileContent, char* huffmanCode) {
    long long huffmanI = 0;
    for (long long i = 0; fileContent[i] != EOF; i++) {
        int bitsPosition = 0;
        char bitsArray[MAX_HUFFMAN_CODE_BITS] = { 0 };
        findHuffmanCodingOfACharacter(huffmanTree, fileContent[i], bitsArray, &bitsPosition);
        for (int i = 0; i < bitsPosition; i++) {
            huffmanCode[huffmanI] = bitsArray[bitsPosition];
            huffmanI++;
        }
    }
    return huffmanI;
}

//������������д���ļ�
void writeToFile(const char* fileName, char* HuffmanCoding, Tree HuffmanTree) {

}




















int main() {

}