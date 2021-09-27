/*
 * huffman.c
 *
 *  Created on: Sep 20, 2021
 *      Author: hugop
 */
/*****************************************************
 *                      Include                      *
 ****************************************************/
#include "huffman.h"

/*****************************************************
 *                     Functions                     *
 ****************************************************/
/**
 *  @brief Fill in occurrence array
 */
void occurrence(uint8_t* i_chaine, uint32_t* o_tab)
{
	// Variable declaration
	uint16_t index = 0;

	do
	{
		// Increment occurrence array
		o_tab[i_chaine[index]]++;

		// Increment index
		index++;

	// Until we reach the end of the chain
	}while(END_CHAR != i_chaine[index]);

	// TODO : print occurence tab on Serial Com
}

/**
 *  @brief Create feuilles
 */
void creer_feuille(struct noeud* o_arbre[NB_CHAR_MAX], uint32_t i_tab[NB_CHAR_MAX])
{
	// Variable declaration
	uint16_t index_occ     = 0;
	uint16_t taille_arbre  = 0;

	// Check occurrence array
	for (index_occ = 0; index_occ < NB_CHAR_MAX; index_occ++)
	{
		// If there is a char
		if (0 != i_tab[index_occ])
		{
			// Allocate memory to the new char
			o_arbre[taille_arbre] = malloc(sizeof(struct noeud));

			// Initialize feuille
			o_arbre[taille_arbre]->character   = index_occ;
			o_arbre[taille_arbre]->occurrence  = i_tab[index_occ];
			o_arbre[taille_arbre]->droite      = NULL;
			o_arbre[taille_arbre]->gauche      = NULL;
			o_arbre[taille_arbre]->code        = 0;
			o_arbre[taille_arbre]->taille_code = 0;
			// Increment index
			taille_arbre++;
		}
	}
}

void afficher_arbre_huffman(struct noeud* arbre[NB_CHAR_MAX], uint32_t taille)
{
	// Variable declaration
	uint16_t index_arbre;

	printf("\r \n");
	printf("---------------------------- Arbre de Huffman ----------------------------");
	printf("\r \n");
	printf("Character | Occurrence |  Droite  |  Gauche  |   Code   | Taille du code |");

	// Print every structure of arbres
	for (index_arbre = 0; index_arbre < taille; index_arbre++)
	{
		printf("\r \n");
		printf("-------------------------------------------------------------------------- ");
		printf("\r \n");
		printf("%9c |", arbre[index_arbre]->character);
		printf("  %9d |", arbre[index_arbre]->occurrence);
		printf("%9d |", arbre[index_arbre]->droite);
		printf("%9d |", arbre[index_arbre]->gauche);
		printf("%9d |", arbre[index_arbre]->code);
		printf("      %9d |", arbre[index_arbre]->taille_code);
	}
	printf("\r \n");

}


/*****************************************************
 *                    End of file                    *
 ****************************************************/
