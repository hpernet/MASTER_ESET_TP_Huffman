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

/*****************************************************
 *                      Define                       *
 ****************************************************/

/*****************************************************
 *                     Structure                     *
 ****************************************************/
struct noeud
{
	uint8_t      character;   // Caractere initial.
	uint32_t     occurrence;  // Occurrence number.
	uint32_t     code;        // Code binaire dans l'arbre.
	uint32_t     taille_code; // Nombtre de bit du code.
	struct noeud *gauche;     // Lien vers les noeuds suivant.
	struct noeud *droite;     //             --
};

#endif /* INC_HUFFMAN_H_ */
/*****************************************************
 *                    End of file                    *
 ****************************************************/
