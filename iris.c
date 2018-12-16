#include "iris.h"


list * CreateDataList(FILE * p_pfile, list * p_pflowerList, int p_nbData)
{
	if (!p_pfile)
		exit(-1);

	fseek(p_pfile, 0L, SEEK_SET);

	for (int i = 0; i < p_nbData; i++)
	{
		flower tmp;
		fscanf(p_pfile, "%f,%f,%f,%f,", &tmp.m_sepalWidth, &tmp.m_sepalLength, &tmp.m_petalWidth, &tmp.m_petalLength);
		fscanf(p_pfile, "%s", tmp.m_specieNamed);
		printf("%f, %f, %f, %f, %s\n", tmp.m_sepalWidth, tmp.m_sepalLength, tmp.m_petalWidth, tmp.m_petalLength, tmp.m_specieNamed);
        
		insererFin(p_pflowerList, tmp);
	}

    return p_pflowerList;
}

void insererFin(list * p_pflowerList, flower p_dataFlower)
{
	flowerListNode * pNouveau = creerNoeudList(p_dataFlower);

	if (p_pflowerList->m_head == NULL)
	{
		p_pflowerList->m_head = pNouveau;
	}
	else
	{
		flowerListNode * pCourant = p_pflowerList->m_head;

		while (pCourant->m_next != NULL)
		pCourant = pCourant->m_next;

		pCourant->m_next = pNouveau;
	}
}



flowerListNode * creerNoeudList(flower p_dataFlower)
{
	flowerListNode * pNouveau = (flowerListNode*)calloc(1, sizeof(flowerListNode));

	if (pNouveau == NULL)
		exit(-1);

	pNouveau->m_dataFlower = p_dataFlower;
	pNouveau->m_next = NULL;

	return pNouveau;
}



int CountNbLignes(FILE * p_pfile)
{
	int c;
	int nbLignes = 0;
	int c2 = '\0';

	while ((c = fgetc(p_pfile)) != EOF)
	{
		if (c == '\n')
			nbLignes++;
		c2 = c;
	}

	/* Ici, c2 est égal au caractère juste avant le EOF. */
	if (c2 != '\n')
		nbLignes++; /* Dernière ligne non finie */

	return nbLignes;
}


void afficherList(list * p_pflowerList)
{
	if (p_pflowerList == NULL)
		exit(-1);

	flowerListNode * pCourant = p_pflowerList->m_head;
	printf("\n\n Ma Liste de Fleur et leurs caractéristiques : \n");
	printf("Longueur Sepal | Largeur Sepal | Longueur Petal | Largeur Petal | Nom Espece \n");
		  
	while (pCourant != NULL)
	{
		printf("   %f    |    %f   |    %f    |    %f   | %s\n", pCourant->m_dataFlower.m_sepalWidth, pCourant->m_dataFlower.m_sepalLength, pCourant->m_dataFlower.m_petalWidth, pCourant->m_dataFlower.m_petalLength, pCourant->m_dataFlower.m_specieNamed);
		pCourant = pCourant->m_next;
	}
	printf("\n");
}


void NbFlowerBySpecies(treeNode * p_pflowerNode)
{

    if (p_pflowerNode == NULL)
		exit(-1);
    
    flowerListNode * pCourant = p_pflowerNode->m_irisList->m_head;
    
    while (pCourant != NULL)
    {
        if (strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-setosa") == 0)
            p_pflowerNode->m_tabValue[0] += 1;
        else if (strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-virginica") == 0)
            p_pflowerNode->m_tabValue[1] += 1;
        else if (strcmp(pCourant->m_dataFlower.m_specieNamed, "Iris-versicolor") == 0)
            p_pflowerNode->m_tabValue[2] += 1;
        else
        {
            printf("Espece de fleur inconnu\n");
            exit(-1);
        }
        pCourant = pCourant->m_next;
    }
}

void InitialisationMinEtMax(list * p_pflowerList)
{
    float min = 100;
    float max = 0;
    
    if (p_pflowerNode == NULL || p_pflowerNode->m_irisList == NULL)
		exit(-1);
    
    
    flowerListNode * pCourant = p_pflowerNode->m_irisList->m_head;
    
    
    while (pCourant != NULL)
    {
        if (pCourant->m_dataFlower.m_sepalLength <= min)
            p_pflowerNode->m_parameterTab[0].min = pCourant->m_dataFlower.m_sepalLength;
        if (pCourant->m_dataFlower.m_sepalWidth <= min)
            p_pflowerNode->m_parameterTab[1].min = pCourant->m_dataFlower.m_sepalWidth;
        if (pCourant->m_dataFlower.m_petalLength <= min)
            p_pflowerNode->m_parameterTab[2].min = pCourant->m_dataFlower.m_petalLength;
        if (pCourant->m_dataFlower.m_petalWidth <= min)
            p_pflowerNode->m_parameterTab[3].min = pCourant->m_dataFlower.m_petalWidth;
        
        if (pCourant->m_dataFlower.m_sepalLength >= max)
            p_pflowerNode->m_parameterTab[0].max = pCourant->m_dataFlower.m_sepalLength;
        if (pCourant->m_dataFlower.m_sepalWidth >= max)
            p_pflowerNode->m_parameterTab[1].max = pCourant->m_dataFlower.m_sepalWidth;
        if (pCourant->m_dataFlower.m_petalLength >= max)
            p_pflowerNode->m_parameterTab[2].max = pCourant->m_dataFlower.m_petalLength;
        if (pCourant->m_dataFlower.m_petalWidth >= max)
            p_pflowerNode->m_parameterTab[3].max = pCourant->m_dataFlower.m_petalWidth;
        
        pCourant = pCourant->m_next;
    }
}




float * Compared(treeNode * p_pflowerNode)
{
    
    flowerListNode * pCourant = p_pflowerNode->m_irisList->m_head;
    float tab[3];
    
    
    for (int i = 0 ; i < 4 ; i ++)
    {
        int min = p_pflowerNode->m_parameterTab[i].min;
        int max = p_pflowerNode->m_parameterTab[i].max;
        for (int j = min ; i <= max ; i += 0.05)
        {
            while(pCourant != NULL)
            {
                
                
            }
        }
    }
}

/*treeNode * CreateNode(treeNode * p_pflowerNode)
{
    p_pflowerNode * pSon = 
    
    
}*/

