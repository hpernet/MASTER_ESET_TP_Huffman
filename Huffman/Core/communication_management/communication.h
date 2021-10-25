/*******************************************************************************
 * communication.h
 *
 *  Created on: 11 oct. 2021
 *      Author: hugop
 ******************************************************************************/
#ifndef COMMUNICATION_MANAGEMENT_COMMUNICATION_H_
#define COMMUNICATION_MANAGEMENT_COMMUNICATION_H_

//=========================================================================================================//
//                                                 Include                                                 //
//=========================================================================================================//
#include "../Inc/main.h"
#include "../compression/huffman.h"

//=========================================================================================================//
//                                               Structure                                                 //
//=========================================================================================================//
/**
  * @brief Character header structure
  */
struct character_header_s
{
	uint8_t ASCII_code;
	uint8_t Huffman_code;
	uint8_t code_size;
};

/**
  * @brief Header structure
  */
struct header_s
{
	uint16_t                  header_size;
	uint16_t                  folder_size;
	uint16_t                  nbr_character_tot;
	struct character_header_s char_header[NB_CHAR_MAX];
};

//=========================================================================================================//
//                                             Public Functions                                            //
//=========================================================================================================//
/**
  * @brief Create header
  * @retval None
  */
struct header_s create_header(uint32_t     i_compressed_text_size,
							  uint32_t     i_text_size,
							  struct node* i_p_tree);

#endif /* COMMUNICATION_MANAGEMENT_COMMUNICATION_H_ */
//=========================================================================================================//
//                                               End of file                                               //
//=========================================================================================================//
