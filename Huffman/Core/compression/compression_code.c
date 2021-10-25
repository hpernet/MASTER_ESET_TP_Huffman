/*******************************************************************************
 * compression_code.c
 *
 *  Created on: 11 oct. 2021
 *      Author: hugop
 ******************************************************************************/
//=========================================================================================================//
//                                                 Include                                                 //
//=========================================================================================================//
#include "compression_code.h"

//=========================================================================================================//
//                                             Public Functions                                            //
//=========================================================================================================//
struct node* initialize_huffman_tree(uint8_t  i_text[])
{
	uint32_t     occurence_character[NB_CHAR_MAX];  // Array which contain all character
	struct node* p_huffman_tree[NB_CHAR_MAX];  // TODO Dynamic allocation
	uint8_t      tree_size  = 0U;             // Size of the tree
	uint8_t      init_index = 0U;             // loop index used o initialize tab_caractere

	// Initialize tab caractere
	for (init_index = 0; init_index < ARRAY_SIZE; init_index++)
	{
		occurence_character[init_index] = 0;
	}

	// Compute occurence_character
	occurrence(i_text, occurence_character);

	// Create leaf for all characters
	tree_size = create_leaf(p_huffman_tree, occurence_character);

	// Sort and reduce tree
	sort_tree(p_huffman_tree, tree_size);
	reduce_tree(p_huffman_tree, tree_size);

	// return tree root
	return p_huffman_tree[0];
}

void create_code(struct node* p_node,
		         uint32_t     i_code,
				 uint32_t     i_size)
{
	// Check right and left pointers
	if((p_node->droite == NULL) && (p_node->gauche == NULL))
	{
		// Fill in node
		p_node->size_code = i_size;
		p_node->code      = i_code;
	}
	else
	{
		// Continue to browse the tree
		//    Notice : When we go to right we put a 0 in the code
		//             When we go to left we put a 1 in the code
		create_code(p_node->droite, (i_code << 1),       i_size + 1);
		create_code(p_node->gauche, ((i_code << 1) + 1), i_size + 1);
	}
}


void compress_text(struct node* i_p_root,
		           uint8_t      i_text[],
				   uint8_t*     o_compressed_text,
				   uint32_t*    o_compressed_text_size,
				   uint32_t*    o_text_size)
{
	// Variable declaration
	struct node* p_leaf;
	uint32_t     index_bit_text = 0;
	uint32_t     index_text     = 0;
	uint32_t     index_code     = 0;
	uint8_t      is_bit_set;

	// Write every character of the text
	do
	{
		// Get the character structure
		p_leaf = get_adress(i_p_root, i_text[index_text]);

		// Write character code
		for (index_code = 0; index_code < p_leaf->size_code; index_code++)
		{
			// Read bit value
			is_bit_set = MACRO_READ_BIT(p_leaf->code, index_code);

			//Check if bit is set
			if (is_bit_set)
			{
				// Set bit in compressed text variable
				o_compressed_text[index_bit_text / 8] =  o_compressed_text[index_bit_text / 8] | (1 << ((index_bit_text % 8)));
				printf("\r \n");
				printf("1 ");
			}
			else
			{
				printf("\r \n");
				printf("0 ");
			}

			// Increment bit text index
			index_bit_text++;
		}

		// Increment text index
		index_text++;

	// Until we reach the end of the chain
	} while(END_CHAR != i_text[index_text]);

	// Set output values
	*o_compressed_text_size = index_bit_text;
	*o_text_size            = index_text;
}
//=========================================================================================================//
//                                               End of file                                               //
//=========================================================================================================//
