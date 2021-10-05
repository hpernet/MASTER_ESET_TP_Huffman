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
 *             Private Functions Prototype           *
 ****************************************************/
/**
  * @brief Shift tree leafs
  * @retval None
  */
static void shift_tree(struct node* io_tree[NB_CHAR_MAX], uint32_t* io_size);

/**
  * @brief Create a new node
  * @retval None
  */
static struct node* new_node(struct node* io_tree[NB_CHAR_MAX]);

/*****************************************************
 *             Public Functions Declaration          *
 ****************************************************/
/**
 *  @brief Fill in occurrence array
 */
void occurrence(uint8_t* i_chain, uint32_t* o_tab)
{
	// Variable declaration
	uint16_t index = 0;

	do
	{
		// Increment occurrence array
		o_tab[i_chain[index]]++;

		// Increment index
		index++;

	// Until we reach the end of the chain
	}while(END_CHAR != i_chain[index]);

	// TODO : print occurence tab on Serial Com
}

/**
 *  @brief Create leaf
 */
void creer_feuille(struct node* o_tree[NB_CHAR_MAX], uint32_t i_array[NB_CHAR_MAX])
{
	// Variable declaration
	uint16_t index_occ  = 0;
	uint16_t tree_size  = 0;

	// Check occurrence array
	for (index_occ = 0; index_occ < NB_CHAR_MAX; index_occ++)
	{
		// If there is a char
		if (0 != i_array[index_occ])
		{
			// Allocate memory to the new char
			o_tree[tree_size] = malloc(sizeof(struct node));

			// Initialize feuille
			o_tree[tree_size]->character   = index_occ;
			o_tree[tree_size]->occurrence  = i_array[index_occ];
			o_tree[tree_size]->droite      = NULL;
			o_tree[tree_size]->gauche      = NULL;
			o_tree[tree_size]->code        = 0;
			o_tree[tree_size]->taille_code = 0;

			// Increment index
			tree_size++;
		}
	}
}

void afficher_arbre_huffman(struct node* i_tree[NB_CHAR_MAX], uint32_t i_size)
{
	// Variable declaration
	uint16_t tree_index;

	printf("\r \n");
	printf("---------------------------- Arbre de Huffman ----------------------------");
	printf("\r \n");
	printf("Character | Occurrence |  Droite  |  Gauche  |   Code   | Taille du code |");

	// Print every structure of arbres
	for (tree_index = 0; tree_index < i_size; tree_index++)
	{
		printf("\r \n");
		printf("-------------------------------------------------------------------------- ");
		printf("\r \n");
		printf("%9c |",       i_tree[tree_index]->character);
		printf("  %9d |",     i_tree[tree_index]->occurrence);
		printf("%9d |",       i_tree[tree_index]->droite);
		printf("%9d |",       i_tree[tree_index]->gauche);
		printf("%9d |",       i_tree[tree_index]->code);
		printf("      %9d |", i_tree[tree_index]->taille_code);
	}
	printf("\r \n");
}

void sort_tree(struct node* io_tree[NB_CHAR_MAX], uint32_t i_size)
{
	// Variable declaration
	uint16_t index_algo;
	uint16_t tree_index;
	struct node* p_temp_variable;

	// Repeat the sorted algorithm
	for (index_algo = 0; index_algo < i_size - 1; index_algo++)
	{
		//Check the entire tree
		for (tree_index = 0; tree_index < i_size - 1; tree_index++)
		{
			// Check if the next case of the array has more occurrence than the actual one
			if (io_tree[tree_index]->occurrence > io_tree[tree_index + 1]->occurrence)
			{
				// Invert two case of the array
				p_temp_variable         = io_tree[tree_index];
				io_tree[tree_index]     = io_tree[tree_index + 1];
				io_tree[tree_index + 1] = p_temp_variable;
			}
		}
	}
}

void reduce_tree(struct node* io_tree[NB_CHAR_MAX], uint32_t i_size)
{
	do
	{
		// Create a new node and stock its adress into tree_index case of io_tree array
		io_tree[0] = new_node(io_tree);

		//Shift tree array
		shift_tree(io_tree, &i_size);

		afficher_arbre_huffman(io_tree, i_size);

	// Until the tree size reach 0 (1 case)
	} while(i_size != 1);
}

void tree_browse(struct node* p_node)
{
	// Check right and left pointers
	if((p_node->droite == NULL) && (p_node->gauche == NULL))
	{
		// Print leaf information
		printf("\r \n");
		printf("Je suis une feuille");
		printf("\r \n");
		printf("%9c |",       p_node->character);
		printf("  %9d |",     p_node->occurrence);
		printf("%9d |",       p_node->droite);
		printf("%9d |",       p_node->gauche);
		printf("%9d |",       p_node->code);
		printf("      %9d |", p_node->taille_code);
		printf("\r \n");
	}
	else
	{
		// Print information
		printf("\r \n");
		printf("Je suis un noeud");
		printf("\r \n");

		// Continue to browse the tree
		tree_browse(p_node->droite);
		tree_browse(p_node->gauche);
	}
}

/*****************************************************
 *            Private Functions Declaration          *
 ****************************************************/
static struct node* new_node(struct node* i_tree[NB_CHAR_MAX])
{
	// Variable declaration
	struct node* r_p_temp_variable;

	// Allocate memory to the node
	r_p_temp_variable = malloc(sizeof(struct node));

	// Initialize node
	r_p_temp_variable->character   = '!';
	r_p_temp_variable->occurrence  = i_tree[0]->occurrence + i_tree[1]->occurrence;
	r_p_temp_variable->droite      = i_tree[0];
	r_p_temp_variable->gauche      = i_tree[1];
	r_p_temp_variable->code        = 0;
	r_p_temp_variable->taille_code = 0;
}

static void shift_tree(struct node* io_tree[NB_CHAR_MAX], uint32_t* io_size)
{
	// Variable declaration
	uint16_t index_algo;

	// Reduce tree size
	*io_size = *io_size - 1;

	// Shift all leaf form start index to the end
	for (index_algo = 1; index_algo < *io_size; index_algo++)
	{
		io_tree[index_algo] = io_tree[index_algo + 1];
	}
}

/*****************************************************
 *                    End of file                    *
 ****************************************************/
