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
 *                      Define                       *
 ****************************************************/

/*****************************************************
 *                  Global variables                 *
 ****************************************************/
struct noeud* arbre_huffman[NB_CHAR_MAX];  // TODO Dynamic allocation
struct noeud  feuilles_huffman[NB_CHAR_MAX];  // TODO Dynamic allocation

/*****************************************************
 *                     Functions                     *
 ****************************************************/
/**
 *  @brief Fill in occurrence array
 */
void occurrence(uint8_t* chaine, uint32_t tab[NB_CHAR_MAX])
{
	// Variable declaration
	uint8_t index = 0;

	do
	{
		// Increment occurrence array
		tab[chaine[index]]++;

		// Increment index
		index++;

	// Until we reach the end of the chain
	}while(END_CHAR != chaine[index]);
}

/**
 *  @brief Create feuilles
 */
void creer_feuille(struct noeud* arbre[NB_CHAR_MAX], uint32_t tab[NB_CHAR_MAX])
{
	// Variable declaration
	uint8_t index_occ     = 0;
	uint8_t index_feuille = 0;

	for (index_occ = 0; index_occ < NB_CHAR_MAX; index_occ++)
	{
		if (0 != tab[index_occ])
		{
			// Create feuille
			feuilles_huffman[index_feuille].character  = index_occ;
			feuilles_huffman[index_feuille].occurrence = tab[index_occ];

			// Save feuille
			arbre[index_feuille] = &feuilles_huffman[index_feuille];

			// Increment index
			index_feuille++;
		}
	}
}


/*****************************************************
 *                    End of file                    *
 ****************************************************/
