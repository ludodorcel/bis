#include "iris.h"
#include "entropy.h"

int main(int argc, char **argv)
{
    list * flowerList = (list*)calloc(1, sizeof(list));
    treeNode * arbreDeDecision = (treeNode *)calloc(1, sizeof(treeNode));
    arbreDeDecision->m_tabValue = (float*)calloc(3, sizeof(float));
	arbreDeDecision->m_irisList = flowerList;
    arbreDeDecision->m_leftSon = NULL;
    arbreDeDecision->m_rightSon = NULL;
    

	int nbLignes, i;
	FILE* pfile;
	pfile = fopen("data.txt", "r");

	if (pfile == NULL)
	{
		printf("fichier non valide");
		exit(-1);
	}

	fseek(pfile, 0L, SEEK_SET);

	nbLignes = CountNbLignes(pfile);
    arbreDeDecision->m_samples = nbLignes;
	printf("nombre de lignes : %d\n", arbreDeDecision->m_samples);
    

	// Set pointer to beginning of file:
	fseek(pfile, 0L, SEEK_SET);

	arbreDeDecision->m_irisList = CreateDataList(pfile, flowerList, nbLignes);
    NbFlowerBySpecies(arbreDeDecision);
    
    printf("\n");
    for (i = 0 ; i < 3 ; i++)
    {
        printf("%lf ", arbreDeDecision->m_tabValue[i]);
    }
    
    arbreDeDecision->m_entropy = entropy(arbreDeDecision->m_tabValue, arbreDeDecision->m_samples);
    printf("\n\nentropy : %lf\n", arbreDeDecision->m_entropy);
    
	afficherList(arbreDeDecision->m_irisList);
    
    float min = Min(arbreDeDecision->m_irisList);
    float max = Max(arbreDeDecision->m_irisList);
    
    printf("\nmin : %lf  max : %lf\n", min, max);
    
	fclose(pfile);
	return 0;
}
