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
// Nodes
struct node
{
	uint8_t      character;   // Caractere initial.
	uint32_t     occurrence;  // Occurrence number.
	uint32_t     code;        // Code binaire dans l'arbre.
	uint32_t     taille_code; // Nombre de bit du code.
	struct noeud *gauche;     // Lien vers les noeuds suivant.
	struct noeud *droite;     //             --
};

/*****************************************************
 *                 Public Functions                  *
 ****************************************************/
/**
  * @brief Count character occurrence
  * @retval None
  */
void occurrence(uint8_t* i_chaine, uint32_t o_tab[NB_CHAR_MAX]);

/**
  * @brief Create leaf
  * @retval None
  */
void creer_feuille(struct node* o_arbre[NB_CHAR_MAX], uint32_t i_tab[NB_CHAR_MAX]);

/**
  * @brief Print huffman tree
  * @retval None
  */
void afficher_arbre_huffman(struct node* i_arbre[NB_CHAR_MAX], uint32_t i_taille);

/**
  * @brief Sort tree by occurrences
  * @retval None
  */
void sort_tree(struct node* arbre[NB_CHAR_MAX], uint32_t taille);

/**
  * @brief Reduce tree by creating nodes
  * @retval None
  */
void reduce_tree(struct node* io_tree[NB_CHAR_MAX], uint32_t i_size);

/**
  * @brief Browse Huffman tree and print all leafs
  * @retval None
  */
void tree_browse(struct node* p_node);

#endif /* INC_HUFFMAN_H_ */
/*****************************************************
 *                    End of file                    *
 ****************************************************/
