/*****************************************************
 * huffman.h
 *
 *  Created on: Sep 20, 2021
 *      Author: hugop
 *****************************************************/
#ifndef INC_HUFFMAN_H_
#define INC_HUFFMAN_H_

/*****************************************************
 *                      Include                      *
 ****************************************************/
#include "main.h"

/*****************************************************
 *                      Define                       *
 ****************************************************/
#define END_CHAR         '\0'

/*****************************************************
 *                     Structure                     *
 ****************************************************/
struct noeud
{
	uint8_t      character;   // Caractere initial.
	uint32_t     occurrence;  // Occurrence number.
	uint32_t     code;        // Code binaire dans l'arbre.
	uint32_t     taille_code; // Nombre de bit du code.
	struct noeud *gauche;     // Lien vers les noeuds suivant.
	struct noeud *droite;     //             --
};

/*****************************************************
 *                     Functions                     *
 ****************************************************/
void occurrence(uint8_t* chaine, uint32_t tab[NB_CHAR_MAX]);
void creer_feuille(struct noeud* arbre[NB_CHAR_MAX], uint32_t tab[NB_CHAR_MAX]);

#endif /* INC_HUFFMAN_H_ */
/*****************************************************
 *                    End of file                    *
 ****************************************************/
