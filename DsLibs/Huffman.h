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

//malloc错误处理
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

//找出树节点数组中权重最小的那两个节点的下标
//找不到置为NOT_FOUND
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

//输入权重数组，返回哈夫曼树
Tree buildHaffmanTree(int* weights) {
    //初始化树
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

    //建立根节点
    int firstWeight;
    int secondWeight;
    Tree root = NULL;

    //建立树
    while (1) {
        //建立新节点，右子节点
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

        //收尾
        treeArray[firstWeight] = root;
        treeArray[secondWeight] = NULL;
    }
    return root;
}

//读取被编码的文件
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

//使用被编码文件的信息生成权值
void generateFileStatistics(int* weights, char* fileContent) {
    for (int i = 0; i < NUM_OF_CHARACTERS; i++) {
        weights[i] = 0;
    }
    for (long long i = 0; fileContent[i] != EOF; i++) {
        weights[fileContent[i]]++;
    }
    return;
}

//寻找某个字符的哈夫曼编码,预先为char数组存下MAX_HUFFMAN_CODE_BITS,预先全部清空。
//返回值1表示找到了
//哈夫曼编码左0右1
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


//使用哈夫曼树进行编码,返回编码的哨位位置
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

//将哈夫曼编码写入文件
void writeToFile(const char* fileName, char* HuffmanCoding, Tree HuffmanTree) {

}




















int main() {

}