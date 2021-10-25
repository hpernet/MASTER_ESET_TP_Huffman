/*******************************************************************************
 * communication.c
 *
 *  Created on: 11 oct. 2021
 *      Author: hugop
 ******************************************************************************/

//=========================================================================================================//
//                                                 Include                                                 //
//=========================================================================================================//
#include "communication.h"

//=========================================================================================================//
//                                       Private Functions Prototypes                                      //
//=========================================================================================================//
/**
  * @brief Fill in character information in header structure
  * @retval None
  */
void fill_in_char_informations(struct node*     p_node,
		                       struct header_s* o_header,
							   uint32_t*        io_header_index);

//=========================================================================================================//
//                                             Public Functions                                            //
//=========================================================================================================//
struct header_s create_header(uint32_t     i_compressed_text_size,
							  uint32_t     i_text_size,
							  struct node* i_p_tree)
{
	// Variable declaration
	struct header_s r_header;
	uint32_t        char_information_size = 0U;

	// Fill in sizes in header structure
	r_header.folder_size       = i_compressed_text_size;
	r_header.nbr_character_tot = i_text_size;

	// Fill in char informations
	fill_in_char_informations(i_p_tree, &r_header, &char_information_size);

	// Compute header size
	r_header.header_size = i_compressed_text_size + i_text_size + char_information_size;

	// Return header
	return r_header;
}

//=========================================================================================================//
//                                            Private Functions                                            //
//=========================================================================================================//
void fill_in_char_informations(struct node*     p_node,
		                       struct header_s* o_header,
							   uint32_t*        io_header_index)
{
	// Check right and left pointers
	if((p_node->droite == NULL) && (p_node->gauche == NULL))
	{
		//Fill in header
		o_header->char_header[*io_header_index].ASCII_code   = p_node->character;
		o_header->char_header[*io_header_index].Huffman_code = p_node->code;
		o_header->char_header[*io_header_index].code_size    = p_node->size_code;

		*io_header_index = *io_header_index + 1;
	}
	else
	{
		// Continue to browse the tree
		fill_in_char_informations(p_node->droite, o_header, io_header_index);
		fill_in_char_informations(p_node->gauche, o_header, io_header_index);
	}
}

//=========================================================================================================//
//                                               End of file                                               //
//=========================================================================================================//
