/*
 * Nicholas Schantz U08416544
 * nschantz21@gmail.com
 * C/C++ Programming II
 * 142605 Ray Mitchell
 * 2019-11-12
 * C2A7E1_main.c
 * Linux Ubuntu 16.04.4 LTS
 * g++ 5.4.0
 * 
 * Perform hashing function and store the words in ordered binary trees instead
 * of singly linked lists.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256                 /* size of input buffer */
#define BUFFMT "%255"                /* field width for input buffer scan */
#define MIN_ARGS 3                   /* fewest command line arguments */
#define FILE_ARG_IX 1                /* index of file name argument */
#define BINS_ARG_IX 2                /* index of bin count argument */

void *SafeMalloc(size_t size)
{
   void *vp;

   if ((vp = malloc(size)) == NULL)
   {
      fputs("Out of memory\n", stderr);
      exit(EXIT_FAILURE);
   }
   return(vp);
}

FILE *OpenFile(const char *fileName)
{
   FILE *fp;

   if ((fp = fopen(fileName, "r")) == NULL)
   {
      fprintf(stderr, "File \"%s\" didn't open.\n", fileName);
      perror(fileName);
      exit(EXIT_FAILURE);
   }
   return fp;
}

typedef struct Node NODE;
struct Node
{
   char *strng;         /* points to string this node represents */
   size_t count;        /* number of occurrences of this string */
   NODE *left, *right;  /* pointers to left and right children */
};

typedef struct          /* type of table array elements */
{
   size_t nodes;        /* # of list nodes for this bin */
   NODE *firstNode;     /* 1st node in this bin's tree */
} BIN;

typedef struct          /* type of hash table descriptor */
{
   size_t bins;         /* bins in hash table */
   BIN *firstBin;       /* first bin */
} TABLE;

int HashFunction(const char *key, size_t bins)  /* get bin value from key */
{
   return((int)(strlen(key) % bins));           /* value is character count % bins */
}

/* CreateTable creates and initializes the hash table and its bins */
TABLE *CreateTable(size_t bins)
{
   TABLE *hashTable;
   BIN *end;
   hashTable = (TABLE *)SafeMalloc(sizeof(TABLE));   /* alloc desc struct */
   hashTable->bins = bins;                           /* how many bins */
   /* alloc bins */
   hashTable->firstBin = (BIN *)SafeMalloc(bins * sizeof(BIN));
   end = hashTable->firstBin + bins;                      /* end of bins */

   for (BIN *bin = hashTable->firstBin; bin < end; ++bin) /* initialize bins */
   {
      bin->nodes = 0;                                     /* no btree nodes */
      bin->firstNode = NULL;                              /* no btree */
   }
   return(hashTable);
}

NODE *BuildTree(NODE *pNode, char *str, BIN *pBin)
{
   if (pNode == NULL)                                        /* string not found */
   {
      size_t length = strlen(str) + 1;                       /* length of string */

      pNode = (NODE *)SafeMalloc(sizeof(NODE));              /* allocate a node */
      pNode->strng = (char *)SafeMalloc(length);
      memcpy(pNode->strng, str, length);                     /* copy string */
      pNode->count = 1;                                      /* 1st occurrence */
      pNode->left = pNode->right = NULL;                     /* no subtrees */
      ++pBin->nodes;                                         /* increment bin count */
   }
   else
   {
      int result = strcmp(str, pNode->strng);                /* compare strings */

      if (result == 0)                                       /* new string == current */
         ++pNode->count;                                     /* increment occurrence */
      else if (result < 0)                                   /* new string < current */
         pNode->left = BuildTree(pNode->left, str, pBin);    /* traverse left */
      else                                                   /* new string > current */
         pNode->right = BuildTree(pNode->right, str, pBin);  /* traverse right */
   }
   return(pNode);
}

/*  PrintTree recursively prints the binary tree in pNode alphabetically */
void PrintTree(const NODE *pNode)
{
   if (pNode != NULL)                            /* if child exists */
   {
      PrintTree(pNode->left);                    /* traverse left */
      printf("%4d  %s\n", (int)pNode->count, pNode->strng);
      PrintTree(pNode->right);                   /* traverse right */
   }
}

/*  FreeTree recursively frees the binary tree in pNode */
void FreeTree(NODE *pNode)
{
   if (pNode != NULL)                            /* if child exists */
   {
      FreeTree(pNode->left);                     /* traverse left */
      FreeTree(pNode->right);                    /* traverse right */
      free(pNode->strng);                        /* free the string */ 
      free(pNode);                               /* free the node */ 
   }
}

/* PrintTable prints the hash table */
void PrintTable(const TABLE *hashTable)
{
   BIN *end;

   end = hashTable->firstBin + hashTable->bins;       /* end of bins */
   for (BIN *bin = hashTable->firstBin; bin < end; ++bin)  /* visit bins */
   {
      printf("%d entries for bin %d:\n", (int)bin->nodes, (int)(bin - hashTable->firstBin));
      /* print the binary tree */
      PrintTree(bin->firstNode);
   }
}

/* FreeTable frees the hash table */
void FreeTable(TABLE *hashTable)
{
   BIN *end;

   end = hashTable->firstBin + hashTable->bins;            /* end of bins */
   for (BIN *bin = hashTable->firstBin; bin < end; ++bin)  /* visit bins */
   {
      /* free binary tree within bin */
      FreeTree(bin->firstNode);
   }
   free(hashTable->firstBin);       /* free all bins */
   free(hashTable);                 /* free table descriptor */
}

int main(int argc, char *argv[])
{
   char buf[LINE_LEN];              /* word string buffer */
   char fileName[LINE_LEN];         /* file name buffer */
   int howManyBins;                 /* number of bins to create */
   TABLE *hashTable;                /* pointer to hash table */
   FILE *fp;

   /* Read file name from command line */
   if (argc < MIN_ARGS || sscanf(argv[FILE_ARG_IX], BUFFMT "s", fileName) != 1)
   {
      fprintf(stderr, "No file name specified on command line\n");
      return EXIT_FAILURE;
   }
   fp = OpenFile(fileName);

   /* Read bin count from command line */
   if (sscanf(argv[BINS_ARG_IX], "%d", &howManyBins) != 1)
   {
      fprintf(stderr, "No bin count specified on command line\n");
      return EXIT_FAILURE;
   }      
   hashTable = CreateTable((size_t)howManyBins);  /* allocate table array */

   /*
    * The following loop will read one string at a time from stdin until
    * EOF is reached.  For each string read the BuildList function will
    * be called to update the hash table.
    */
   while (fscanf(fp, BUFFMT "s", buf) != EOF) /* get string from file */
   {
      /* find appropriate bin */
      BIN *bin = &hashTable->firstBin[HashFunction(buf, (size_t)howManyBins)];
      /* add string to bin's tree */
      bin->firstNode = BuildTree(bin->firstNode, buf, bin);
   }
   fclose(fp);
   PrintTable(hashTable);                    /* print all strings */
   FreeTable(hashTable);                     /* free the table */
   return(EXIT_SUCCESS);
}
