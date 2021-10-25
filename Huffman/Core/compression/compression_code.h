/*******************************************************************************
 * compression_code.h
 *
 *  Created on: 11 oct. 2021
 *      Author: hugop
 ******************************************************************************/
#ifndef INC_COMPRESSION_CODE_H_
#define INC_COMPRESSION_CODE_H_

//=========================================================================================================//
//                                                 Include                                                 //
//=========================================================================================================//
#include "huffman.h"

//=========================================================================================================//
//                                             Public Functions                                            //
//=========================================================================================================//
/**
  * @brief Initialize Huffman code
  * @retval None
  */
struct node* initialize_huffman_tree(uint8_t  i_text[]);

/**
  * @brief Create Huffman code
  * @retval None
  */
void create_code(struct node* p_node,
		         uint32_t     code,
				 uint32_t     size);

/**
  * @brief Compress text
  * @retval None
  */
void compress_text(struct node* i_p_root,
		           uint8_t      i_text[],
				   uint8_t*     o_compressed_text,
				   uint32_t*    o_compressed_text_size,
				   uint32_t*    o_text_size);

#endif /* INC_COMPRESSION_CODE_H_ */
//=========================================================================================================//
//                                               End of file                                               //
//=========================================================================================================//
