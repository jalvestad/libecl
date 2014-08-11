/*
   Copyright (C) 2014  Statoil ASA, Norway. 
    
   The file 'fault_block.h' is part of ERT - Ensemble based Reservoir Tool. 
    
   ERT is free software: you can redistribute it and/or modify 
   it under the terms of the GNU General Public License as published by 
   the Free Software Foundation, either version 3 of the License, or 
   (at your option) any later version. 
    
   ERT is distributed in the hope that it will be useful, but WITHOUT ANY 
   WARRANTY; without even the implied warranty of MERCHANTABILITY or 
   FITNESS FOR A PARTICULAR PURPOSE.   
    
   See the GNU General Public License at <http://www.gnu.org/licenses/gpl.html> 
   for more details. 
*/

#ifndef __FAULT_BLOCK_H__
#define __FAULT_BLOCK_H__
#ifdef __cplusplus
extern "C" {
#endif

#include <ert/util/int_vector.h>
#include <ert/util/type_macros.h>
#include <ert/ecl/ecl_grid.h>
#include <ert/ecl/ecl_kw.h>



  
  typedef struct fault_block_struct  fault_block_type;
  
  fault_block_type * fault_block_alloc( const ecl_grid_type * grid , int k , int block_id );
  void               fault_block_free( fault_block_type * block );
  void               fault_block_free__( void * arg);
  int                fault_block_get_size( const fault_block_type * block );
  void               fault_block_add_cell( fault_block_type * fault_block , int i , int j);
  double             fault_block_get_xc( fault_block_type * fault_block );
  double             fault_block_get_yc( fault_block_type * fault_block );
  int                fault_block_get_id( const fault_block_type * block );
  int                fault_block_get_size( const fault_block_type * fault_block );
  void               fault_block_export_cell(const fault_block_type * fault_block , int index , int * i , int * j , int * k , double * x, double * y, double * z);
  const int_vector_type * fault_block_get_global_index_list(const fault_block_type * fault_block);
  void               fault_block_assign_to_region( fault_block_type * fault_block , int region_id );
  const int_vector_type * fault_block_get_region_list( const fault_block_type * fault_block );

  UTIL_IS_INSTANCE_HEADER(fault_block);
  
#ifdef __cplusplus
}
#endif
#endif